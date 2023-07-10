#include "driver2.hpp"
#include "driver1.hpp"



using namespace std;

int main(){
    string ch="a";
    int height,length;
    cout<<"Enter the size of the board (height-length)\n";
    cin>>height>>length;
    Tetris t1(height,length);
    system("clear");
    t1.draw();
    while(ch!="Q"){ // while loop until board is full or press 'Q';
        
        cout<<"\nEnter the shape or 'Q' to exit (I,O,T,L,J,S,Z): ";
        cin>>ch;
        if(ch=="I"){
            Tetromino t(tetros:: shape_I);
            if(t1.game_over()){
                t1.Animate(t);
            }
            
        }
        else if(ch=="O"){
            Tetromino t(tetros:: shape_O);
            if(t1.game_over()){
                t1.Animate(t);
            }  
        }
        else if(ch=="T"){
            Tetromino t(tetros:: shape_T);
            if(t1.game_over()){
                t1.Animate(t);
            }  
        }
        else if(ch=="L"){
            Tetromino t(tetros:: shape_L);
            if(t1.game_over()){
                t1.Animate(t);
            }  
        }
        else if(ch=="J"){
            Tetromino t(tetros:: shape_J);
            if(t1.game_over()){
                t1.Animate(t);
            }  
        }
        else if(ch=="S"){
            Tetromino t(tetros:: shape_S);
            if(t1.game_over()){
                t1.Animate(t);
            }
        }
        else if(ch=="Z"){
            Tetromino t(tetros:: shape_Z);
            if(t1.game_over()){
                t1.Animate(t);
            }  
        }
        
        else if(ch=="Q"){
            cout<<"Good bye"<<endl;
        }
        if(!t1.game_over()){
            cout<<"The board is fulled."<<endl;
            break;
        }
    }

    return 0;
}







