#include "game.h"
#include "player.h"

Game::Game()
{
    m_gamecount = 0;
    m_level = 0;

    m_player = new Player();
    m_player->setRect(0, 0, 100, 100);
    this->addItem(m_player);
    m_player->setFlag(QGraphicsItem::ItemIsFocusable);
    m_player->setFocus();
}
