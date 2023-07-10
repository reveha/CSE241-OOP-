#ifndef TETROMINO
#define TETROMINO

#define CAN_FIT_RATIO 1000
#define EMPYT_RATIO 10
#define SIZE_RATIO 11

#define RANDOMIZER 0

#include <iostream>
#include <vector>
#include <climits>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#if defined(unix) || defined(__unix) || defined(__unix__) || defined(linux) || defined(__linux) || defined(__linux__)
#define SLEEP 
#include <unistd.h>
#endif
typedef std::vector<int> D1int;
typedef std::vector<D1int> D2int;

struct st
{
public:
    bool canFitted;
    int len;
    int e_count;
    st(bool c = false, int len = INT16_MAX, int ec = INT16_MAX)
    {
        this->canFitted = c;
        this->len = len;
        this->e_count = ec;
    }
};

enum class Tms : char
{
    I,
    O,
    T,
    L,
    J,
    Z,
    S,
    X,
    GhostI,
    GhostO,
    GhostT,
    GhostL,
    GhostJ,
    GhostZ,
    GhostS,
    Random,
    B
};

typedef std::vector<Tms> D1Tms;
typedef std::vector<D1Tms> D2Tms;

enum class Rotation : char
{
    Left,
    Right,
    Up,
    Down
};

class Dual
{
public:
    int x;
    int y;
    int r;

    Dual(const Dual &s);
    Dual(const int x = 0, const int y = 0, const int r = 0);
    int operator|(const Dual &s) const;
    Dual operator+(const Dual &s) const;
    Dual operator-() const;
    bool operator==(const Dual &s) const;
    bool operator>=(const Dual &s) const;
    bool operator>=(const int s) const;
    bool operator<(const int s) const;
    bool operator<(const Dual &s) const;
};

typedef std::vector<Dual> D1Dual;

class Tetros;
const Tetros start();
class Tetromino
{
private:
    Tms type;
    Tms ghost;

protected:
    static void special_print(Tms = Tms::X, int = 0);
    void transpose();
    int empyt_counter() const;
    D2Tms piece;
    bool canFit(const Tetromino &) const;
    Dual size;

public:
    Tetromino(Tms = Tms::X);
    void rotate(Rotation = Rotation::Left);
    void print() const;

    friend class Tetros;
    friend class NodeMap;
    friend class TetrisBoard;
    friend const Tetros start();
};

class Tetros : public Tetromino
{
private:
    static const std::vector<Tms> menu();

public:
    void bestFit(Tetromino &);
    Tetros();
    Tetros &operator+=(const Tetromino &);
    bool canFit(const Tetromino &) const;
    friend class Tetromino;
    friend const Tetros start();
};

class Color
{
private:
    short r;
    short g;
    short b;

public:
    Color(int = 0, int = 0, int = 0);
    friend std::ostream &operator<<(std::ostream &, Color);
};

extern std::vector<Color> ColorMap;

#endif