#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include "driver2.hpp"

#ifndef _DRIVER1_HPP_
#define _DRIVER1_HPP_


/*
comment lines are in util.cpp
*/


namespace Tet{
    // GLOBAL FUNCTIONS
static int numberOfMoves(int move_count){
    static int total=0;// COUNTING TOTAL MOVES
    total+=move_count;
    return total;
}

template <class T>
void lastMove(T &t1, string move_direction, string rotate_direction, int move_count, int rotate_count){
    try{
        if(t1.getLastKey()=='A'){// THAT MEANS NO SHAPES ENTERED THROW -1 AN INTEGER
            throw -1;
        }
        else{
            throw 'T';
        }
    }
    catch(int x){
        cout<<"There is no last move information!"<<endl;
    }
    catch(char a){
        cout<<"\n---LAST TETROMINO---"<<endl;
        cout<<"Tetromino type: "<<t1.getLastKey()<<endl;
        cout<<"Tetromino rotate direction: "<<rotate_direction<<endl;
        cout<<"Tetromino rotate count: "<<rotate_count<<endl;
        cout<<"Tetromino move direction: "<<move_direction<<endl;
        cout<<"Tetromino move count: "<<move_count<<endl;
    }
}


template <class T>
void print_menu(T &t1){
    fstream file;
    int temp_count_rotate;
    int total_move;
    string game;
    cout<<"L for load previous game, any key to new game: ";
    cin>>game;
    if(game=="L" || game=="l")
        t1.readFromFile(file);
    string ch="a",rotate_direction,move_direction;
    int count_rotate,count_move,number;
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
            numberOfMoves(count_move);
            temp_count_rotate=count_rotate;
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
            break;
        }
        else{
            cerr<<"You typed incorrectly"<<endl;
        }
        if(!t1.game_over()){
            cout<<"The board is fulled."<<endl;
            break;
        }
        string choice;
        cout<<"Do you want to see last Tetromino and its features? (Y/N) ";
        cin>>choice;
        if(choice=="Y" || choice=="y"){
            lastMove(t1,move_direction,rotate_direction,count_move,temp_count_rotate);
        }
        number=-1;
    }
    cout<<"Number of Moves: "<<numberOfMoves(0)<<endl<<endl;
    cout<<"Do you want to save game?(Y/N) ";
    cin>>game;
    if(game=="Y" || game == "y"){
        t1.writeToFile(file);
        cout<<"The game has been successfully saved!"<<endl;\
    }
    else if(game=="N" || game=="n"){
        cout<<"Good bye!"<<endl;
    }
    else{
        cout<<"You typed incorrectly, the game wasn't saved. Good bye!"<<endl;
    }
    exit(0);
}


    class AbstractTetris{
    public:
        AbstractTetris(int h=10, int l=10);
        virtual ~AbstractTetris();
        // Pure virtual functions declerations
        virtual void draw() const =0;
        virtual void Animate(Tetromino &shape, int count_move, int count_rotate, string direction)=0;
        virtual bool check_index(const Tetromino &shape, int count, string direction)=0;
        virtual void clear_top(const Tetromino &shape)=0;
        virtual void clear()=0;
        virtual void fill_board()=0;
        virtual void rotate_added_shape(const Tetromino &shape)=0;
        virtual bool game_over() const =0;
        virtual void move_animation(Tetromino &shape)=0;
        virtual void fill_indexes(const Tetromino &shape)=0;
        virtual void fill_just_y_indexes(const Tetromino &shape)=0;
        virtual AbstractTetris& operator+=(Tetromino &shape)=0;
        virtual void readFromFile(fstream &file)=0;
        virtual void writeToFile(fstream &file)=0;
        virtual int getHeight()const{return height;}
        virtual int getLength()const{return length;}
    protected:
        //char **board;
        int height;
        int length;
        int index_x,index_y; // to keep indexes that will be fitted with the shape;
    };


    class TetrisVector:public AbstractTetris{
    public:
        TetrisVector(int h=10, int l=10);
        ~TetrisVector();
        vector< vector<char> > getBoard(){return board;}
        void create_board();
        void fill_board();
        void draw() const;
        void Animate(Tetromino &shape, int count_move, int count_rotate, string direction);
        bool check_index(const Tetromino &shape, int count, string direction);
        void clear_top(const Tetromino &shape);
        void clear();
        void rotate_added_shape(const Tetromino &shape);
        bool game_over() const;
        void move_animation(Tetromino &shape);
        void fill_indexes(const Tetromino &shape);
        void fill_just_y_indexes(const Tetromino &shape);
        void readFromFile(fstream &file);
        void writeToFile(fstream &file);
        char getLastKey(){return last_tetro;}
        TetrisVector& operator+=(Tetromino &shape);
        void driver_test(){ // just for testing functions . for driver1.cpp
            for(auto i=1;i<AbstractTetris::length-1;i++){
                if(board[AbstractTetris::height-2][i]=='.'){
                    board[AbstractTetris::height-2][i]='A';
                }
            }
        }
        
    private:   
        vector< vector<char> > board={ {' ', ' ', ' ',' '},{' ',' ', ' ', ' '},{' ', ' ', ' ',' '},{' ',' ',' ',' '}};
        char last_tetro='A';
    };


    class TetrisArray1D:public AbstractTetris{
    public:
        TetrisArray1D(int h, int l);
        ~TetrisArray1D();
        char *getBoard(){return board;}
        void create_board();
        void fill_board();
        void draw() const;
        void Animate(Tetromino &shape, int count_move, int count_rotate, string direction);
        bool check_index(const Tetromino &shape, int count, string direction);
        void clear_top(const Tetromino &shape);
        void clear();
        void rotate_added_shape(const Tetromino &shape);
        bool game_over() const;
        void move_animation(Tetromino &shape);
        void fill_indexes(const Tetromino &shape);
        void fill_just_y_indexes(const Tetromino &shape);
        void readFromFile(fstream &file);
        void writeToFile(fstream &file);
        char getLastKey(){return last_tetro;}
        TetrisArray1D& operator+=(Tetromino &shape);
        void driver_test(){ // just for testing functions . for driver1.cpp
            for(auto i=1;i<AbstractTetris::length-1;i++){
                if(board[AbstractTetris::length*(AbstractTetris::height-2)+i]=='.'){
                    board[AbstractTetris::length*(AbstractTetris::height-2)+i]='A';
                }
            }
        }
    private:
        char *board;
        char last_tetro='A';
    };

    template <class T>
    class TetrisAdapter: public AbstractTetris{
    public:
        TetrisAdapter(int h=10, int l=10);
        ~TetrisAdapter();
        T getBoard(){return board;}
        void create_board();
        void fill_board();
        void draw() const;
        void Animate(Tetromino &shape, int count_move, int count_rotate, string direction);
        bool check_index(const Tetromino &shape, int count, string direction);
        void clear_top(const Tetromino &shape);
        void clear();
        void rotate_added_shape(const Tetromino &shape);
        bool game_over() const;
        void move_animation(Tetromino &shape);
        void fill_indexes(const Tetromino &shape);
        void fill_just_y_indexes(const Tetromino &shape);
        void readFromFile(fstream &file);
        void writeToFile(fstream &file);
        char getLastKey(){return last_tetro;}
        TetrisAdapter<T>& operator+=(Tetromino &shape);
        void driver_test();
    private:
        T board;
        char last_tetro='A';
    };



