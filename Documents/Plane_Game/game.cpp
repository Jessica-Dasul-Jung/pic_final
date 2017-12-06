#include "game.h"
#include "player.h"
#include "enemyairplane.h"
#include "globals.h"
#include <QDebug>
#include <QLabel>

Game::Game(QGraphicsScene* scene, QWidget* parent)
{
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WIN_WIDTH,WIN_HEIGHT);//supplementary

    m_gamecount = 0;
    m_level = 0;
    m_scene = scene;
    setScene(m_scene);


    m_player = new Player();
    m_player->setRect(0, 0, 100, 100);
    m_player->setPos(WIN_WIDTH/2 - 50, WIN_HEIGHT - m_player->rect().height());

    m_scene->addItem(m_player);
    m_player->setFlag(QGraphicsItem::ItemIsFocusable);
    m_player->setFocus();

    //BUTTON IMPLEMENTATION:
    /*
    m_playbtn = new QPushButton ("PLAY", this);
    m_pausebtn = new QPushButton ("PAUSE", this);
    m_pausebtn->setCheckable (true);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_playbtn);
    layout->addWidget(m_pausebtn);

    connect (m_playbtn, SIGNAL(clicked()), this, clickPlay());
    connect (m_pausebtn, SIGNAL(clicked()), this, clickPause());
    */

    m_timer = new QTimer();
    QObject::connect (m_timer, SIGNAL(timeout()), this, SLOT(produceEnemy()));
    m_timer->start(LV1_INTERVAL);

}

void Game::EnemyArrives(int energy)
{
    qDebug() << "cannot even call";

    if (m_player == nullptr)
    {
        qDebug() << "why?";
        return;

    }
    qDebug() << "after if";
    m_player->loseEnergy(energy); //stuff here
}

void Game::gameover()
{
    QGraphicsTextItem* over_label = new QGraphicsTextItem();
    over_label->setPlainText(QString("OVER"));
    m_scene->addItem(over_label);
}

void Game::clickPlay()
{
    //m_timer->start(LV1_INTERVAL);
}

void Game::clickPause()
{
    //m_timer->stop();
}

void Game::produceEnemy()
{
    qDebug() << "produce Enemy";
    for (int i = 0; i < ENEMY_NUM; i++)
    {
        qDebug() << "enemy produced";
        EnemyAirplane* enemy = new EnemyAirplane(i + 1, this);
        m_scene->addItem(enemy);
    }
}
