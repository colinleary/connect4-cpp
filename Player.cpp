#include <iostream>
#include <sstream>
#include <string>
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

/*!
 * @brief
 *  Gets a player's next move
 *
 * @return
 *  The position the player would like to drop the piece.
 *
 * Reads input from stdin for next move.
 *
*/
uint8_t Player::DoGetMove(const BoardGrid& bg)
{
    int slot;
    std::string input;

    for (auto& c : bg) {
        for (auto& r : c) {
            std::cout << static_cast<char>(r) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Enter your slot (0 - 6): ";
    std::getline(std::cin, input);
    std::istringstream(input) >> slot;

    while (slot > 6) {
        std::cout << std::endl << "Invalid entry. Valid values are in the range (0 - 6): ";
        std::getline(std::cin, input);
        std::istringstream(input) >> slot;
    }

    return static_cast<uint8_t>(slot);
}
