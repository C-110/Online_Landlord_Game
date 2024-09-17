//
// Created by yyds on 2024/9/5.
//

#ifndef SERVER_RSACRYPTO_H
#define SERVER_RSACRYPTO_H


#include <string>
#include <map>
#include <openssl/evp.h>
#include "Hash.h"

using namespace std;

class RsaCrypto
{
public:
    enum KeyLength{
        BITS_1K = 1024,
        BITS_2K = 2048,
        BITS_3K = 3072,
        BITS_4K = 4096,
    };
    enum keyType{PublicKey, PrivateKey};
    using hashFunc = const EVP_MD*(*)(void);
    explicit RsaCrypto() = default;
    // 构造对象并加载密钥文件中的数据到内存中
    explicit RsaCrypto(string fileName, keyType type);
    ~RsaCrypto();

    // 将密钥字符串解析为秘钥类型
    void parseStringToKey(string data, keyType type);

    // 生成密钥对
    void generateRsaKey(KeyLength bits, string pub = "public.pem", string pri = "private.pem");
    // 通过公钥进行加密
    string pubKeyEncrypt(string data);
    // 通过私钥进行解密
    string priKeyDecrypt(string data);
    // 数据签名
    string sign(string data, HashType hash = HashType::Sha256);
    // 签名校验
    bool verify(string sign, string data, HashType hash = HashType::Sha256);

private:
    EVP_PKEY *m_pubKey = NULL;
    EVP_PKEY *m_priKey = NULL;

};


#endif //SERVER_RSACRYPTO_H
