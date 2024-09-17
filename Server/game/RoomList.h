//
// Created by yyds on 2024/9/17.
//

#ifndef SERVER_ROOMLIST_H
#define SERVER_ROOMLIST_H
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <mutex>

// 单例模式 - 懒汉模式
using callback = std::function<void(std::string)>;  // 可调用对象
using UserMap = std::map<std::string,callback>;
class RoomList{
public:
    RoomList(const RoomList&) = delete;
    RoomList& operator=(const RoomList&) = delete;
    static RoomList* getInstance();
    // 添加用户到指定房间
    void addUser(std::string roomName, std::string userName, callback sendMessage);
    // 通过房间名字取出用户信息
    UserMap getPlayers(std::string roomName);

private:
    RoomList() = default;

private:
    std::map<std::string ,UserMap> m_roomMap;   // 共享资源，需要进行多线程访问
    std::mutex m_mutex;

};


#endif //SERVER_ROOMLIST_H
