#include <iostream>
#include "Board.h"

int main(int, char**)
{
Board board;
for (size_t idx = 0; idx < 6; ++idx) {
    Board::Piece p;
    if (idx % 2) {
        p = Board::Piece::Red;
    }
    else {
        p = Board::Piece::Black;
    }

    bool result = board.Insert(0, p);
    std::cout << "Inserting ";
    std::cout << (p == Board::Piece::Red ? "Red" : "Black");
    std::cout << (result ? " succeeded" : " failed");
    std::cout << std::endl;
}
std::cout << board.Draw() << std::endl;

return 0;
}
