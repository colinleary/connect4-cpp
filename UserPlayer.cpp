#include <iostream>
#include "UserPlayer.h"

#if (defined(_WIN32) || defined(_WIN64))
    #include "windows.h"
#else
    #error "User input not supported on this platform"
#endif

namespace
{
enum class Key {
    Invalid,
    Drop,
    Exit,
    Left,
    Right
};

}
static Key GetKey(void);

UserPlayer::UserPlayer(Piece color)
  : Player(color)
{
}

/*!
 * @brief
 *  Gets a player's next move
 *
 * @return
 *  The position the player would like to drop the piece.
 *
 * Reads input from stdin for next move.
 *
*/
uint8_t UserPlayer::DoGetMove(const BoardGrid& bg)
{
    uint8_t slot = 0;
    Key key = Key::Drop;

    do {
        if (key != Key::Invalid) {
            std::cout << std::endl << std::endl;

            for (uint8_t i = 0; i < 7; ++i) {
                std::cout << static_cast<char>(i == slot ? GetColor() : Piece::Empty) << " ";
            }

            std::cout << std::endl << std::endl;

            for (auto& c : bg) {
                for (auto& r : c) {
                    std::cout << static_cast<char>(r) << " ";
                }
                std::cout << std::endl;
            }
        }

        key = GetKey();
        switch (key) {
            case Key::Left:
                --slot;
                break;

            case Key::Right:
                ++slot;
                break;

            case Key::Exit:
                exit(1);
                break;

            default:
                break;
        }

        slot = slot % 7;
    } while( key != Key::Drop );

    return slot;

}

static Key GetKey(void)
{
    Key key;

#if (defined(_WIN32) || defined(_WIN64))
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD NumInputs = 0;
    DWORD InputsRead = 0;
    INPUT_RECORD irInput;

    GetNumberOfConsoleInputEvents(hInput, &NumInputs);
    ReadConsoleInput(hInput, &irInput, 1, &InputsRead);

    if (!irInput.Event.KeyEvent.bKeyDown) {
        return Key::Invalid;
    }

    switch (irInput.Event.KeyEvent.wVirtualKeyCode) {
        case VK_ESCAPE:
        case VK_CANCEL:
            key = Key::Exit;
        break;

        case VK_LEFT:
            key = Key::Left;
            break;

        case VK_RIGHT:
            key = Key::Right;
            break;

        case VK_RETURN:
            key = Key::Drop;
            break;

        default:
            key = Key::Invalid;
            break;
    }

    /* Short delay */
    Sleep(10);
#else

#endif

    return key;
}