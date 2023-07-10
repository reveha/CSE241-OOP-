#include "tetromino.hpp"

#pragma region Values
// Valid values for input
std::vector<char> valid_values = {
    'I',
    'O',
    'T',
    'J',
    'L',
    'S',
    'Z'};
// For turning input to Tetromino
D1Tms turn_table = {
    Tms::I,
    Tms::O,
    Tms::T,
    Tms::J,
    Tms::L,
    Tms::S,
    Tms::Z};
#pragma endregion

#pragma region Dual
// Basically 3 integers packed together nothing more
Dual::Dual(const Dual &s)
{
    this->x = s.x;
    this->y = s.y;
    this->r = s.r;
}
Dual::Dual(const int x, const int y, const int r)
{
    this->x = x;
    this->y = y;
    this->r = r;
}

// Square of distance between two points
int Dual::operator|(const Dual &s) const
{
    return (this->x - s.x) * (this->x - s.x) + (this->y - s.y) * (this->y - s.y);
}
// Sum
Dual Dual::operator+(const Dual &s) const
{
    return {(this->x + s.x), (this->y + s.y)};
}
// Turn to negative
Dual Dual::operator-() const
{
    return {-this->x, -this->y};
}
// Check if equal
bool Dual::operator==(const Dual &s) const
{
    if (this->x == s.x && this->y == s.y && this->r == s.r)
        return true;
    return false;
}
// Other checking
bool Dual::operator>=(const Dual &s) const
{
    if (this->x >= s.x && this->y >= s.y)
        return true;
    return false;
}
bool Dual::operator>=(const int s) const
{
    if (this->x >= s && this->y >= s)
        return true;
    return false;
}
bool Dual::operator<(const int s) const
{
    if (this->x < s || this->y < s)
        return true;
    return false;
}
bool Dual::operator<(const Dual &s) const
{
    if (this->x < s.x && this->y < s.y)
        return true;
    return false;
}
#pragma endregion

