//
// Created by yyds on 2024/9/16.
//

#include "Room.h"
#include "JsonParse.h"
#include "Log.h"

bool Room::initEnvironment() {
    // tcp://127.0.0.1:6379
    JsonParse json;
    auto info = json.getDatabaseInfo(JsonParse::Redis);
    string conStr = "tcp://" + info->ip + ":" + to_string(info->port);
    m_redis = new sw::redis::Redis(conStr);
    // 测试连接
    if(m_redis->ping() == "PONG") {
        Debug("成功连接 redis 服务器");
        return true;
    }
    return false;
}

void Room::clear() {
    // flushdb
    m_redis->flushdb();
}

void Room::saveRsaSecKey(std::string field, std::string value) {
    m_redis->hset("RSA",field,value);
}

std::string Room::rsaSecKey(std::string field) {
    auto value = m_redis->hget("RSA",field);
    if(value.has_value())
    {
        return value.value();
    }
    return std::string();
}

Room::~Room() {
    if(m_redis)
    {
        delete m_redis;
    }
}

bool Room::joinRoom(string userName, string roomName)
{
    // 检查房间人数是否满人了
    if(m_redis->zcard(roomName) >= 3)
    {
        return false;
    }
    // 检查房间是否存在 --> 不存在直接添加房间
    if(!m_redis->exists(roomName))
    {
        m_redis->sadd(OnePlayer,roomName);
    }
    // 移动房间
    else if(m_redis->sismember(OnePlayer,roomName))
    {
        m_redis->smove(OnePlayer,TwoPlayer,roomName);
    }
    else if(m_redis->sismember(TwoPlayer,roomName))
    {
        m_redis->smove(TwoPlayer,ThreePlayer,roomName);
    }
    else
    {
        assert(false);
    }
    // 将玩家添加到房间
    m_redis->zadd(roomName,userName,0);
    // 将玩家存储起来， 通过玩家找到玩家房间，哈希
    m_redis->hset("Players",userName,roomName);
    return true;
}

string Room::joinRoom(string userName)
{
    optional<string> room;
    if(m_redis->scard(TwoPlayer) > 0)
    {
        room = m_redis->srandmember(TwoPlayer);
    }
    else if(m_redis->scard(OnePlayer) > 0)
    {
        room = m_redis->srandmember(OnePlayer);
    }
    else    // 添加新的房间
    {
        room = getNewRoomName();
    }
    joinRoom(userName,room.value());
    return room.value();
}

string Room::getNewRoomName() {
    // 创建随机数
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(100000,999999);
    int randNum = dis(gen);
    return to_string(randNum);
}

int Room::getPlayerCount(string roomName) {
    int count = m_redis->zcard(roomName);
    return count;
}

void Room::updatePlayerScore(string roomName, string userName, int score) {
    m_redis->zadd(roomName,userName,score);
}

string Room::whereAmi(string userName) {
    auto value = m_redis->hget("Players",userName);
    if(value.has_value())
    {
        return value.value();
    }
    return std::string();
}

int Room::playerScore(string roomName, string userName) {
    auto score = m_redis->zscore(roomName,userName);
    if(score.has_value())
    {
        return score.value();
    }
    return 0;
}

string Room::playerOrder(string roomName)
{
    int index = 0;
    string data;
    vector<pair<string,double>> output;
    m_redis->zrevrange(roomName, 0, -1, back_inserter(output));
    for(auto it : output)
    {
        data += it.first + "-" + to_string(++index) + "-" + to_string((int)it.second) + "#";
    }
    return data;
}
