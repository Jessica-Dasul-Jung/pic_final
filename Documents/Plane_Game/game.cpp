#include "game.h"
#include "player.h"
#include "enemyairplane.h"
#include <QDebug>

Game::Game()
{
    m_gamecount = 0;
    m_level = 0;

    m_player = new Player();
    m_player->setRect(0, 0, 100, 100);
    m_player->setPos(WIN_WIDTH/2 - 50, WIN_HEIGHT - m_player->rect().height());

    this->addItem(m_player);
    m_player->setFlag(QGraphicsItem::ItemIsFocusable);
    m_player->setFocus();

    m_timer = new QTimer();
    QObject::connect (m_timer, SIGNAL(timeout()), this, SLOT(produceEnemy()));
    m_timer->start(LV1_INTERVAL);
}

void Game::produceEnemy()
{
    qDebug() << "produce Enemy";
    for (int i = 0; i < ENEMY_NUM; i++)
    {
        qDebug() << "enemy produced";
        EnemyAirplane* enemy = new EnemyAirplane(i + 1);
        this->addItem(enemy);
    }
}
