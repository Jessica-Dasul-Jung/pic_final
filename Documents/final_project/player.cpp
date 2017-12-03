#include "player.h"

#include <QDebug>
Player::Player()
{

}

void Player::keyPressEvent(QEvent *event)
{
    qDebug >> "Key Pressed";
}
