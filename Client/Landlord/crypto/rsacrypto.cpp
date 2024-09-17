#include "base64.h"
#include "rsacrypto.h"
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <QDebug>

RsaCrypto::RsaCrypto(QObject *parent)
    : QObject{parent}
{}

RsaCrypto::RsaCrypto(QByteArray fileName, keyType type, QObject *parent) : QObject{parent}
{
    BIO* bio = BIO_new_file(fileName.data(),"rb");
    assert(bio != NULL);
    if(type == PublicKey)
    {
        PEM_read_bio_PUBKEY(bio,&m_pubKey,NULL,NULL);
    }
    else
    {

        PEM_read_bio_PrivateKey(bio,&m_priKey,NULL,NULL);
    }
    BIO_free(bio);
}

RsaCrypto::~RsaCrypto()
{
    if(m_pubKey)
    {
        EVP_PKEY_free(m_pubKey);
    }
    if(m_priKey)
    {
        EVP_PKEY_free(m_priKey);
    }
}

void RsaCrypto::parseStringToKey(QByteArray data, keyType type)
{
    BIO* bio = BIO_new_mem_buf(data.data(),data.size());
    assert(bio != NULL);
    if(type == PublicKey)
    {
        PEM_read_bio_PUBKEY(bio,&m_pubKey,NULL,NULL);
    }
    else
    {

        PEM_read_bio_PrivateKey(bio,&m_priKey,NULL,NULL);
    }
    BIO_free(bio);
}

void RsaCrypto::generateRsaKey(KeyLength bits, QByteArray pub, QByteArray pri)
{
    // 创建密钥对上下文
    EVP_PKEY_CTX * ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, nullptr);
    // 初始化
    int ret = EVP_PKEY_keygen_init(ctx);
    assert(ret == 1);
    // 指定密钥对长度
    ret = EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, bits);
    assert(ret == 1);
    // 生成密钥对 -->密钥对和单个秘钥的存储结构体是一样的，这里就用私钥代替
    // 另一个点：私钥是包含公钥的，公钥只有公钥
    ret = EVP_PKEY_generate(ctx, &m_priKey);
    assert(ret == 1);
    // 释放上下文ctx
    EVP_PKEY_CTX_free(ctx);

    // 将私钥写入到磁盘文件
    BIO* bio = BIO_new_file(pri.data(),"wb");
    // 设为空的参数都是和获取密钥加密有关的，暂时不用
    ret = PEM_write_bio_PrivateKey(bio,m_priKey,nullptr,nullptr,0,nullptr,nullptr);
    assert(ret == 1);
    // 将数据刷到磁盘
    BIO_flush(bio);
    BIO_free(bio);

    // 将公钥写入到磁盘文件
    bio = BIO_new_file(pub.data(),"wb");
    // 设为空的参数都是和获取密钥加密有关的，暂时不用
    ret = PEM_write_bio_PUBKEY(bio,m_priKey);
    assert(ret == 1);
    // 将数据刷到磁盘
    BIO_flush(bio);
    BIO_free(bio);
}

QByteArray RsaCrypto::pubKeyEncrypt(QByteArray data)
{
    // 创建上下文
    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(m_pubKey, NULL);
    assert(ctx != NULL);
    // 设置加密和填充模式
    int ret = EVP_PKEY_encrypt_init(ctx);
    assert(ret == 1);
    ret = EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING);
    assert(ret == 1);
    // 使用公钥对数据进行加密
    size_t outlen = 0;
    // 这里进行两次加密的原因：不知道加密后密文的长度（明文长度+哈希混淆填充后的长度），利用加密函数计算返回加密后的长度
    // 再利用加密后的长度申请缓存空间，再进行加密
    ret = EVP_PKEY_encrypt(ctx, NULL, &outlen,
                           reinterpret_cast<unsigned char*> (data.data()), data.size());
    assert(ret == 1);
    unsigned char *out = new unsigned char[outlen];
    ret = EVP_PKEY_encrypt(ctx, out, &outlen,
                           reinterpret_cast<unsigned char*> (data.data()), data.size());
    assert(ret == 1);

    // 将二进制数据编码为base64，方便传输
    Base64 base;
    QByteArray retStr = base.encode(reinterpret_cast<char*>(out),outlen);
    // 释放资源
    delete[] out;
    EVP_PKEY_CTX_free(ctx);
    return retStr;
}

