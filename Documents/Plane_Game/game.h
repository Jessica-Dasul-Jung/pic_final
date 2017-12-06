#ifndef GAME_H
#define GAME_H
#include "globals.h"
#include <QGraphicsScene>

class Player;
class EnemyAirplane;
class Game: public QGraphicsScene //or sth else?
{
public:
    Game();
    Q_OBJECT

public slots:
    void produceEnemy();

private:
    int m_gamecount;
    int m_level;
    Player* m_player;
//    EnemyAirplane* m_enemy[ENEMY_NUM];
    QTimer* m_timer;
};

#endif // GAME_H
