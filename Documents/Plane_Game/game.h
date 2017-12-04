#ifndef GAME_H
#define GAME_H
#include "globals.h"

class Player;
class Game: public QGraphicsScene //or sth else?
{
public:
    Game();

private:
    int m_gamecount;
    int m_level;
    Player* m_player;
};

#endif // GAME_H
