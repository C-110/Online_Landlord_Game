#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QByteArray>
#include "communication.h"

// 饿汉模式
class DataManager
{
public:
    static DataManager* getInstance();

    // 设置数据
    void setUserName(QByteArray name);
    void setIP(QByteArray ip);
    void setPort(QByteArray port);
    void setCommunition(Communication* comm);
    // 获取数据
    QByteArray getUserName();
    QByteArray getIP();
    QByteArray getPort();
    Communication* getCommunication();

private:    // 构造，拷贝构造，赋值重载运算符
    DataManager() = default;
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;
private:
    static DataManager* m_data;

    // 全局数据
    QByteArray m_userName;
    QByteArray m_ip = "172.19.166.10";
    QByteArray m_port = "10000";
    Communication* m_commun;

};
#endif // DATAMANAGER_H
