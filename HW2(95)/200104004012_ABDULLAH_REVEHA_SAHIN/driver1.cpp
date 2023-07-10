#include "driver1.hpp"
#include "driver2.hpp"

using namespace std;



int main(){
    /*
    driver code ;
    */
    
    Tetromino t6(tetros::shape_J);
    Tetromino t7(tetros::shape_S);
    Tetromino t8(tetros::shape_T);
    Tetromino t9(tetros::shape_O);
    Tetromino t2(tetros::shape_Z);
    Tetromino t3(tetros::shape_L);
    Tetromino t4(tetros::shape_I);

    
    
    
    
    Tetris t1(10,8);
    
    

    t1.Animate(t6); // in this function fit() and Add() functions work;
    t1.draw();
    
    
    t1.find_index(t7);//TESTING OTHER FUNCTIONS
    t1.fill_indexes(t7);
    t1.find_index(t8);
    t1.fill_indexes(t8);
    t1.find_index(t9);
    t1.fill_indexes(t9);
    t1.find_index(t3);
    t1.fill_indexes(t3);
    t1.find_index(t4);
    t1.fill_indexes(t4);
    t1.find_index(t2);
    t1.fill_indexes(t2);
    t1.draw();//DRAWING THE LAST BOARD WITH SHAPES

    
    

    
    


    

    
     

    
    
    return 0;
}





