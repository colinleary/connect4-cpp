#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdint.h>
#include "Board.h"

class Player
{
public:
    Player(Piece color);

    uint8_t GetMove(const BoardGrid& bg);
    Piece GetColor(void);

private:
    virtual uint8_t DoGetMove(const BoardGrid& bg) = 0;

private:
    Piece m_color;
};

#endif /* PLAYER_H_ */
