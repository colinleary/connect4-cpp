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

    bool Insert(uint8_t position, Piece piece);
    std::string Draw(void);

private:
    std::array<Piece, 42> m_board;
    Piece m_lastPiece;
};

#endif /* BOARD_H_ */
