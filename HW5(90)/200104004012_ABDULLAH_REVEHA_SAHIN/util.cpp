#include "driver1.hpp"
#include "driver2.hpp"

using namespace std;
using namespace Tet;


AbstractTetris:: AbstractTetris(int h, int l){
    /*
    THIS IS MY CONSTRUCTOR WHICH DOES ASSIGNMENT FOR (AbstractTetris::height) AND (AbstractTetris::length) AND CREATE BOARD;
    */
    (AbstractTetris::height)=h;
    (AbstractTetris::length)=l;
    //create_board();
    //fill_board();
}

AbstractTetris:: ~AbstractTetris(){
    //DESTRUCTOR WORKS
}

Tetromino:: ~Tetromino(){
    //DESTRUCTOR WORKS
    for(auto i=0;i<4;i++)
        delete[] tet[i];

    delete[] tet;
    
}
TetrisVector::TetrisVector(int h, int l): AbstractTetris(h,l){
    create_board();
    fill_board();
}
TetrisVector::~TetrisVector(){
    board.clear();
}

void TetrisVector::writeToFile(fstream &file){
    // Writing the datas into file
    file.open("tetrisgame.txt",ios::out);
    file<<AbstractTetris::height<<" "<<AbstractTetris::length<<" ";
    for(auto i:board){
        for(auto j:i){
            file<<j;
        }
    }
    file.close();
}

void TetrisVector::readFromFile(fstream &file){
    file.open("tetrisgame.txt",ios::in);
    file>>AbstractTetris::height>>AbstractTetris::length;
    create_board();
    for(auto i=0;i<AbstractTetris::height;i++){
        for(auto j=0;j<AbstractTetris::length;j++){
            file>>board[i][j];
        }
    }
    file.close();
}

TetrisVector& TetrisVector:: operator+=(Tetromino &shape){
    /*
    NEW Add() FUNCTION ADDS THE TETROMINO TO THE BOARD ACCORDING TO THE ITS SHAPE
    ONLY IF THE BOARD IS AVALIABLE TO PRINT TOP BOTTOM
    */
    this->last_tetro=shape.getKey();
    if(shape.getKey()=='I'){
        if(board[1][((AbstractTetris::length)/2)-2]=='.'&&board[1][((AbstractTetris::length)/2)-1]=='.'&&board[1][((AbstractTetris::length)/2)]=='.'&&board[1][((AbstractTetris::length)/2)+1]=='.'){
            board[1][((AbstractTetris::length)/2)-2]='I';
            board[1][((AbstractTetris::length)/2)-1]='I';
            board[1][((AbstractTetris::length)/2)]='I';
            board[1][((AbstractTetris::length)/2)+1]='I';
            shape.setAdd(true); // that means the shape are printed the top bottom screen
        }
        else{
            shape.setAdd(false);//that means i couldn't do it
        } 
    }
    else if(shape.getKey()=='O'){
        if(board[1][((AbstractTetris::length)/2)-1]=='.'&&board[2][((AbstractTetris::length)/2)-1]=='.'&&board[1][((AbstractTetris::length)/2)]=='.'&&board[2][((AbstractTetris::length)/2)]=='.'){
            board[1][((AbstractTetris::length)/2)-1]='O';
            board[2][((AbstractTetris::length)/2)-1]='O';
            board[1][((AbstractTetris::length)/2)]='O';
            board[2][((AbstractTetris::length)/2)]='O';
            
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        } 
    }
    else if(shape.getKey()=='T'){
        if(board[1][(AbstractTetris::length)/2]=='.'&&board[1][((AbstractTetris::length)/2)-1]=='.'&&board[1][((AbstractTetris::length)/2)+1]=='.'&&board[2][(AbstractTetris::length)/2]=='.'){
            board[1][(AbstractTetris::length)/2]='T';
            board[1][((AbstractTetris::length)/2)-1]='T';
            board[1][((AbstractTetris::length)/2)+1]='T';
            board[2][(AbstractTetris::length)/2]='T';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }       
    }
    else if(shape.getKey()=='J'){
        if(board[1][(AbstractTetris::length)/2]=='.'&&board[2][(AbstractTetris::length)/2]=='.'&&board[3][(AbstractTetris::length)/2]=='.'&&board[3][((AbstractTetris::length)/2)-1]=='.'){
            board[1][(AbstractTetris::length)/2]='J';
            board[2][(AbstractTetris::length)/2]='J';
            board[3][(AbstractTetris::length)/2]='J';
            board[3][((AbstractTetris::length)/2)-1]='J';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }
    }
    else if(shape.getKey()=='L'){
        if(board[1][(AbstractTetris::length)/2]=='.'&&board[2][(AbstractTetris::length)/2]=='.'&&board[3][(AbstractTetris::length)/2]=='.'&&board[3][((AbstractTetris::length)/2)+1]=='.'){
            board[1][(AbstractTetris::length)/2]='L';
            board[2][(AbstractTetris::length)/2]='L';
            board[3][(AbstractTetris::length)/2]='L';
            board[3][((AbstractTetris::length)/2)+1]='L';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }
    }
    else if(shape.getKey()=='S'){
        if(board[1][(AbstractTetris::length)/2]=='.'&&board[2][(AbstractTetris::length)/2]=='.'&&board[1][((AbstractTetris::length)/2)+1]=='.'&&board[2][((AbstractTetris::length)/2)-1]=='.'){
            board[1][(AbstractTetris::length)/2]='S';
            board[2][(AbstractTetris::length)/2]='S';
            board[1][((AbstractTetris::length)/2)+1]='S';
            board[2][((AbstractTetris::length)/2)-1]='S';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }
    }
    else if(shape.getKey()=='Z'){
        if(board[1][(AbstractTetris::length)/2]=='.'&&board[2][(AbstractTetris::length)/2]=='.'&&board[1][((AbstractTetris::length)/2)-1]=='.'&&board[2][((AbstractTetris::length)/2)+1]=='.'){
            board[1][(AbstractTetris::length)/2]='Z';
            board[2][(AbstractTetris::length)/2]='Z';
            board[1][((AbstractTetris::length)/2)-1]='Z';
            board[2][((AbstractTetris::length)/2)+1]='Z';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }
    }
    draw();
    return *this;
}


void TetrisVector:: rotate_added_shape(const Tetromino &shape){
    //WHEN I NEED TO ROTATE A TETROMINO
    // I PRINT IT AFTER Add() FUNCTION
    //SO, IN THIS FUNCTION I NEED TO CLEAR UNROTATED TETROMINO FROM THE TOP MIDDLE
    for(auto i=1;i<4;i++){
        for(auto j=1;j<(AbstractTetris::length)-1;j++){
            if(shape.getKey()=='I' && shape.getAdd()){
                    board[1][((AbstractTetris::length)/2)-2]='.';
                    board[1][((AbstractTetris::length)/2)-1]='.';
                    board[1][((AbstractTetris::length)/2)]='.';
                    board[1][((AbstractTetris::length)/2)+1]='.';
            }
            else if(shape.getKey()=='O' && shape.getAdd()){
                    board[1][((AbstractTetris::length)/2)-1]='.';
                    board[2][((AbstractTetris::length)/2)-1]='.';
                    board[1][((AbstractTetris::length)/2)]='.';
                    board[2][((AbstractTetris::length)/2)]='.';
            }
            else if(shape.getKey()=='T' && shape.getAdd()){
                    board[1][(AbstractTetris::length)/2]='.';
                    board[1][((AbstractTetris::length)/2)-1]='.';
                    board[1][((AbstractTetris::length)/2)+1]='.';
                    board[2][(AbstractTetris::length)/2]='.';
            }
            else if(shape.getKey()=='J' && shape.getAdd()){
                    board[1][(AbstractTetris::length)/2]='.';
                    board[2][(AbstractTetris::length)/2]='.';
                    board[3][(AbstractTetris::length)/2]='.';
                    board[3][((AbstractTetris::length)/2)-1]='.';
            }
            else if(shape.getKey()=='L' && shape.getAdd()){
                    board[1][(AbstractTetris::length)/2]='.';
                    board[2][(AbstractTetris::length)/2]='.';
                    board[3][(AbstractTetris::length)/2]='.';
                    board[3][((AbstractTetris::length)/2)+1]='.';
            }
            else if(shape.getKey()=='S' && shape.getAdd()){
                    board[1][(AbstractTetris::length)/2]='.';
                    board[2][(AbstractTetris::length)/2]='.';
                    board[1][((AbstractTetris::length)/2)+1]='.';
                    board[2][((AbstractTetris::length)/2)-1]='.';
            }
            else if(shape.getKey()=='Z' && shape.getAdd()){
                    board[1][(AbstractTetris::length)/2]='.';
                    board[2][(AbstractTetris::length)/2]='.';
                    board[1][((AbstractTetris::length)/2)-1]='.';
                    board[2][((AbstractTetris::length)/2)+1]='.';
            }
        }
    }
}






