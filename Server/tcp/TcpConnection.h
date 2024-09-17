#pragma once
#include "EventLoop.h"
#include "Buffer.h"
#include "Channel.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "Communication.h"

//#define MSG_SEND_AUTO

class TcpConnection
{
public:
    TcpConnection(int fd, EventLoop* evloop);
    ~TcpConnection();

    // 发送数据
    void addWriteTask(std::string data);
    // 释放资源
    void addDeleteTask();

    // 准备密钥
    void prepareSecretKey();

    // 这里将回调函数设置为静态函数，可以作为可调用对象，供其他类使用，如果成员函数不是类的静态函数，需要使用bind对其进行绑定，得到可调用对象
    static int processRead(void* arg);
    static int processWrite(void* arg);
    static int destroy(void* arg);

private:
    string m_name;
    EventLoop* m_evLoop;
    Channel* m_channel;
    Buffer* m_readBuf;
    Buffer* m_writeBuf;
    Communication* m_reply = nullptr;
};