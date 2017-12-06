#ifndef ENEMYAIRPLANE_H
#define ENEMYAIRPLANE_H

#include "globals.h"

class Game;
class EnemyAirplane: public QObject, public QGraphicsRectItem
{
        Q_OBJECT
public:
    EnemyAirplane(int type);
    virtual ~EnemyAirplane();

    //accessor:
    int getEnergy();
    //mutator:
    void loseEnergy(int energy); //dead if energy < 0
    void setBossLevel();


public slots:
    void move();

private:
    int m_energy;
    int m_type;
    Game* m_game;
    QTimer* m_timer;
};

#endif // ENEMYAIRPLANE_H
