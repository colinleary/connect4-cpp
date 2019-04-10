#include "Board.h"

Board::Board()
  : m_lastPiece(Piece::Empty)
{
    m_board.fill(Piece::Empty);
}

Board::~Board()
{
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
    size_t idx = 35 + position;
    while (idx < m_board.size()) {
        if(m_board[idx] == Piece::Empty) {
            m_board[idx] = piece;
            return true;
        }
        idx -= 7;
    }

    return false;
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
std::string Board::Draw(void)
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
