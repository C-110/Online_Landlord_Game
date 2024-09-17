//
// Created by yyds on 2024/9/16.
//

#ifndef SERVER_ROOM_H
#define SERVER_ROOM_H
#include <string>
#include <iostream>
#include <sw/redis++/redis++.h>
using namespace std;


class Room {
public:
    Room() = default;
    ~Room();

    // 初始化 - 连接redis
    bool initEnvironment();
    // 清空数据
    void clear();
    // 保存RSA密钥对
    // key(filed, value)
    void saveRsaSecKey(std::string field,std::string value);
    // 读密钥
    std::string rsaSecKey(std::string field);
    // 加入房间
    string joinRoom(string userName);
    bool joinRoom(string userName, string roomName);
    // 随机生成房间的名字
    string getNewRoomName();
    // 得到房间内玩家的数量
    int getPlayerCount(string roomName);
    // 存储玩家的分数
    void updatePlayerScore(string roomName, string userName, int score);
    // 通过玩家找房间
    string whereAmi(string userName);
    // 查询玩家分数
    int playerScore(string roomName,string userName);
    // 得到抢地主的次序
    string playerOrder(string roomName);
private:
    sw::redis::Redis* m_redis;
    const string OnePlayer = "OnePlayer";
    const string TwoPlayer = "TwoPlayer";
    const string ThreePlayer = "ThreePlayer";
};


#endif //SERVER_ROOM_H
