#ifndef RAND_PLAYER_H_
#define RAND_PLAYER_H_

#include "Player.h"

#include <random>

class RandPlayer : public Player
{
public:
    RandPlayer(Piece color);

private:
    virtual uint8_t DoGetMove(const BoardGrid& bg) override;

private:
    std::mt19937 m_rng;
    std::uniform_int_distribution<std::mt19937::result_type> m_dist;

};

#endif /* RAND_PLAYER_H_ */
