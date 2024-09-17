#include "communication.h"
#include "datamanager.h"
#include <QThread>
#include <QDebug>
#include <QSharedPointer>
#include <RsaCrypto.h>
#include <QDateTime>

Communication::Communication(Message& msg, QObject *parent)
    : QObject{parent},m_msgInfo(msg)
{
    setAutoDelete(true);
}

Communication::~Communication()
{
    if(m_aes)
        delete m_aes;
}

void Communication::sendMessage(Message *msg, bool encrypt)
{
    Codec codec(msg);
    QByteArray data = codec.encodeMsg();
    qDebug()<<"1111: "<<msg->reqcode;
    // 加密数据
    if(encrypt)
    {
        data = m_aes->enctypt(data);
    }
    m_socket->sendMsg(data);
}

void Communication::parseRecvMessage()
{
    // 接收数据
    QByteArray data = m_socket->recvMsg(2);
    // qDebug()<<"接收到的数据："<<data;
    if(data.isEmpty())
        return ;
    // 反序列化
    Codec codec(data);
    QSharedPointer<Message> ptr = codec.decodeMsg();
    // qDebug()<<ptr->rescode<<", "<<ptr->data1<<", "<<ptr->data2;
    switch (ptr->rescode)
    {
    case RespondCode::LoginOk:
        emit loginOk();
        qDebug()<<"登录成功了！";
        break;
    case RespondCode::RegisterOk:
        emit registerOk();
        qDebug()<<"注册成功了！";
        break;
    case RespondCode::RsaFenFa:
        handleRsaFenfa(ptr.get());
        break;
    case RespondCode::AesVerifOK:
        m_aes = new AesCrypto(AesCrypto::AES_CBC_256,m_aesKey);
        sendMessage(&m_msgInfo);
        qDebug()<<"Aes 的秘钥分发成功了";
        break;
    case RespondCode::Failed:
        emit failedMsg(ptr->data1);
        break;
    default:
        break;
    }
}

void Communication::handleRsaFenfa(Message* msg)
{
    // 签名校验
    RsaCrypto rsa;
    rsa.parseStringToKey(msg->data1,RsaCrypto::PublicKey);
    bool flag = rsa.verify(msg->data2,msg->data1);
    assert(flag);

    // 生成对称加密密钥
    m_aesKey = generateAesKey(KeyLen::L32);
    Message resMsg;
    resMsg.reqcode = RequestCode::AesFenfa;
    // 公钥加密aes密钥
    resMsg.data1 = rsa.pubKeyEncrypt(m_aesKey);
    // aes密钥哈希
    resMsg.data2 = QCryptographicHash::hash(m_aesKey,QCryptographicHash::Sha224).toHex(); //16进制数哈希
    sendMessage(&resMsg,false);
}

QByteArray Communication::generateAesKey(KeyLen len)
{
    // 利用系统时间+哈希计算生成随机aes密钥
    QByteArray time = QDateTime::currentDateTime().toString("yyyy.MM,dd-hh:mm:ss.zzz").toUtf8();
    // 哈希处理
    QCryptographicHash hash(QCryptographicHash::Sha3_384);
    hash.addData(time);
    time = hash.result();
    time = time.left(len);
    return time;
}

void Communication::run()
{
    m_socket = new TcpSocket();
    // 连接服务器
    DataManager* obj = DataManager::getInstance();
    bool flag = m_socket->connectTcpHost(obj->getIP(),obj->getPort().toInt());
    qDebug()<<"=============通信子线程id: "<<QThread::currentThread()<<"connected? "<<flag;
    if(!flag)
    {
        // 通知主线程连接失败
        emit connectFailed();
        delete m_socket;
    }
    // 连接成功了
    while(!m_stop)
    {
        // 处理服务器回复的数据
        // 首先得到非对称加密的公钥，发送加密之后的对称加密密钥，服务器回复接收密钥成功的消息，然后发送登录或者注册请求
        parseRecvMessage();
    }
    m_socket->disConnect();
    delete m_socket;
}
