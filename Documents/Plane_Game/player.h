#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "bullet.h"

class Player: public QGraphicsRectItem
{
public:
    Player();
    virtual void keyPressEvent(QKeyEvent* event);

    void initBullet();
    //accessor:
    int getEnergy() const;


    //mutator:
    void loseEnergy(int energy);


private:
    //Bullet* m_bullet;
    int m_energy;
};

#endif // PLAYER_H
