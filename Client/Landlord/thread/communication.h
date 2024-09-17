#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <QRunnable>
#include "tcpsocket.h"
#include "codec.h"
#include "aescrypto.h"

class Communication : public QObject, public QRunnable
{
    Q_OBJECT
public:
    enum KeyLen{L16 = 16, L24 = 24, L32 = 32};  // 单位字节
    explicit Communication(Message& msg, QObject *parent = nullptr);
    ~Communication();

    // 给服务器发送数据
    void sendMessage(Message* msg, bool encrypt = true);
    // 解析数据 --服务器发过来的数据
    void parseRecvMessage();
    // 验证服务器的公钥，生成对称密钥并用公钥加密
    void handleRsaFenfa(Message* msg);
    // 生成对称密钥
    QByteArray generateAesKey(KeyLen len);

    inline void stopLoop()
    {
        m_stop = true;
    }

protected:
    void run() override;

signals:
    void connectFailed();
    void loginOk();
    void registerOk();
    void failedMsg(QByteArray msg);
private:
    bool m_stop = false;
    Message m_msgInfo;
    TcpSocket* m_socket = nullptr;
    QByteArray m_aesKey;
    AesCrypto* m_aes = nullptr;
};

#endif // COMMUNICATION_H