void TetrisVector:: Animate(Tetromino &shape, int count_move, int count_rotate, string direction){
    /*
    1. Draw the board with Tetromino at the top 
    2. Ask the user rotation direction and rotation count 
    3. Ask the user move direction and count 
    4. Rotate and move the Tetromino 
    5. Draw the board 
    6. Sleep 50 miliseconds
    7. Lower the Tetromino one level and go to step 5 until it hits the bottom.
    */
    for(auto i=0;i<count_rotate;i++){// ROTATING THE SHAPES THE USER ENTERED COUNT TIMES
        shape.rotate();
    }
    //*this+=shape; // operator overloading to add tetromino the top bottom
    //draw();
    clear_top(shape);
    *this+=shape;
    try{
        if(check_index(shape,count_move,direction)){// THAT MEANS THE SHAPE WITH ROTATED FORM CAN BE FITTED TO THE BOARD
            move_animation(shape);
            clear();
            draw();
        } 
        else{
            
            clear_top(shape);
            throw "\nThe shape cannot be fitted that index\n";
            //draw();
        }
        
    }
    catch(string str){
        cout<<str<<endl;
    }
    
}
void TetrisVector:: clear_top(const Tetromino &shape){
    // WHEN THE TETROMINO CANNOT BE FITTED THE INDEXES OF USER ENTERED, I NEED TO CLEAR TETROMINO FROM THE TOP BOTTOM
    //SINCE EVERY TETROMINO HAS DIFFERENT INDEXES, I CHECK EACH ONE
    if(shape.getKey()=='I'){
        board[1][((AbstractTetris::length)/2)-2]='.'; board[1][((AbstractTetris::length)/2)-1]='.';
        board[1][((AbstractTetris::length)/2)]='.'; board[1][((AbstractTetris::length)/2)+1]='.';
    }
    else if(shape.getKey()=='O'){
        board[1][((AbstractTetris::length)/2)-1]='.'; board[1][((AbstractTetris::length)/2)]='.';
        board[2][((AbstractTetris::length)/2)-1]='.'; board[2][((AbstractTetris::length)/2)]='.';
    }
    else if(shape.getKey()=='T'){
        board[2][((AbstractTetris::length)/2)]='.'; board[1][((AbstractTetris::length)/2)]='.';
        board[1][((AbstractTetris::length)/2)-1]='.'; board[1][((AbstractTetris::length)/2)+1]='.';
    }
    else if(shape.getKey()=='J'){
        board[3][((AbstractTetris::length)/2)-1]='.'; board[3][((AbstractTetris::length)/2)]='.';
        board[2][((AbstractTetris::length)/2)]='.'; board[1][((AbstractTetris::length)/2)]='.';
    }
    else if(shape.getKey()=='L'){
        board[3][((AbstractTetris::length)/2)]='.'; board[2][((AbstractTetris::length)/2)]='.';
        board[1][((AbstractTetris::length)/2)]='.'; board[3][((AbstractTetris::length)/2)+1]='.';
    }
    else if(shape.getKey()=='S'){
        board[2][((AbstractTetris::length)/2)-1]='.'; board[2][((AbstractTetris::length)/2)]='.';
        board[1][((AbstractTetris::length)/2)]='.'; board[1][((AbstractTetris::length)/2)+1]='.';
    }
    else if(shape.getKey()=='Z'){
        board[2][((AbstractTetris::length)/2)]='.'; board[2][((AbstractTetris::length)/2)+1]='.';
        board[1][((AbstractTetris::length)/2)]='.'; board[1][((AbstractTetris::length)/2)-1]='.';
    }
}
bool TetrisVector:: check_index(const Tetromino &shape, int count, string direction){
    //these function to get indexes the user want;
    //for example shape is T tetromino without rotated;
    //user wants to move it 2 times to right;
    //i check the downest index the shape can be fitted;
    //and i keep that index in my (AbstractTetris::index_x) and (AbstractTetris::index_y) variables which is coming from AbstractTetris class
    try{
        if(((AbstractTetris::length)/2)+count>(AbstractTetris::length)){
            cerr<<"Out of the range!\n"<<endl;
            throw false;
        }
    }
    catch(bool check){
        return check;
    }
    if(direction=="L"){
        count*=-1;
    }
            if(shape.getKey()=='I'){
                    for(auto i=(AbstractTetris::height)-1;i>0;i--){
                        if(board[i][((AbstractTetris::length)/2)-2+count]=='.'&&board[i][((AbstractTetris::length)/2)-1+count]=='.'&&
                        board[i][((AbstractTetris::length)/2)+count]=='.'&&board[i][((AbstractTetris::length)/2)+1+count]=='.'&&
                        (shape.getRotated()==0||shape.getRotated()==2)){
                            //The if for I tetromino which is not rotated;
                            (AbstractTetris::index_y)=((AbstractTetris::length)/2)-2+count;
                            (AbstractTetris::index_x)=i;
                            return true;
                            
                    }
                    else if(board[i][((AbstractTetris::length)/2)+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+count]=='.'&&
                    board[i-2][((AbstractTetris::length)/2)+count]=='.'&&board[i-3][((AbstractTetris::length)/2)+count]=='.'&&
                    (shape.getRotated()==1||shape.getRotated()==3)){
                        //The if for I tetromino which is rotated;
                        (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                        (AbstractTetris::index_x)=i;
                        return true;
                    }
                }
        }
        else if(shape.getKey()=='O'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[i][((AbstractTetris::length)/2)-1+count]=='.'&&board[i][((AbstractTetris::length)/2)+count]=='.'&&
                board[i-1][((AbstractTetris::length)/2)-1+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+count]=='.'){
                    //The if for O tetromino
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
        else if(shape.getKey()=='T'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[i][((AbstractTetris::length)/2)+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+count]=='.'&&
                board[i-1][((AbstractTetris::length)/2)-1+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+1+count]=='.'&&
                shape.getRotated()==0){
                    //The if for T tetromino which is not rotated;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[i][((AbstractTetris::length)/2)+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+count]=='.'&&
                board[i-1][((AbstractTetris::length)/2)-1+count]=='.'&&board[i-2][((AbstractTetris::length)/2)+count]=='.'&&
                shape.getRotated()==1){
                    //The if for T tetromino which is rotated 1 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[i][((AbstractTetris::length)/2)-1+count]=='.'&&board[i][((AbstractTetris::length)/2)+count]=='.'&&
                board[i][((AbstractTetris::length)/2)+1+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+count]=='.'&&
                shape.getRotated()==2){
                    //The if for T tetromino which is rotated 2 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[i][((AbstractTetris::length)/2)+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+count]=='.'&&
                board[i-1][((AbstractTetris::length)/2)+1+count]=='.'&&board[i-2][((AbstractTetris::length)/2)+count]=='.'&&
                shape.getRotated()==3){
                    //The if for T tetromino which is rotated 3 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
        else if(shape.getKey()=='J'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[i][((AbstractTetris::length)/2)-1+count]=='.'&&board[i][((AbstractTetris::length)/2)+count]=='.'&&
                board[i-1][((AbstractTetris::length)/2)+count]=='.'&&board[i-2][((AbstractTetris::length)/2)+count]=='.'&&
                shape.getRotated()==0){
                    //The if for J tetromino which is rotated 0 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[i][((AbstractTetris::length)/2)-1+count]=='.'&&board[i][((AbstractTetris::length)/2)+count]=='.'&&
                board[i][((AbstractTetris::length)/2)+1+count]=='.'&&board[i-1][((AbstractTetris::length)/2)-1+count]=='.'&&
                shape.getRotated()==1){
                    //The if for J tetromino which is rotated 1 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[i][((AbstractTetris::length)/2)-1+count]=='.'&&board[i-1][((AbstractTetris::length)/2)-1+count]=='.'&&
                board[i-2][((AbstractTetris::length)/2)-1+count]=='.'&&board[i-2][((AbstractTetris::length)/2)+count]=='.'&&
                shape.getRotated()==2){
                    //The if for J tetromino which is rotated 2 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[i][((AbstractTetris::length)/2)+1+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+1+count]=='.'&&
                board[i-1][((AbstractTetris::length)/2)+count]=='.'&&board[i-1][((AbstractTetris::length)/2)-1+count]=='.'&&
                shape.getRotated()==3){
                    //The if for J tetromino which is rotated 3 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
        else if(shape.getKey()=='L'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[i][((AbstractTetris::length)/2)+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+count]=='.'&&
                board[i-2][((AbstractTetris::length)/2)+count]=='.'&&board[i][((AbstractTetris::length)/2)+1+count]=='.'&&
                shape.getRotated()==0){
                    //The if for L tetromino which is rotated 0 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[i][((AbstractTetris::length)/2)-1+count]=='.'&&board[i-1][((AbstractTetris::length)/2)-1+count]=='.'&&
                board[i-1][((AbstractTetris::length)/2)+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+1+count]=='.'&&
                shape.getRotated()==1){
                    //The if for L tetromino which is rotated 1 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[i][((AbstractTetris::length)/2)+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+count]=='.'&&
                board[i-2][((AbstractTetris::length)/2)+count]=='.'&&board[i-2][((AbstractTetris::length)/2)-1+count]=='.'&&
                shape.getRotated()==2){
                    //The if for L tetromino which is rotated 2 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[i][((AbstractTetris::length)/2)-1+count]=='.'&&board[i][((AbstractTetris::length)/2)+count]=='.'&&
                board[i][((AbstractTetris::length)/2)+1+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+1+count]=='.'&&
                shape.getRotated()==3){
                    //The if for L tetromino which is rotated 3 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
        else if(shape.getKey()=='S'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[i][((AbstractTetris::length)/2)-1+count]=='.'&&board[i][((AbstractTetris::length)/2)+count]=='.'&&
                board[i-1][((AbstractTetris::length)/2)+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+1+count]=='.'&&
                (shape.getRotated()==0||shape.getRotated()==2)){
                    //The if for S tetromino which is rotated 0 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[i][((AbstractTetris::length)/2)+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+count]=='.'&&
                board[i-1][((AbstractTetris::length)/2)-1+count]=='.'&&board[i-2][((AbstractTetris::length)/2)-1+count]=='.'&&
                (shape.getRotated()==1||shape.getRotated()==3)){
                    //The if for S tetromino which is rotated 1 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
        else if(shape.getKey()=='Z'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[i][((AbstractTetris::length)/2)+count]=='.'&&board[i][((AbstractTetris::length)/2)+1+count]=='.'&&
                board[i-1][((AbstractTetris::length)/2)+count]=='.'&&board[i-1][((AbstractTetris::length)/2)-1+count]=='.'&&
                (shape.getRotated()==0||shape.getRotated()==2)){
                    //The if for Z tetromino which is rotated 0 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[i][((AbstractTetris::length)/2)+count]=='.'&&board[i-1][((AbstractTetris::length)/2)+count]=='.'&&
                board[i-1][((AbstractTetris::length)/2)+1+count]=='.'&&board[i-2][((AbstractTetris::length)/2)+1+count]=='.'&&
                (shape.getRotated()==1||shape.getRotated()==3)){
                    //The if for Z tetromino which is rotated 1 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
    return false;
}

bool TetrisVector:: game_over()const{
    //CHECKING IF THE BOARD IS FULL OR NOT
    int counter=0;
    for(auto j=1;j<(AbstractTetris::length)-1;j++){
        if(board[2][j]!='.'){
            counter++;
        }
    }
    if(counter>((AbstractTetris::length)/2)){
        return false;
    }
    return true;
}

void TetrisVector::create_board(){
    //CREATING A BOARD WITH SIZES
	int i=0;
	board.resize((AbstractTetris::height));
	for (int i = 0; i <(AbstractTetris::height); ++i)
        board[i].resize((AbstractTetris::length));
}

void TetrisVector:: fill_board(){
    // FILLING THE EMPTY BOARD WITH SIZES
    for(auto i=0;i<(AbstractTetris::height);i++){ 
        for(auto j=0;j<(AbstractTetris::length);j++){

            if(j==0 || j==(AbstractTetris::length)-1){
                board[i][j]='X';
            }
            else if(i==0 || i==(AbstractTetris::height)-1){
                board[i][j]='X';
            }
            else{
                board[i][j]='.';
            }
        }
    }
}

void TetrisVector:: clear(){
    //this function to clear horizantal fully tables;
    //also it moves every index to down
    int counter=0;
    for(auto i=(AbstractTetris::height)-2;i>0;i--){
        for(auto j=1;j<(AbstractTetris::length)-1;j++){
            if(board[i][j]!='.'){counter++;}
        }
        if(counter==(AbstractTetris::length)-2){
            for(auto k=i-1;k>0;k--){
                for(auto t=1;t<(AbstractTetris::length)-1;t++){
                    board[k+1][t]=board[k][t];
                }
            }
            for(auto t=1;t<(AbstractTetris::length)-1;t++){
                board[1][t]='.';
            }
            i=(AbstractTetris::height)-1;
        }
        counter=0;
    }
}

void TetrisVector:: draw() const{
    // MY DRAW FUNCTION, DRAWING THE BOARD WITH TETROMINOS
    usleep(500000);
    system("clear");

    for(auto i=0;i<(AbstractTetris::height);i++){
        for(auto j=0;j<(AbstractTetris::length);j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

void TetrisVector:: fill_just_y_indexes(const Tetromino &shape){
    // THIS FUNCTION IS TO CHECK IF THERE IS ANY COLLUSION WHEN I MOVE THE TETROMINO RIGHT OR LEFT
    // IF THERE IS A COLLUSION, I PRINT THE TETROMINO JUST CORRECT INDEX WITHOUT MOVING...
    // I NEED TO CHECK EVERY SHAPE AND DIRECTION OF THE SHAPE.
    if(shape.getKey()=='I'){
        if(shape.getRotated()==0){
            board[1][(AbstractTetris::index_y)]='I';
            board[1][(AbstractTetris::index_y)+1]='I';
            board[1][(AbstractTetris::index_y)+1]='I';
            board[1][(AbstractTetris::index_y)+1]='I';
        }
        else if(shape.getRotated()==1){
            board[1][(AbstractTetris::index_y)]='I';
            board[2][(AbstractTetris::index_y)]='I';
            board[3][(AbstractTetris::index_y)]='I';
            board[4][(AbstractTetris::index_y)]='I';
        }
    }
    else if(shape.getKey()=='O'){
        board[2][(AbstractTetris::index_y)]='O';
        board[2][(AbstractTetris::index_y)+1]='O';
        board[1][(AbstractTetris::index_y)]='O';
        board[1][(AbstractTetris::index_y)+1]='O';
    }
    else if(shape.getKey()=='T'){
        if(shape.getRotated()==0){
            board[2][(AbstractTetris::index_y)]='T';
            board[1][(AbstractTetris::index_y)]='T';
            board[1][(AbstractTetris::index_y)-1]='T';
            board[1][(AbstractTetris::index_y)+1]='T';
        }
        else if(shape.getRotated()==1){
            board[3][(AbstractTetris::index_y)]='T';
            board[2][(AbstractTetris::index_y)]='T';
            board[2][(AbstractTetris::index_y)-1]='T';
            board[1][(AbstractTetris::index_y)]='T';
        }
        else if(shape.getRotated()==2){
            board[2][(AbstractTetris::index_y)]='T';
            board[2][(AbstractTetris::index_y)+1]='T';
            board[2][(AbstractTetris::index_y)+2]='T';
            board[1][(AbstractTetris::index_y)+1]='T';
        }
        else if(shape.getRotated()==3){
            board[3][(AbstractTetris::index_y)]='T';
            board[2][(AbstractTetris::index_y)]='T';
            board[2][(AbstractTetris::index_y)+1]='T';
            board[1][(AbstractTetris::index_y)]='T';
        }
    }
    else if(shape.getKey()=='L'){
        if(shape.getRotated()==0){
            board[3][(AbstractTetris::index_y)]='L';
            board[3][(AbstractTetris::index_y)+1]='L';
            board[2][(AbstractTetris::index_y)]='L';
            board[1][(AbstractTetris::index_y)]='L';
        }
        else if(shape.getRotated()==1){
            board[2][(AbstractTetris::index_y)]='L';
            board[1][(AbstractTetris::index_y)]='L';
            board[1][(AbstractTetris::index_y)+1]='L';
            board[1][(AbstractTetris::index_y)+1]='L';
        }
        else if(shape.getRotated()==2){
            board[3][(AbstractTetris::index_y)]='L';
            board[2][(AbstractTetris::index_y)]='L';
            board[1][(AbstractTetris::index_y)]='L';
            board[1][(AbstractTetris::index_y)-1]='L';
        }
        else if(shape.getRotated()==3){
            board[2][(AbstractTetris::index_y)]='L';
            board[2][(AbstractTetris::index_y)+1]='L';
            board[2][(AbstractTetris::index_y)+2]='L';
            board[1][(AbstractTetris::index_y)]='L';
        }
    }
    else if(shape.getKey()=='J'){
        if(shape.getRotated()==0){
            board[3][(AbstractTetris::index_y)]='J';
            board[3][(AbstractTetris::index_y)+1]='J';
            board[2][(AbstractTetris::index_y)+1]='J';
            board[1][(AbstractTetris::index_y)+1]='J';
        }
        else if(shape.getRotated()==1){
            board[2][(AbstractTetris::index_y)]='J';
            board[2][(AbstractTetris::index_y)+1]='J';
            board[2][(AbstractTetris::index_y)+2]='J';
            board[1][(AbstractTetris::index_y)]='J';
        }
        else if(shape.getRotated()==2){
            board[3][(AbstractTetris::index_y)]='J';
            board[2][(AbstractTetris::index_y)]='J';
            board[1][(AbstractTetris::index_y)]='J';
            board[1][(AbstractTetris::index_y)+1]='J';
        }
        else if(shape.getRotated()==3){
            board[2][(AbstractTetris::index_y)]='J';
            board[1][(AbstractTetris::index_y)]='J';
            board[1][(AbstractTetris::index_y)-1]='J';
            board[1][(AbstractTetris::index_y)-2]='J';
        }
    }
    else if(shape.getKey()=='S'){
        if(shape.getRotated()==0){
            board[2][(AbstractTetris::index_y)]='S';
            board[2][(AbstractTetris::index_y)+1]='S';
            board[1][(AbstractTetris::index_y)+1]='S';
            board[1][(AbstractTetris::index_y)+2]='S';
        }
        else if(shape.getRotated()==1){
            board[3][(AbstractTetris::index_y)]='S';
            board[2][(AbstractTetris::index_y)]='S';
            board[2][(AbstractTetris::index_y)-1]='S';
            board[1][(AbstractTetris::index_y)-1]='S';
        }
    }
    else if(shape.getKey()=='Z'){
        if(shape.getRotated()==0){
            board[2][(AbstractTetris::index_y)]='Z';
            board[2][(AbstractTetris::index_y)+1]='Z';
            board[1][(AbstractTetris::index_y)]='Z';
            board[1][(AbstractTetris::index_y)-1]='Z';
        }
        else if(shape.getRotated()==1){
            board[3][(AbstractTetris::index_y)]='Z';
            board[2][(AbstractTetris::index_y)]='Z';
            board[2][(AbstractTetris::index_y)+1]='Z';
            board[1][(AbstractTetris::index_y)+1]='Z';
        }
    }
}

void TetrisVector:: fill_indexes(const Tetromino &shape){
    // THIS FUNCTION IS TO CHECK IF THERE IS ANY COLLUSION WHEN I MOVE THE TETROMINO
    // IF THERE IS A COLLUSION, I PRINT THE TETROMINO JUST CORRECT INDEX WITHOUT MOVING...
    // I NEED TO CHECK EVERY SHAPE AND DIRECTION OF THE SHAPE.
    if(shape.getKey()=='I'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='I';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+1]='I';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+2]='I';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+3]='I';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='I';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='I';
            board[(AbstractTetris::index_x)-2][(AbstractTetris::index_y)]='I';
            board[(AbstractTetris::index_x)-3][(AbstractTetris::index_y)]='I';
        }
    }
    else if(shape.getKey()=='O'){
        board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='O';
        board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+1]='O';
        board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='O';
        board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)+1]='O';
    }
    else if(shape.getKey()=='T'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)-1]='T';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)+1]='T';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)-1]='T';
            board[(AbstractTetris::index_x)-2][(AbstractTetris::index_y)]='T';
        }
        else if(shape.getRotated()==2){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+1]='T';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+2]='T';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)+1]='T';
        }
        else if(shape.getRotated()==3){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)+1]='T';
            board[(AbstractTetris::index_x)-2][(AbstractTetris::index_y)]='T';
        }
    }
    else if(shape.getKey()=='L'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+1]='L';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::index_x)-2][(AbstractTetris::index_y)]='L';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)+1]='L';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)+1]='L';
        }
        else if(shape.getRotated()==2){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::index_x)-2][(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::index_x)-2][(AbstractTetris::index_y)-1]='L';
        }
        else if(shape.getRotated()==3){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+1]='L';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+2]='L';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)+2]='L';
        }
    }
    else if(shape.getKey()=='J'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+1]='J';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)+1]='J';
            board[(AbstractTetris::index_x)-2][(AbstractTetris::index_y)+1]='J';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+1]='J';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+2]='J';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='J';
        }
        else if(shape.getRotated()==2){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::index_x)-2][(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::index_x)-2][(AbstractTetris::index_y)+1]='J';
        }
        else if(shape.getRotated()==3){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)-1]='J';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)-2]='J';
        }
    }
    else if(shape.getKey()=='S'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='S';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+1]='S';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)+1]='S';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)+2]='S';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='S';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='S';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)-1]='S';
            board[(AbstractTetris::index_x)-2][(AbstractTetris::index_y)-1]='S';
        }
    }
    else if(shape.getKey()=='Z'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='Z';
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)+1]='Z';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='Z';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)-1]='Z';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::index_x)][(AbstractTetris::index_y)]='Z';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)]='Z';
            board[(AbstractTetris::index_x)-1][(AbstractTetris::index_y)+1]='Z';
            board[(AbstractTetris::index_x)-2][(AbstractTetris::index_y)+1]='Z';
        }
    }
}