#pragma region Tetromino
// Colorful print of piece
void Tetromino::special_print(Tms character, int i)
{
    if (character == Tms::X)
        std::cout << "  ";
    else
        std::cout << ColorMap[static_cast<int>(character)] << "  \033[0m";
}
// Tetromino constructor
Tetromino::Tetromino(Tms type)
{
    switch (type)
    {
    case Tms::I:
        this->type = Tms::I;
        this->ghost = Tms::GhostI;
        this->piece.push_back({Tms::I, Tms::I, Tms::I, Tms::I});
        this->size = {4, 1};
        break;
    case Tms::O:
        this->type = Tms::O;
        this->ghost = Tms::GhostO;
        this->piece.push_back({Tms::O, Tms::O});
        this->piece.push_back({Tms::O, Tms::O});
        this->size = {2, 2};
        break;
    case Tms::T:
        this->type = Tms::T;
        this->ghost = Tms::GhostT;
        this->piece.push_back({Tms::X, Tms::T, Tms::X});
        this->piece.push_back({Tms::T, Tms::T, Tms::T});
        this->size = {3, 2};
        break;
    case Tms::J:
        this->type = Tms::J;
        this->ghost = Tms::GhostJ;
        this->piece.push_back({Tms::J, Tms::X, Tms::X});
        this->piece.push_back({Tms::J, Tms::J, Tms::J});
        this->size = {3, 2};
        break;
    case Tms::L:
        this->type = Tms::L;
        this->ghost = Tms::GhostL;
        this->piece.push_back({Tms::L, Tms::L, Tms::L});
        this->piece.push_back({Tms::L, Tms::X, Tms::X});
        this->size = {3, 2};
        break;
    case Tms::S:
        this->type = Tms::S;
        this->ghost = Tms::GhostS;
        this->piece.push_back({Tms::X, Tms::S, Tms::S});
        this->piece.push_back({Tms::S, Tms::S, Tms::X});
        this->size = {3, 2};
        break;
    case Tms::Z:
        this->type = Tms::Z;
        this->ghost = Tms::GhostZ;
        this->piece.push_back({Tms::Z, Tms::Z, Tms::X});
        this->piece.push_back({Tms::X, Tms::Z, Tms::Z});
        this->size = {3, 2};
        break;
    case Tms::X:
        this->type = Tms::X;
        this->size = {0, 0};
        break;
    case Tms::B:
        this->type = Tms::B;
        this->ghost = Tms::GhostO;
        this->piece.push_back({Tms::O});
        this->size = {1, 1};
        break;
    case Tms::Random:
        D1Tms a = {Tms::I, Tms::O, Tms::T, Tms::J, Tms::L, Tms::S, Tms::Z};
        *this = *new Tetromino(a[rand() % a.size()]);
        break;
    }
}
// Print piece
void Tetromino::print() const
{
    for (auto row : this->piece)
    {
        for (auto cha : row)
        {
            Tetromino::special_print(cha);
        }
        putchar('\n');
    }
    putchar('\n');
}
// Transposing for rotate
void Tetromino::transpose()
{
    D2Tms temp(this->size.x, D1Tms(this->size.y, Tms::X));
    for (int i = 0; i < this->size.x; i++)
        for (int j = 0; j < this->size.y; j++)
            temp[i][j] = this->piece[j][i];
    this->piece = temp;
    int temp_int;
    temp_int = this->size.x;
    this->size.x = this->size.y;
    this->size.y = temp_int;
}
// Rotate, default to left
void Tetromino::rotate(Rotation rotation)
{
    this->transpose();
    Tms temp;

    if (rotation == Rotation::Left)
    {
        D1Tms temp;
        for (int i = 0; i < this->size.y / 2; i++)
        {
            temp = this->piece[i];
            this->piece[i] = this->piece[this->size.y - i - 1];
            this->piece[this->size.y - i - 1] = temp;
        }
        temp.clear();
        this->size.r++;
    }
    else if (rotation == Rotation::Right)
    {
        Tms temp;
        for (int j = 0; j < this->size.y; j++)
        {
            for (int i = 0; i < this->size.x / 2; i++)
            {
                temp = this->piece[j][i];
                this->piece[j][i] = this->piece[j][size.x - i - 1];
                this->piece[j][size.x - i - 1] = temp;
            }
        }
        this->size.r--;
    }
}
// Check if the piece can fit
bool Tetromino::canFit(const Tetromino &second_tetromino) const
{
    Tetros temp;
    temp += *this;
    temp += second_tetromino;
    int st = 0;
    for (auto x : temp.piece.back())
        if (!st && x == Tms::X)
            st = 1;
        else if (st && x != Tms::X)
            st = 2;
    if (st == 2)
        return false;
    return true;
}
// Count empyt spots of piece, it requires for best fit
int Tetromino::empyt_counter() const
{
    int count = 0;
    for (auto x : this->piece.back())
        if (x == Tms::X)
            count++;
    return count;
}
#pragma endregion

