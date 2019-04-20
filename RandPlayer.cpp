#include "RandPlayer.h"

#include <random>

RandPlayer::RandPlayer(Piece color)
  : Player(color)
  , m_rng(std::random_device()())
  , m_dist(0, 6)
{
}

/*!
 * @brief
 *  Gets a player's next move
 *
 * @return
 *  The position the player would like to drop the piece.
 *
 * Randomly selects a position for a next move.
 *
*/
uint8_t RandPlayer::DoGetMove(const BoardGrid&)
{
return static_cast<uint8_t>(m_dist(m_rng));
}
