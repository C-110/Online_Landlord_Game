//
// Created by yyds on 2024/9/6.
//

#include <netinet/in.h>
#include "Communication.h"
#include "RsaCrypto.h"
#include "Log.h"
#include "JsonParse.h"
#include "RoomList.h"

void Communication::parseRequest(Buffer* buf)
{
    // 先读数据头
    std::string data = buf->data(sizeof (int));
    int length = *(int*)data.data();
    length = ntohl(length);
    // 读数据体
    data = buf->data(length);
    if(m_aes)
    {
        data = m_aes->dectypt(data);
    }

    // 数据的反序列化
    Codec codec(data);
    Message resMsg;
    sendCallback myfunc = sendMessage;
    // 共享智能指针
    shared_ptr<Message> ptr = codec.decodeMsg();
    switch(ptr->reqcode)
    {
        case RequestCode::AesFenfa:
            handleAesFenfa(ptr.get(),resMsg);
            break;
        case RequestCode::UserLogin:
            handleLogin(ptr.get(), resMsg);
            break;
        case RequestCode::Register:
            handleRegister(ptr.get(),resMsg);
            break;
        case RequestCode::AutoRoom:
        case RequestCode::ManualRoom:
            handleAddRoom(ptr.get(),resMsg);
            // 改变可调用对象
            myfunc = std::bind(&Communication::readyForPlay,this,resMsg.roomName,std::placeholders::_1);
            break;
        default:
            break;
    }
    // 序列化并发送数据
    codec.reLoad(&resMsg);
    myfunc(codec.encodeMsg());
}

void Communication::handleAesFenfa(Message* reqMsg, Message& resMsg)
{
    RsaCrypto rsa;
    rsa.parseStringToKey(m_redis->rsaSecKey("PrivateKey"),RsaCrypto::PrivateKey);
    std::string aesKey = rsa.priKeyDecrypt(reqMsg->data1);
    // 哈希校验
    Hash h(HashType::Sha224);
    h.addData(aesKey);
    std::string res = h.result();

    resMsg.rescode = RespondCode::AesVerifOK;
    if(reqMsg->data2 != res)
    {
        Debug("密钥校验失败--ase");
        resMsg.rescode = RespondCode::Failed;
        resMsg.data1 = "Aes 密钥的哈希校验失败--";
    }
    else
    {
        m_aes = new AesCrypto(AesCrypto::AES_CBC_256,aesKey);
        Debug("密钥校验成功--ase");
    }
}

void Communication::setCallback(Communication::sendCallback func1, Communication::deleteCallback func2)
{
    sendMessage = func1;
    disconnect = func2;
}

void Communication::handleRegister(Message *reqMsg, Message &resMsg)
{
    // 查询数据库
    // select 字段 from 数据库表 where 条件;
    char sql[1024];
    sprintf(sql, "SELECT * FROM `user` WHERE `name`='%s';", reqMsg->userName.data());
    bool flag = m_mysql->query(sql);
    Debug("flag = %d, sql = %s", flag, sql);
    if(flag && !m_mysql->next())
    {
        // 将注册信息写入到数据库
        m_mysql->transaction();
        sprintf(sql, "INSERT INTO `user`(name, passwd, phone, date) VALUES('%s', '%s', '%s', NOW());",
                reqMsg->userName.data(), reqMsg->data1.data(), reqMsg->data2.data());
        bool fl1 = m_mysql->update(sql);
        Debug("fl1 = %d, sql = %s", fl1, sql);
        sprintf(sql, "INSERT INTO `information`(name, score, status) VALUES('%s', 0, 0);",
                reqMsg->userName.data());
        bool fl2 = m_mysql->update(sql);
        Debug("fl2 = %d, sql = %s", fl2, sql);
        if(fl1 && fl2)
        {
            m_mysql->commit();
            resMsg.rescode = RespondCode::RegisterOk;
        }
        else
        {
            m_mysql->rollback();
            resMsg.rescode = RespondCode::Failed;
            resMsg.data1 = "数据库插入数据失败!";
        }
    }
    else
    {
        resMsg.rescode = RespondCode::Failed;
        resMsg.data1 = "用户名已经存在, 无法完成注册!";
    }
}

Communication::Communication()
{
    JsonParse json;
    shared_ptr<DBInfo> info = json.getDatabaseInfo(JsonParse::Mysql);

    m_mysql = new MySqlConn();
    // 这里数据库的表有点诡异，因为之前创表的时候乱起名
    bool flag = m_mysql->connect(info->user, info->dbname, info->passwd,info->ip, info->port);
    assert(flag);
    m_redis = new Room;
    flag = m_redis->initEnvironment();
    assert(flag);
}