//HW1 DECLERATIONS
Tetromino:: Tetromino(enum tetros shape){
        tet=new char*[4]; // allocating new tetromino
        for(auto i=0;i<4;i++)
            tet[i]=new char[4];


        for(auto i=0;i<4;i++){
            for(auto j=0;j<4;j++){
                tet[i][j]='.';
            }
        }
        // initilazing tetrominos
        if(static_cast<char>(shape)=='I'){
            keyword='I';
            tet[3][0]='I'; tet[3][1]='I'; tet[3][2]='I'; tet[3][3]='I';
        }
        else if(static_cast<char>(shape)=='O'){
            keyword='O';
            tet[2][0]='O'; tet[2][1]='O'; tet[3][0]='O'; tet[3][1]='O';
        }
        else if(static_cast<char>(shape)=='T'){
            keyword='T';
            tet[2][0]='T'; tet[2][1]='T'; tet[2][2]='T'; tet[3][1]='T';
        }
        else if(static_cast<char>(shape)=='J'){
            keyword='J';
            tet[1][1]='J'; tet[2][1]='J'; tet[3][1]='J'; tet[3][0]='J';
        }
        else if(static_cast<char>(shape)=='L'){
            keyword='L';
            tet[1][0]='L'; tet[2][0]='L'; tet[3][0]='L'; tet[3][1]='L';
        }
        else if(static_cast<char>(shape)=='S'){
            keyword='S';
            tet[3][0]='S'; tet[3][1]='S'; tet[2][1]='S'; tet[2][2]='S';
        }
        else if(static_cast<char>(shape)=='Z'){
            keyword='Z';
            tet[2][0]='Z'; tet[2][1]='Z'; tet[3][1]='Z'; tet[3][2]='Z';
        }
        
    }

Tetromino& Tetromino::  operator=(char **temp){ // operator overloading for two 2d char array
    // to assign two 2d char array;  for example: char **temp=char **temp2;
    for(auto i=0;i<4;i++){
        for(auto j=0;j<4;j++){
            this->tet[i][j]=temp[i][j];
        }
    }
    return *this;
}


void Tetromino:: rotate(){
        /*
WHEN I ROTATE A SHAPE I USE THIS WAY

0000
0000   
TTT0
0T00

WHEN I WANT TO ROTATE RIGHT AT ONCE THIS SHAPE MY FUNCTION GIVES ME THIS

0T00
TT00
0T00
0000

SINCE I WANT TO EVERY SHAPE LEFT BOTTOM I HAVE TO FIX SOME INDEX PROBLEMS

WHEN I FIX THESE PROBLEMS MY SHAPE WILL BE LIKE THIS

0000
0T00
TT00
0T00

IN ROTATE FUNCTION I AM DOING THESE FIXING INDEXES OPERATIONS


*/
    // 2D char array initilazing dynamically
        char **temp=new char*[4];
        for(auto i=0;i<4;i++)
            temp[i]=new char[4];
        int index=N-1;
        if(keyword=='I'){ // for each shape there are some speacial index cases, i check here this cases
            if(temp[1][0]!='I'){ //THESE FOR LOOPS ARE TO REPAIR WRONG INDEXES
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='I'){
                        //cout<<i<<endl<<j<<endl;
                            temp[i+3][j]='I';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            
            *this=temp; // operator overloading
            rotated++;
        }
        else if(keyword=='T'){  // for each shape there are some speacial index cases, i check here this cases
                if(rotated==0){ // checking to understand current rotate of the shape
                    for(auto i=N-1;i>=0;i--){
                        for(auto j=N-1;j>=0;j--){
                            if(temp[i][j]=='T'){
                                //cout<<i<<endl<<j<<endl;
                                temp[i+1][j]='T';
                                temp[i][j]='.';
                            }
                        }      
                    }     
                }
                else if(rotated==1){
                    //cout<<"hellow"<<endl; 
                    for(auto i=N-1;i>=0;i--){
                        for(auto j=N-1;j>=0;j--){
                            if(temp[i][j]=='T'){
                                //cout<<i<<endl<<j<<endl;
                                temp[i+2][j]='T';
                                temp[i][j]='.';
                            }
                        }      
                    } 
                }
                else if(rotated==2){
                    for(auto i=N-1;i>=0;i--){
                        for(auto j=N-1;j>=0;j--){
                            if(temp[i][j]=='T'){
                                //cout<<i<<endl<<j<<endl;
                                temp[i+1][j]='T';
                                temp[i][j]='.';
                            }
                        }      
                    } 
                }
                else{
                    for(auto i=N-1;i>=0;i--){
                        for(auto j=N-1;j>=0;j--){
                            if(temp[i][j]=='T'){
                                //cout<<i<<endl<<j<<endl;
                                temp[i+2][j]='T';
                                temp[i][j]='.';
                            }
                        }      
                    } 
                }
                
            *this=temp; // operator overloading
            rotated++;
        }
        else if(keyword=='J'){
            if(rotated==0){
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='J'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+2][j]='J';
                            temp[i][j]='.';
                        }
                    }      
                }  
            }
            else if(rotated==1){
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='J'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+1][j]='J';
                            temp[i][j]='.';
                        }
                    }      
                }  
            }
            else{
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='J'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+1][j]='J';
                            temp[i][j]='.';
                        }
                    }      
                } 
            }
            *this=temp; // operator overloading   
            rotated++;
        }
        else if(keyword=='L'){
            if(rotated==0){
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='L'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+2][j]='L';
                            temp[i][j]='.';
                        }
                    }      
                } 
            }
            else if(rotated==1){
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='L'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+1][j]='L';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            else if(rotated==2){
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='L'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+2][j]='L';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            else{
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='L'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+1][j]='L';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            *this=temp; // operator overloading
            rotated++;
        }
        else if(keyword=='S'){
            if(rotated==0){
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='S'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+1][j]='S';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            else{
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='S'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+2][j]='S';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            *this=temp; // operator overloading
            rotated++;
        }
        else if(keyword=='Z'){
            if(rotated==0){
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='Z'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+1][j]='Z';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            else{
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='Z'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+2][j]='Z';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            rotated++;
            *this=temp; // operator overloading
        }
        //DELETING THE TEMP 2D CHAR ARRAY
        for(auto i=0;i<4;i++)
            delete[] temp[i];
        delete[] temp;
    }


