#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"

class Player: public QGraphicsPixmapItem
{
public:
    Player();
    virtual void keyPressEvent(QKeyEvent* event);

    //accessor:
    int getEnergy() const;
    double getWidth() const;
    double getHeight() const;



    //mutator:
    void loseEnergy(int energy);


private:
    //Bullet* m_bullet;
    int m_energy;
    QPixmap* m_image;
};

#endif // PLAYER_H
