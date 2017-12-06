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

static const int ENEMY1 = 1;
static const int ENEMY2 = 2;
static const int ENEMY3 = 3;


static const int ENEMY1_NRG = 100;
static const int ENEMY2_NRG = 200;
static const int ENEMY3_NRG = 300;
static const int BOSS_NRG = 1000;

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


#endif // GLOBALS_H
