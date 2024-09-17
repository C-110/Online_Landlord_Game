#include "gamemode.h"
#include "ui_gamemode.h"
#include "gamepanel.h"
#include "codec.h"
#include "datamanager.h"
#include "joinroom.h"

#include <QCloseEvent>


GameMode::GameMode(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameMode)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    // 单机模式
    connect(ui->singleModeBtn,&QPushButton::clicked,this,[=](){
        GamePanel* panel = new GamePanel();
        connect(panel,&GamePanel::panelClose,this,&GameMode::show);
        panel->show();
        hide();
    });

    connect(ui->netModeBtn,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    // 自动加入某个房间
    connect(ui->autoBtn,&QPushButton::clicked,this,[=](){
        Message msg;
        msg.userName = DataManager::getInstance()->getUserName();
        msg.reqcode = RequestCode::AutoRoom;
        DataManager::getInstance()->getCommunication()->sendMessage(&msg);
    });

    connect(ui->manualBtn,&QPushButton::clicked,this,[=](){
        JoinRoom room(DialogType::Manual);
        room.setWindowTitle("创建房间");
        room.exec();
    });

    connect(ui->searchBtn,&QPushButton::clicked,this,[=](){
        JoinRoom room(DialogType::Search);
        room.setWindowTitle("搜索房间");
        room.exec();
    });
}

GameMode::~GameMode()
{
    delete ui;
}

void GameMode::closeEvent(QCloseEvent *ev)
{
    if(ui->stackedWidget->currentIndex() == 1)
    {
        ui->stackedWidget->setCurrentIndex(0);
        ev->ignore();
    }
    else
    {
        ev->accept();
    }
}
