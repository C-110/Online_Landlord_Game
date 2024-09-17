//
// Created by yyds on 2024/9/6.
//

#ifndef SERVER_COMMUNICATION_H
#define SERVER_COMMUNICATION_H
#include "Buffer.h"
#include "Codec.h"
#include "AesCrypto.h"
#include "MySqlConn.h"
#include "Room.h"
#include "RoomList.h"

class Communication {
public:
    Communication();
    ~Communication();
    // 解析客户端发送过来的数据
    void parseRequest(Buffer* buf);
    // 设置回调
    using sendCallback = function<void(string)>;
    using deleteCallback = function<void()>;
    void setCallback(sendCallback func1, deleteCallback func2);

    // 处理秘钥分发
    void handleAesFenfa(Message* reqMsg,Message& resMsg);
    // 处理注册
    void handleRegister(Message* reqMsg,Message& resMsg);
    // 处理登录
    void handleLogin(Message* reqMsg,Message& resMsg);
    // 处理加入房间
    void handleAddRoom(Message* reqMsg,Message& resMsg);
    // 准备开始游戏
    void readyForPlay(std::string roomName, std::string data);
    // 发牌
    void dealCards(UserMap players);
    // 洗牌
    void initCards();
    // 随机取出一张牌
    pair<int,int> takeOneCard();
private:
    sendCallback sendMessage;
    deleteCallback disconnect;
    AesCrypto* m_aes = nullptr;
    MySqlConn *m_mysql = nullptr;
    Room* m_redis = nullptr;
    multimap<int,int> m_cards;
};


#endif //SERVER_COMMUNICATION_H
