#ifndef ENEMYAIRPLANE_H
#define ENEMYAIRPLANE_H

#include "globals.h"

class Game;
class EnemyAirplane: public QGraphicsRectItem, public QObject
{
public:
    Q_OBJECT
    EnemyAirplane();
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