void Communication::handleLogin(Message *reqMsg, Message &resMsg)
{
    char sql[1024];
    sprintf(sql, "SELECT * FROM `user` WHERE `name`='%s' AND passwd='%s' AND (select  count(*) from information where name = '%s' AND status=0);"
            , reqMsg->userName.data(),reqMsg->data1.data(),reqMsg->userName.data());
    bool flag = m_mysql->query(sql);
    if(flag && m_mysql->next())
    {
        m_mysql->transaction();
        sprintf(sql, "update `information` set status=1 WHERE `name`='%s'", reqMsg->userName.data());
        bool flag1 = m_mysql->update(sql);
        if(flag1)
        {
            m_mysql->commit();
            resMsg.rescode = RespondCode::LoginOk;
            Debug("用户登录成功了!");
            return;
        }
        m_mysql->rollback();
    }
    resMsg.rescode = RespondCode::Failed;
    resMsg.data1 = "用户名或者密码错误, 或者当前用户已经成功登录了...";
}

void Communication::handleAddRoom(Message *reqMsg, Message &resMsg)
{
    // 如果玩家已经不是第一次（登录之后）加入房间
    string oldRoom = m_redis->whereAmi(reqMsg->userName);
    // 查询这个玩家上次加入到的房间，然后把分数读出来
    int score = m_redis->playerScore(oldRoom,reqMsg->userName);
    bool flag = true;
    string roomName;
    if(reqMsg->reqcode == RequestCode::AutoRoom)
    {
        roomName = m_redis->joinRoom(reqMsg->userName);
    }
    else
    {
        roomName = reqMsg->roomName;
        flag = m_redis->joinRoom(reqMsg->userName,roomName);
    }
    // 判断房间是否已经加入成功
    if(flag)
    {
        // 第一次加载分数，在redis中更新，最后将分数同步到mysql
        if(score == 0)
        {
            // 查询mysql，并将其存储到redis中
            string sql = "select score from information where name = '" + reqMsg->userName + "'";
            bool fl = m_mysql->query(sql);
            assert(fl);
            m_mysql->next();
            score = stoi(m_mysql->value(0));
        }
        m_redis->updatePlayerScore(roomName,reqMsg->userName,score);

        // 将房间和玩家的关系保存到单例对象中
        RoomList* roomList = RoomList::getInstance();
        roomList->addUser(roomName,reqMsg->userName,sendMessage);

        // 给客户端回复加入成功
        resMsg.rescode = RespondCode::JoinRoomOK;
        resMsg.data1 = m_redis->getPlayerCount(roomName);
        resMsg.roomName = roomName;
    }
    else
    {
        // 回复失败
        resMsg.rescode = RespondCode::Failed;
        resMsg.data1 = "抱歉，加入房间失败了，人数已满！";
    }

}

Communication::~Communication() {
    if(m_redis)
    {
        delete m_redis;
    }
    if(m_aes)
    {
        delete m_aes;
    }
    if(m_mysql)
    {
        delete m_mysql;
    }
}

void Communication::readyForPlay(std::string roomName, std::string data)
{
     // 取出单例对象，获取房间内玩家信息（包括通信函数）
     RoomList* instance  = RoomList::getInstance();
     UserMap players = instance->getPlayers(roomName);
     // 判断满员
     if(players.size() < 3)
     {
         // 房间还没有满，通知房间内的每个玩家房间人数
         for(auto item : players)
         {
             item.second(data);
         }
     }
     else
     {
        // 房间满了
        // 发牌数据
         dealCards(players);
        // 通知客户端可以开始游戏了
        Message msg;
        msg.rescode = RespondCode::StartGame;
        msg.data1 = m_redis->playerOrder(roomName);
        Codec codec(&msg);
        for(const auto& item : players)
        {
            item.second(codec.encodeMsg());
        }
     }
}

void Communication::dealCards(UserMap players)
{
    Message msg;
    // 洗牌
    initCards();
    string &all = msg.data1;
    for(int i=0;i<51;i++)
    {
        // 取出一张牌
        auto card = takeOneCard();
        string sub = to_string(card.first) + "-" + to_string(card.second) + "#";
        all+=sub;
    }
    // 剩余3张底牌
    string &lastCard = msg.data2;
    for(const auto& item : m_cards)
    {
        string sub = to_string(item.first) + "-" + to_string(item.second) + "#";
        lastCard += sub;
    }
    msg.rescode = RespondCode::DealCards;
    Codec codec(&msg);
    // 遍历当前房间中的所有玩家
    for(const auto& player : players)
    {
        // 发送数据
        player.second(codec.encodeMsg());
    }
}

void Communication::initCards()
{
    m_cards.clear();
    for(int i=1;i<=4;i++)
    {
        // i对应花色
        for(int j=1;j<=13;j++)
        {
            // j对应点数
            m_cards.insert(make_pair(i,j));
        }
    }
    m_cards.insert(make_pair(0,14));
    m_cards.insert(make_pair(0,15));
}

pair<int, int> Communication::takeOneCard() {
    // 生成随机数
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,m_cards.size()-1);
    int randNum = dis(gen);
    auto it = m_cards.begin();
    // 遍历map容器
    for(int i=0;i<randNum;i++,it++);
    m_cards.erase(it);
    return *it;     // 这里返回*it有bug，因为之前已经删除it对应的值了
}
