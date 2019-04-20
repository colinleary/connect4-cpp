#include <iostream>
#include "Board.h"
#include "UserPlayer.h"
#include "RandPlayer.h"

int main(int, char**)
{
Board board;
UserPlayer p1(Piece::Black);
UserPlayer p2(Piece::Red);
bool turn = true;

while (!board.IsGameOver()) {
    Player& p = (turn ? p1 : p2);
    while (!board.Insert(p.GetMove(board.GetBoardGrid()), p.GetColor()));
    turn = !turn;
    std::cout << board.ToString() << std::endl << std::endl;
}
std::cout << board.ToString() << std::endl << std::endl;

return 0;
}
