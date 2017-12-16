#ifndef GAME_H
#define GAME_H
#include "globals.h"
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsView>
#include <QWidget>

class Player;
class EnemyAirplane;
class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QGraphicsScene* scene, QWidget* parent = Q_NULLPTR);
    void EnemyArrives(int energy);
    void gameover();
    void increaseScore(int type); //+10 when it kills enemy1, +20 for enemy2, +30 for enemy3
    void initEnemy();
    void initTexts();

public slots:
    void produceEnemy();

private:
    QGraphicsScene* m_scene;
    int m_gamecount;
    int m_level;
    Player* m_player;
    QTimer* m_timer;
    QGraphicsTextItem* m_overtxt;
    QGraphicsTextItem* m_scorelabeltxt;
    QGraphicsTextItem* m_scoretxt;
    QGraphicsTextItem* m_killtxt;
    QGraphicsTextItem* m_killnumtxt;
    QGraphicsTextItem* m_statustxt;
    QGraphicsTextItem* m_energytxt;
    int m_score;
    int m_kill;
    QGraphicsRectItem* m_stats;
    QGraphicsPixmapItem* m_background;

};

#endif // GAME_H
