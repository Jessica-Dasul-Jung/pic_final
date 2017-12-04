#include "bullet.h"

Bullet::Bullet()
{
    this->setRect(0, 0, 10, 50);
    m_timer = new QTimer();
    connect (m_timer, SIGNAL(timeout()), this, SLOT(move()));
    m_timer->start(50);
}

void Bullet::move()
{
    this->setPos(x(), y() - 10);
    if (this->pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
