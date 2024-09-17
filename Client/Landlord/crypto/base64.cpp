#include "base64.h"
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <QDebug>

Base64::Base64(QObject *parent)
    : QObject{parent}
{}

QByteArray Base64::encode(QByteArray data)
{
    return encode(data.data(), data.size());
}

QByteArray Base64::encode(const char *data, int length)
{
    // 创建bio对象
    // 用于编码base64的BIO对象
    BIO* b64 = BIO_new(BIO_f_base64());
    // 用于连接内存的BIO对象
    BIO* mem = BIO_new(BIO_s_mem());
    // 组织bio链接 b64->mem
    BIO_push(b64,mem);
    // 数据编码
    // 将数据载入b64进行编码操作->处理完的数据会进入下一个bio节点
    BIO_write(b64,data,length);
    BIO_flush(b64);
    // 把编码后的数据取出
    BUF_MEM* ptr;
    BIO_get_mem_ptr(b64,&ptr);
    QByteArray str(ptr->data,ptr->length);

    // 释放BIO链的所有节点
    BIO_free_all(b64);

    return str;
}

QByteArray Base64::decode(QByteArray data)
{
    return decode(data.data(), data.size());
}

QByteArray Base64::decode(const char *data, int length)
{
    // 创建bio对象
    // 用于编码base64的BIO对象
    BIO* b64 = BIO_new(BIO_f_base64());
    // 用于连接内存的BIO对象
    BIO* mem = BIO_new(BIO_s_mem());
    // 组织bio链接 b64->mem
    BIO_push(b64,mem);
    // 将数据写入到mem节点
    BIO_write(mem,data,length);

    // 解码
    char* buf = new char[length];
    int ret = BIO_read(b64,buf,length);
    QByteArray out(buf,ret);

    // 释放BIO链的所有节点
    BIO_free_all(b64);
    delete[] buf;

    return out;
}
