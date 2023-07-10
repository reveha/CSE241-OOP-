#include "driver2.hpp"
#include "driver1.hpp"



using namespace std;
using namespace Tet;

int main(){
    string ch="a",rotate_direction,move_direction;
    int height,length,count_rotate,count_move,number;
    cout<<"Enter the size of the board (height-length)\n";
    cin>>height>>length;
    Tetris t1(height,length);
    system("clear");
    t1.draw();
    srand(time(NULL));
    while(ch!="Q"){ // while loop until board is full or press 'Q';
        cout<<"\nEnter the shape or 'Q' to exit (I,O,T,L,J,S,Z): ";
        cin>>ch;
        cin.ignore();
        if(ch=="R"){
            number=rand()%7;// according to the number choosing randomly
            //cout<<number;
        }
        if((ch=="I"||ch=="O"||ch=="T"||ch=="L"||ch=="J"||ch=="S"||ch=="Z"||ch=="R")){
            if(ch=="I"||number==0){// to add tetromino top bottom
                Tetromino t(tetros:: shape_I);
                t1+=t; 
            }
            else if(ch=="O"||number==1){// to add tetromino top bottom
                Tetromino t(tetros:: shape_O);
                t1+=t;
            }
            else if(ch=="T"||number==2){// to add tetromino top bottom
                Tetromino t(tetros:: shape_T);
                t1+=t;
            }
            else if(ch=="L"||number==3){// to add tetromino top bottom
                Tetromino t(tetros:: shape_L);
                t1+=t;
            }
            else if(ch=="J"||number==4){// to add tetromino top bottom
                Tetromino t(tetros:: shape_J);
                t1+=t;
            }
            else if(ch=="S"||number==5){// to add tetromino top bottom
                Tetromino t(tetros:: shape_S);
                t1+=t;
            }
            else if(ch=="Z"||number==6){// to add tetromino top bottom
                Tetromino t(tetros:: shape_Z);
                t1+=t;
            }
            //these while loops are to ask question to user.
            do{
                cout<<"Enter the rotate direction of the shape(R->right && L->left): ";
                cin>>rotate_direction;
                if(rotate_direction=="R"||rotate_direction=="L"){
                    break;
                }
                cerr<<"Enter just 'R' or 'L'"<<endl;
            }while(1);
            do{
                cout<<"Enter the how many times will be rotated the shape: ";
                cin>>count_rotate;
                if(count_rotate<0){
                    cerr<<"Number of rotation cannot be negative"<<endl;
                }
            }while(count_rotate<0);
            do{
                cout<<"Enter the moving direction of the shape(R->right && L->left): ";
                cin>>move_direction;
                if(move_direction=="R"||move_direction=="L"){
                    break;
                }
                cerr<<"Enter just 'R' or 'L'"<<endl;
            }while(1);
            do{
                cout<<"Enter the how many times will be moved the shape: ";
                cin>>count_move;
                if(count_move<0){
                    cerr<<"Number of moving counter cannot be negative"<<endl;
                }
            }while(count_move<0);

            count_rotate%=4;// each 4 rotation it become same shape; so i took the modula of the number of rotation
        
            if(rotate_direction=="L"){count_rotate=4-count_rotate;
                if(count_rotate==4){count_rotate=0;}// when it rotates 4 times it become original shape  
            } // my rotate function rotates to right 
    //if the user enter left, i will rotate 4-count_rotate times to rigth instead of count_rotate times to left
            
            if(ch=="I"||number==0){
                Tetromino t(tetros:: shape_I);
                if(t1.game_over()){
                    t1.Animate(t,count_move,count_rotate,move_direction);
                }
                
            }
            else if(ch=="O"||number==1){
                Tetromino t(tetros:: shape_O);
                if(t1.game_over()){
                    t1.Animate(t,count_move,count_rotate,move_direction);
                }  
            }
            else if(ch=="T"||number==2){
                Tetromino t(tetros:: shape_T);
                if(t1.game_over()){
                    t1.Animate(t,count_move,count_rotate,move_direction);
                }  
            }
            else if(ch=="L"||number==3){
                Tetromino t(tetros:: shape_L);
                if(t1.game_over()){
                    t1.Animate(t,count_move,count_rotate,move_direction);
                }  
            }
            else if(ch=="J"||number==4){
                Tetromino t(tetros:: shape_J);
                if(t1.game_over()){
                    t1.Animate(t,count_move,count_rotate,move_direction);
                }  
            }
            else if(ch=="S"||number==5){
                Tetromino t(tetros:: shape_S);
                if(t1.game_over()){
                    t1.Animate(t,count_move,count_rotate,move_direction);
                }
            }
            else if(ch=="Z"||number==6){
                Tetromino t(tetros:: shape_Z);
                if(t1.game_over()){
                    t1.Animate(t,count_move,count_rotate,move_direction);
                }  
            }
        }
        
        else if(ch=="Q"){
            cout<<"Good bye"<<endl;
        }
        else{
            cerr<<"You typed incorrectly"<<endl;
        }
        if(!t1.game_over()){
            cout<<"The board is fulled."<<endl;
            break;
        }
        number=-1;
    }

    return 0;
}

