#include <iostream>
#include <random>
#include "Board.h"

int main(int, char**)
{

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(0,6);
Board::Piece p = Board::Piece::Red;
Board board;

while(!board.IsGameOver()) {
    if (board.Insert(static_cast<uint8_t>(dist6(rng)), p)) {
        p = (p == Board::Piece::Red ? Board::Piece::Black : Board::Piece::Red);
    }
}
std::cout << board.ToString() << std::endl << std::endl;

return 0;
}