void TetrisVector:: move_animation(Tetromino &shape){
    /*
    THIS FUNCTION IS SO BAD BUT IT IS WORKING..
    WHY I SAID SO BAD BECAUSE IT IS ABOUT 1100 LINES..
    I TRY TO EXPLAIN THIS FUNCTION..

    AS YOU CAN UNDERSTAND THE NAME OF FUNCTION, THIS FUNCTION SUBJECT IS ANIMATION OF THE MOVING...
    SINCE EVERY SHAPE AND DIRECTIONS HAVE DIFFERENT INDEXES WHEN I MOVE THEM..7
    THERE ARE SO MANY IF CASES AND FOR LOOPS IN THIS FUNCTION TO GET CORRECT INDEXES WHEN I MOVE A TETROMINO..
    
    FOR EXAMPLE:
    THE TETROMINO IS 'T' TETROMINO
    I CHECK ITS DIRECTION
    IF IT IS NOT ROTATED OR IF IT IS ROTATED ONCE RIGHT OR IF IT IS ROTATED ONCE LEFT
    I MEAN I CHECK EVERY ROTATED CASE OF THE SHAPES..
    ACCORDING TO THE IF CASES I USE FOR LOOPS WHICH STARTING POINTS AND END POINTS ARE DIFFERENT FROM EACH OTHER..
    YOU MAY SAY WHY DID NOT YOU USE ANOTHER FUNCTION FOR LOOPS,
    AS I SAID EVERY FUNCTION HAS DIFFERENT STARTING AND END POINT
    
    I WRITE IN 2 LOOP WHAT IT DOES.. SINCE FUNCTION SO LONG YOU CAN ASSUME THAT OTHER FUNCTIONS DOES SAME THING
    WITH DIFFERENT SHAPES AND INDEXES...
    */
    if(shape.getKey()=='I'){
        if(shape.getRotated()==0){// THAT MEANS IT IS NOT ROTATED
            if(!shape.getAdd()){ // THAT MEANNS Add() FUNCTION DIDNOT WORK SO, THERE WILL BE COLLUSION IF I PRINT TOP BOTTOM. I NEED TO PRINT ITS BEST INDEXES.
                fill_indexes(shape);
                draw();
                return;
            }
            draw();          
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-2){
                // THIS IF TO UNDERSTAND WILL I MOVE THE SHAPE TO THE RIGHT OR LEFT!!!/ IF IS TRUE I WILL MOVE LEFT
                for(auto j=((AbstractTetris::length)/2)-2;j>(AbstractTetris::index_y);j--){
                    // THIS FOR LOOP TO MOVE TO THE LEFT
                    board[1][j]='.';
                    board[1][j+1]='.';
                    board[1][j+2]='.';
                    board[1][j+3]='.';
                    if(board[1][j-1]!='.'||board[1][j]!='.'||board[1][j+1]!='.'||board[1][j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j-1]='I';
                    board[1][j]='I';
                    board[1][j+1]='I';
                    board[1][j+2]='I';
                    
                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-2;j<(AbstractTetris::index_y);j++){
                    //THIS FOR LOOP FOR MOVING TO THE RIGHT
                    board[1][j]='.';
                    board[1][j+1]='.';
                    board[1][j+2]='.';
                    board[1][j+3]='.';
                    if(board[1][j+1]!='.'||board[1][j+2]!='.'||board[1][j+3]!='.'||board[1][j+4]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j+1]='I';
                    board[1][j+2]='I';
                    board[1][j+3]='I';
                    board[1][j+4]='I';

                    draw();
                }
            }
            for(auto i=2;i<=(AbstractTetris::index_x);i++){
                // THIS FOR LOOP FOR MOVING DOWN
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-1][(AbstractTetris::index_y)+1]='.';
                    board[i-1][(AbstractTetris::index_y)+2]='.';
                    board[i-1][(AbstractTetris::index_y)+3]='.';
                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i][(AbstractTetris::index_y)+1]!='.'||board[i][(AbstractTetris::index_y)+2]!='.'||board[i][(AbstractTetris::index_y)+3]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i][(AbstractTetris::index_y)]='I';
                    board[i][(AbstractTetris::index_y)+1]='I';
                    board[i][(AbstractTetris::index_y)+2]='I';
                    board[i][(AbstractTetris::index_y)+3]='I';

                    draw();
                }
        }
        else{// THIS ELSE MEANS THE SHAPE ROTATED
            draw();            
            rotate_added_shape(shape);
            if(board[1][(AbstractTetris::length)/2]=='.'&&board[2][(AbstractTetris::length)/2]=='.'&&board[3][(AbstractTetris::length)/2]=='.'&&board[4][(AbstractTetris::length)/2]=='.'){
                board[1][(AbstractTetris::length)/2]='I';
                board[2][(AbstractTetris::length)/2]='I';
                board[3][(AbstractTetris::length)/2]='I';
                board[4][(AbstractTetris::length)/2]='I';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            
            draw(); 
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){// TO UNDERSTAND MOVING RIGHT OR LEFT.. MOVING LEFT
                for(auto j=(AbstractTetris::length)/2;j>(AbstractTetris::index_y);j--){
                    // MOVING LEFT LOOP
                    board[1][j]='.';
                    board[2][j]='.';
                    board[3][j]='.';
                    board[4][j]='.';
                    if(board[1][j-1]!='.'||board[2][j-1]!='.'||board[3][j-1]!='.'||board[4][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j-1]='I';
                    board[2][j-1]='I';
                    board[3][j-1]='I';
                    board[4][j-1]='I';

                    draw();
                }
            }
            else{
                for(auto j=(AbstractTetris::length)/2;j<(AbstractTetris::index_y);j++){
                    //MOVING RIGHT LOOP
                    board[1][j]='.';
                    board[2][j]='.';
                    board[3][j]='.';
                    board[4][j]='.';
                    if(board[1][j+1]!='.'||board[2][j+1]!='.'||board[3][j+1]!='.'||board[4][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j+1]='I';
                    board[2][j+1]='I';
                    board[3][j+1]='I';
                    board[4][j+1]='I';

                    draw();
                }
            }
            for(auto i=5;i<=(AbstractTetris::index_x);i++){
                //MOVING DOWN LOOP
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-3][(AbstractTetris::index_y)]='.';
                    board[i-4][(AbstractTetris::index_y)]='.';
                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)]!='.'||board[i-2][(AbstractTetris::index_y)]!='.'||board[i-3][(AbstractTetris::index_y)]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i][(AbstractTetris::index_y)]='I';
                    board[i-1][(AbstractTetris::index_y)]='I';
                    board[i-2][(AbstractTetris::index_y)]='I';
                    board[i-3][(AbstractTetris::index_y)]='I';

                    draw();
                }
        }
    }
    else if(shape.getKey()=='O'){
        if(!shape.getAdd()){
            fill_indexes(shape);
            draw();
            return;
        }
        draw(); 
        if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){ // THAT MEANS THE SHAPE WILL MOVE LEFT
            for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                board[1][j]='.';
                board[1][j+1]='.';
                board[2][j]='.';
                board[2][j+1]='.';
                if(board[1][j-1]!='.'||board[1][j]!='.'||board[2][j-1]!='.'||board[2][j]!='.'){
                    fill_just_y_indexes(shape);\
                    draw();
                    break;
                }
                board[1][j-1]='O';
                board[1][j]='O';
                board[2][j-1]='O';
                board[2][j]='O';
                
                draw();
            }

        }
        else{// THE SHAPE WILL MOVE RIGHT
            for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                board[1][j]='.';
                board[1][j+1]='.';
                board[2][j]='.';
                board[2][j+1]='.';
                if(board[1][j+1]!='.'||board[1][j+2]!='.'||board[2][j+1]!='.'||board[2][j+2]!='.'){
                    fill_just_y_indexes(shape);
                    draw();
                    break;
                }
                board[1][j+1]='O';
                board[1][j+2]='O';
                board[2][j+1]='O';
                board[2][j+2]='O';
                
                draw();
            }
        }
        for(auto i=3;i<=(AbstractTetris::index_x);i++){ // THIS LOOP TO SHAPE TO MOVE DOWN
                board[i-1][(AbstractTetris::index_y)]='.';
                board[i-1][(AbstractTetris::index_y)+1]='.';
                board[i-2][(AbstractTetris::index_y)]='.';
                board[i-2][(AbstractTetris::index_y)+1]='.';
                if(board[i][(AbstractTetris::index_y)]!='.'||board[i][(AbstractTetris::index_y)+1]!='.'||board[i-1][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)+1]!='.'){
                    fill_indexes(shape);
                    draw();
                    break;
                }
                board[i][(AbstractTetris::index_y)]='O';
                board[i][(AbstractTetris::index_y)+1]='O';
                board[i-1][(AbstractTetris::index_y)]='O';
                board[i-1][(AbstractTetris::index_y)+1]='O';
                
                draw();
            }
    }
    else if(shape.getKey()=='T'){     
        if(shape.getRotated()==0){
            if(!shape.getAdd()){
                fill_indexes(shape);
                draw();
                return;
            }
            draw();  
            if((AbstractTetris::index_y)<=(AbstractTetris::length)/2){
                for(auto j=(AbstractTetris::length)/2;j>(AbstractTetris::index_y);j--){
                    board[2][j]='.';
                    board[1][j]='.';
                    board[1][j-1]='.';
                    board[1][j+1]='.';
                    if(board[2][j-1]!='.'||board[1][j-1]!='.'||board[1][j-2]!='.'||board[1][j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[2][j-1]='T';
                    board[1][j-1]='T';
                    board[1][j-2]='T';
                    board[1][j]='T';

                    draw();
                }
            }
            else{
                for(auto j=(AbstractTetris::length)/2;j<(AbstractTetris::index_y);j++){
                    board[2][j]='.';
                    board[1][j]='.';
                    board[1][j-1]='.';
                    board[1][j+1]='.';
                    if(board[2][j+1]!='.'||board[1][j+1]!='.'||board[1][j]!='.'||board[1][j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[2][j+1]='T';
                    board[1][j+1]='T';
                    board[1][j]='T';
                    board[1][j+2]='T';

                    draw();
                }
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)-1]='.';
                    board[i-2][(AbstractTetris::index_y)+1]='.';
                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)-1]!='.'||board[i-1][(AbstractTetris::index_y)+1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i][(AbstractTetris::index_y)]='T';
                    board[i-1][(AbstractTetris::index_y)]='T';
                    board[i-1][(AbstractTetris::index_y)-1]='T';
                    board[i-1][(AbstractTetris::index_y)+1]='T';

                    draw();
                }
        }
        else if(shape.getRotated()==1){
            draw();            
            rotate_added_shape(shape);
            if(board[1][((AbstractTetris::length)/2)]=='.'&&board[2][((AbstractTetris::length)/2)]=='.'&&board[2][((AbstractTetris::length)/2)-1]=='.'&&board[3][((AbstractTetris::length)/2)]=='.'){
                board[1][((AbstractTetris::length)/2)]='T';
                board[2][((AbstractTetris::length)/2)]='T';
                board[2][((AbstractTetris::length)/2)-1]='T';
                board[3][((AbstractTetris::length)/2)]='T';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){
                for(auto j=((AbstractTetris::length)/2);j>(AbstractTetris::index_y);j--){
                    board[3][j]='.';
                    board[2][j]='.';
                    board[2][j-1]='.';
                    board[1][j]='.';
                    if(board[3][j-1]!='.'||board[2][j-1]!='.'||board[2][j-2]!='.'||board[1][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[3][j-1]='T';
                    board[2][j-1]='T';
                    board[2][j-2]='T';
                    board[1][j-1]='T';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2);j<(AbstractTetris::index_y);j++){
                    board[3][j]='.';
                    board[2][j]='.';
                    board[2][j-1]='.';
                    board[1][j]='.';
                    if(board[3][j+1]!='.'||board[2][j+1]!='.'||board[2][j]!='.'||board[1][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[3][j+1]='T';
                    board[2][j+1]='T';
                    board[2][j]='T';
                    board[1][j+1]='T';

                    draw();
                }
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)-1]='.';
                    board[i-3][(AbstractTetris::index_y)]='.';
                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)-1]!='.'||board[i-2][(AbstractTetris::index_y)]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i][(AbstractTetris::index_y)]='T';
                    board[i-1][(AbstractTetris::index_y)]='T';
                    board[i-1][(AbstractTetris::index_y)-1]='T';
                    board[i-2][(AbstractTetris::index_y)]='T';

                    draw();
                }
        }
        else if(shape.getRotated()==2){
            draw();            
            rotate_added_shape(shape);
            if(board[1][((AbstractTetris::length)/2)]=='.'&&board[2][((AbstractTetris::length)/2)]=='.'&&board[2][((AbstractTetris::length)/2)-1]=='.'&&board[2][((AbstractTetris::length)/2)+1]=='.'){
                board[1][((AbstractTetris::length)/2)]='T';
                board[2][((AbstractTetris::length)/2)]='T';
                board[2][((AbstractTetris::length)/2)-1]='T';
                board[2][((AbstractTetris::length)/2)+1]='T';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();           
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[2][j]='.';
                    board[2][j+1]='.';
                    board[2][j+2]='.';
                    board[1][j+1]='.';
                    if(board[2][j-1]!='.'||board[2][j]!='.'||board[2][j+1]!='.'||board[1][j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[2][j-1]='T';
                    board[2][j]='T';
                    board[2][j+1]='T';
                    board[1][j]='T';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[2][j]='.';
                    board[2][j+1]='.';
                    board[2][j+2]='.';
                    board[1][j+1]='.';
                    if(board[2][j+1]!='.'||board[2][j+2]!='.'||board[2][j+3]!='.'||board[1][j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[2][j+1]='T';
                    board[2][j+2]='T';
                    board[2][j+3]='T';
                    board[1][j+2]='T';

                    draw();
                }
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-1][(AbstractTetris::index_y)+1]='.';
                    board[i-2][(AbstractTetris::index_y)+1]='.';
                    board[i-1][(AbstractTetris::index_y)+2]='.';
                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i][(AbstractTetris::index_y)+1]!='.'||board[i-1][(AbstractTetris::index_y)+1]!='.'||board[i][(AbstractTetris::index_y)+2]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i][(AbstractTetris::index_y)]='T';
                    board[i][(AbstractTetris::index_y)+1]='T';
                    board[i-1][(AbstractTetris::index_y)+1]='T';
                    board[i][(AbstractTetris::index_y)+2]='T';

                    draw();
                }
        }
        else if(shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(board[1][(AbstractTetris::length)/2]=='.'&&board[2][(AbstractTetris::length)/2]=='.'&&board[2][((AbstractTetris::length)/2)+1]=='.'&&board[3][(AbstractTetris::length)/2]=='.'){
                board[1][(AbstractTetris::length)/2]='T';
                board[2][(AbstractTetris::length)/2]='T';
                board[2][((AbstractTetris::length)/2)+1]='T';
                board[3][(AbstractTetris::length)/2]='T';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }

            draw();            
            if((AbstractTetris::index_y)<=(AbstractTetris::length)/2){
                for(auto j=(AbstractTetris::length)/2;j>(AbstractTetris::index_y);j--){
                    board[1][j]='.';
                    board[2][j]='.';
                    board[2][j+1]='.';
                    board[3][j]='.';
                    if(board[1][j-1]!='.'||board[2][j-1]!='.'||board[2][j]!='.'||board[3][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j-1]='T';
                    board[2][j-1]='T';
                    board[2][j]='T';
                    board[3][j-1]='T';

                    draw();
                }
            }
            else{
                for(auto j=(AbstractTetris::length)/2;j<(AbstractTetris::index_y);j++){
                    board[1][j]='.';
                    board[2][j]='.';
                    board[2][j+1]='.';
                    board[3][j]='.';
                    if(board[1][j+1]!='.'||board[2][j+1]!='.'||board[2][j+2]!='.'||board[3][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j+1]='T';
                    board[2][j+1]='T';
                    board[2][j+2]='T';
                    board[3][j+1]='T';

                    draw();
                }  
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)+1]='.';
                    board[i-3][(AbstractTetris::index_y)]='.';
                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)+1]!='.'||board[i-2][(AbstractTetris::index_y)]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i][(AbstractTetris::index_y)]='T';
                    board[i-1][(AbstractTetris::index_y)]='T';
                    board[i-1][(AbstractTetris::index_y)+1]='T';
                    board[i-2][(AbstractTetris::index_y)]='T';

                    draw();
                }
        }
    }
    else if(shape.getKey()=='J'){       
        if(shape.getRotated()==0){        
            if(!shape.getAdd()){
                fill_indexes(shape);
                draw();
                return;
            }   
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[3][j]='.';
                    board[3][j+1]='.';
                    board[2][j+1]='.';
                    board[1][j+1]='.';
                    if(board[3][j-1]!='.'||board[3][j]!='.'||board[2][j]!='.'||board[1][j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[3][j-1]='J';
                    board[3][j]='J';
                    board[2][j]='J';
                    board[1][j]='J';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[3][j]='.';
                    board[3][j+1]='.';
                    board[2][j+1]='.';
                    board[1][j+1]='.';
                    if(board[3][j+1]!='.'||board[3][j+2]!='.'||board[2][j+2]!='.'||board[1][j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[3][j+1]='J';
                    board[3][j+2]='J';
                    board[2][j+2]='J';
                    board[1][j+2]='J';

                    draw();
                }
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-1][(AbstractTetris::index_y)+1]='.';
                    board[i-2][(AbstractTetris::index_y)+1]='.';
                    board[i-3][(AbstractTetris::index_y)+1]='.';
                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i][(AbstractTetris::index_y)+1]!='.'||board[i-1][(AbstractTetris::index_y)+1]!='.'||board[i-2][(AbstractTetris::index_y)+1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i][(AbstractTetris::index_y)]='J';
                    board[i][(AbstractTetris::index_y)+1]='J';
                    board[i-1][(AbstractTetris::index_y)+1]='J';
                    board[i-2][(AbstractTetris::index_y)+1]='J';

                    draw();
                }
        }
        else if(shape.getRotated()==1){
            draw();            
            rotate_added_shape(shape);
            if(board[1][((AbstractTetris::length)/2)-1]=='.'&&board[2][((AbstractTetris::length)/2)-1]=='.'&&board[2][((AbstractTetris::length)/2)]=='.'&&board[2][((AbstractTetris::length)/2)+1]=='.'){
                board[1][((AbstractTetris::length)/2)-1]='J';
                board[2][((AbstractTetris::length)/2)-1]='J';
                board[2][((AbstractTetris::length)/2)]='J';
                board[2][((AbstractTetris::length)/2)+1]='J';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }

            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[1][j]='.';
                    board[2][j]='.';
                    board[2][j+1]='.';
                    board[2][j+2]='.';
                    if(board[1][j-1]!='.'||board[2][j-1]!='.'||board[2][j]!='.'||board[2][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j-1]='J';
                    board[2][j-1]='J';
                    board[2][j]='J';
                    board[2][j+1]='J';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[1][j]='.';
                    board[2][j]='.';
                    board[2][j+1]='.';
                    board[2][j+2]='.';
                    if(board[1][j+1]!='.'||board[2][j+1]!='.'||board[2][j+2]!='.'||board[2][j+3]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j+1]='J';
                    board[2][j+1]='J';
                    board[2][j+2]='J';
                    board[2][j+3]='J';

                    draw();
                }
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-1][(AbstractTetris::index_y)+1]='.';
                    board[i-1][(AbstractTetris::index_y)+2]='.';
                    if(board[i-1][(AbstractTetris::index_y)]!='.'||board[i][(AbstractTetris::index_y)]!='.'||board[i][(AbstractTetris::index_y)+1]!='.'||board[i][(AbstractTetris::index_y)+2]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i-1][(AbstractTetris::index_y)]='J';
                    board[i][(AbstractTetris::index_y)]='J';
                    board[i][(AbstractTetris::index_y)+1]='J';
                    board[i][(AbstractTetris::index_y)+2]='J';

                    draw();
                }
        }
        else if(shape.getRotated()==2){
            draw();            
            rotate_added_shape(shape);
            if(board[1][((AbstractTetris::length)/2)-1]=='.'&&board[1][((AbstractTetris::length)/2)]=='.'&&board[2][((AbstractTetris::length)/2)-1]=='.'&&board[3][((AbstractTetris::length)/2)-1]=='.'){
                board[1][((AbstractTetris::length)/2)-1]='J';
                board[1][((AbstractTetris::length)/2)]='J';
                board[2][((AbstractTetris::length)/2)-1]='J';
                board[3][((AbstractTetris::length)/2)-1]='J';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[1][j]='.';
                    board[1][j+1]='.';
                    board[2][j]='.';
                    board[3][j]='.';
                    if(board[1][j-1]!='.'||board[1][j]!='.'||board[2][j-1]!='.'||board[3][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j-1]='J';
                    board[1][j]='J';
                    board[2][j-1]='J';
                    board[3][j-1]='J';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[1][j]='.';
                    board[1][j+1]='.';
                    board[2][j]='.';
                    board[3][j]='.';
                    if(board[1][j+1]!='.'||board[1][j+2]!='.'||board[2][j+1]!='.'||board[3][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j+1]='J';
                    board[1][j+2]='J';
                    board[2][j+1]='J';
                    board[3][j+1]='J';

                    draw();
                }
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[i-3][(AbstractTetris::index_y)]='.';
                    board[i-3][(AbstractTetris::index_y)+1]='.';
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-1][(AbstractTetris::index_y)]='.';
                    if(board[i-2][(AbstractTetris::index_y)]!='.'||board[i-2][(AbstractTetris::index_y)+1]!='.'||board[i-1][(AbstractTetris::index_y)]!='.'||board[i][(AbstractTetris::index_y)]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i-2][(AbstractTetris::index_y)]='J';
                    board[i-2][(AbstractTetris::index_y)+1]='J';
                    board[i-1][(AbstractTetris::index_y)]='J';
                    board[i][(AbstractTetris::index_y)]='J';

                    draw();
                }
        }
        else if(shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(board[1][((AbstractTetris::length)/2)-1]=='.'&&board[1][((AbstractTetris::length)/2)]=='.'&&board[1][((AbstractTetris::length)/2)+1]=='.'&&board[2][((AbstractTetris::length)/2)+1]=='.'){
                board[1][((AbstractTetris::length)/2)-1]='J';
                board[1][((AbstractTetris::length)/2)]='J';
                board[1][((AbstractTetris::length)/2)+1]='J';
                board[2][((AbstractTetris::length)/2)+1]='J';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)+1){
                for(auto j=((AbstractTetris::length)/2)+1;j>(AbstractTetris::index_y);j--){
                    board[1][j-2]='.';
                    board[1][j-1]='.';
                    board[1][j]='.';
                    board[2][j]='.';
                    if(board[1][j-3]!='.'||board[1][j-2]!='.'||board[1][j-1]!='.'||board[2][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j-3]='J';
                    board[1][j-2]='J';
                    board[1][j-1]='J';
                    board[2][j-1]='J';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)+1;j<(AbstractTetris::index_y);j++){
                    board[1][j-2]='.';
                    board[1][j-1]='.';
                    board[1][j]='.';
                    board[2][j]='.';
                    if(board[1][j-1]!='.'||board[1][j]!='.'||board[1][j+1]!='.'||board[2][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j-1]='J';
                    board[1][j]='J';
                    board[1][j+1]='J';
                    board[2][j+1]='J';

                    draw();
                }
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)-1]='.';
                    board[i-2][(AbstractTetris::index_y)-2]='.';
                    board[i-1][(AbstractTetris::index_y)]='.';
                    if(board[i-1][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)-1]!='.'||board[i-1][(AbstractTetris::index_y)-2]!='.'||board[i][(AbstractTetris::index_y)]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i-1][(AbstractTetris::index_y)]='J';
                    board[i-1][(AbstractTetris::index_y)-1]='J';
                    board[i-1][(AbstractTetris::index_y)-2]='J';
                    board[i][(AbstractTetris::index_y)]='J';

                    draw();
                }
        }
    }
    else if(shape.getKey()=='L'){
        if(shape.getRotated()==0){  
            if(!shape.getAdd()){
                fill_indexes(shape);
                draw();
                return;
            }         
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){
                for(auto j=((AbstractTetris::length)/2);j>(AbstractTetris::index_y);j--){
                    board[1][j]='.';
                    board[2][j]='.';
                    board[3][j]='.';
                    board[3][j+1]='.';
                    if(board[1][j-1]!='.'||board[2][j-1]!='.'||board[3][j-1]!='.'||board[3][j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;  
                    }
                    board[1][j-1]='L';
                    board[2][j-1]='L';
                    board[3][j-1]='L';
                    board[3][j]='L';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2);j<(AbstractTetris::index_y);j++){
                    board[1][j]='.';
                    board[2][j]='.';
                    board[3][j]='.';
                    board[3][j+1]='.';
                    if(board[1][j+1]!='.'||board[2][j+1]!='.'||board[3][j+1]!='.'||board[3][j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;  
                    }
                    board[1][j+1]='L';
                    board[2][j+1]='L';
                    board[3][j+1]='L';
                    board[3][j+2]='L';

                    draw();
                }
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-1][(AbstractTetris::index_y)+1]='.';
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-3][(AbstractTetris::index_y)]='.';
                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i][(AbstractTetris::index_y)+1]!='.'||board[i-1][(AbstractTetris::index_y)]!='.'||board[i-2][(AbstractTetris::index_y)]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    board[i][(AbstractTetris::index_y)]='L';
                    board[i][(AbstractTetris::index_y)+1]='L';
                    board[i-1][(AbstractTetris::index_y)]='L';
                    board[i-2][(AbstractTetris::index_y)]='L';

                    draw();
                }
        }
        else if(shape.getRotated()==1){
            draw();            
            rotate_added_shape(shape);
            if(board[1][((AbstractTetris::length)/2)-1]=='.'&&board[2][((AbstractTetris::length)/2)-1]=='.'&&board[1][((AbstractTetris::length)/2)]=='.'&&board[1][((AbstractTetris::length)/2)+1]=='.'){
                board[1][((AbstractTetris::length)/2)-1]='L';
                board[2][((AbstractTetris::length)/2)-1]='L';
                board[1][((AbstractTetris::length)/2)]='L';
                board[1][((AbstractTetris::length)/2)+1]='L';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();           
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[1][j]='.';
                    board[1][j+1]='.';
                    board[1][j+2]='.';
                    board[2][j]='.';
                    if(board[1][j-1]!='.'||board[1][j]!='.'||board[1][j+1]!='.'||board[2][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[1][j-1]='L';
                    board[1][j]='L';
                    board[1][j+1]='L';
                    board[2][j-1]='L';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[1][j]='.';
                    board[1][j+1]='.';
                    board[1][j+2]='.';
                    board[2][j]='.';
                    if(board[1][j+1]!='.'||board[1][j+2]!='.'||board[1][j+3]!='.'||board[2][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[1][j+1]='L';
                    board[1][j+2]='L';
                    board[1][j+3]='L';
                    board[2][j+1]='L';

                    draw();
                }
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)+1]='.';
                    board[i-2][(AbstractTetris::index_y)+2]='.';
                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)+1]!='.'||board[i-1][(AbstractTetris::index_y)+1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    board[i][(AbstractTetris::index_y)]='L';
                    board[i-1][(AbstractTetris::index_y)]='L';
                    board[i-1][(AbstractTetris::index_y)+1]='L';
                    board[i-1][(AbstractTetris::index_y)+2]='L';

                    draw();
                }
        }
        else if(shape.getRotated()==2){
            draw();            
            rotate_added_shape(shape);
            if(board[1][((AbstractTetris::length)/2)-1]=='.'&&board[1][((AbstractTetris::length)/2)]=='.'&&board[2][((AbstractTetris::length)/2)-1]=='.'&&board[3][((AbstractTetris::length)/2)-1]=='.'){
                board[1][((AbstractTetris::length)/2)-1]='L';
                board[1][((AbstractTetris::length)/2)]='L';
                board[2][((AbstractTetris::length)/2)]='L';
                board[3][((AbstractTetris::length)/2)]='L';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){
                for(auto j=((AbstractTetris::length)/2);j>(AbstractTetris::index_y);j--){
                    board[1][j-1]='.';
                    board[1][j]='.';
                    board[2][j]='.';
                    board[3][j]='.';
                    if(board[1][j-1]!='.'||board[1][j-1]!='.'||board[2][j-1]!='.'||board[3][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[1][j-2]='L';
                    board[1][j-1]='L';
                    board[2][j-1]='L';
                    board[3][j-1]='L';
                        draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2);j<(AbstractTetris::index_y);j++){
                    board[1][j-1]='.';
                    board[1][j]='.';
                    board[2][j]='.';
                    board[3][j]='.';
                    if(board[1][j]!='.'||board[1][j+1]!='.'||board[2][j+1]!='.'||board[3][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[1][j]='L';
                    board[1][j+1]='L';
                    board[2][j+1]='L';
                    board[3][j+1]='L';
                        draw();
                }
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-3][(AbstractTetris::index_y)]='.';
                    board[i-3][(AbstractTetris::index_y)-1]='.';
                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)]!='.'||board[i-2][(AbstractTetris::index_y)]!='.'||board[i-2][(AbstractTetris::index_y)-1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    board[i][(AbstractTetris::index_y)]='L';
                    board[i-1][(AbstractTetris::index_y)]='L';
                    board[i-2][(AbstractTetris::index_y)]='L';
                    board[i-2][(AbstractTetris::index_y)-1]='L';

                    draw();
                }
        }
        else if(shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(board[1][((AbstractTetris::length)/2)+1]=='.'&&board[2][((AbstractTetris::length)/2)-1]=='.'&&board[2][((AbstractTetris::length)/2)]=='.'&&board[2][((AbstractTetris::length)/2)+1]=='.'){
                board[1][((AbstractTetris::length)/2)+1]='L';
                board[2][((AbstractTetris::length)/2)-1]='L';
                board[2][((AbstractTetris::length)/2)]='L';
                board[2][((AbstractTetris::length)/2)+1]='L';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
        
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[1][j+2]='.';
                    board[2][j]='.';
                    board[2][j+1]='.';
                    board[2][j+2]='.';
                    if(board[1][j+1]!='.'||board[2][j-1]!='.'||board[2][j]!='.'||board[2][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[1][j+1]='L';
                    board[2][j-1]='L';
                    board[2][j]='L';
                    board[2][j+1]='L';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[1][j+2]='.';
                    board[2][j]='.';
                    board[2][j+1]='.';
                    board[2][j+2]='.';
                    if(board[1][j+3]!='.'||board[2][j+1]!='.'||board[2][j+2]!='.'||board[2][j+3]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[1][j+3]='L';
                    board[2][j+1]='L';
                    board[2][j+2]='L';
                    board[2][j+3]='L';

                    draw();
                }
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[i-2][(AbstractTetris::index_y)+2]='.';
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-1][(AbstractTetris::index_y)+1]='.';
                    board[i-1][(AbstractTetris::index_y)+2]='.';
                    if(board[i-1][(AbstractTetris::index_y)+2]!='.'||board[i][(AbstractTetris::index_y)]!='.'||board[i][(AbstractTetris::index_y)+1]!='.'||board[i][(AbstractTetris::index_y)+2]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    board[i-1][(AbstractTetris::index_y)+2]='L';
                    board[i][(AbstractTetris::index_y)]='L';
                    board[i][(AbstractTetris::index_y)+1]='L';
                    board[i][(AbstractTetris::index_y)+2]='L';

                    draw();
                }
        }
    }
    else if(shape.getKey()=='S'){
        if(shape.getRotated()==0 || shape.getRotated()==2){
            if(!shape.getAdd()){
                fill_indexes(shape);
                draw();
                return;
            }
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[2][j]='.';
                    board[2][j+1]='.';
                    board[1][j+1]='.';
                    board[1][j+2]='.';
                    if(board[2][j-1]!='.'||board[2][j]!='.'||board[1][j-1]!='.'||board[1][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[2][j-1]='S';
                    board[2][j]='S';
                    board[1][j]='S';
                    board[1][j+1]='S';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[2][j]='.';
                    board[2][j+1]='.';
                    board[1][j+1]='.';
                    board[1][j+2]='.';
                    if(board[2][j+1]!='.'||board[2][j+2]!='.'||board[1][j+2]!='.'||board[1][j+3]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[2][j+1]='S';
                    board[2][j+2]='S';
                    board[1][j+2]='S';
                    board[1][j+3]='S';

                    draw();
                }
                
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-1][(AbstractTetris::index_y)+1]='.';
                    board[i-2][(AbstractTetris::index_y)+1]='.';
                    board[i-2][(AbstractTetris::index_y)+2]='.';
                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i][(AbstractTetris::index_y)+1]!='.'||board[i-1][(AbstractTetris::index_y)+1]!='.'||board[i-1][(AbstractTetris::index_y)+2]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    board[i][(AbstractTetris::index_y)]='S';
                    board[i][(AbstractTetris::index_y)+1]='S';
                    board[i-1][(AbstractTetris::index_y)+1]='S';
                    board[i-1][(AbstractTetris::index_y)+2]='S';

                    draw();
                }
        }
        else if(shape.getRotated()==1 || shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(board[1][((AbstractTetris::length)/2)-1]=='.'&&board[2][((AbstractTetris::length)/2)-1]=='.'&&board[2][((AbstractTetris::length)/2)]=='.'&&board[3][((AbstractTetris::length)/2)]=='.'){
                board[1][((AbstractTetris::length)/2)-1]='S';
                board[2][((AbstractTetris::length)/2)-1]='S';
                board[2][((AbstractTetris::length)/2)]='S';
                board[3][((AbstractTetris::length)/2)]='S';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){
                for(auto j=((AbstractTetris::length)/2);j>(AbstractTetris::index_y);j--){
                    board[1][j-1]='.';
                    board[2][j-1]='.';
                    board[2][j]='.';
                    board[3][j]='.';
                    if(board[1][j-2]!='.'||board[2][j-2]!='.'||board[2][j-1]!='.'||board[3][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[1][j-2]='S';
                    board[2][j-2]='S';
                    board[2][j-1]='S';
                    board[3][j-1]='S';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2);j<(AbstractTetris::index_y);j++){
                    board[1][j-1]='.';
                    board[2][j-1]='.';
                    board[2][j]='.';
                    board[3][j]='.';
                    if(board[1][j]!='.'||board[2][j]!='.'||board[2][j+1]!='.'||board[3][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j]='S';
                    board[2][j]='S';
                    board[2][j+1]='S';
                    board[3][j+1]='S';

                    draw();
                }
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)-1]='.';
                    board[i-3][(AbstractTetris::index_y)-1]='.';
                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)-1]!='.'||board[i-2][(AbstractTetris::index_y)-1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i][(AbstractTetris::index_y)]='S';
                    board[i-1][(AbstractTetris::index_y)]='S';
                    board[i-1][(AbstractTetris::index_y)-1]='S';
                    board[i-2][(AbstractTetris::index_y)-1]='S';

                    draw();

                }
        }
    }
    else if(shape.getKey()=='Z'){
        if(shape.getRotated()==0 || shape.getRotated()==2){
            if(!shape.getAdd()){
                fill_indexes(shape);
                draw();
                return;
            }
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){
                for(auto j=((AbstractTetris::length)/2);j>(AbstractTetris::index_y);j--){
                    board[1][j]='.';
                    board[1][j-1]='.';
                    board[2][j]='.';
                    board[2][j+1]='.';
                    if(board[1][j-1]!='.'||board[1][j-2]!='.'||board[2][j-1]!='.'||board[2][j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j-1]='Z';
                    board[1][j-2]='Z';
                    board[2][j-1]='Z';
                    board[2][j]='Z';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2);j<(AbstractTetris::index_y);j++){
                    board[1][j]='.';
                    board[1][j-1]='.';
                    board[2][j]='.';
                    board[2][j+1]='.';

                    if(board[1][j+1]!='.'||board[1][j]!='.'||board[2][j+1]!='.'||board[2][j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j+1]='Z';
                    board[1][j]='Z';
                    board[2][j+1]='Z';
                    board[2][j+2]='Z';

                    draw();
                }
                
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-1][(AbstractTetris::index_y)+1]='.';
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)-1]='.';

                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i][(AbstractTetris::index_y)+1]!='.'||board[i-1][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)-1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i][(AbstractTetris::index_y)]='Z';
                    board[i][(AbstractTetris::index_y)+1]='Z';
                    board[i-1][(AbstractTetris::index_y)]='Z';
                    board[i-1][(AbstractTetris::index_y)-1]='Z';

                    draw();
                }
        }
        else if(shape.getRotated()==1 || shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(board[1][((AbstractTetris::length)/2)+1]=='.'&&board[2][((AbstractTetris::length)/2)+1]=='.'&&board[2][((AbstractTetris::length)/2)]=='.'&&board[3][((AbstractTetris::length)/2)]=='.'){
                board[1][((AbstractTetris::length)/2)+1]='Z';
                board[2][((AbstractTetris::length)/2)+1]='Z';
                board[2][((AbstractTetris::length)/2)]='Z';
                board[3][((AbstractTetris::length)/2)]='Z';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){
                for(auto j=((AbstractTetris::length)/2);j>(AbstractTetris::index_y);j--){
                    board[1][j+1]='.';
                    board[2][j+1]='.';
                    board[2][j]='.';
                    board[3][j]='.';

                    if(board[1][j]!='.'||board[2][j]!='.'||board[2][j-1]!='.'||board[3][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[1][j]='Z';
                    board[2][j]='Z';
                    board[2][j-1]='Z';
                    board[3][j-1]='Z';

                    draw();
                }          
            }
            else{
                for(auto j=((AbstractTetris::length)/2);j<(AbstractTetris::index_y);j++){
                    board[1][j+1]='.';
                    board[2][j+1]='.';
                    board[2][j]='.';
                    board[3][j]='.';

                    if(board[1][j+2]!='.'||board[2][j+2]!='.'||board[2][j+1]!='.'||board[3][j+1]!='.'){
                        fill_just_y_indexes(shape);             
                        draw();
                        break;
                    }
                    board[1][j+2]='Z';
                    board[2][j+2]='Z';
                    board[2][j+1]='Z';
                    board[3][j+1]='Z';

                    draw();

                }
                
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[i-1][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)]='.';
                    board[i-2][(AbstractTetris::index_y)+1]='.';
                    board[i-3][(AbstractTetris::index_y)+1]='.';

                    if(board[i][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)]!='.'||board[i-1][(AbstractTetris::index_y)+1]!='.'||board[i-2][(AbstractTetris::index_y)+1]!='.'){
                        fill_indexes(shape);
                        break;
                    }
                    board[i][(AbstractTetris::index_y)]='Z';
                    board[i-1][(AbstractTetris::index_y)]='Z';
                    board[i-1][(AbstractTetris::index_y)+1]='Z';
                    board[i-2][(AbstractTetris::index_y)+1]='Z';

                    draw();
                }
        }
    }

}





