#ifndef GLOBALS_H
#define GLOBALS_H

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>
//#include <QtGlobal>
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <QList>
#include <QHBoxLayout>
#include <QGraphicsTextItem>

static const int ENEMY1 = 1;
static const int ENEMY2 = 2;
static const int ENEMY3 = 3;


static const int ENEMY1_NRG = 200;
static const int ENEMY2_NRG = 300;
static const int ENEMY3_NRG = 400;
static const int BOSS_NRG = 1000;


static const int ENEMY1_SCORE = 10;
static const int ENEMY2_SCORE = 10;
static const int ENEMY3_SCORE = 10;


//random number generator for int:
static int getRandomNum(int start, int end)
{
    int num = qrand()% ((end + 1) - start) + start;
    return num;
}

static const int WIN_WIDTH = 800;
static const int WIN_HEIGHT = 600;
static const int ENEMY_NUM = 3;

static const int LV1_INTERVAL = 4000;
static const int BULLET_ENERGY = 50;
static const int PLAYER_INITIAL_ENERGY = 1000;


static const int SIDE_WIDTH = 780;
static const int SIDE_HEIGHT = 100;

#endif // GLOBALS_H
