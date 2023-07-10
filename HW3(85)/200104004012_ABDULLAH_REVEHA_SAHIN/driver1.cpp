#include "driver1.hpp"
#include "driver2.hpp"

using namespace std;
using namespace Tet;


int main(){
    /*
    driver code ;
    */
    srand(time(NULL));
    cout<<"How many times you want to move TO RIGHT:";
    int move_count;
    cin>>move_count;
    cout<<"How many times you want to rotate TO RIGHT:";
    int rotate_count;
    cin>>rotate_count;
    Tetromino t2(tetros::shape_J);
    Tetromino t3(tetros::shape_I);
    Tetromino t4(tetros::shape_T);
    Tetromino t5(tetros::shape_O);
    Tetromino t6(tetros::shape_S);
    Tetromino t7(tetros::shape_Z);
    Tetromino t8(tetros::shape_L);
    Tetris t1(10,15);

    t1+=t2;// ADDING THE TOP BOTTOM

    t1.Animate(t2,move_count,rotate_count,"R"); // every member function is called from Animate function

     cout<<"How many times you want to move TO LEFT:";
    cin>>move_count;
    cout<<"How many times you want to rotate TO LEFT:";
    cin>>rotate_count;
    rotate_count%=4;
    rotate_count=4-rotate_count;
    t1.Animate(t4,move_count,rotate_count,"L");
    t1+=t7;
    t1.check_index(t7,rand()%7,"L");
    t1.fill_indexes(t7);
    t1.clear_top(t7);
    t1.draw();
    usleep(2500000);
    t1.driver_test();
    t1.draw();
    cout<<"\n'A' WILL BE DELETED TO SHOW clear() FUNCTION IS WORKING"<<endl;
    usleep(4000000);
    t1.clear();
    t1.draw();
    cout<<"\nAFTER CLEAR FUNCTION WORKED"<<endl;
    return 0;
}





