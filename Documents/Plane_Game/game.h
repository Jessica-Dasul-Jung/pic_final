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
    //QWidget* m_widget;

};

#endif // GAME_H
