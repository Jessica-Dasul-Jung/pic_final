#ifndef GAME_H
#define GAME_H
#include "globals.h"
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsView>
#include <QWidget>

class Player;
class EnemyAirplane;
class Game: public QGraphicsView //or sth else?
{
    Q_OBJECT
public:
    Game(QGraphicsScene* scene, QWidget* parent = Q_NULLPTR);
    void EnemyArrives(int energy);
    void gameover();
    void increaseScore(int type); //+10 when it kills enemy1, +20 for enemy2, +30 for enemy3

private slots:
    void clickPlay();
    void clickPause();
public slots:
    void produceEnemy();

private:
    QGraphicsScene* m_scene;
    int m_gamecount;
    int m_level;
    Player* m_player;
    QTimer* m_timer;

    QPushButton* m_exitbtn;
    QPushButton* m_replaybtn;
    QPushButton* m_playbtn;
    QPushButton* m_pausebtn;

    QGraphicsTextItem* m_overtxt;
    QGraphicsTextItem* m_scorelabeltxt;
    QGraphicsTextItem* m_scoretxt;
    int m_score;

    QGraphicsRectItem* m_stats;
    QGraphicsPixmapItem* m_background;

};

#endif // GAME_H
