#include <iostream>
#include <vector>
#include <climits>
#include <limits>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Enum for tet objects 
 */
enum class TType : char
{
    
    /*
	Def = ' ',
	I = 'I',
    O = 'O',
    L = 'L',
    S = 'S',
    Z = 'Z',
	T = 'T',
    J = 'J' */
};
/**
 * @brief Enum for direction
 */
enum Rotation
{
    /* Left = 0,
    Right = 1 */
};

typedef std::vector<std::vector<TType>> Tetro;


/**
 * @brief Class for tet objects
 */
class Tetromino
{
private:
    TType tetromino_type;         // Hold tetromino type.
    Tetro tetromino;            // Hold tetromino shape.
	int x;						// size 
	int y;						// size
public:
    Tetromino(TType tetromino = TType::Def);
    bool canFit(const Tetromino &second_tetromino) const;
    void rotate(Rotation rotation = Rotation::Left);
    void print() const;
    friend class Tetros;
};

/**
 * @brief Class for game
 */
class Tetros : public Tetromino
{
private:
    Tetros &operator+=(const Tetromino &other_piece); 
    Tetros();
	bool canFit(const Tetromino &second_tetromino) const; 
    static const std::vector<TType> menu(); 
	void bestFit(Tetromino &second_tetromino); 
public:
    friend const Tetros play(); 
    friend Tetromino;
};
