#ifndef ROBOTGRAPLORD_H
#define ROBOTGRAPLORD_H

#include <QRunnable>
#include "player.h"

// 继承QObject类才能使用信号与槽函数
class RobotGrapLord : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit RobotGrapLord(Player* player, QObject *parent = nullptr);

protected:
    void run() override;

signals:
private:
    Player* m_player;

};

#endif // ROBOTGRAPLORD_H