QByteArray RsaCrypto::priKeyDecrypt(QByteArray data)
{
    // 创建上下文
    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(m_priKey, NULL);
    assert(ctx != NULL);
    // 设置解密和还原填充模式
    int ret = EVP_PKEY_decrypt_init(ctx);
    assert(ret == 1);
    ret = EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING);
    assert(ret == 1);

    // 对base64数据解码，->二进制
    Base64 base;
    data = base.decode(data);

    // 使用私钥对数据进行解密
    size_t outlen = 0;
    ret = EVP_PKEY_decrypt(ctx, NULL, &outlen,
                           reinterpret_cast<unsigned char*> (data.data()), data.size());
    assert(ret == 1);
    unsigned char *out = new unsigned char[outlen];
    ret = EVP_PKEY_decrypt(ctx, out, &outlen,
                           reinterpret_cast<unsigned char*> (data.data()), data.size());
    assert(ret == 1);
    // 转换
    QByteArray retStr(reinterpret_cast<char*>(out),outlen);
    // 释放资源
    delete[] out;
    EVP_PKEY_CTX_free(ctx);
    return retStr;
}

QByteArray RsaCrypto::sign(QByteArray data, QCryptographicHash::Algorithm hash)
{
    // 计算哈希值
    QCryptographicHash h(hash);
    h.addData(data);
    QByteArray md = h.result();


    // 创建上下文
    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(m_priKey, NULL);
    assert(ctx != NULL);
    // 设置加密和填充模式
    int ret = EVP_PKEY_sign_init(ctx);
    assert(ret == 1);
    // 这里设置签名的时候不能使用OAEP进行填充，会导致加密后的数据不可控
    ret = EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_PADDING);
    assert(ret == 1);

    // 设置签名使用的哈希算法
    ret = EVP_PKEY_CTX_set_signature_md(ctx, m_hashMethods.value(hash)());
    assert(ret == 1);

    // 私钥加密哈希计算过后的数据
    size_t outlen = 0;
    ret = EVP_PKEY_sign(ctx, NULL, &outlen,
                           reinterpret_cast<unsigned char*> (md.data()), md.size());
    assert(ret == 1);
    unsigned char *out = new unsigned char[outlen];
    ret = EVP_PKEY_sign(ctx, out, &outlen,
                           reinterpret_cast<unsigned char*> (md.data()), md.size());
    assert(ret == 1);
    // 转base64
    Base64 base;
    QByteArray retStr = base.encode(reinterpret_cast<char*>(out),outlen);
    // 释放资源
    delete[] out;
    EVP_PKEY_CTX_free(ctx);
    return retStr;
}

bool RsaCrypto::verify(QByteArray sign, QByteArray data, QCryptographicHash::Algorithm hash)
{
    // 解码
    Base64 base;
    sign = base.decode(sign);
    // 计算哈希值
    QCryptographicHash h(hash);
    h.addData(data);
    QByteArray md = h.result();

    // 创建上下文
    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(m_pubKey, NULL);
    assert(ctx != NULL);
    // 设置解密和还原填充模式
    int ret = EVP_PKEY_verify_init(ctx);
    assert(ret == 1);
    // 非OAEP
    ret = EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_PADDING);
    assert(ret == 1);

    // 设置校验签名使用的哈希算法
    ret = EVP_PKEY_CTX_set_signature_md(ctx, m_hashMethods.value(hash)());
    assert(ret == 1);

    // 签名校验
    ret = EVP_PKEY_verify(ctx,
                        reinterpret_cast<unsigned char*>(sign.data()), sign.size(),
                        reinterpret_cast<unsigned char*>(md.data()), md.size());
    EVP_PKEY_CTX_free(ctx);
    if(ret == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
