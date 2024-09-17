#ifndef CODEC_H
#define CODEC_H

#include <QByteArray>
#include "infomation.pb.h"
#include <QSharedPointer>

struct Message
{
    QByteArray userName;
    QByteArray roomName;
    QByteArray data1;
    QByteArray data2;
    QByteArray data3;
    // 操作码
    RequestCode reqcode;
    RespondCode rescode;
};

class Codec
{
public:
    // 序列化
    Codec(Message* msg);
    // 反序列化
    Codec(QByteArray msg);
    // 数据编码
    QByteArray encodeMsg();
    // 数据解码
    QSharedPointer<Message> decodeMsg();
    // 设置数据
    void reLoad(QByteArray msg);
    void reLoad(Message* msg);

private:
    QByteArray m_msg;
    Information m_obj;  // 用于数据序列化和反序列化

};

#endif // CODEC_H
