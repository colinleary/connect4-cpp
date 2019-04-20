#include "Board.h"

Board::Board()
  : m_lastPiece(Piece::Empty)
  , m_count(0)
{
    m_board.fill(Piece::Empty);
}

Board::~Board()
{
}

bool Board::CheckForVictory(void)
{
    /* Need to check up-down, left-right, down-right, down-left */
    static const std::array<uint8_t, 4> steps = { 7, /* Up-Down */
                                                 1, /* Left-Right */
                                                 8, /* Down-Right */
                                                 6, /* Down-Left */
                                                };

    if( m_lastPiece == Piece::Empty) {
        return false;
    }

    for (auto& step : steps) {
        uint8_t count = 1;
        /* We always use the last insert position as a seed */
        uint8_t cursor = m_lastPosition - step;
        while (cursor < m_board.size() && cursor % 7 != 6 && m_board[cursor] == m_lastPiece) {
            ++count;
            cursor -= step;
        }

        cursor = m_lastPosition + step;
        while (cursor < m_board.size() && cursor % 7 != 0 && m_board[cursor] == m_lastPiece) {
            ++count;
            cursor += step;
        }

        if (count >= 4) {
            return true;
        }
    }

    return false;
}

/*!
 * @brief
 *  Inserts a Color into the Board
 *
 * @param [in] position
 *  The position to insert into
 * @param [in] color
 *  The color to insert
 *
 * @return
 *  True if insert occurred.
 *
 * The position must be between 0 and 6 (inclusive), and the color cannot
 * be the same color previously inserted.
*/
bool Board::Insert(uint8_t position, Board::Piece piece)
{
    /* Disallow insertion of two of the same color in a row */
    if (piece == m_lastPiece) {
        return false;
    }

    /* Ensure color being inserted is valid */
    if (piece == Piece::Empty) {
        return false;
    }

    /* Ensure that position is valid */
    if (position > 6) {
        return false;
    }

    /* Ensure that the position we are inserting into is not full */
    if (m_board[position] != Piece::Empty) {
        return false;
    }

    /* Attempt to insert the piece */
    uint8_t idx = 35 + position;
    while (idx < m_board.size()) {
        if(m_board[idx] == Piece::Empty) {
            m_board[idx] = piece;
            m_lastPosition = idx;
            m_lastPiece = piece;
            ++m_count;
            return true;
        }
        idx -= 7;
    }

    return false;
}

/*!
 * @brief
 *  Checks if the game is over
 *
 * @return
 *  Returns true if the game is over.
 *
 * The game is over if the board is full, or a player has gotten 4 in a row.
*/
bool Board::IsGameOver(void)
{
    /* Minumum 7 moves for victory */
    if (m_count < 7) {
        return false;
    }

    /* Check for 4 in a row */
    if (CheckForVictory()) {
        return true;
    }

    return m_count >= m_board.size();
}

/*!
 * @brief
 *  Generates a string of the board
 *
 * @return
 *  A string representation of the board
 *
 * The returned string will represent a 6x7 grid.
*/
std::string Board::ToString(void)
    {
    std::string result;

    for (size_t idx = 0; idx < m_board.size(); ++idx) {
        if (idx > 0 && idx % 7 == 0) {
            result += '\n';
        }

        switch (m_board[idx]) {
            case Piece::Black:
                result += 'B';
                break;

            case Piece::Red:
                result += 'R';
                break;

            default:
                result += 'X';
                break;
        }

        result += ' ';
    }

    return result;
}
