#include "player.h"
#include <QDebug>
#include "bullet.h"

Player::Player()
{
    m_energy = PLAYER_INITIAL_ENERGY;

    m_image = new QPixmap(":/picture/tank1.png");
    m_image->scaled(0.5, 0.5, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    this->setPixmap(*m_image);

    //m_player->setRect(0, 0, 100, 100);
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

        bullet->setPos (x() + 50 - bullet->rect().width()/2, y());
        //bullet->setPos(x() + rect().width()/2 - bullet->rect().width()/2, y());
        scene()->addItem(bullet);
    }
}

int Player::getEnergy() const
{
    return m_energy;
}

double Player::getWidth() const
{
    double width = boundingRect().width();
    return width;

}

double Player::getHeight() const
{
    double height = boundingRect().height();
    return height;
}

void Player::loseEnergy(int energy)
{
    m_energy -= energy;
}



