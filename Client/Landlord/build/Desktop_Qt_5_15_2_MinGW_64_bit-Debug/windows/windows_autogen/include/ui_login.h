/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QCheckBox *savePwd;
    QLabel *label_2;
    QLineEdit *passaword;
    QLineEdit *userName;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *loginBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *regUser;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_6;
    QGridLayout *gridLayout_2;
    QLineEdit *regUserName;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *regPassword;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *registerBtn;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *phone;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_4;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_10;
    QWidget *widget_9;
    QGridLayout *gridLayout_3;
    QLineEdit *port;
    QLabel *label_6;
    QLineEdit *ipAddr;
    QLabel *label_5;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *netOkBtn;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer_6;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *homeBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *netSetBtn;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(510, 349);
        verticalLayout_2 = new QVBoxLayout(Login);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stackedWidget = new QStackedWidget(Login);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        widget_3 = new QWidget(page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        widget = new QWidget(widget_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        savePwd = new QCheckBox(widget);
        savePwd->setObjectName(QString::fromUtf8("savePwd"));

        gridLayout->addWidget(savePwd, 2, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        passaword = new QLineEdit(widget);
        passaword->setObjectName(QString::fromUtf8("passaword"));

        gridLayout->addWidget(passaword, 1, 1, 1, 1);

        userName = new QLineEdit(widget);
        userName->setObjectName(QString::fromUtf8("userName"));

        gridLayout->addWidget(userName, 0, 1, 1, 1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        loginBtn = new QPushButton(widget_2);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));

        horizontalLayout->addWidget(loginBtn);

        horizontalSpacer_2 = new QSpacerItem(67, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget_2, 3, 0, 1, 2);

        regUser = new QPushButton(widget);
        regUser->setObjectName(QString::fromUtf8("regUser"));

        gridLayout->addWidget(regUser, 2, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(widget);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        widget_5 = new QWidget(page_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(76, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_2 = new QGridLayout(widget_6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        regUserName = new QLineEdit(widget_6);
        regUserName->setObjectName(QString::fromUtf8("regUserName"));

        gridLayout_2->addWidget(regUserName, 0, 1, 1, 1);

        label_7 = new QLabel(widget_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        regPassword = new QLineEdit(widget_6);
        regPassword->setObjectName(QString::fromUtf8("regPassword"));

        gridLayout_2->addWidget(regPassword, 1, 1, 1, 1);

        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        registerBtn = new QPushButton(widget_7);
        registerBtn->setObjectName(QString::fromUtf8("registerBtn"));

        horizontalLayout_5->addWidget(registerBtn);

        horizontalSpacer_8 = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        gridLayout_2->addWidget(widget_7, 3, 0, 1, 2);

        phone = new QLineEdit(widget_6);
        phone->setObjectName(QString::fromUtf8("phone"));

        gridLayout_2->addWidget(phone, 2, 1, 1, 1);


        horizontalLayout_4->addWidget(widget_6);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        verticalLayout_3->addWidget(widget_5);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_4 = new QVBoxLayout(page_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_5 = new QSpacerItem(20, 54, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        widget_8 = new QWidget(page_3);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_6 = new QHBoxLayout(widget_8);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_10 = new QSpacerItem(76, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);

        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        gridLayout_3 = new QGridLayout(widget_9);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        port = new QLineEdit(widget_9);
        port->setObjectName(QString::fromUtf8("port"));

        gridLayout_3->addWidget(port, 1, 1, 1, 1);

        label_6 = new QLabel(widget_9);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        ipAddr = new QLineEdit(widget_9);
        ipAddr->setObjectName(QString::fromUtf8("ipAddr"));

        gridLayout_3->addWidget(ipAddr, 0, 1, 1, 1);

        label_5 = new QLabel(widget_9);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        widget_10 = new QWidget(widget_9);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_7 = new QHBoxLayout(widget_10);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_11 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);

        netOkBtn = new QPushButton(widget_10);
        netOkBtn->setObjectName(QString::fromUtf8("netOkBtn"));

        horizontalLayout_7->addWidget(netOkBtn);

        horizontalSpacer_12 = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);


        gridLayout_3->addWidget(widget_10, 2, 0, 1, 2);


        horizontalLayout_6->addWidget(widget_9);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);


        verticalLayout_4->addWidget(widget_8);

        verticalSpacer_6 = new QSpacerItem(20, 53, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);

        stackedWidget->addWidget(page_3);

        verticalLayout_2->addWidget(stackedWidget);

        widget_4 = new QWidget(Login);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        homeBtn = new QPushButton(widget_4);
        homeBtn->setObjectName(QString::fromUtf8("homeBtn"));

        horizontalLayout_3->addWidget(homeBtn);

        horizontalSpacer_5 = new QSpacerItem(273, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        netSetBtn = new QPushButton(widget_4);
        netSetBtn->setObjectName(QString::fromUtf8("netSetBtn"));

        horizontalLayout_3->addWidget(netSetBtn);


        verticalLayout_2->addWidget(widget_4);


        retranslateUi(Login);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        savePwd->setText(QCoreApplication::translate("Login", "\344\277\235\345\255\230\345\257\206\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201:", nullptr));
        loginBtn->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        regUser->setText(QCoreApplication::translate("Login", "\351\251\254\344\270\212\346\263\250\345\206\214", nullptr));
        label->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("Login", "\346\211\213\346\234\272\345\217\267:", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201:", nullptr));
        label_4->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        registerBtn->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        label_6->setText(QCoreApplication::translate("Login", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("Login", "\347\253\257\345\217\243\345\217\267:", nullptr));
        netOkBtn->setText(QCoreApplication::translate("Login", "\347\241\256\345\256\232", nullptr));
        homeBtn->setText(QCoreApplication::translate("Login", "\344\270\273\351\241\265", nullptr));
        netSetBtn->setText(QCoreApplication::translate("Login", "\347\275\221\347\273\234\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
