//#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsView>

#include "game.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, WIN_WIDTH, WIN_HEIGHT);

    Game* game = new Game(scene);
    game->show();
    return a.exec();
}
