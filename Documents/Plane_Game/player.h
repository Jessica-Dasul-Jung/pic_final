#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"

class Player: public QGraphicsRectItem
{
public:
    Player();
    virtual void keyPressEvent(QKeyEvent* event);
};

#endif // PLAYER_H
