#ifndef USER_PLAYER_H_
#define USER_PLAYER_H_

#include <stdint.h>
#include "Player.h"

class UserPlayer : public Player
{
public:
    UserPlayer(Piece color);

private:
    virtual uint8_t DoGetMove(const BoardGrid& bg) override;
};

#endif /* USER_PLAYER_H_ */