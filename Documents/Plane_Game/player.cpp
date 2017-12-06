#include "player.h"
#include <QDebug>
#include "bullet.h"

Player::Player()
{
    m_energy = PLAYER_INITIAL_ENERGY;

}

void Player::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Right)
    {
        setPos(x()+10, y());
    }
    else if (event->key() == Qt::Key_Left)
    {
        setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_Space)
    {
        Bullet* bullet = new Bullet();
        bullet->setPos(x() + rect().width()/2 - bullet->rect().width()/2, y());
        scene()->addItem(bullet);
    }

}

int Player::getEnergy() const
{
    return m_energy;
}

void Player::loseEnergy(int energy)
{
    m_energy -= energy;
}

