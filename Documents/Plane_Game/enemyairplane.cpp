#include "enemyairplane.h"

EnemyAirplane::EnemyAirplane()
{
    this->setRect(0, 0, 70, 70);
    //randomly set enemy types:

    m_type = getRandomNum(ENEMY1, ENEMY3);
    switch (m_type)
    {
    case ENEMY1:
        m_energy = ENEMY1_NRG;
        break;
    case ENEMY2:
        m_energy = ENEMY2_NRG;
        break;
    case ENEMY3:
        m_energy = ENEMY3_NRG;
        break;
    default:
        qDebug() >> "Error";
        break;
    }

}

int EnemyAirplane::getEnergy()
{
    return m_energy;
}

void EnemyAirplane::loseEnergy(int energy)
{
    m_energy -= energy;
    if (m_energy < 0)
        scene()->removeItem(this); //DEAD
}

void EnemyAirplane::setBossLevel()
{

    m_energy = BOSS_NRG;
}


