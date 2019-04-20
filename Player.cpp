#include "Player.h"

Player::Player(Piece color)
  : m_color(color)
{
}

/*!
 * @brief
 *  Gets a player's next move
 *
 * @return
 *  The position the player would like to drop the piece.
 *
*/
uint8_t Player::GetMove(const BoardGrid& bg)
{
    return DoGetMove(bg);
}

/*!
 * @brief
 *  Gets a player's color
 *
 * @return
 *  The color of the player's piece
 *
*/
Piece Player::GetColor(void)
{
    return m_color;
}
