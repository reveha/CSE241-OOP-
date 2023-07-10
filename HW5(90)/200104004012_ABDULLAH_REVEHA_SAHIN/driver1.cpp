#include "driver1.hpp"
#include "driver2.hpp"

using namespace std;
using namespace Tet;


int main(){
    /*
    driver code ;
    */
    int pass;
    cout<<"Do you want to pass driver source code? 1-yes/0-no: ";
    cin>>pass;
    if(pass==1){
        return 0;
    }

    fstream file;
    srand(time(NULL));
    Tetromino t2(tetros::shape_J);
    Tetromino t3(tetros::shape_I);
    Tetromino t4(tetros::shape_T);
    Tetromino t5(tetros::shape_O);
    Tetromino t6(tetros::shape_S);
    Tetromino t7(tetros::shape_Z);
    Tetromino t8(tetros::shape_L);
    
    // test driver object tetris adapter<vector>
    TetrisAdapter<vector< vector<char>> > t(10,15);

    t+=t2;// ADDING THE TOP BOTTOM

    cout<<"How many times you want to move TO RIGHT:";
    int move_count;
    cin>>move_count;
    cout<<"How many times you want to rotate TO RIGHT:";
    int rotate_count;
    cin>>rotate_count;
     
    t.Animate(t2,move_count,rotate_count,"R"); // every member function is called from Animate function

    cout<<"How many times you want to move TO LEFT:";
    cin>>move_count;
    cout<<"How many times you want to rotate TO LEFT:";
    cin>>rotate_count;

    rotate_count%=4;
    rotate_count=4-rotate_count;
    t.Animate(t4,move_count,rotate_count,"L");
    t+=t7;
    t.check_index(t7,rand()%7,"L");
    t.fill_indexes(t7);
    t.clear_top(t7);
    t.draw();
    usleep(2500000);
    t.driver_test();
    t.draw();
    cout<<"\n'A' WILL BE DELETED TO SHOW clear() FUNCTION IS WORKING"<<endl;
    usleep(4000000);
    t.clear();
    t.draw();
    cout<<"\nAFTER CLEAR FUNCTION WORKED"<<endl;
    
    
    // test driver object tetris adapter <deque>
    TetrisAdapter<deque< deque<char>> > t20(10,15);

    t20+=t2;// ADDING THE TOP BOTTOM

    cout<<"How many times you want to move TO RIGHT:";
    cin>>move_count;
    cout<<"How many times you want to rotate TO RIGHT:";
    cin>>rotate_count;
     
    t20.Animate(t2,move_count,rotate_count,"R"); // every member function is called from Animate function

    cout<<"How many times you want to move TO LEFT:";
    cin>>move_count;
    cout<<"How many times you want to rotate TO LEFT:";
    cin>>rotate_count;

    rotate_count%=4;
    rotate_count=4-rotate_count;
    t20.Animate(t4,move_count,rotate_count,"L");
    t20+=t7;
    t20.check_index(t7,rand()%7,"L");
    t20.fill_indexes(t7);
    t20.clear_top(t7);
    t20.draw();
    usleep(2500000);
    t20.driver_test();
    t20.draw();
    cout<<"\n'A' WILL BE DELETED TO SHOW clear() FUNCTION IS WORKING"<<endl;
    usleep(4000000);
    t20.clear();
    t20.draw();
    cout<<"\nAFTER CLEAR FUNCTION WORKED"<<endl;


    // test driver object tetris array 1d
    TetrisArray1D t21(10,15);

    t21+=t2;// ADDING THE TOP BOTTOM

    cout<<"How many times you want to move TO RIGHT:";
    cin>>move_count;
    cout<<"How many times you want to rotate TO RIGHT:";
    cin>>rotate_count;
     
    t21.Animate(t2,move_count,rotate_count,"R"); // every member function is called from Animate function

    cout<<"How many times you want to move TO LEFT:";
    cin>>move_count;
    cout<<"How many times you want to rotate TO LEFT:";
    cin>>rotate_count;

    rotate_count%=4;
    rotate_count=4-rotate_count;
    t21.Animate(t4,move_count,rotate_count,"L");
    t21+=t7;
    t21.check_index(t7,rand()%7,"L");
    t21.fill_indexes(t7);
    t21.clear_top(t7);
    t21.draw();
    usleep(2500000);
    t21.driver_test();
    t21.draw();
    cout<<"\n'A' WILL BE DELETED TO SHOW clear() FUNCTION IS WORKING"<<endl;
    usleep(4000000);
    t21.clear();
    t21.draw();
    cout<<"\nAFTER CLEAR FUNCTION WORKED"<<endl;

    // test driver object tetris vector
    TetrisVector t1(10,15);

    t1+=t2;// ADDING THE TOP BOTTOM

    cout<<"How many times you want to move TO RIGHT:";
    cin>>move_count;
    cout<<"How many times you want to rotate TO RIGHT:";
    cin>>rotate_count;
     
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





