#include <QApplication>
#include <QGraphicsView>

#include "globals.h"
#include "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene* scene = new QGraphicsScene();
    Player* player = new Player();
    player->setRect(0, 0, 100, 100);

    scene->addItem(player);

    //player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFlag(QGraphicsItem::ItemIsMovable);
    player->setFocus();




    QGraphicsView* view = new QGraphicsView (scene);
    view->show();

    //MainWindow w;
    //w.show();

    return a.exec();
}
