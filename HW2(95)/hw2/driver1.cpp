#include "tetris_board.hpp"

void print_line(int i = 30)
{
    std::cout << "\033[31m\n";
    while (i-- > 0)
    putchar('-');
    std::cout << "\n\033[0m\n";
}

int main(int argc, char const *argv[])
{
    std::cout << "\033[33mTETROMINO CLASS\033[0m" << std::endl;
    #pragma region canFit
    print_line();
    std::cout << "canFit Function Test:" << std::endl;
    Tetromino b(Tms::T);
    Tetromino c(Tms::O);
    Tetros a;
    a += b;
    b.rotate();
    a += b;
    a+= c;
    std::cout << "Main group :" << std::endl;
    a.print();
    std::cout << "New piece :" << std::endl;
    b.print();
    std::cout << "canFit return value : " << a.canFit(b) << std::endl;
    #pragma endregion

    #pragma region rotate
    print_line();
    std::cout << "rotate function Test : " << std::endl;
    b.print();
    b.rotate(Rotation::Right);
    b.print();
    std::cout << "canFit return value : " << a.canFit(b) << std::endl;
    #pragma endregion

    #pragma region bestFit
    print_line();
    std::cout << "bestFit Test: " << std::endl;
    Tetros x;
    Tetromino d(Tms::T);
    Tetromino e(Tms::I);
    Tetromino f(Tms::J);
    x.bestFit(e);
    x += f;
    std::cout << "Main group :" << std::endl;
    x.print();
    std::cout << "New piece :" << std::endl;
    d.print();
    x.bestFit(d);
    std::cout << "After bestFit :" << std::endl;
    x.print();
    #pragma endregion
    
    std::cout << "Press enter to next Page" << std::endl;
    std::string str;
    getline(std::cin, str);
    std::cout << "\033[2J\033[0H\033[33mTETRIS BOARD CLASS\033[0m" << std::endl;
    
    #pragma region Board
    print_line();
    Tetromino z(Tms::L);
    std::cout << "Piece to board" << std::endl;
    std::cout << "Next Piece : " << std::endl;
    z.print();
    std::cout << "Enter 2 numbers" << std::endl;
    int i = 10;
    int j = 20;
    std::cin >> i;
    bool test = std::cin.good();
    std::cin >> j;
    TetrisBoard *xboard;
    if (std::cin.good() && test)
    {
        xboard = new TetrisBoard ({i, j});
    }
    else
    {
        std::cin.clear(); std::cin.ignore(INT_MAX,'\n'); 
        std::cout << "You have a chance but you have lost it. Now I will enter it." << std::endl;
        xboard = new TetrisBoard({10, 20});
    }
    std::cout << "Board" << std::endl;
    (*xboard).Draw(1);
    z.rotate();
    z.rotate();
    (*xboard).Add(z);
    (*xboard).Draw();
    sleep(2);
    (*xboard).Fit(z);
    print_line();
    #pragma endregion
    std::cout << "Press enter to driver2.cpp file" << std::endl;
    std::cin.clear(); std::cin.ignore(INT_MAX,'\n'); 
    std::cin.ignore();

    return 0;
}