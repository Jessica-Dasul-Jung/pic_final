#include "game.h"
#include "player.h"
#include "enemyairplane.h"
#include "globals.h"
#include <QDebug>
#include <QLabel>

Game::Game(QGraphicsScene* scene, QWidget* parent)
{
    //setting game property:
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WIN_WIDTH,WIN_HEIGHT);//supplementary

    m_gamecount = 0;
    m_level = 0;
    m_score = 0;
    m_scene = scene;
    setScene(m_scene);

    //initializing player:
    m_player = new Player();
    m_player->setRect(0, 0, 100, 100);
    m_player->setPos(WIN_WIDTH/2 - 50, WIN_HEIGHT - m_player->rect().height());
    m_scene->addItem(m_player);
    m_player->setFlag(QGraphicsItem::ItemIsFocusable);
    m_player->setFocus();


    //producing enemy implementation:
    m_timer = new QTimer();
    QObject::connect (m_timer, SIGNAL(timeout()), this, SLOT(produceEnemy()));
    m_timer->start(LV1_INTERVAL);

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

    //game over text
    m_overtxt = new QGraphicsTextItem();
    m_overtxt->setPlainText(QString("GAMEOVER"));

    //score text:
    m_scoretxt = new QGraphicsTextItem();
    m_scorelabeltxt = new QGraphicsTextItem();

    m_scorelabeltxt->setPlainText(QString::fromStdString("Score: "));
    m_scoretxt->setPlainText(QString::number(m_score));

    m_scorelabeltxt->setPos(10, WIN_HEIGHT - 50);
    m_scoretxt->setPos(20, WIN_HEIGHT - 50);
    m_scene->addItem(m_scorelabeltxt);
    m_scene->addItem(m_scoretxt);

    //Statistics implementation:
    m_stats = new QGraphicsRectItem();
    m_stats->setRect(0, 0, SIDE_WIDTH, SIDE_HEIGHT);
    m_stats->setPos(10, WIN_HEIGHT - 10);
    m_scene->addItem(m_stats);




}

void Game::EnemyArrives(int energy)
{
    qDebug() << "cannot even call";
    m_player->loseEnergy(energy); //stuff here
    if (m_player->getEnergy() <= 0)
        gameover();
}

void Game::gameover()
{
    m_scene->addItem(m_overtxt);
}

void Game::increaseScore(int type)
{
    int score = 0;
    switch (type)
    {
    case 1: score = 10;
        break;
    case 2: score = 20;
        break;
    case 3: score = 30;
        break;
    default: break;
    }
    m_score += score;
    m_scoretxt->setPlainText(QString::number(m_score));

    if (m_score >= 500)
    {
        qDebug() << "Level up";
    }
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
