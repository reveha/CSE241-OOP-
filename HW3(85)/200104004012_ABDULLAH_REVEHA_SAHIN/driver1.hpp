#include <iostream>
#include <vector>

#include "driver2.hpp"

#ifndef _DRIVER1_HPP_
#define _DRIVER1_HPP_




/*
comment lines are in util.cpp

*/

namespace Tet{
    class Tetris{
    public:
        Tetris(int h=10, int l=10);
        ~Tetris();
        //void Add(Tetromino &shape)const;
        //void fit(Tetromino &shape);
        void draw() const;
        void Animate(Tetromino &shape, int count_move, int count_rotate, string direction);
        bool check_index(const Tetromino &shape, int count, string direction);
        //void find_index(Tetromino &shape);
        void clear_top(const Tetromino &shape);
        void clear();
        void create_board();
        void fill_board();
        void rotate_added_shape(const Tetromino &shape);
        bool game_over() const ;
        void move_animation(Tetromino &shape);
        void fill_indexes(const Tetromino &shape);
        void fill_just_y_indexes(const Tetromino &shape);
        Tetris& operator+=(Tetromino &shape);

        void driver_test(){ // just for testing functions . for driver1.cpp
            for(auto i=1;i<b.length-1;i++){
                if(b.board[b.height-2][i]=='.'){
                    b.board[b.height-2][i]='A';
                }
            }
        }
    private:
        Board b;
        int index_x,index_y=8; // to keep indexes that will be fitted with the shape;
    };
}

#endif