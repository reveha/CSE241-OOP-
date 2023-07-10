#include <iostream>
#include <vector>
using namespace std;

#define N 4

#define COLUMN 40
enum class tetros{shape_I='I',shape_O='O',shape_T='T',shape_J='J',shape_L='L',shape_S='S',shape_Z='Z'};

struct Board{ // this struct to keep best horizantal fit
    vector<vector<char> > board;
};





class Tetromino{
private:
    
    vector< vector<char> > tet={ {' ', ' ', ' ',' '},{' ',' ', ' ', ' '},{' ', ' ', ' ',' '},{' ',' ',' ',' '}};
    
    char keyword;
    int rotated=0; // to understand direction of the shape;

public:
    Tetromino();
    Tetromino(enum tetros shape);
    
    vector<vector<char> > loop_for_rotate(vector<vector<char> > shape);
    void rotate();
    bool canFit(Tetromino &oth);
    void fill_second_shape(Board &b, Tetromino &oth);
    void fill_table(struct Board &b);
    bool fill_table(Tetromino &oth, struct Board &b);
    void create_table(struct Board &b, int number);
    void print() const;
    void print_best_horizantal_fit(struct Board b);
};