// Template class definitions.. why i put these long code here instead of util.cpp->>> when i compile code if this definitions
// are in util.cpp i got errors which is not compiler which is written white messages... However, i run this code with this hpp file
// everything is okey, why this happens i dont know
template <class T>
TetrisAdapter<T>::TetrisAdapter(int h, int l): AbstractTetris(h,l){
    create_board();
    fill_board();
}

template <class T>
TetrisAdapter<T>::~TetrisAdapter(){
    board.clear();
}

template<class T>
void TetrisAdapter<T>::writeToFile(fstream &file){
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

template<class T>
void TetrisAdapter<T>::readFromFile(fstream &file){
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

template <class T>
TetrisAdapter<T>& TetrisAdapter<T>:: operator+=(Tetromino &shape){
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

template <class T>
void TetrisAdapter<T>:: rotate_added_shape(const Tetromino &shape){
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

template <class T>
void TetrisAdapter<T>:: Animate(Tetromino &shape, int count_move, int count_rotate, string direction){
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
    if(check_index(shape,count_move,direction)){// THAT MEANS THE SHAPE WITH ROTATED FORM CAN BE FITTED TO THE BOARD
        move_animation(shape);
        clear();
        draw();
    } 
    else{
        cerr<<"\nThe shape cannot be fitted that index\n"<<endl;
        clear_top(shape);
        //draw();
    }
    
}

template <class T>
void TetrisAdapter<T>:: clear_top(const Tetromino &shape){
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

template <class T>
bool TetrisAdapter<T>:: check_index(const Tetromino &shape, int count, string direction){
    //these function to get indexes the user want;
    //for example shape is T tetromino without rotated;
    //user wants to move it 2 times to right;
    //i check the downest index the shape can be fitted;
    //and i keep that index in my (AbstractTetris::index_x) and (AbstractTetris::index_y) variables which is coming from AbstractTetris class
    if(((AbstractTetris::length)/2)+count>(AbstractTetris::length)){
        cerr<<"Out of the range!\n"<<endl;
        return false;
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

template <class T>
bool TetrisAdapter<T>:: game_over()const{
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

template <class T>
void TetrisAdapter<T>::create_board(){
    //CREATING A BOARD WITH SIZES
	int i=0;
	board.resize((AbstractTetris::height));
	for (int i = 0; i <(AbstractTetris::height); ++i)
        board[i].resize((AbstractTetris::length));
    
}

template <class T>
void TetrisAdapter<T>:: fill_board(){
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

template <class T>
void TetrisAdapter<T>:: clear(){
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

template <class T>
void TetrisAdapter<T>:: draw() const{
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

template <class T>
void TetrisAdapter<T>:: fill_just_y_indexes(const Tetromino &shape){
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

template <class T>
void TetrisAdapter<T>:: fill_indexes(const Tetromino &shape){
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

template <class T>
void TetrisAdapter<T>::driver_test(){
    for(auto i=1;i<AbstractTetris::length-1;i++){
        if(board[AbstractTetris::height-2][i]=='.'){
            board[AbstractTetris::height -2][i]='A';
        }
    }
}


template <class T>
void TetrisAdapter<T>:: move_animation(Tetromino &shape){
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
                    fill_just_y_indexes(shape);
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



}



#endif