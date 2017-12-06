#include "enemyairplane.h"
#include <QDebug>
#include "game.h"

EnemyAirplane::EnemyAirplane(int type, Game* game)
{
    this->setRect(0, 0, 130, 50);


    m_game = game;
    //consistent enemy types:
    m_type = type;

//    m_type = getRandomNum(ENEMY1, ENEMY3);
    switch (m_type)
    {
    case ENEMY1:
        m_energy = ENEMY1_NRG;
        this->setPos(WIN_WIDTH/6 - rect().width()/2, 0);
        break;
    case ENEMY2:
        m_energy = ENEMY2_NRG;
        this->setPos((WIN_WIDTH/2) - rect().width()/2, 0);
        break;
    case ENEMY3:
        this->setPos(5*(WIN_WIDTH/6) - rect().width()/2, 0);
        m_energy = ENEMY3_NRG;
        break;
    default:
        qDebug() << "Error";
        break;
    }
    m_timer = new QTimer();
    QObject::connect (m_timer, SIGNAL(timeout()), this, SLOT(move()));
    m_timer->start(50);

}

EnemyAirplane::~EnemyAirplane()
{
    delete m_timer;
}

int EnemyAirplane::getEnergy()
{
    return m_energy;
}

void EnemyAirplane::loseEnergy(int energy)
{
    m_energy -= energy;
    if (m_energy <= 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void EnemyAirplane::setBossLevel()
{

    m_energy = BOSS_NRG;
}

void EnemyAirplane::move()
{
    this->setPos(x(), y() + 5);
    if (this->pos().y() + rect().height() > WIN_HEIGHT)
    {
        m_game->EnemyArrives(m_energy);
        qDebug() << "Deleted";
        scene()->removeItem(this);
        delete this;
    }
}


