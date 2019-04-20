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
    if( m_lastPiece == Piece::Empty) {
        return false;
    }

    const size_t size = m_board.size();
    const uint8_t ud_step = 7;
    const uint8_t lr_step = 1;
    const uint8_t dr_step = 8;
    const uint8_t dl_step = 6;
    uint8_t cur;
    uint8_t count;

    /* Check up-down */
    count = 1;
    cur = m_lastPosition - ud_step;
    while (cur < size && m_board[cur] == m_lastPiece) {
        ++count;
        cur -= ud_step;
    }

    cur = m_lastPosition + ud_step;
    while (cur < size && m_board[cur] == m_lastPiece) {
        ++count;
        cur += ud_step;
    }

    if (count >= 4) {
        return true;
    }

    /* Check left-right */
    count = 1;
    cur = m_lastPosition - lr_step;
    while (cur < size && cur % 7 < 6 && m_board[cur] == m_lastPiece) {
        ++count;
        cur -= lr_step;
    }

    cur = m_lastPosition + lr_step;
    while (cur < size && cur % 7 > 0 && m_board[cur] == m_lastPiece) {
        ++count;
        cur += lr_step;
    }

    if (count >= 4) {
        return true;
    }

    /* Check down-right */
    count = 1;
    cur = m_lastPosition - dr_step;
    while (cur < size && cur % 7 < 6 && m_board[cur] == m_lastPiece) {
        ++count;
        cur -= dr_step;
    }

    cur = m_lastPosition + dr_step;
    while (cur < size && cur % 7 > 0 && m_board[cur] == m_lastPiece) {
        ++count;
        cur += dr_step;
    }

    if (count >= 4) {
        return true;
    }

    /* Check down-left */
    count = 1;
    cur = m_lastPosition - dl_step;
    while (cur < size && cur % 7 > 0 && m_board[cur] == m_lastPiece) {
        ++count;
        cur -= dl_step;
    }

    cur = m_lastPosition + dl_step;
    while (cur < size && cur % 7 < 6 && m_board[cur] == m_lastPiece) {
        ++count;
        cur += dl_step;
    }

    if (count >= 4) {
        return true;
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
bool Board::Insert(uint8_t position, Piece piece)
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

BoardGrid Board::GetBoardGrid(void)
{
    BoardGrid bg = { Piece::Empty };

    for (uint8_t i = 0; i < m_board.size(); ++i) {
        bg[i / 7][i % 7] = m_board[i];
    }

    return bg;
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