#pragma region Tetros
// Can fit again, not much difference
bool Tetros::canFit(const Tetromino &second_tetromino) const
{
    Tetros temp;
    temp = *this;
    // ! The difference is here.
    // ! Normally it is += but in
    // ! here it makes a lot of problem.

    temp += second_tetromino;
    int st = 0;
    for (auto x : temp.piece.back())
        if (!st && x == Tms::X)
            st = 1;
        else if (st && x != Tms::X)
            st = 2;
    if (st == 2)
        return false;
    return true;
}
// Fit the pieces to main group as best as possible
void Tetros::bestFit(Tetromino &second_tetromino)
{
    std::vector<st> test(4);
    for (int i = 0; i < 4; i++)
    {
        Tetros temp = *this;
        test[i].canFitted = temp.canFit(second_tetromino);
        temp += second_tetromino;
        test[i].len = temp.size.x;
        test[i].e_count = temp.empyt_counter();
        second_tetromino.rotate(Rotation::Right);
    }
    int best = INT8_MAX;
    int best_index = 0;
    for (int i = 0; i < 4; i++)
    {
        if ((SIZE_RATIO * test[i].len) -
                (CAN_FIT_RATIO * test[i].canFitted) +
                (EMPYT_RATIO * test[i].e_count) <
            best)
        {
            best = (SIZE_RATIO * test[i].len) -
                   (CAN_FIT_RATIO * test[i].canFitted) +
                   (EMPYT_RATIO * test[i].e_count);
            best_index = i;
        }
    }
    for (int i = 0; i < best_index; i++)
        second_tetromino.rotate(Rotation::Right);
    *this += second_tetromino;
}
// Constructor
Tetros::Tetros()
{
    this->size = {0, 0};
}
// Add to main group without changing anything
Tetros &Tetros::operator+=(const Tetromino &other_piece)
{
    int ymax = (this->size.y > other_piece.size.y) ? this->size.y : other_piece.size.y;
    int dif = ymax - this->size.y;
    for (int i = this->size.y; i < ymax; i++)
        this->piece.insert(this->piece.begin(), D1Tms(this->size.x, Tms::X));
    this->size.y = ymax;
    for (int i = 0; i < ymax - other_piece.size.y; i++)
        for (int j = 0; j < other_piece.size.x; j++)
            this->piece[i].push_back(Tms::X);
    for (int i = ymax - other_piece.size.y; i < ymax; i++)
        for (int j = 0; j < other_piece.size.x; j++)
            this->piece[i].push_back(other_piece.piece[i - ymax + other_piece.size.y][j]);
    int x = this->size.x;
    this->size.x = this->piece[0].size();
    bool canShrink = true;
    while (canShrink)
    {
        if (x >= this->size.x || !x)
            break;
        else
            for (int j = dif; j < this->size.y; j++)
            {
                if (x &&
                    this->piece[j][x - 1] != Tms::X &&
                    this->piece[j][x] != Tms::X)
                    canShrink = false;
            }
        if (canShrink)
        {
            for (int j = dif; j < this->size.y; j++)
            {
                this->piece[j][x - 1] = (this->piece[j][x - 1] == Tms::X)
                                            ? this->piece[j][x]
                                            : this->piece[j][x - 1];
                this->piece[j].erase(this->piece[j].begin() + x);
            }
            for (int j = 0; j < dif; j++)
            {
                this->piece[j][x - 1 - dif] = (this->piece[j][x - 1 - dif] == Tms::X)
                                                  ? this->piece[j][x - dif]
                                                  : this->piece[j][x - 1 - dif];
                this->piece[j].erase(this->piece[j].begin() + x - dif);
            }
            this->size.x--;
        }
    }
    return *this;
}
// Menu
const D1Tms Tetros::menu()
{
    std::cout << "How many tetrominos do you want?" << std::endl;
    int count;
    std::cin >> count;
    std::cin.ignore();
    if (!std::cin.good())
    {
        std::cout << "Invalid input." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return menu();
    }

    D1Tms T;
    char a;
    std::cout << "Tetrominos type:" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cin >> a;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        bool found = false;
        for (int i = 0; i < 7; i++)
            if (valid_values[i] == a)
            {
                found = true;
                T.push_back(turn_table[i]);
                continue;
            }
        if (!found)
        {
            std::cout << "Invalid type." << std::endl;
            --i;
        }
    }
    return T;
}
// Main function, kinda useless but make everthing a bit more clear
const Tetros start()
{
    Tetros c;
#if RANDOMIZER == 0
    D1Tms x = Tetros::menu();
    std::cout << "Your tetrominos:" << std::endl;
    for (auto y : x)
    {
        Tetromino temp(y);
        temp.print();
        c.bestFit(temp);
    }
#else
    srand(time(0));
    int x = rand() % 15;
    while (--x)
        c.bestFit(*new Tetromino(Tms::Random));
#endif
    std::cout << "Best fit:" << std::endl;
    c.print();
    return c;
}
#pragma endregion

#pragma region Color
// Color class for printing
Color::Color(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}
std::ostream &operator<<(std::ostream &os, Color color)
{
    os << "\033[48;2;" << color.r << ';' << color.g << ';' << color.b << 'm';
    return os;
}
// Color for tetrominos
// Half of them are for making shadow at the end of path of piece
std::vector<Color> ColorMap = {
    {0, 240, 240},
    {240, 240, 0},
    {160, 0, 240},
    {240, 160, 0},
    {0, 0, 240},
    {240, 0, 0},
    {0, 240, 0},
    {0, 0, 0},
    {0, 160, 160},
    {160, 160, 0},
    {160, 0, 160},
    {160, 160, 0},
    {0, 0, 160},
    {160, 0, 0},
    {0, 160, 0}};

#pragma endregion
