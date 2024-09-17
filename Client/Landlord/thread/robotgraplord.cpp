#include "robotgraplord.h"
#include <QThread>

RobotGrapLord::RobotGrapLord(Player* player, QObject *parent) :QObject(parent), QRunnable()
{
    m_player = player;
    setAutoDelete(true);    // 任务对象this在线程池的线程中执行结束时自动销毁
}

void RobotGrapLord::run()
{
    QThread::msleep(2000);
    m_player->thinkCallLord();
}
