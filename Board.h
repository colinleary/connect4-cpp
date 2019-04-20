#ifndef BOARD_H_
#define BOARD_H_

#include <array>
#include <string>

class Board
{
public:
    enum Piece {
        Empty,
        Red,
        Black
    };

    Board();
    virtual ~Board();

    bool Board::CheckForVictory(void);
    bool Insert(uint8_t position, Piece piece);
    bool IsGameOver(void);
    std::string ToString(void);

private:
    std::array<Piece, 42> m_board;
    Piece m_lastPiece;
    uint8_t m_lastPosition;
    uint8_t m_count;
};

#endif /* BOARD_H_ */
