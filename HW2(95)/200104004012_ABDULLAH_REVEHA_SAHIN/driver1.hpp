#include <iostream>
#include <vector>

#include "driver2.hpp"

#ifndef _DRIVER1_HPP_
#define _DRIVER1_HPP_


using namespace std;

/*
comment lines are in util.cpp

*/


class Tetris{

public:
    Tetris(int h, int l);
    void Add(Tetromino &shape);
    void fit(Tetromino &shape);
    void draw() const;
    void Animate(Tetromino shape);
    void find_index(Tetromino &shape);
    void create_board();
    void fill_board();
    
    void rotate_added_shape(Tetromino &shape);
    bool game_over();
    void move_animation(Tetromino &shape);
    void fill_indexes(Tetromino &shape);
    void fill_just_y_indexes(Tetromino &shape);
private:
    Board b;
    int index_x,index_y; // to keep indexes that will be fitted with the shape;
};


#endif