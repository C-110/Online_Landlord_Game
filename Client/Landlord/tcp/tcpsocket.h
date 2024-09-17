#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QByteArray>

#ifdef Q_OS_WIN
#include <winsock2.h>
#endif


class TcpSocket : public QObject
{
    Q_OBJECT;   // 使用这个宏才可以使用qt的信号与槽

public:
    TcpSocket(QObject* parent = nullptr);
    TcpSocket(QByteArray ip,unsigned short port, QObject* parent = nullptr);
    ~TcpSocket();

    // 连接服务器
    bool connectTcpHost(QByteArray ip,unsigned short port);
    // 接收和发送数据
    QByteArray recvMsg(int timeout = -1);   // 单位： s
    bool sendMsg(QByteArray msg,int timeout = -1);
    // 断开连接
    void disConnect();

private:
    bool readTimeout(int timeout);
    bool writeTimeout(int timeout);
    int readn(char* buf,int count);
    int writen(const char* buf,int count);

// 通过qt提供的宏判断操作系统
#ifdef Q_OS_WIN
    SOCKET m_socket;
#endif

#ifdef Q_OS_LINUX
    int m_socket;
#endif
};




#endif
