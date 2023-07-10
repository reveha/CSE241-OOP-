#include "tetris_board.hpp"

int main(int argc, char const *argv[])
{
    srand(time(0));
    Dual x;
    std::cout << "\033[0H\033[2J";
    std::cout << "Enter size of Board (width, height) : \n";
    std::cout << "Width : \n";
    std::cin >> x.x;
    std::cin.ignore();
    while (!std::cin.good())
    {
        std::cout << "Invalid value re-enter it :\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> x.x;
    }
    std::cout << "Height : \n";
    std::cin >> x.y;
    std::cin.ignore();
    while (!std::cin.good())
    {
        std::cout << "Invalid value re-enter it :\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> x.x;
    }

    TetrisBoard a(x.x, x.y);
    std::cout << "\033[0H\033[2J";
    a.Draw();
    bool game = true;
    while (game)
    {
        std::cout << "Tetromino type:" << std::endl;
        std::cout << "\033[J";
        char character;
        std::cin >> character;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (character == 'Q')
        return 0;
        bool found = false;
        for (int i = 0; i < 8; i++)
        if (xvalid_values[i] == character)
        {
            found = true;
            std::cout << "\033[0H";
            game = a.Fit(xturn_table[i]);
            break;
        }
        if (!found)
        {
            std::cout << "Invalid type." << std::endl;
        }
    }

    return 0;
}
