#include "bullet.h"
#include <QDebug>
#include "enemyairplane.h"
Bullet::Bullet()
{
    this->setRect(0, 0, 10, 50);
    m_timer = new QTimer();
    connect (m_timer, SIGNAL(timeout()), this, SLOT(move()));
    m_timer->start(50);
}

Bullet::~Bullet()
{
    delete m_timer;
}

void Bullet::move()
{
    QList <QGraphicsItem *> shotPlane = collidingItems();
    int num = shotPlane.size();
    for (int k = 0; k < num; k++)
    {
        if (typeid(*shotPlane[k]) == typeid(EnemyAirplane))
        {
            EnemyAirplane* ptr = dynamic_cast<EnemyAirplane*> (shotPlane[k]);
            ptr->loseEnergy(BULLET_ENERGY);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    this->setPos(x(), y() - 10);
    if (this->pos().y() + rect().height() < 0)
    {
       scene()->removeItem(this);
       delete this;
    }
}