// 1D ARRAY CLASS DEFINITIONS
TetrisArray1D::TetrisArray1D(int h, int l): AbstractTetris(h,l){
    create_board();
    fill_board();
}
TetrisArray1D::~TetrisArray1D(){
    delete[] board;
}

void TetrisArray1D::writeToFile(fstream &file){
    // Writing the datas into file
    file.open("tetrisgame.txt",ios::out);
    file<<AbstractTetris::height<<" "<<AbstractTetris::length;
    for(auto i=0;i<AbstractTetris::length*AbstractTetris::height;i++){
        file<<board[i];
    }
    file.close();
}

void TetrisArray1D::readFromFile(fstream &file){
    file.open("tetrisgame.txt",ios::in);
    file>>AbstractTetris::height>>AbstractTetris::length;
    create_board();
    for(auto i=0;i<AbstractTetris::length*AbstractTetris::height;i++){
        file>>board[i];
    }
    file.close();
}

TetrisArray1D& TetrisArray1D:: operator+=(Tetromino &shape){
    /*
    NEW Add() FUNCTION ADDS THE TETROMINO TO THE BOARD ACCORDING TO THE ITS SHAPE
    ONLY IF THE BOARD IS AVALIABLE TO PRINT TOP BOTTOM
    */
    this->last_tetro=shape.getKey();
    if(shape.getKey()=='I'){
        if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-2]=='.'&&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]=='.'
        &&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]=='.'){
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-2]='I';
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='I';
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='I';
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='I';
            shape.setAdd(true); // that means the shape are printed the top bottom screen
        }
        else{
            shape.setAdd(false);//that means i couldn't do it
        }
    }
    else if(shape.getKey()=='O'){
        if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]=='.'
        &&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'){
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='O';
            board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='O';
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='O';
            board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='O';
            
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        } 
    }
    else if(shape.getKey()=='T'){
        if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]=='.'
        &&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'){
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='T';
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='T';
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='T';
            board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='T';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }       
    }
    else if(shape.getKey()=='J'){
        if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'&&
        board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)-1]=='.'){
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='J';
            board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='J';
            board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]='J';
            board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)-1]='J';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }
    }
    else if(shape.getKey()=='L'){
        if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'
        &&board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)+1]=='.'){
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='L';
            board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='L';
            board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]='L';
            board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)+1]='L';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }
    }
    else if(shape.getKey()=='S'){
        if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'
        &&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]=='.'){
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='S';
            board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='S';
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='S';
            board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='S';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }
    }
    else if(shape.getKey()=='Z'){
        if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'
        &&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]=='.'){
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='Z';
            board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='Z';
            board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='Z';
            board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]='Z';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }
    }
    draw();
    return *this;
}


