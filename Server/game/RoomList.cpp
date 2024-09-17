//
// Created by yyds on 2024/9/17.
//

#include "RoomList.h"

RoomList *RoomList::getInstance() {
    static RoomList obj;
    return &obj;
}

void RoomList::addUser(std::string roomName, std::string userName, callback sendMessage) {
    // 在当前map中搜索roomMap
    std::lock_guard<std::mutex> locker(m_mutex);
    if(m_roomMap.find(roomName)!= m_roomMap.end())
    {
        // 找到了
        auto &value = m_roomMap[roomName];
        value.insert(make_pair(userName,sendMessage));
    }
    else
    {
        // 没找到
        UserMap  value = {{userName,sendMessage}};
        m_roomMap.insert(make_pair(roomName,value));
    }
}

UserMap RoomList::getPlayers(std::string roomName)
{
    std::lock_guard<std::mutex> locker(m_mutex);
    auto item = m_roomMap.find(roomName);
    if(m_roomMap.end() == item)
    {
        return UserMap();
    }
    UserMap user = item->second;
    return user;
}
