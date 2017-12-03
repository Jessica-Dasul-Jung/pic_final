#include "player.h"
#include <QDebug>
Player::Player()
{

}

void Player::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "This is pressed";

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
    default: break;
        //does not do anything

    }

}
