#include "driver2.hpp"
#include "driver1.hpp"



using namespace std;
using namespace Tet;






int main(){
    int height,length;
    string type;
    cout<<"Enter the size of the board (height-length)\n";
    cin>>height>>length;
    do{ 
        cout<<"Enter the type of the Tetris class (V for vector, 1 for array1D, A for adaptor, OR Q TO QUIT): ";
        cin>>type;
        if(type!="V" && type!="v" && type!="1" && type!="A" && type!="a" && type!="Q" && type!="q"){
            cout<<"\nYou typed incorrectly!\n"<<endl;
        }
    }while(type!="V" && type!="v" && type!="1" && type!="A" && type!="a" && type!="Q" && type!="q");

    while(true){
        if(type=="V" || type=="v"){
            TetrisVector t1(height,length);
            print_menu(t1);
        }
        else if(type=="1"){
            TetrisArray1D t1(height,length);
            print_menu(t1);
        }
        else if(type=="A" || type=="a"){
            cout<<"V for vector, D for deque: ";
            cin>>type;
            if(type=="V" || type=="v"){
                TetrisAdapter<vector<vector<char>> > t1(height,length);
                print_menu(t1);
            }
            else if(type=="D" || type=="d"){
                TetrisAdapter<deque<deque<char>> > t1(height,length);
                print_menu(t1);
            }
        }
        else if(type=="Q" || type=="q"){
            exit(0);
        }
    }
    
    

    return 0;
}

