/********************************************************************************
** Form generated from reading UI file 'gamemode.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMODE_H
#define UI_GAMEMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameMode
{
public:
    QVBoxLayout *verticalLayout_8;
    QStackedWidget *stackedWidget;
    QWidget *mode_page;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *single_label;
    QPushButton *singleModeBtn;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *net_label;
    QPushButton *netModeBtn;
    QSpacerItem *horizontalSpacer_4;
    QWidget *roo_page;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QLabel *auto_label;
    QPushButton *autoBtn;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_7;
    QLabel *manual_label;
    QPushButton *manualBtn;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_9;
    QLabel *search_label;
    QPushButton *searchBtn;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *GameMode)
    {
        if (GameMode->objectName().isEmpty())
            GameMode->setObjectName(QString::fromUtf8("GameMode"));
        GameMode->resize(520, 387);
        verticalLayout_8 = new QVBoxLayout(GameMode);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        stackedWidget = new QStackedWidget(GameMode);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        mode_page = new QWidget();
        mode_page->setObjectName(QString::fromUtf8("mode_page"));
        horizontalLayout = new QHBoxLayout(mode_page);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        widget = new QWidget(mode_page);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        single_label = new QLabel(widget);
        single_label->setObjectName(QString::fromUtf8("single_label"));

        verticalLayout->addWidget(single_label);

        singleModeBtn = new QPushButton(widget);
        singleModeBtn->setObjectName(QString::fromUtf8("singleModeBtn"));

        verticalLayout->addWidget(singleModeBtn);


        horizontalLayout->addWidget(widget);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        widget_2 = new QWidget(mode_page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        net_label = new QLabel(widget_2);
        net_label->setObjectName(QString::fromUtf8("net_label"));

        verticalLayout_2->addWidget(net_label);

        netModeBtn = new QPushButton(widget_2);
        netModeBtn->setObjectName(QString::fromUtf8("netModeBtn"));

        verticalLayout_2->addWidget(netModeBtn);


        horizontalLayout->addWidget(widget_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        stackedWidget->addWidget(mode_page);
        roo_page = new QWidget();
        roo_page->setObjectName(QString::fromUtf8("roo_page"));
        horizontalLayout_2 = new QHBoxLayout(roo_page);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget_3 = new QWidget(roo_page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 136, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer);

        auto_label = new QLabel(widget_3);
        auto_label->setObjectName(QString::fromUtf8("auto_label"));

        verticalLayout_3->addWidget(auto_label);

        autoBtn = new QPushButton(widget_3);
        autoBtn->setObjectName(QString::fromUtf8("autoBtn"));

        verticalLayout_3->addWidget(autoBtn);

        verticalSpacer_2 = new QSpacerItem(20, 135, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_2->addWidget(widget_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        widget_4 = new QWidget(roo_page);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(verticalSpacer_7);

        manual_label = new QLabel(widget_4);
        manual_label->setObjectName(QString::fromUtf8("manual_label"));

        verticalLayout_6->addWidget(manual_label);

        manualBtn = new QPushButton(widget_4);
        manualBtn->setObjectName(QString::fromUtf8("manualBtn"));

        verticalLayout_6->addWidget(manualBtn);

        verticalSpacer_8 = new QSpacerItem(20, 135, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(verticalSpacer_8);


        horizontalLayout_2->addWidget(widget_4);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        widget_5 = new QWidget(roo_page);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_7 = new QVBoxLayout(widget_5);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(verticalSpacer_9);

        search_label = new QLabel(widget_5);
        search_label->setObjectName(QString::fromUtf8("search_label"));

        verticalLayout_7->addWidget(search_label);

        searchBtn = new QPushButton(widget_5);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));

        verticalLayout_7->addWidget(searchBtn);

        verticalSpacer_10 = new QSpacerItem(20, 135, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(verticalSpacer_10);


        horizontalLayout_2->addWidget(widget_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(roo_page);

        verticalLayout_8->addWidget(stackedWidget);


        retranslateUi(GameMode);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(GameMode);
    } // setupUi

    void retranslateUi(QDialog *GameMode)
    {
        GameMode->setWindowTitle(QCoreApplication::translate("GameMode", "Dialog", nullptr));
        single_label->setText(QCoreApplication::translate("GameMode", "TextLabel", nullptr));
        singleModeBtn->setText(QCoreApplication::translate("GameMode", "\345\215\225\346\234\272\346\250\241\345\274\217", nullptr));
        net_label->setText(QCoreApplication::translate("GameMode", "TextLabel", nullptr));
        netModeBtn->setText(QCoreApplication::translate("GameMode", "\347\275\221\347\273\234\346\250\241\345\274\217", nullptr));
        auto_label->setText(QCoreApplication::translate("GameMode", "TextLabel", nullptr));
        autoBtn->setText(QCoreApplication::translate("GameMode", "PushButton", nullptr));
        manual_label->setText(QCoreApplication::translate("GameMode", "TextLabel", nullptr));
        manualBtn->setText(QCoreApplication::translate("GameMode", "PushButton", nullptr));
        search_label->setText(QCoreApplication::translate("GameMode", "TextLabel", nullptr));
        searchBtn->setText(QCoreApplication::translate("GameMode", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameMode: public Ui_GameMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMODE_H
