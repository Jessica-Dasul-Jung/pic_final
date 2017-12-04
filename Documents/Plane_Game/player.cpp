#include "player.h"
#include <QDebug>


Player::Player()
{
    //m_bullet = new Bullet();
}

void Player::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "This is pressed";
    Bullet* bullet = new Bullet();

    switch(event->key())
    {
    case Qt::Key_Right:
        setPos(x()+10, y());
        break;
    case Qt::Key_Left:
        setPos(x()-10, y());
        break;
    case Qt::Key_Up:
        setPos(x(), y() - 10); //anchor (0,0) is top left corner
        break;
    case Qt::Key_Down:
        setPos(x(), y() + 10);
        break;
    case Qt::Key_Space:
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
        return;
    default: break;
        //does not do anything

    }
    delete bullet;


}

void Player::initBullet()
{

}

