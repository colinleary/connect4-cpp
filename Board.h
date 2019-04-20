#ifndef BOARD_H_
#define BOARD_H_

#include <array>
#include <string>
#include <vector>

enum class Piece : char {
        Empty = 'X',
        Red = 'R',
        Black = 'B'
};

typedef std::array<std::array<Piece, 7>, 6> BoardGrid;

class Board
{
public:
    Board();
    virtual ~Board();

    bool CheckForVictory(void);
    bool Insert(uint8_t position, Piece piece);
    bool IsGameOver(void);
    BoardGrid GetBoardGrid(void);
    std::string ToString(void);

private:
    std::array<Piece, 42> m_board;
    Piece m_lastPiece;
    uint8_t m_lastPosition;
    uint8_t m_count;
};

#endif /* BOARD_H_ */
