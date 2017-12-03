//#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include "globals.h"
#include "player.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();


    QGraphicsScene* scene = new  QGraphicsScene();
    Player* rect = new Player();
    rect->setRect(0, 0, 100, 100);
    scene->addItem(rect);

    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();


    QGraphicsView* view = new QGraphicsView(scene);
    view->show();

    return a.exec();
}
