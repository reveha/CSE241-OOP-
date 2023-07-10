#include <iostream>
#include <string>

#include <unistd.h>

#ifndef _DRIVER2_HPP_
#define _DRIVER2_HPP_

#define N 4

using namespace std;


/*
comment lines are in util.cpp

*/
namespace Tet{

    enum class tetros{shape_I='I',shape_O='O',shape_T='T',shape_J='J',shape_L='L',shape_S='S',shape_Z='Z'}; // strong enum

    class Tetromino{
    public:
        Tetromino();
        Tetromino(enum tetros shape);
        ~Tetromino();
        //void loop_for_rotate(char **shape);
        void rotate();
        //void fill_second_shape(Board &b, Tetromino &oth);
        //void fill_table(struct Board &b);
        //bool fill_table(Tetromino &oth, struct Board &b);
        void create_table(struct Board &b, int number);
        //void print_best_horizantal_fit(struct Board b)const;
        char getKey()const{return keyword;}
        int getRotated()const{return rotated;}
        bool getAdd()const{return added;}
        void setAdd(bool a){added=a;}
        Tetromino& operator=(char **temp);// to assign two 2d char vector like ->  char **a, **b;     a=b;
    private:
        char keyword;
        bool added=false;// to understand the shape was added the top of the up or not. according to this variable i will print or not.
        int rotated=0; // to understand direction of the shape;
        //vector< vector<char> > tet={ {' ', ' ', ' ',' '},{' ',' ', ' ', ' '},{' ', ' ', ' ',' '},{' ',' ',' ',' '}};
        char **tet;
        
    };
}

#endif