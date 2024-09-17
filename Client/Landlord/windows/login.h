#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLineEdit>
#include "codec.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    // 校验数据
    bool verifyData(QLineEdit *edit);
    // 连接服务器
    void startConnect(Message* msg);

    // 记住密码
    // 保存数据
    void saveUserInfo();
    // 加载数据
    void loadUserInfo();

public slots:
    void onLogin();
    void onRegister();
    void onNetOK();

private:
    Ui::Login *ui;
    bool m_isConnected = false;
    const QByteArray KEY = "保存密码用的加密密钥";
};

#endif // LOGIN_H
