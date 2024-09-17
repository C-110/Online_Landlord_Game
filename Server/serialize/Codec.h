//
// Created by yyds on 2024/9/4.
//

#ifndef SERVER_CODEC_H
#define SERVER_CODEC_H


#ifndef CODEC_H
#define CODEC_H

#include <string>
#include "infomation.pb.h"
#include <memory>

struct Message
{
    std::string userName;
    std::string roomName;
    std::string data1;
    std::string data2;
    std::string data3;
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
    Codec(std::string msg);

// 数据编码
std::string encodeMsg();

// 数据解码
std::shared_ptr<Message> decodeMsg();

    void reLoad(Message* msg);

private:
    // 设置数据
    void reLoad(std::string msg);

private:
    std::string m_msg;
    Information m_obj;  // 用于数据序列化和反序列化

};

#endif // CODEC_H



#endif //SERVER_CODEC_H
