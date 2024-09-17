#include "TcpConnection.h"
#include "HttpRequest.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include "Codec.h"
#include "RsaCrypto.h"
#include "Log.h"
#include "Room.h"

int TcpConnection::processRead(void* arg)
{
    TcpConnection* conn = static_cast<TcpConnection*>(arg);
    // 接收数据
    int socket = conn->m_channel->getSocket();
    int count = conn->m_readBuf->socketRead(socket);

    Debug("接收到的http请求数据: %s", conn->m_readBuf->data());
    if (count > 0)
    {
        // 解析斗地主数据
        conn->m_reply->parseRequest(conn->m_readBuf);
        Debug("和客户端断开连接----");
    }
    else if(count <= 0)
    {
        // 和客户端断开连接
        conn->addDeleteTask();
    }
    return 0;
}

int TcpConnection::processWrite(void* arg)
{
//    Debug("开始发送数据了(基于写事件发送)....");
    TcpConnection* conn = static_cast<TcpConnection*>(arg);
    // 发送数据
    int count = conn->m_writeBuf->sendData(conn->m_channel->getSocket());
    if (count > 0)
    {
        // 判断数据是否被全部发送出去了
        if (conn->m_writeBuf->readableSize() == 0)
        {
            // 1. 不再检测写事件 -- 修改channel中保存的事件
            conn->m_channel->setCurrentEvent(FDEvent::ReadEvent);
            // 2. 修改dispatcher检测的集合 -- 添加任务节点
            conn->m_evLoop->addTask(conn->m_channel, ElemType::MODIFY);
            Debug("数据发送完毕----");
        }
    }
    return 0;
}

int TcpConnection::destroy(void* arg)
{
    TcpConnection* conn = static_cast<TcpConnection*>(arg);
    if (conn != nullptr)
    {
        delete conn;
    }
    return 0;
}

TcpConnection::TcpConnection(int fd, EventLoop* evloop)
{
    m_evLoop = evloop;
    m_readBuf = new Buffer(10240);
    m_writeBuf = new Buffer(10240);
    m_reply = new Communication();

    // 类的成员函数要先使用bind进行绑定才能作为可调用对象
    auto delFunc = std::bind(&TcpConnection::addDeleteTask,this);
    auto writeFunc = std::bind(&TcpConnection::addWriteTask,this,std::placeholders::_1);
    m_reply->setCallback(writeFunc,delFunc);

    m_name = "Connection-" + to_string(fd);
    // 分发公钥
    prepareSecretKey();
    m_channel = new Channel(fd, FDEvent::WriteEvent, processRead, processWrite, destroy, this);
    evloop->addTask(m_channel, ElemType::ADD);
}

TcpConnection::~TcpConnection()
{
    if (m_readBuf && m_readBuf->readableSize() == 0 &&
        m_writeBuf && m_writeBuf->readableSize() == 0)
    {
        delete m_readBuf;
        delete m_writeBuf;
        m_evLoop->freeChannel(m_channel);
    }
    Debug("连接断开, 释放资源, gameover, connName: %s", m_name.data());
}

void TcpConnection::prepareSecretKey()
{
    Room redis;
    redis.initEnvironment();
    // 读取磁盘里的公钥
    string pubkey = redis.rsaSecKey("PublicKey");
    // 发送数据
    Message msg;
    msg.rescode = RespondCode::RsaFenFa;
    msg.data1 = pubkey;
    RsaCrypto rsa;
    rsa.parseStringToKey(redis.rsaSecKey("PrivateKey"),RsaCrypto::PrivateKey);
    string data = rsa.sign(pubkey);
    msg.data2 = data;
    Codec codec(&msg);
    data = codec.encodeMsg();

    // 写数据
    m_writeBuf->appendPackage(data);
}

void TcpConnection::addWriteTask(std::string data)
{
    m_writeBuf->appendPackage(data);
#if 0 // 通过事件进行发送
    // 1. 不再检测写事件 -- 修改channel中保存的事件
    m_channel->setCurrentEvent(FDEvent::WriteEvent);
    // 2. 修改dispatcher检测的集合 -- 添加任务节点
    m_evLoop->addTask(m_channel, ElemType::MODIFY);
#else // 直接发送
    m_writeBuf->sendData(m_channel->getSocket());
#endif
}

void TcpConnection::addDeleteTask()
{
    m_evLoop->addTask(m_channel, ElemType::DELETE);
    Debug("断开连接服务器, connName = %s",m_name.data());
}