void TetrisArray1D:: rotate_added_shape(const Tetromino &shape){
    //WHEN I NEED TO ROTATE A TETROMINO
    // I PRINT IT AFTER Add() FUNCTION
    //SO, IN THIS FUNCTION I NEED TO CLEAR UNROTATED TETROMINO FROM THE TOP MIDDLE
    for(auto i=1;i<4;i++){
        for(auto j=1;j<(AbstractTetris::length)-1;j++){
            if(shape.getKey()=='I' && shape.getAdd()){
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-2]='.';
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='.';
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='.';
            }
            else if(shape.getKey()=='O' && shape.getAdd()){
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='.';
                    board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='.';
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='.';
            }
            else if(shape.getKey()=='T' && shape.getAdd()){
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='.';
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='.';
                    board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='.';
            }
            else if(shape.getKey()=='J' && shape.getAdd()){
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)-1]='.';
            }
            else if(shape.getKey()=='L' && shape.getAdd()){
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)+1]='.';
            }
            else if(shape.getKey()=='S' && shape.getAdd()){
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='.';
                    board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='.';
            }
            else if(shape.getKey()=='Z' && shape.getAdd()){
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='.';
                    board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='.';
                    board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]='.';
            }
        }
    }
}






void TetrisArray1D:: Animate(Tetromino &shape, int count_move, int count_rotate, string direction){
    /*
    1. Draw the board with Tetromino at the top 
    2. Ask the user rotation direction and rotation count 
    3. Ask the user move direction and count 
    4. Rotate and move the Tetromino 
    5. Draw the board 
    6. Sleep 50 miliseconds
    7. Lower the Tetromino one level and go to step 5 until it hits the bottom.
    */
    for(auto i=0;i<count_rotate;i++){// ROTATING THE SHAPES THE USER ENTERED COUNT TIMES
        shape.rotate();
    }
    //*this+=shape; // operator overloading to add tetromino the top bottom
    //draw();
    clear_top(shape);
    *this+=shape;
    try{
        if(check_index(shape,count_move,direction)){// THAT MEANS THE SHAPE WITH ROTATED FORM CAN BE FITTED TO THE BOARD
            move_animation(shape);
            clear();
            draw();
        } 
        else{
            clear_top(shape);
            throw "\nThe shape cannot be fitted that index\n";
            //draw();
        }
    }
    catch(string str){
        cout<<str<<endl;
    }
    
}
void TetrisArray1D:: clear_top(const Tetromino &shape){
    // WHEN THE TETROMINO CANNOT BE FITTED THE INDEXES OF USER ENTERED, I NEED TO CLEAR TETROMINO FROM THE TOP BOTTOM
    //SINCE EVERY TETROMINO HAS DIFFERENT INDEXES, I CHECK EACH ONE
    if(shape.getKey()=='I'){
        board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-2]='.'; board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='.';
        board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.'; board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='.';
    }
    else if(shape.getKey()=='O'){
        board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='.'; board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.';
        board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='.'; board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='.';
    }
    else if(shape.getKey()=='T'){
        board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='.'; board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.';
        board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='.'; board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='.';
    }
    else if(shape.getKey()=='J'){
        board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)-1]='.'; board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]='.';
        board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='.'; board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.';
    }
    else if(shape.getKey()=='L'){
        board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]='.'; board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='.';
        board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.'; board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)+1]='.';
    }
    else if(shape.getKey()=='S'){
        board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='.'; board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='.';
        board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.'; board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='.';
    }
    else if(shape.getKey()=='Z'){
        board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='.'; board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]='.';
        board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='.'; board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='.';
    }
}
bool TetrisArray1D:: check_index(const Tetromino &shape, int count, string direction){
    //these function to get indexes the user want;
    //for example shape is T tetromino without rotated;
    //user wants to move it 2 times to right;
    //i check the downest index the shape can be fitted;
    //and i keep that index in my (AbstractTetris::index_x) and (AbstractTetris::index_y) variables which is coming from AbstractTetris class
    try{
        if(((AbstractTetris::length)/2)+count>(AbstractTetris::length)){
        cerr<<"Out of the range!\n"<<endl;
        throw false;
        }
    } 
    catch(bool check){
        return check;
    }   
    if(direction=="L"){
        count*=-1;
    }
        if(shape.getKey()=='I'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)-2+count]=='.'&&board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)-1+count]=='.'&&
                    board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+1+count]=='.'&&
                    (shape.getRotated()==0||shape.getRotated()==2)){
                        //The if for I tetromino which is not rotated;
                        (AbstractTetris::index_y)=((AbstractTetris::length)/2)-2+count;
                        (AbstractTetris::index_x)=i;
                        return true;
                            
                }
                else if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*(i-2)+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-3)+((AbstractTetris::length)/2)+count]=='.'&&
                (shape.getRotated()==1||shape.getRotated()==3)){
                     //The if for I tetromino which is rotated;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
        else if(shape.getKey()=='O'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'){
                    //The if for O tetromino
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
        else if(shape.getKey()=='T'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+1+count]=='.'&&
                shape.getRotated()==0){
                    //The if for T tetromino which is not rotated;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*(i-2)+((AbstractTetris::length)/2)+count]=='.'&&
                shape.getRotated()==1){
                    //The if for T tetromino which is rotated 1 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+1+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&
                shape.getRotated()==2){
                    //The if for T tetromino which is rotated 2 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+1+count]=='.'&&board[(AbstractTetris::length)*(i-2)+((AbstractTetris::length)/2)+count]=='.'&&
                shape.getRotated()==3){
                    //The if for T tetromino which is rotated 3 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
        else if(shape.getKey()=='J'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-2)+((AbstractTetris::length)/2)+count]=='.'&&
                shape.getRotated()==0){
                    //The if for J tetromino which is rotated 0 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+1+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)-1+count]=='.'&&
                shape.getRotated()==1){
                    //The if for J tetromino which is rotated 1 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)-1+count]=='.'&&
                board[(AbstractTetris::length)*(i-2)+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*(i-2)+((AbstractTetris::length)/2)+count]=='.'&&
                shape.getRotated()==2){
                    //The if for J tetromino which is rotated 2 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+1+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+1+count]=='.'&&
                board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)-1+count]=='.'&&
                shape.getRotated()==3){
                    //The if for J tetromino which is rotated 3 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
        else if(shape.getKey()=='L'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*(i-2)+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+1+count]=='.'&&
                shape.getRotated()==0){
                    //The if for L tetromino which is rotated 0 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)-1+count]=='.'&&
                board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+1+count]=='.'&&
                shape.getRotated()==1){
                    //The if for L tetromino which is rotated 1 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*(i-2)+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-2)+((AbstractTetris::length)/2)-1+count]=='.'&&
                shape.getRotated()==2){
                    //The if for L tetromino which is rotated 2 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+1+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+1+count]=='.'&&
                shape.getRotated()==3){
                    //The if for L tetromino which is rotated 3 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
        else if(shape.getKey()=='S'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+1+count]=='.'&&
                (shape.getRotated()==0||shape.getRotated()==2)){
                    //The if for S tetromino which is rotated 0 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)-1+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)-1+count]=='.'&&board[(AbstractTetris::length)*(i-2)+((AbstractTetris::length)/2)-1+count]=='.'&&
                (shape.getRotated()==1||shape.getRotated()==3)){
                    //The if for S tetromino which is rotated 1 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
        else if(shape.getKey()=='Z'){
            for(auto i=(AbstractTetris::height)-1;i>0;i--){
                if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+1+count]=='.'&&
                board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)-1+count]=='.'&&
                (shape.getRotated()==0||shape.getRotated()==2)){
                    //The if for Z tetromino which is rotated 0 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
                else if(board[(AbstractTetris::length)*i+((AbstractTetris::length)/2)+count]=='.'&&board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+count]=='.'&&
                board[(AbstractTetris::length)*(i-1)+((AbstractTetris::length)/2)+1+count]=='.'&&board[(AbstractTetris::length)*(i-2)+((AbstractTetris::length)/2)+1+count]=='.'&&
                (shape.getRotated()==1||shape.getRotated()==3)){
                    //The if for Z tetromino which is rotated 1 times to right;
                    (AbstractTetris::index_y)=((AbstractTetris::length)/2)+count;
                    (AbstractTetris::index_x)=i;
                    return true;
                }
            }
        }
    return false;
}

bool TetrisArray1D:: game_over()const{
    //CHECKING IF THE BOARD IS FULL OR NOT
    int counter=0;
    for(auto j=1;j<(AbstractTetris::length)-1;j++){
        if(board[(AbstractTetris::length)*2+j]!='.'){
            counter++;
        }
    }
    if(counter>((AbstractTetris::length)/2)){
        return false;
    }
    return true;
}

void TetrisArray1D::create_board(){
    //CREATING A BOARD WITH SIZES
	board=new char[(AbstractTetris::length)*(AbstractTetris::height)];   
}

void TetrisArray1D:: fill_board(){
    // FILLING THE EMPTY BOARD WITH SIZES
    for(auto i=0;i<(AbstractTetris::height);i++){ 
        for(auto j=0;j<(AbstractTetris::length);j++){

            if(j==0 || j==(AbstractTetris::length)-1){
                board[(AbstractTetris::length)*i+j]='X';
            }
            else if(i==0 || i==(AbstractTetris::height)-1){
                board[(AbstractTetris::length)*i+j]='X';
            }
            else{
                board[(AbstractTetris::length)*i+j]='.';
            }
        }
    }
}

void TetrisArray1D:: clear(){
    //this function to clear horizantal fully tables;
    //also it moves every index to down
    int counter=0;
    for(auto i=(AbstractTetris::height)-2;i>0;i--){
        for(auto j=1;j<(AbstractTetris::length)-1;j++){
            if(board[(AbstractTetris::length)*i+j]!='.'){counter++;}
        }
        if(counter==(AbstractTetris::length)-2){
            for(auto k=i-1;k>0;k--){
                for(auto t=1;t<(AbstractTetris::length)-1;t++){
                    board[(AbstractTetris::length)*(k+1)+t]=board[(AbstractTetris::length)*k+t];
                }
            }
            for(auto t=1;t<(AbstractTetris::length)-1;t++){
                board[(AbstractTetris::length)*1+t]='.';
            }
            i=(AbstractTetris::height)-1;
        }
        counter=0;
    }
}

void TetrisArray1D:: draw() const{
    // MY DRAW FUNCTION, DRAWING THE BOARD WITH TETROMINOS
    usleep(500000);
    system("clear");

    for(auto i=0;i<(AbstractTetris::height);i++){
        for(auto j=0;j<(AbstractTetris::length);j++){
            cout<<board[(AbstractTetris::length)*i+j];
        }
        cout<<endl;
    }
}

void TetrisArray1D:: fill_just_y_indexes(const Tetromino &shape){
    // THIS FUNCTION IS TO CHECK IF THERE IS ANY COLLUSION WHEN I MOVE THE TETROMINO RIGHT OR LEFT
    // IF THERE IS A COLLUSION, I PRINT THE TETROMINO JUST CORRECT INDEX WITHOUT MOVING...
    // I NEED TO CHECK EVERY SHAPE AND DIRECTION OF THE SHAPE.
    if(shape.getKey()=='I'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='I';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+1]='I';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+2]='I';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+3]='I';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='I';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='I';
            board[(AbstractTetris::length)*3+(AbstractTetris::index_y)]='I';
            board[(AbstractTetris::length)*4+(AbstractTetris::index_y)]='I';
        }
    }
    else if(shape.getKey()=='O'){
        board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='O';
        board[(AbstractTetris::length)*2+(AbstractTetris::index_y)+1]='O';
        board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='O';
        board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+1]='O';
    }
    else if(shape.getKey()=='T'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)-1]='T';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+1]='T';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::length)*3+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)-1]='T';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='T';
        }
        else if(shape.getRotated()==2){
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)+1]='T';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)+2]='T';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+1]='T';
        }
        else if(shape.getRotated()==3){
            board[(AbstractTetris::length)*3+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)+1]='T';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='T';
        }
    }
    else if(shape.getKey()=='L'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::length)*3+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*3+(AbstractTetris::index_y)+1]='L';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='L';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+1]='L';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+1]='L';
        }
        else if(shape.getRotated()==2){
            board[(AbstractTetris::length)*3+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)-1]='L';
        }
        else if(shape.getRotated()==3){
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)+1]='L';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)+2]='L';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='L';
        }
    }
    else if(shape.getKey()=='J'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::length)*3+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*3+(AbstractTetris::index_y)+1]='J';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)+1]='J';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+1]='J';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)+1]='J';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)+2]='J';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='J';
        }
        else if(shape.getRotated()==2){
            board[(AbstractTetris::length)*3+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+1]='J';
        }
        else if(shape.getRotated()==3){
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)-1]='J';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)-2]='J';
        }
    }
    else if(shape.getKey()=='S'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='S';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)+1]='S';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+1]='S';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+2]='S';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::length)*3+(AbstractTetris::index_y)]='S';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='S';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)-1]='S';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)-1]='S';
        }
    }
    else if(shape.getKey()=='Z'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='Z';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)+1]='Z';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)]='Z';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)-1]='Z';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::length)*3+(AbstractTetris::index_y)]='Z';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)]='Z';
            board[(AbstractTetris::length)*2+(AbstractTetris::index_y)+1]='Z';
            board[(AbstractTetris::length)*1+(AbstractTetris::index_y)+1]='Z';
        }
    }
}

void TetrisArray1D:: fill_indexes(const Tetromino &shape){
    // THIS FUNCTION IS TO CHECK IF THERE IS ANY COLLUSION WHEN I MOVE THE TETROMINO
    // IF THERE IS A COLLUSION, I PRINT THE TETROMINO JUST CORRECT INDEX WITHOUT MOVING...
    // I NEED TO CHECK EVERY SHAPE AND DIRECTION OF THE SHAPE.
    if(shape.getKey()=='I'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='I';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+1]='I';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+2]='I';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+3]='I';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='I';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='I';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-2)+(AbstractTetris::index_y)]='I';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-3)+(AbstractTetris::index_y)]='I';
        }
    }
    else if(shape.getKey()=='O'){
        board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='O';
        board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+1]='O';
        board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='O';
        board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)+1]='O';
    }
    else if(shape.getKey()=='T'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)-1]='T';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)+1]='T';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)-1]='T';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-2)+(AbstractTetris::index_y)]='T';
        }
        else if(shape.getRotated()==2){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+1]='T';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+2]='T';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)+1]='T';
        }
        else if(shape.getRotated()==3){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='T';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)+1]='T';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-2)+(AbstractTetris::index_y)]='T';
        }
    }
    else if(shape.getKey()=='L'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+1]='L';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-2)+(AbstractTetris::index_y)]='L';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)+1]='L';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)+1]='L';
        }
        else if(shape.getRotated()==2){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-2)+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-2)+(AbstractTetris::index_y)-1]='L';
        }
        else if(shape.getRotated()==3){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='L';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+1]='L';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+2]='L';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)+2]='L';
        }
    }
    else if(shape.getKey()=='J'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+1]='J';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)+1]='J';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-2)+(AbstractTetris::index_y)+1]='J';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+1]='J';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+2]='J';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='J';
        }
        else if(shape.getRotated()==2){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-2)+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-2)+(AbstractTetris::index_y)+1]='J';
        }
        else if(shape.getRotated()==3){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='J';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)-1]='J';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)-2]='J';
        }
    }
    else if(shape.getKey()=='S'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='S';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+1]='S';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)+1]='S';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)+2]='S';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='S';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='S';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)-1]='S';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-2)+(AbstractTetris::index_y)-1]='S';
        }
    }
    else if(shape.getKey()=='Z'){
        if(shape.getRotated()==0){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='Z';
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)+1]='Z';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='Z';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)-1]='Z';
        }
        else if(shape.getRotated()==1){
            board[(AbstractTetris::length)*(AbstractTetris::index_x)+(AbstractTetris::index_y)]='Z';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)]='Z';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-1)+(AbstractTetris::index_y)+1]='Z';
            board[(AbstractTetris::length)*((AbstractTetris::index_x)-2)+(AbstractTetris::index_y)+1]='Z';
        }
    }
}



