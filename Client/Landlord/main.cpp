#include "login.h"
#include "cards.h"
#include <QApplication>
#include <QResource>
#include "aescrypto.h"
#include "rsacrypto.h"
#include "QDebug"

void test()
{
    AesCrypto aes(AesCrypto::AES_CBC_128,"1234567812345678");
    QByteArray text = aes.enctypt("这里所使用的数字N和加密时使用的数字N是相同的。数D和数N组合起来就是RSA的解密密钥，因此D和N的组合就是私钥。只有知道D和N两个数的人才能够完成解密的运算。");
    text = aes.dectypt(text);
    qDebug()<<text.data();

    // 获取密钥对并刷到磁盘
    RsaCrypto rsa;
    rsa.generateRsaKey(RsaCrypto::BITS_2K);

    RsaCrypto rsa1("public.pem",RsaCrypto::PublicKey);
    // 可加密的最大数据长度 = (bits/8)-11;
    QByteArray temp = "坚持努力，终会胜利！";
    temp = rsa1.pubKeyEncrypt(temp);
    qDebug()<<"公钥加密后的密文："<<temp;
    RsaCrypto rsa2("private.pem",RsaCrypto::PrivateKey);
    temp = rsa2.priKeyDecrypt(temp);
    qDebug()<<temp.data();

    temp = rsa2.sign(text);
    qDebug()<<"私钥签名的密文："<<temp;
    bool flag = rsa1.verify(temp,text);
    qDebug()<<"flag = "<<flag;
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qRegisterMetaType<Cards>("Cards&");
    qRegisterMetaType<Cards>("Cards");
    //QResource::registerResource("./resource .rcc");
    Login w;
    int ret = w.exec();
    if(ret == QDialog::Accepted)
    {
        test();
        return a.exec();
    }
}