void TetrisArray1D:: move_animation(Tetromino &shape){
    /*
    THIS FUNCTION IS SO BAD BUT IT IS WORKING..
    WHY I SAID SO BAD BECAUSE IT IS ABOUT 1100 LINES..
    I TRY TO EXPLAIN THIS FUNCTION..

    AS YOU CAN UNDERSTAND THE NAME OF FUNCTION, THIS FUNCTION SUBJECT IS ANIMATION OF THE MOVING...
    SINCE EVERY SHAPE AND DIRECTIONS HAVE DIFFERENT INDEXES WHEN I MOVE THEM..7
    THERE ARE SO MANY IF CASES AND FOR LOOPS IN THIS FUNCTION TO GET CORRECT INDEXES WHEN I MOVE A TETROMINO..
    
    FOR EXAMPLE:
    THE TETROMINO IS 'T' TETROMINO
    I CHECK ITS DIRECTION
    IF IT IS NOT ROTATED OR IF IT IS ROTATED ONCE RIGHT OR IF IT IS ROTATED ONCE LEFT
    I MEAN I CHECK EVERY ROTATED CASE OF THE SHAPES..
    ACCORDING TO THE IF CASES I USE FOR LOOPS WHICH STARTING POINTS AND END POINTS ARE DIFFERENT FROM EACH OTHER..
    YOU MAY SAY WHY DID NOT YOU USE ANOTHER FUNCTION FOR LOOPS,
    AS I SAID EVERY FUNCTION HAS DIFFERENT STARTING AND END POINT
    
    I WRITE IN 2 LOOP WHAT IT DOES.. SINCE FUNCTION SO LONG YOU CAN ASSUME THAT OTHER FUNCTIONS DOES SAME THING
    WITH DIFFERENT SHAPES AND INDEXES...
    */
    if(shape.getKey()=='I'){
        if(shape.getRotated()==0){// THAT MEANS IT IS NOT ROTATED
            if(!shape.getAdd()){ // THAT MEANNS Add() FUNCTION DIDNOT WORK SO, THERE WILL BE COLLUSION IF I PRINT TOP BOTTOM. I NEED TO PRINT ITS BEST INDEXES.
                fill_indexes(shape);
                draw();
                return;
            }
            draw();          
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-2){
                // THIS IF TO UNDERSTAND WILL I MOVE THE SHAPE TO THE RIGHT OR LEFT!!!/ IF IS TRUE I WILL MOVE LEFT
                for(auto j=((AbstractTetris::length)/2)-2;j>(AbstractTetris::index_y);j--){
                    // THIS FOR LOOP TO MOVE TO THE LEFT
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    board[(AbstractTetris::length)*1+j+2]='.';
                    board[(AbstractTetris::length)*1+j+3]='.';
                    if(board[(AbstractTetris::length)*1+j-1]!='.'||board[(AbstractTetris::length)*1+j]!='.'
                    ||board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*1+j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j-1]='I';
                    board[(AbstractTetris::length)*1+j]='I';
                    board[(AbstractTetris::length)*1+j+1]='I';
                    board[(AbstractTetris::length)*1+j+2]='I';
                    
                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-2;j<(AbstractTetris::index_y);j++){
                    //THIS FOR LOOP FOR MOVING TO THE RIGHT
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    board[(AbstractTetris::length)*1+j+2]='.';
                    board[(AbstractTetris::length)*1+j+3]='.';
                    if(board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*1+j+2]!='.'
                    ||board[(AbstractTetris::length)*1+j+3]!='.'||board[(AbstractTetris::length)*1+j+4]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j+1]='I';
                    board[(AbstractTetris::length)*1+j+2]='I';
                    board[(AbstractTetris::length)*1+j+3]='I';
                    board[(AbstractTetris::length)*1+j+4]='I';

                    draw();
                }
            }
            for(auto i=2;i<=(AbstractTetris::index_x);i++){
                // THIS FOR LOOP FOR MOVING DOWN
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+2]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+3]='.';
                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]!='.'
                    ||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+2]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+3]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='I';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]='I';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+2]='I';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+3]='I';

                    draw();
                }
        }
        else{// THIS ELSE MEANS THE SHAPE ROTATED
            draw();            
            rotate_added_shape(shape);
            if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'
            &&board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*4+((AbstractTetris::length)/2)]=='.'){
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='I';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='I';
                board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]='I';
                board[(AbstractTetris::length)*4+((AbstractTetris::length)/2)]='I';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            
            draw();
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){// TO UNDERSTAND MOVING RIGHT OR LEFT.. MOVING LEFT
                for(auto j=(AbstractTetris::length)/2;j>(AbstractTetris::index_y);j--){
                    // MOVING LEFT LOOP
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*3+j]='.';
                    board[(AbstractTetris::length)*4+j]='.';
                    if(board[(AbstractTetris::length)*1+j-1]!='.'||board[(AbstractTetris::length)*2+j-1]!='.'
                    ||board[(AbstractTetris::length)*3+j-1]!='.'||board[(AbstractTetris::length)*4+j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j-1]='I';
                    board[(AbstractTetris::length)*2+j-1]='I';
                    board[(AbstractTetris::length)*3+j-1]='I';
                    board[(AbstractTetris::length)*4+j-1]='I';

                    draw();
                }
            }
            else{
                for(auto j=(AbstractTetris::length)/2;j<(AbstractTetris::index_y);j++){
                    //MOVING RIGHT LOOP
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*3+j]='.';
                    board[(AbstractTetris::length)*4+j]='.';
                    if(board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*2+j+1]!='.'
                    ||board[(AbstractTetris::length)*3+j+1]!='.'||board[(AbstractTetris::length)*4+j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j+1]='I';
                    board[(AbstractTetris::length)*2+j+1]='I';
                    board[(AbstractTetris::length)*3+j+1]='I';
                    board[(AbstractTetris::length)*4+j+1]='I';

                    draw();
                }
            }
            for(auto i=5;i<=(AbstractTetris::index_x);i++){
                //MOVING DOWN LOOP
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-4)+(AbstractTetris::index_y)]='.';
                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'
                    ||board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='I';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='I';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='I';
                    board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)]='I';

                    draw();
                }
        }
    }
    else if(shape.getKey()=='O'){
        if(!shape.getAdd()){
            fill_indexes(shape);
            draw();
            return;
        }
        draw(); 
        if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){ // THAT MEANS THE SHAPE WILL MOVE LEFT
            for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                board[(AbstractTetris::length)*1+j]='.';
                board[(AbstractTetris::length)*1+j+1]='.';
                board[(AbstractTetris::length)*2+j]='.';
                board[(AbstractTetris::length)*2+j+1]='.';
                if(board[(AbstractTetris::length)*1+j-1]!='.'||board[(AbstractTetris::length)*1+j]!='.'
                ||board[(AbstractTetris::length)*2+j-1]!='.'||board[(AbstractTetris::length)*2+j]!='.'){
                    fill_just_y_indexes(shape);
                    draw();
                    break;
                }
                board[(AbstractTetris::length)*1+j-1]='O';
                board[(AbstractTetris::length)*1+j]='O';
                board[(AbstractTetris::length)*2+j-1]='O';
                board[(AbstractTetris::length)*2+j]='O';
                
                draw();
            }

        }
        else{// THE SHAPE WILL MOVE RIGHT
            for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                board[(AbstractTetris::length)*1+j]='.';
                board[(AbstractTetris::length)*1+j+1]='.';
                board[(AbstractTetris::length)*2+j]='.';
                board[(AbstractTetris::length)*2+j+1]='.';
                if(board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*1+j+2]!='.'
                ||board[(AbstractTetris::length)*2+j+1]!='.'||board[(AbstractTetris::length)*2+j+2]!='.'){
                    fill_just_y_indexes(shape);
                    draw();
                    break;
                }
                board[(AbstractTetris::length)*1+j+1]='O';
                board[(AbstractTetris::length)*1+j+2]='O';
                board[(AbstractTetris::length)*2+j+1]='O';
                board[(AbstractTetris::length)*2+j+2]='O';
                
                draw();
            }
        }
        for(auto i=3;i<=(AbstractTetris::index_x);i++){ // THIS LOOP TO SHAPE TO MOVE DOWN
                board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='.';
                board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]='.';
                if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]!='.'
                ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]!='.'){
                    fill_indexes(shape);
                    draw();
                    break;
                }
                board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='O';
                board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]='O';
                board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='O';
                board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='O';
                
                draw();
            }
    }
    else if(shape.getKey()=='T'){     
        if(shape.getRotated()==0){
            if(!shape.getAdd()){
                fill_indexes(shape);
                draw();
                return;
            }
            draw();  
            if((AbstractTetris::index_y)<=(AbstractTetris::length)/2){
                for(auto j=(AbstractTetris::length)/2;j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*1+j-1]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    if(board[(AbstractTetris::length)*2+j-1]!='.'||board[(AbstractTetris::length)*1+j-1]!='.'
                    ||board[(AbstractTetris::length)*1+j-2]!='.'||board[(AbstractTetris::length)*1+j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*2+j-1]='T';
                    board[(AbstractTetris::length)*1+j-1]='T';
                    board[(AbstractTetris::length)*1+j-2]='T';
                    board[(AbstractTetris::length)*1+j]='T';

                    draw();
                }
            }
            else{
                for(auto j=(AbstractTetris::length)/2;j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*1+j-1]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    if(board[(AbstractTetris::length)*2+j+1]!='.'||board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*1+j]!='.'
                    ||board[(AbstractTetris::length)*1+j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*2+j+1]='T';
                    board[(AbstractTetris::length)*1+j+1]='T';
                    board[(AbstractTetris::length)*1+j]='T';
                    board[(AbstractTetris::length)*1+j+2]='T';

                    draw();
                }
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)-1]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]='.';
                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)-1]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='T';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='T';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)-1]='T';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='T';

                    draw();
                }
        }
        else if(shape.getRotated()==1){
            draw();            
            rotate_added_shape(shape);
            if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'
            &&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]=='.'&&board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]=='.'){
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='T';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='T';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='T';
                board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]='T';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){
                for(auto j=((AbstractTetris::length)/2);j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*3+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j-1]='.';
                    board[(AbstractTetris::length)*1+j]='.';
                    if(board[(AbstractTetris::length)*3+j-1]!='.'||board[(AbstractTetris::length)*2+j-1]!='.'||board[(AbstractTetris::length)*2+j-2]!='.'
                    ||board[(AbstractTetris::length)*1+j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*3+j-1]='T';
                    board[(AbstractTetris::length)*2+j-1]='T';
                    board[(AbstractTetris::length)*2+j-2]='T';
                    board[(AbstractTetris::length)*1+j-1]='T';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2);j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*3+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j-1]='.';
                    board[(AbstractTetris::length)*1+j]='.';
                    if(board[(AbstractTetris::length)*3+j+1]!='.'||board[(AbstractTetris::length)*2+j+1]!='.'||board[(AbstractTetris::length)*2+j]!='.'
                    ||board[(AbstractTetris::length)*1+j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*3+j+1]='T';
                    board[(AbstractTetris::length)*2+j+1]='T';
                    board[(AbstractTetris::length)*2+j]='T';
                    board[(AbstractTetris::length)*1+j+1]='T';

                    draw();
                }
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)-1]='.';
                    board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)]='.';
                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)-1]!='.'||board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='T';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='T';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)-1]='T';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='T';

                    draw();
                }
        }
        else if(shape.getRotated()==2){
            draw();            
            rotate_added_shape(shape);
            if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]=='.'){
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='T';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='T';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='T';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]='T';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();           
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*2+j+2]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    if(board[(AbstractTetris::length)*2+j-1]!='.'||board[(AbstractTetris::length)*2+j]!='.'
                    ||board[(AbstractTetris::length)*2+j+1]!='.'||board[(AbstractTetris::length)*1+j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*2+j-1]='T';
                    board[(AbstractTetris::length)*2+j]='T';
                    board[(AbstractTetris::length)*2+j+1]='T';
                    board[(AbstractTetris::length)*1+j]='T';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*2+j+2]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    if(board[(AbstractTetris::length)*2+j+1]!='.'||board[(AbstractTetris::length)*2+j+2]!='.'
                    ||board[(AbstractTetris::length)*2+j+3]!='.'||board[(AbstractTetris::length)*1+j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*2+j+1]='T';
                    board[(AbstractTetris::length)*2+j+2]='T';
                    board[(AbstractTetris::length)*2+j+3]='T';
                    board[(AbstractTetris::length)*1+j+2]='T';

                    draw();
                }
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+2]='.';
                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+2]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='T';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]='T';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='T';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+2]='T';

                    draw();
                }
        }
        else if(shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'
            &&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]=='.'&&board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]=='.'){
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='T';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='T';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]='T';
                board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]='T';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }

            draw();            
            if((AbstractTetris::index_y)<=(AbstractTetris::length)/2){
                for(auto j=(AbstractTetris::length)/2;j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*3+j]='.';
                    if(board[(AbstractTetris::length)*1+j-1]!='.'||board[(AbstractTetris::length)*2+j-1]!='.'||board[(AbstractTetris::length)*2+j]!='.'
                    ||board[(AbstractTetris::length)*3+j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j-1]='T';
                    board[(AbstractTetris::length)*2+j-1]='T';
                    board[(AbstractTetris::length)*2+j]='T';
                    board[(AbstractTetris::length)*3+j-1]='T';

                    draw();
                }
            }
            else{
                for(auto j=(AbstractTetris::length)/2;j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*3+j]='.';
                    if(board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*2+j+1]!='.'
                    ||board[(AbstractTetris::length)*2+j+2]!='.'||board[(AbstractTetris::length)*3+j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j+1]='T';
                    board[(AbstractTetris::length)*2+j+1]='T';
                    board[(AbstractTetris::length)*2+j+2]='T';
                    board[(AbstractTetris::length)*3+j+1]='T';

                    draw();
                }  
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)]='.';
                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]!='.'||board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='T';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='T';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='T';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='T';

                    draw();
                }
        }
    }
    else if(shape.getKey()=='J'){       
        if(shape.getRotated()==0){        
            if(!shape.getAdd()){
                fill_indexes(shape);
                draw();
                return;
            }   
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*3+j]='.';
                    board[(AbstractTetris::length)*3+j+1]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    if(board[(AbstractTetris::length)*3+j-1]!='.'||board[(AbstractTetris::length)*3+j]!='.'||board[(AbstractTetris::length)*2+j]!='.'
                    ||board[(AbstractTetris::length)*1+j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*3+j-1]='J';
                    board[(AbstractTetris::length)*3+j]='J';
                    board[(AbstractTetris::length)*2+j]='J';
                    board[(AbstractTetris::length)*1+j]='J';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*3+j]='.';
                    board[(AbstractTetris::length)*3+j+1]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    if(board[(AbstractTetris::length)*3+j+1]!='.'||board[(AbstractTetris::length)*3+j+2]!='.'||board[(AbstractTetris::length)*2+j+2]!='.'
                    ||board[(AbstractTetris::length)*1+j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*3+j+1]='J';
                    board[(AbstractTetris::length)*3+j+2]='J';
                    board[(AbstractTetris::length)*2+j+2]='J';
                    board[(AbstractTetris::length)*1+j+2]='J';

                    draw();
                }
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)+1]='.';
                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]!='.'||board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='J';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]='J';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='J';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]='J';

                    draw();
                }
        }
        else if(shape.getRotated()==1){
            draw();            
            rotate_added_shape(shape);
            if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]=='.'
            &&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]=='.'){
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='J';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='J';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='J';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]='J';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }

            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*2+j+2]='.';
                    if(board[(AbstractTetris::length)*1+j-1]!='.'||board[(AbstractTetris::length)*2+j-1]!='.'||board[(AbstractTetris::length)*2+j]!='.'
                    ||board[(AbstractTetris::length)*2+j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j-1]='J';
                    board[(AbstractTetris::length)*2+j-1]='J';
                    board[(AbstractTetris::length)*2+j]='J';
                    board[(AbstractTetris::length)*2+j+1]='J';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*2+j+2]='.';
                    if(board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*2+j+1]!='.'||board[(AbstractTetris::length)*2+j+2]!='.'
                    ||board[(AbstractTetris::length)*2+j+3]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j+1]='J';
                    board[(AbstractTetris::length)*2+j+1]='J';
                    board[(AbstractTetris::length)*2+j+2]='J';
                    board[(AbstractTetris::length)*2+j+3]='J';

                    draw();
                }
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+2]='.';
                    if(board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'
                    ||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+2]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='J';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='J';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]='J';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+2]='J';

                    draw();
                }
        }
        else if(shape.getRotated()==2){
            draw();            
            rotate_added_shape(shape);
            if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]=='.'&&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'
            &&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]=='.'&&board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)-1]=='.'){
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='J';
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='J';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='J';
                board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)-1]='J';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*3+j]='.';
                    if(board[(AbstractTetris::length)*1+j-1]!='.'||board[(AbstractTetris::length)*1+j]!='.'
                    ||board[(AbstractTetris::length)*2+j-1]!='.'||board[(AbstractTetris::length)*3+j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j-1]='J';
                    board[(AbstractTetris::length)*1+j]='J';
                    board[(AbstractTetris::length)*2+j-1]='J';
                    board[(AbstractTetris::length)*3+j-1]='J';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*3+j]='.';
                    if(board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*1+j+2]!='.'
                    ||board[(AbstractTetris::length)*2+j+1]!='.'||board[(AbstractTetris::length)*3+j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j+1]='J';
                    board[(AbstractTetris::length)*1+j+2]='J';
                    board[(AbstractTetris::length)*2+j+1]='J';
                    board[(AbstractTetris::length)*3+j+1]='J';

                    draw();
                }
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    if(board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='J';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]='J';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='J';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='J';

                    draw();
                }
        }
        else if(shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]=='.'&&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'
            &&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]=='.'){
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='J';
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='J';
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='J';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]='J';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)+1){
                for(auto j=((AbstractTetris::length)/2)+1;j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*1+j-2]='.';
                    board[(AbstractTetris::length)*1+j-1]='.';
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    if(board[(AbstractTetris::length)*1+j-3]!='.'||board[(AbstractTetris::length)*1+j-2]!='.'||board[(AbstractTetris::length)*1+j-1]!='.'
                    ||board[(AbstractTetris::length)*2+j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j-3]='J';
                    board[(AbstractTetris::length)*1+j-2]='J';
                    board[(AbstractTetris::length)*1+j-1]='J';
                    board[(AbstractTetris::length)*2+j-1]='J';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)+1;j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*1+j-2]='.';
                    board[(AbstractTetris::length)*1+j-1]='.';
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    if(board[(AbstractTetris::length)*1+j-1]!='.'||board[(AbstractTetris::length)*1+j]!='.'
                    ||board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*2+j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j-1]='J';
                    board[(AbstractTetris::length)*1+j]='J';
                    board[(AbstractTetris::length)*1+j+1]='J';
                    board[(AbstractTetris::length)*2+j+1]='J';

                    draw();
                }
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)-1]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)-2]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    if(board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)-1]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)-2]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='J';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)-1]='J';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)-2]='J';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='J';

                    draw();
                }
        }
    }
    else if(shape.getKey()=='L'){
        if(shape.getRotated()==0){  
            if(!shape.getAdd()){
                fill_indexes(shape);
                draw();
                return;
            }         
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){
                for(auto j=((AbstractTetris::length)/2);j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*3+j]='.';
                    board[(AbstractTetris::length)*3+j+1]='.';
                    if(board[(AbstractTetris::length)*1+j-1]!='.'||board[(AbstractTetris::length)*2+j-1]!='.'
                    ||board[(AbstractTetris::length)*3+j-1]!='.'||board[(AbstractTetris::length)*3+j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;  
                    }
                    board[(AbstractTetris::length)*1+j-1]='L';
                    board[(AbstractTetris::length)*2+j-1]='L';
                    board[(AbstractTetris::length)*3+j-1]='L';
                    board[(AbstractTetris::length)*3+j]='L';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2);j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*3+j]='.';
                    board[(AbstractTetris::length)*3+j+1]='.';
                    if(board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*2+j+1]!='.'
                    ||board[(AbstractTetris::length)*3+j+1]!='.'||board[(AbstractTetris::length)*3+j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;  
                    }
                    board[(AbstractTetris::length)*1+j+1]='L';
                    board[(AbstractTetris::length)*2+j+1]='L';
                    board[(AbstractTetris::length)*3+j+1]='L';
                    board[(AbstractTetris::length)*3+j+2]='L';

                    draw();
                }
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)]='.';
                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='L';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]='L';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='L';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='L';

                    draw();
                }
        }
        else if(shape.getRotated()==1){
            draw();            
            rotate_added_shape(shape);
            if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]=='.'
            &&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]=='.'){
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='L';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='L';
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='L';
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='L';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();           
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    board[(AbstractTetris::length)*1+j+2]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    if(board[(AbstractTetris::length)*1+j-1]!='.'||board[(AbstractTetris::length)*1+j]!='.'
                    ||board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*2+j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*1+j-1]='L';
                    board[(AbstractTetris::length)*1+j]='L';
                    board[(AbstractTetris::length)*1+j+1]='L';
                    board[(AbstractTetris::length)*2+j-1]='L';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    board[(AbstractTetris::length)*1+j+2]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    if(board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*1+j+2]!='.'
                    ||board[(AbstractTetris::length)*1+j+3]!='.'||board[(AbstractTetris::length)*2+j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*1+j+1]='L';
                    board[(AbstractTetris::length)*1+j+2]='L';
                    board[(AbstractTetris::length)*1+j+3]='L';
                    board[(AbstractTetris::length)*2+j+1]='L';

                    draw();
                }
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+2]='.';
                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='L';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='L';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='L';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+2]='L';

                    draw();
                }
        }
        else if(shape.getRotated()==2){
            draw();            
            rotate_added_shape(shape);
            if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]=='.'&&board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]=='.'
            &&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]=='.'&&board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)-1]=='.'){
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='L';
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)]='L';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='L';
                board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]='L';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){
                for(auto j=((AbstractTetris::length)/2);j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*1+j-1]='.';
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*3+j]='.';
                    if(board[(AbstractTetris::length)*1+j-1]!='.'||board[(AbstractTetris::length)*1+j-1]!='.'
                    ||board[(AbstractTetris::length)*2+j-1]!='.'||board[(AbstractTetris::length)*3+j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*1+j-2]='L';
                    board[(AbstractTetris::length)*1+j-1]='L';
                    board[(AbstractTetris::length)*2+j-1]='L';
                    board[(AbstractTetris::length)*3+j-1]='L';
                        draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2);j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*1+j-1]='.';
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*3+j]='.';
                    if(board[(AbstractTetris::length)*1+j]!='.'||board[(AbstractTetris::length)*1+j+1]!='.'
                    ||board[(AbstractTetris::length)*2+j+1]!='.'||board[(AbstractTetris::length)*3+j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*1+j]='L';
                    board[(AbstractTetris::length)*1+j+1]='L';
                    board[(AbstractTetris::length)*2+j+1]='L';
                    board[(AbstractTetris::length)*3+j+1]='L';
                        draw();
                }
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)-1]='.';
                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'
                    ||board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)-1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='L';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='L';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='L';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)-1]='L';

                    draw();
                }
        }
        else if(shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]=='.'
            &&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]=='.'){
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='L';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='L';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='L';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]='L';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
        
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*1+j+2]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*2+j+2]='.';
                    if(board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*2+j-1]!='.'
                    ||board[(AbstractTetris::length)*2+j]!='.'||board[(AbstractTetris::length)*2+j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*1+j+1]='L';
                    board[(AbstractTetris::length)*2+j-1]='L';
                    board[(AbstractTetris::length)*2+j]='L';
                    board[(AbstractTetris::length)*2+j+1]='L';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*1+j+2]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*2+j+2]='.';
                    if(board[(AbstractTetris::length)*1+j+3]!='.'||board[(AbstractTetris::length)*2+j+1]!='.'
                    ||board[(AbstractTetris::length)*2+j+2]!='.'||board[(AbstractTetris::length)*2+j+3]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*1+j+3]='L';
                    board[(AbstractTetris::length)*2+j+1]='L';
                    board[(AbstractTetris::length)*2+j+2]='L';
                    board[(AbstractTetris::length)*2+j+3]='L';

                    draw();
                }
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+2]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+2]='.';
                    if(board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+2]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'
                    ||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+2]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+2]='L';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='L';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]='L';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+2]='L';

                    draw();
                }
        }
    }
    else if(shape.getKey()=='S'){
        if(shape.getRotated()==0 || shape.getRotated()==2){
            if(!shape.getAdd()){
                fill_indexes(shape);
                draw();
                return;
            }
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)-1){
                for(auto j=((AbstractTetris::length)/2)-1;j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    board[(AbstractTetris::length)*1+j+2]='.';
                    if(board[(AbstractTetris::length)*2+j-1]!='.'||board[(AbstractTetris::length)*2+j]!='.'
                    ||board[(AbstractTetris::length)*1+j-1]!='.'||board[(AbstractTetris::length)*1+j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*2+j-1]='S';
                    board[(AbstractTetris::length)*2+j]='S';
                    board[(AbstractTetris::length)*1+j]='S';
                    board[(AbstractTetris::length)*1+j+1]='S';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2)-1;j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*1+j+1]='.';
                    board[(AbstractTetris::length)*1+j+2]='.';
                    if(board[(AbstractTetris::length)*2+j+1]!='.'||board[(AbstractTetris::length)*2+j+2]!='.'
                    ||board[(AbstractTetris::length)*1+j+2]!='.'||board[(AbstractTetris::length)*1+j+3]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*2+j+1]='S';
                    board[(AbstractTetris::length)*2+j+2]='S';
                    board[(AbstractTetris::length)*1+j+2]='S';
                    board[(AbstractTetris::length)*1+j+3]='S';

                    draw();
                }
                
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+2]='.';
                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+2]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='S';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]='S';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='S';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+2]='S';

                    draw();
                }
        }
        else if(shape.getRotated()==1 || shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]=='.'
            &&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]=='.'){
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)-1]='S';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)-1]='S';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='S';
                board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]='S';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){
                for(auto j=((AbstractTetris::length)/2);j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*1+j-1]='.';
                    board[(AbstractTetris::length)*2+j-1]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*3+j]='.';
                    if(board[(AbstractTetris::length)*1+j-2]!='.'||board[(AbstractTetris::length)*2+j-2]!='.'
                    ||board[(AbstractTetris::length)*2+j-1]!='.'||board[(AbstractTetris::length)*3+j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    board[(AbstractTetris::length)*1+j-2]='S';
                    board[(AbstractTetris::length)*2+j-2]='S';
                    board[(AbstractTetris::length)*2+j-1]='S';
                    board[(AbstractTetris::length)*3+j-1]='S';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2);j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*1+j-1]='.';
                    board[(AbstractTetris::length)*2+j-1]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*3+j]='.';
                    if(board[(AbstractTetris::length)*1+j]!='.'||board[(AbstractTetris::length)*2+j]!='.'
                    ||board[(AbstractTetris::length)*2+j+1]!='.'||board[(AbstractTetris::length)*3+j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j]='S';
                    board[(AbstractTetris::length)*2+j]='S';
                    board[(AbstractTetris::length)*2+j+1]='S';
                    board[(AbstractTetris::length)*3+j+1]='S';

                    draw();
                }
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)-1]='.';
                    board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)-1]='.';
                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)-1]!='.'||board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)-1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='S';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='S';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)-1]='S';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)-1]='S';

                    draw();

                }
        }
    }
    else if(shape.getKey()=='Z'){
        if(shape.getRotated()==0 || shape.getRotated()==2){
            if(!shape.getAdd()){
                fill_indexes(shape);
                draw();
                return;
            }
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){
                for(auto j=((AbstractTetris::length)/2);j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*1+j-1]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    if(board[(AbstractTetris::length)*1+j-1]!='.'||board[(AbstractTetris::length)*1+j-2]!='.'
                    ||board[(AbstractTetris::length)*2+j-1]!='.'||board[(AbstractTetris::length)*2+j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j-1]='Z';
                    board[(AbstractTetris::length)*1+j-2]='Z';
                    board[(AbstractTetris::length)*2+j-1]='Z';
                    board[(AbstractTetris::length)*2+j]='Z';

                    draw();
                }
            }
            else{
                for(auto j=((AbstractTetris::length)/2);j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*1+j]='.';
                    board[(AbstractTetris::length)*1+j-1]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';

                    if(board[(AbstractTetris::length)*1+j+1]!='.'||board[(AbstractTetris::length)*1+j]!='.'
                    ||board[(AbstractTetris::length)*2+j+1]!='.'||board[(AbstractTetris::length)*2+j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j+1]='Z';
                    board[(AbstractTetris::length)*1+j]='Z';
                    board[(AbstractTetris::length)*2+j+1]='Z';
                    board[(AbstractTetris::length)*2+j+2]='Z';

                    draw();
                }
                
            }
            for(auto i=3;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)-1]='.';

                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)-1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='Z';
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)+1]='Z';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='Z';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)-1]='Z';

                    draw();
                }
        }
        else if(shape.getRotated()==1 || shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]=='.'&&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]=='.'
            &&board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]=='.'&&board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]=='.'){
                board[(AbstractTetris::length)*1+((AbstractTetris::length)/2)+1]='Z';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)+1]='Z';
                board[(AbstractTetris::length)*2+((AbstractTetris::length)/2)]='Z';
                board[(AbstractTetris::length)*3+((AbstractTetris::length)/2)]='Z';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if((AbstractTetris::index_y)<=((AbstractTetris::length)/2)){
                for(auto j=((AbstractTetris::length)/2);j>(AbstractTetris::index_y);j--){
                    board[(AbstractTetris::length)*1+j+1]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*3+j]='.';

                    if(board[(AbstractTetris::length)*1+j]!='.'||board[(AbstractTetris::length)*2+j]!='.'||board[(AbstractTetris::length)*2+j-1]!='.'
                    ||board[(AbstractTetris::length)*3+j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j]='Z';
                    board[(AbstractTetris::length)*2+j]='Z';
                    board[(AbstractTetris::length)*2+j-1]='Z';
                    board[(AbstractTetris::length)*3+j-1]='Z';

                    draw();
                }          
            }
            else{
                for(auto j=((AbstractTetris::length)/2);j<(AbstractTetris::index_y);j++){
                    board[(AbstractTetris::length)*1+j+1]='.';
                    board[(AbstractTetris::length)*2+j+1]='.';
                    board[(AbstractTetris::length)*2+j]='.';
                    board[(AbstractTetris::length)*3+j]='.';

                    if(board[(AbstractTetris::length)*1+j+2]!='.'||board[(AbstractTetris::length)*2+j+2]!='.'||board[(AbstractTetris::length)*2+j+1]!='.'
                    ||board[(AbstractTetris::length)*3+j+1]!='.'){
                        fill_just_y_indexes(shape);             
                        draw();
                        break;
                    }
                    board[(AbstractTetris::length)*1+j+2]='Z';
                    board[(AbstractTetris::length)*2+j+2]='Z';
                    board[(AbstractTetris::length)*2+j+1]='Z';
                    board[(AbstractTetris::length)*3+j+1]='Z';

                    draw();

                }
                
            }
            for(auto i=4;i<=(AbstractTetris::index_x);i++){
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)]='.';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]='.';
                    board[(AbstractTetris::length)*(i-3)+(AbstractTetris::index_y)+1]='.';

                    if(board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]!='.'||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]!='.'
                    ||board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]!='.'||board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]!='.'){
                        fill_indexes(shape);
                        break;
                    }
                    board[(AbstractTetris::length)*i+(AbstractTetris::index_y)]='Z';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)]='Z';
                    board[(AbstractTetris::length)*(i-1)+(AbstractTetris::index_y)+1]='Z';
                    board[(AbstractTetris::length)*(i-2)+(AbstractTetris::index_y)+1]='Z';

                    draw();
                }
        }
    }

}







