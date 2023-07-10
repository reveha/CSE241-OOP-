#include "driver1.hpp"
#include "driver2.hpp"

using namespace std;



Tetris:: Tetris(int h, int l){
    /*
    THIS IS MY CONSTRUCTOR WHICH DOES ASSIGNMENT FOR HEIGHT AND LENGTH AND CREATE BOARD;
    */
    b.height=h;
    b.length=l;
    create_board();
    fill_board();
}

void Tetris:: Add(Tetromino &shape){
    /*
    Add() FUNCTION ADDS THE TETROMINO TO THE BOARD ACCORDING TO THE ITS SHAPE
    ONLY IF THE BOARD IS AVALIABLE TO PRINT TOP BOTTOM
    */
    if(shape.getKey()=='I'){
        if(b.board[1][(b.length/2)-2]=='.'&&b.board[1][(b.length/2)-1]=='.'&&b.board[1][(b.length/2)]=='.'&&b.board[1][(b.length/2)+1]=='.'){
            b.board[1][(b.length/2)-2]='I';
            b.board[1][(b.length/2)-1]='I';
            b.board[1][(b.length/2)]='I';
            b.board[1][(b.length/2)+1]='I';
            shape.setAdd(true); // that means the shape are printed the top bottom screen
        }
        else{
            shape.setAdd(false);//that means i couldn't do it
        } 
    }
    else if(shape.getKey()=='O'){
        if(b.board[1][(b.length/2)-1]=='.'&&b.board[2][(b.length/2)-1]=='.'&&b.board[1][(b.length/2)]=='.'&&b.board[2][(b.length/2)]=='.'){
            b.board[1][(b.length/2)-1]='O';
            b.board[2][(b.length/2)-1]='O';
            b.board[1][(b.length/2)]='O';
            b.board[2][(b.length/2)]='O';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        } 
    }
    else if(shape.getKey()=='T'){
        if(b.board[1][b.length/2]=='.'&&b.board[1][(b.length/2)-1]=='.'&&b.board[1][(b.length/2)+1]=='.'&&b.board[2][b.length/2]=='.'){
            b.board[1][b.length/2]='T';
            b.board[1][(b.length/2)-1]='T';
            b.board[1][(b.length/2)+1]='T';
            b.board[2][b.length/2]='T';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }       
    }
    else if(shape.getKey()=='J'){
        if(b.board[1][b.length/2]=='.'&&b.board[2][b.length/2]=='.'&&b.board[3][b.length/2]=='.'&&b.board[3][(b.length/2)-1]=='.'){
            b.board[1][b.length/2]='J';
            b.board[2][b.length/2]='J';
            b.board[3][b.length/2]='J';
            b.board[3][(b.length/2)-1]='J';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }
    }
    else if(shape.getKey()=='L'){
        if(b.board[1][b.length/2]=='.'&&b.board[2][b.length/2]=='.'&&b.board[3][b.length/2]=='.'&&b.board[3][(b.length/2)+1]=='.'){
            b.board[1][b.length/2]='L';
            b.board[2][b.length/2]='L';
            b.board[3][b.length/2]='L';
            b.board[3][(b.length/2)+1]='L';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }
    }
    else if(shape.getKey()=='S'){
        if(b.board[1][b.length/2]=='.'&&b.board[2][b.length/2]=='.'&&b.board[1][(b.length/2)+1]=='.'&&b.board[2][(b.length/2)-1]=='.'){
            b.board[1][b.length/2]='S';
            b.board[2][b.length/2]='S';
            b.board[1][(b.length/2)+1]='S';
            b.board[2][(b.length/2)-1]='S';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }
    }
    else if(shape.getKey()=='Z'){
        if(b.board[1][b.length/2]=='.'&&b.board[2][b.length/2]=='.'&&b.board[1][(b.length/2)-1]=='.'&&b.board[2][(b.length/2)+1]=='.'){
            b.board[1][b.length/2]='Z';
            b.board[2][b.length/2]='Z';
            b.board[1][(b.length/2)-1]='Z';
            b.board[2][(b.length/2)+1]='Z';
            shape.setAdd(true);
        }
        else{
            shape.setAdd(false);
        }
    }
}

void Tetris:: find_index(Tetromino &shape){ 
    /*
    find_index() FUNCTION FINDS THE INDEXES WHICH THE TETROMINO WILL BE FITTED 
    ACCORDING TO THE INDEXES I ROTATED THE SHAPES AND RETURNED IT
    SINCE EVERY TETROMINO SHAPES HAS DIFFERENT INDEXES I NEED TO CHECK EVERY SHAPE WITH ITS OWN INDEXES
    SO, THERE ARE A LOT OF FOR LOOPS AND IF CASES IN THIS FUNCTION
    
    WHEN THE PROGRAM FOUND A SPACE INDEX IN THE BOARD
    ACCORDING TO THE SHAPE AND ITS DIRECTION IT CHECKS OTHER INDEXES, IF ANY SHAPE WITH ANY ROTATION FITS THE INDEXES
    IT IS OKEY RETURN 
    */
    // returns columns of the best index for shape
    int check=0; // to understand which rotation of the shape is correct to fit
    for(auto i=b.height-2;i>0;i--){
        for(auto j=1;j<b.length-1;j++){
            if(b.board[i][j]=='.'){
                if(shape.getKey()=='T'){
                    for(auto k=j;k<b.length-1;k++){
                        // THIS IF CASES TO UNDERSTAND DIRECTION OF THE SHAPE
                        if(b.board[i][k]=='.' && b.board[i][k+1]=='.' && b.board[i][k+2]=='.' && b.board[i-1][k+1]=='.'){
                            check=1;
                            index_y=k;
                            index_x=i;
                            shape.rotate();
                            shape.rotate();
                            return;
                        }
                    }
                    if(!check){
                        for(auto k=j;k<b.length-1;k++){
                            // THIS IF CASES TO UNDERSTAND DIRECTION OF THE SHAPE
                            if(b.board[i][k]=='.' && b.board[i-1][k]=='.' && b.board[i-1][k+1]=='.' && b.board[i-1][k-1]=='.' && b.board[i][k+1]!='.' && b.board[i][k-1]!='.'){
                                check=1;
                                index_y=k;
                                index_x=i;
                                return;
                            }
                            // THIS IF CASES TO UNDERSTAND DIRECTION OF THE SHAPE
                            else if(b.board[i][k]=='.' && b.board[i-1][k]=='.' && b.board[i-1][k+1]=='.' && b.board[i-2][k]=='.' && b.board[i][k+1]!='.'){
                                check=1;
                                index_y=k;
                                index_x=i;
                                shape.rotate();
                                shape.rotate();
                                shape.rotate();
                                return;
                            }
                            // THIS IF CASES TO UNDERSTAND DIRECTION OF THE SHAPE
                            else if(b.board[i][k]=='.' && b.board[i-1][k]=='.' && b.board[i-1][k-1]=='.' && b.board[i-2][k]=='.' && b.board[i][k-1]!='.'){
                                check=1;
                                index_y=k;
                                index_x=i;
                                shape.rotate();
                                return;
                            }
                        }
                    }
                }
                else if(shape.getKey()=='I'){
                    for(auto k=j;k<b.length-1;k++){
                        if(b.board[i][k]=='.' && b.board[i][k+1]=='.' && b.board[i][k+2]=='.' && b.board[i][k+3]=='.' && k<=b.length-5){
                            check=1;
                            index_y=k;
                            index_x=i;
                            return;
                        }
                    }
                    if(!check){
                        for(auto k=j;k<b.length-1;k++){
                            if(b.board[i][k]=='.' && b.board[i-1][k]=='.' && b.board[i-2][k]=='.' && b.board[i-3][k]=='.' && i-4>=0){
                                shape.rotate();
                                check=1;
                                index_y=k;
                                index_x=i;
                                return;
                            }  
                        }
                    }
                }
                else if(shape.getKey()=='O'){
                    for(auto k=j;k<b.length-1;k++){
                        if(b.board[i][k]=='.' && b.board[i][k+1]=='.' && b.board[i-1][k]=='.' && b.board[i-1][k+1]=='.'){
                            check=1;
                            index_y=k;
                            index_x=i;
                            return;
                        }
                    }
                }
                else if(shape.getKey()=='J'){
                    for(auto k=j;k<b.length-1;k++){
                        if(b.board[i][k]=='.' && b.board[i][k+1]=='.' && b.board[i][k+2]=='.' && b.board[i-1][k]=='.' && k<=b.length-4){
                            check=1;
                            index_x=i;
                            index_y=k;
                            shape.rotate();
                            return;
                        }
                    }
                    if(!check){
                        for(auto k=j;k<b.length-1;k++){
                            if(b.board[i][k]=='.' && b.board[i][k+1]=='.' && b.board[i-1][k+1]=='.' && b.board[i-2][k+1]=='.'){
                                check=1;
                                index_x=i;
                                index_y=k;
                                return;
                            }
                            else if(b.board[i][k]=='.' && b.board[i-1][k]=='.' && b.board[i-1][k-1]=='.' && b.board[i-1][k-2]=='.'){
                                check=1;
                                index_x=i;
                                index_y=k;
                                shape.rotate();
                                shape.rotate();
                                shape.rotate();
                                return;
                            }
                            else if(b.board[i][k]=='.' && b.board[i-1][k]=='.' && b.board[i-2][k]=='.' && b.board[i-2][k+1]=='.'){
                                check=1;
                                index_x=i;
                                index_y=k;
                                shape.rotate();
                                shape.rotate();
                                return;
                            }
                            
                        }
                    }
                }
                else if(shape.getKey()=='L'){
                    for(auto k=j;k<b.length-1;k++){
                        if(b.board[i][k]=='.' && b.board[i][k+1]=='.' && b.board[i][k+2]=='.' && b.board[i-1][k+2]=='.' && k<=b.length-4){
                            check=1;
                            index_x=i;
                            index_y=k;
                            shape.rotate();
                            shape.rotate();
                            shape.rotate();
                            return;
                        }
                    }
                    if(!check){
                        for(auto k=j;k<b.length-1;k++){
                            if(b.board[i][k]=='.' && b.board[i][k+1]=='.' && b.board[i-1][k+1]=='.' && b.board[i-2][k+1]=='.'){
                                check=1;
                                index_x=i;
                                index_y=k;
                                return;
                            }
                            else if(b.board[i][k]=='.' && b.board[i-1][k]=='.' && b.board[i-1][k+1]=='.' && b.board[i-1][k+2]=='.'){
                                check=1;
                                index_x=i;
                                index_y=k;
                                shape.rotate();
                                return;
                            }
                            else if(b.board[i][k]=='.' && b.board[i-1][k]=='.' && b.board[i-2][k]=='.' && b.board[i-2][k-1]=='.'){
                                check=1;
                                index_x=i;
                                index_y=k;
                                shape.rotate();
                                shape.rotate();
                                return;
                            }
                        }
                    }
                }
                else if(shape.getKey()=='S'){
                    for(auto k=j;k<b.length-1;k++){
                        if(b.board[i][k]=='.' && b.board[i][k+1]=='.' && b.board[i-1][k+1]=='.' && b.board[i-1][k+2]=='.'){
                            if((b.board[i][k+2]!='.') || (b.board[i][k+2]=='.' && b.board[i][k+3]=='.')){
                                check=1;
                                index_x=i;
                                index_y=k;
                                return;
                            }
                            
                        }
                    }
                    if(!check){
                        for(auto k=j;k<b.length-1;k++){
                            if(b.board[i][k]=='.' && b.board[i-1][k]=='.' && b.board[i-1][k-1]=='.' && b.board[i-2][k-1]=='.'){
                                check=1;
                                index_x=i;
                                index_y=k;
                                shape.rotate();
                                return;
                            }
                        }
                    }
                }
                else if(shape.getKey()=='Z'){
                    for(auto k=j;k<b.length-1;k++){
                        if(b.board[i][k]=='.' && b.board[i][k+1]=='.' && b.board[i-1][k]=='.' && b.board[i-1][k-1]=='.'){
                            check=1;
                            index_x=i;
                            index_y=k;
                            return;
                        }
                    }
                    if(!check){
                        for(auto k=j;k<b.length-1;k++){
                            if(b.board[i][k]=='.' && b.board[i-1][k]=='.' && b.board[i-1][k+1]=='.' && b.board[i-2][k+1]=='.'){
                                check=1;
                                index_x=i;
                                index_y=k;
                                shape.rotate();
                                return;
                            }
                        }
                    }
                }
                
            }
        }
    }
}


void Tetris:: rotate_added_shape(Tetromino &shape){
    //WHEN I NEED TO ROTATE A TETROMINO
    // I PRINT IT AFTER Add() FUNCTION
    //SO, IN THIS FUNCTION I NEED TO CLEAR UNROTATED TETROMINO FROM THE TOP MIDDLE
    for(auto i=1;i<4;i++){
        for(auto j=1;j<b.length-1;j++){
            if(shape.getKey()=='I' && shape.getAdd()){
                    b.board[1][(b.length/2)-2]='.';
                    b.board[1][(b.length/2)-1]='.';
                    b.board[1][(b.length/2)]='.';
                    b.board[1][(b.length/2)+1]='.';
            }
            else if(shape.getKey()=='O' && shape.getAdd()){
                    b.board[1][(b.length/2)-1]='.';
                    b.board[2][(b.length/2)-1]='.';
                    b.board[1][(b.length/2)]='.';
                    b.board[2][(b.length/2)]='.';
            }
            else if(shape.getKey()=='T' && shape.getAdd()){
                    b.board[1][b.length/2]='.';
                    b.board[1][(b.length/2)-1]='.';
                    b.board[1][(b.length/2)+1]='.';
                    b.board[2][b.length/2]='.';
            }
            else if(shape.getKey()=='J' && shape.getAdd()){
                    b.board[1][b.length/2]='.';
                    b.board[2][b.length/2]='.';
                    b.board[3][b.length/2]='.';
                    b.board[3][(b.length/2)-1]='.';
            }
            else if(shape.getKey()=='L' && shape.getAdd()){
                    b.board[1][b.length/2]='.';
                    b.board[2][b.length/2]='.';
                    b.board[3][b.length/2]='.';
                    b.board[3][(b.length/2)+1]='.';
            }
            else if(shape.getKey()=='S' && shape.getAdd()){
                    b.board[1][b.length/2]='.';
                    b.board[2][b.length/2]='.';
                    b.board[1][(b.length/2)+1]='.';
                    b.board[2][(b.length/2)-1]='.';
            }
            else if(shape.getKey()=='Z' && shape.getAdd()){
                    b.board[1][b.length/2]='.';
                    b.board[2][b.length/2]='.';
                    b.board[1][(b.length/2)-1]='.';
                    b.board[2][(b.length/2)+1]='.';
            }
        }
    }
}






void Tetris:: Animate(Tetromino shape){
    /*
    1. Draw the board with Tetromino at the top 
    2. Rotate and move the Tetromino to its optimal position at the top 
    3. Draw the board again 
    4. Sleep 50 millisecond=
    5. Lower the Tetromino one level and go to step 3 until it hits the bottom.
    */
    Add(shape);
    fit(shape);

}

bool Tetris:: game_over(){
    //CHECKING IF THE BOARD IS FULL OR NOT
    int counter=0;
    for(auto j=1;j<b.length-1;j++){
        if(b.board[2][j]!='.'){
            counter++;
        }
    }
    if(counter>3){
        return false;
    }
    return true;
}

void Tetris::create_board(){
    //CREATING A BOARD WITH SIZES
	int i=0;
	b.board.resize(b.height);
	for (int i = 0; i < b.height; ++i)
        b.board[i].resize(b.length);
    
}

void Tetris:: fill_board(){
    // FILLING THE EMPTY BOARD WITH SIZES
    for(auto i=0;i<b.height;i++){ 
        for(auto j=0;j<b.length;j++){

            if(j==0 || j==b.length-1){
                b.board[i][j]='X';
            }
            else if(i==0 || i==b.height-1){
                b.board[i][j]='X';
            }
            else{
                b.board[i][j]='.';
            }
        }
    }
}


void Tetris:: draw() const{
    // MY DRAW FUNCTION, DRAWING THE BOARD WITH TETROMINOS
    usleep(500000);
    system("clear");

    for(auto i:b.board){ // range based for loop
        for(auto j:i){
            cout<<j;
        }
        cout<<endl;
    }
}




void Tetris:: fit(Tetromino &shape){
    find_index(shape);
    move_animation(shape);
}



void Tetris:: move_animation(Tetromino &shape){
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
            if(index_y<=(b.length/2)-2){
                // THIS IF TO UNDERSTAND WILL I MOVE THE SHAPE TO THE RIGHT OR LEFT!!!/ IF IS TRUE I WILL MOVE LEFT
                for(auto j=(b.length/2)-2;j>index_y;j--){
                    // THIS FOR LOOP TO MOVE TO THE LEFT
                    b.board[1][j]='.';
                    b.board[1][j+1]='.';
                    b.board[1][j+2]='.';
                    b.board[1][j+3]='.';
                    if(b.board[1][j-1]!='.'||b.board[1][j]!='.'||b.board[1][j+1]!='.'||b.board[1][j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j-1]='I';
                    b.board[1][j]='I';
                    b.board[1][j+1]='I';
                    b.board[1][j+2]='I';
                    
                    draw();
                }
            }
            else{
                for(auto j=(b.length/2)-2;j<index_y;j++){
                    //THIS FOR LOOP FOR MOVING TO THE RIGHT
                    b.board[1][j]='.';
                    b.board[1][j+1]='.';
                    b.board[1][j+2]='.';
                    b.board[1][j+3]='.';
                    if(b.board[1][j+1]!='.'||b.board[1][j+2]!='.'||b.board[1][j+3]!='.'||b.board[1][j+4]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j+1]='I';
                    b.board[1][j+2]='I';
                    b.board[1][j+3]='I';
                    b.board[1][j+4]='I';

                    draw();
                }
            }
            for(auto i=2;i<=index_x;i++){
                // THIS FOR LOOP FOR MOVING DOWN
                    b.board[i-1][index_y]='.';
                    b.board[i-1][index_y+1]='.';
                    b.board[i-1][index_y+2]='.';
                    b.board[i-1][index_y+3]='.';
                    if(b.board[i][index_y]!='.'||b.board[i][index_y+1]!='.'||b.board[i][index_y+2]!='.'||b.board[i][index_y+3]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[i][index_y]='I';
                    b.board[i][index_y+1]='I';
                    b.board[i][index_y+2]='I';
                    b.board[i][index_y+3]='I';

                    draw();
                }
        }
        else{// THIS ELSE MEANS THE SHAPE ROTATED
            draw();            
            rotate_added_shape(shape);
            if(b.board[1][b.length/2]=='.'&&b.board[2][b.length/2]=='.'&&b.board[3][b.length/2]=='.'&&b.board[4][b.length/2]=='.'){
                b.board[1][b.length/2]='I';
                b.board[2][b.length/2]='I';
                b.board[3][b.length/2]='I';
                b.board[4][b.length/2]='I';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            
            draw(); 
            if(index_y<=(b.length/2)){// TO UNDERSTAND MOVING RIGHT OR LEFT.. MOVING LEFT
                for(auto j=b.length/2;j>index_y;j--){
                    // MOVING LEFT LOOP
                    b.board[1][j]='.';
                    b.board[2][j]='.';
                    b.board[3][j]='.';
                    b.board[4][j]='.';
                    if(b.board[1][j-1]!='.'||b.board[2][j-1]!='.'||b.board[3][j-1]!='.'||b.board[4][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j-1]='I';
                    b.board[2][j-1]='I';
                    b.board[3][j-1]='I';
                    b.board[4][j-1]='I';

                    draw();
                }
            }
            else{
                for(auto j=b.length/2;j<index_y;j++){
                    //MOVING RIGHT LOOP
                    b.board[1][j]='.';
                    b.board[2][j]='.';
                    b.board[3][j]='.';
                    b.board[4][j]='.';
                    if(b.board[1][j+1]!='.'||b.board[2][j+1]!='.'||b.board[3][j+1]!='.'||b.board[4][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j+1]='I';
                    b.board[2][j+1]='I';
                    b.board[3][j+1]='I';
                    b.board[4][j+1]='I';

                    draw();
                }
            }
            for(auto i=5;i<=index_x;i++){
                //MOVING DOWN LOOP
                    b.board[i-1][index_y]='.';
                    b.board[i-2][index_y]='.';
                    b.board[i-3][index_y]='.';
                    b.board[i-4][index_y]='.';
                    if(b.board[i][index_y]!='.'||b.board[i-1][index_y]!='.'||b.board[i-2][index_y]!='.'||b.board[i-3][index_y]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[i][index_y]='I';
                    b.board[i-1][index_y]='I';
                    b.board[i-2][index_y]='I';
                    b.board[i-3][index_y]='I';

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
        if(index_y<=(b.length/2)-1){ // THAT MEANS THE SHAPE WILL MOVE LEFT
            for(auto j=(b.length/2)-1;j>index_y;j--){
                b.board[1][j]='.';
                b.board[1][j+1]='.';
                b.board[2][j]='.';
                b.board[2][j+1]='.';
                if(b.board[1][j-1]!='.'||b.board[1][j]!='.'||b.board[2][j-1]!='.'||b.board[2][j]!='.'){
                    fill_just_y_indexes(shape);
                    draw();
                    break;
                }
                b.board[1][j-1]='O';
                b.board[1][j]='O';
                b.board[2][j-1]='O';
                b.board[2][j]='O';
                
                draw();
            }

        }
        else{// THE SHAPE WILL MOVE RIGHT
            for(auto j=(b.length/2)-1;j<index_y;j++){
                b.board[1][j]='.';
                b.board[1][j+1]='.';
                b.board[2][j]='.';
                b.board[2][j+1]='.';
                if(b.board[1][j+1]!='.'||b.board[1][j+2]!='.'||b.board[2][j+1]!='.'||b.board[2][j+2]!='.'){
                    fill_just_y_indexes(shape);
                    draw();
                    break;
                }
                b.board[1][j+1]='O';
                b.board[1][j+2]='O';
                b.board[2][j+1]='O';
                b.board[2][j+2]='O';
                
                draw();
            }
        }
        for(auto i=3;i<=index_x;i++){ // THIS LOOP TO SHAPE TO MOVE DOWN
                b.board[i-1][index_y]='.';
                b.board[i-1][index_y+1]='.';
                b.board[i-2][index_y]='.';
                b.board[i-2][index_y+1]='.';
                if(b.board[i][index_y]!='.'||b.board[i][index_y+1]!='.'||b.board[i-1][index_y]!='.'||b.board[i-1][index_y+1]!='.'){
                    fill_indexes(shape);
                    draw();
                    break;
                }
                b.board[i][index_y]='O';
                b.board[i][index_y+1]='O';
                b.board[i-1][index_y]='O';
                b.board[i-1][index_y+1]='O';
                
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
            if(index_y<=b.length/2){
                for(auto j=b.length/2;j>index_y;j--){
                    b.board[2][j]='.';
                    b.board[1][j]='.';
                    b.board[1][j-1]='.';
                    b.board[1][j+1]='.';
                    if(b.board[2][j-1]!='.'||b.board[1][j-1]!='.'||b.board[1][j-2]!='.'||b.board[1][j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[2][j-1]='T';
                    b.board[1][j-1]='T';
                    b.board[1][j-2]='T';
                    b.board[1][j]='T';

                    draw();
                }
            }
            else{
                for(auto j=b.length/2;j<index_y;j++){
                    b.board[2][j]='.';
                    b.board[1][j]='.';
                    b.board[1][j-1]='.';
                    b.board[1][j+1]='.';
                    if(b.board[2][j+1]!='.'||b.board[1][j+1]!='.'||b.board[1][j]!='.'||b.board[1][j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[2][j+1]='T';
                    b.board[1][j+1]='T';
                    b.board[1][j]='T';
                    b.board[1][j+2]='T';

                    draw();
                }
            }
            for(auto i=3;i<=index_x;i++){
                    b.board[i-1][index_y]='.';
                    b.board[i-2][index_y]='.';
                    b.board[i-2][index_y-1]='.';
                    b.board[i-2][index_y+1]='.';
                    if(b.board[i][index_y]!='.'||b.board[i-1][index_y]!='.'||b.board[i-1][index_y-1]!='.'||b.board[i-1][index_y+1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[i][index_y]='T';
                    b.board[i-1][index_y]='T';
                    b.board[i-1][index_y-1]='T';
                    b.board[i-1][index_y+1]='T';

                    draw();
                }
        }
        else if(shape.getRotated()==1){
            draw();            
            rotate_added_shape(shape);
            if(b.board[1][(b.length/2)]=='.'&&b.board[2][(b.length/2)]=='.'&&b.board[2][(b.length/2)-1]=='.'&&b.board[3][(b.length/2)]=='.'){
                b.board[1][(b.length/2)]='T';
                b.board[2][(b.length/2)]='T';
                b.board[2][(b.length/2)-1]='T';
                b.board[3][(b.length/2)]='T';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if(index_y<=(b.length/2)){
                for(auto j=(b.length/2);j>index_y;j--){
                    b.board[3][j]='.';
                    b.board[2][j]='.';
                    b.board[2][j-1]='.';
                    b.board[1][j]='.';
                    if(b.board[3][j-1]!='.'||b.board[2][j-1]!='.'||b.board[2][j-2]!='.'||b.board[1][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[3][j-1]='T';
                    b.board[2][j-1]='T';
                    b.board[2][j-2]='T';
                    b.board[1][j-1]='T';

                    draw();
                }
            }
            else{
                for(auto j=(b.length/2);j<index_y;j++){
                    b.board[3][j]='.';
                    b.board[2][j]='.';
                    b.board[2][j-1]='.';
                    b.board[1][j]='.';
                    if(b.board[3][j+1]!='.'||b.board[2][j+1]!='.'||b.board[2][j]!='.'||b.board[1][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[3][j+1]='T';
                    b.board[2][j+1]='T';
                    b.board[2][j]='T';
                    b.board[1][j+1]='T';

                    draw();
                }
            }
            for(auto i=4;i<=index_x;i++){
                    b.board[i-1][index_y]='.';
                    b.board[i-2][index_y]='.';
                    b.board[i-2][index_y-1]='.';
                    b.board[i-3][index_y]='.';
                    if(b.board[i][index_y]!='.'||b.board[i-1][index_y]!='.'||b.board[i-1][index_y-1]!='.'||b.board[i-2][index_y]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[i][index_y]='T';
                    b.board[i-1][index_y]='T';
                    b.board[i-1][index_y-1]='T';
                    b.board[i-2][index_y]='T';

                    draw();
                }
        }
        else if(shape.getRotated()==2){
            draw();            
            rotate_added_shape(shape);
            if(b.board[1][(b.length/2)]=='.'&&b.board[2][(b.length/2)]=='.'&&b.board[2][(b.length/2)-1]=='.'&&b.board[2][(b.length/2)+1]=='.'){
                b.board[1][(b.length/2)]='T';
                b.board[2][(b.length/2)]='T';
                b.board[2][(b.length/2)-1]='T';
                b.board[2][(b.length/2)+1]='T';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();           
            if(index_y<=(b.length/2)-1){
                for(auto j=(b.length/2)-1;j>index_y;j--){
                    b.board[2][j]='.';
                    b.board[2][j+1]='.';
                    b.board[2][j+2]='.';
                    b.board[1][j+1]='.';
                    if(b.board[2][j-1]!='.'||b.board[2][j]!='.'||b.board[2][j+1]!='.'||b.board[1][j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[2][j-1]='T';
                    b.board[2][j]='T';
                    b.board[2][j+1]='T';
                    b.board[1][j]='T';

                    draw();
                }
            }
            else{
                for(auto j=(b.length/2)-1;j<index_y;j++){
                    b.board[2][j]='.';
                    b.board[2][j+1]='.';
                    b.board[2][j+2]='.';
                    b.board[1][j+1]='.';
                    if(b.board[2][j+1]!='.'||b.board[2][j+2]!='.'||b.board[2][j+3]!='.'||b.board[1][j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[2][j+1]='T';
                    b.board[2][j+2]='T';
                    b.board[2][j+3]='T';
                    b.board[1][j+2]='T';

                    draw();
                }
            }
            for(auto i=3;i<=index_x;i++){
                    b.board[i-1][index_y]='.';
                    b.board[i-1][index_y+1]='.';
                    b.board[i-2][index_y+1]='.';
                    b.board[i-1][index_y+2]='.';
                    if(b.board[i][index_y]!='.'||b.board[i][index_y+1]!='.'||b.board[i-1][index_y+1]!='.'||b.board[i][index_y+2]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[i][index_y]='T';
                    b.board[i][index_y+1]='T';
                    b.board[i-1][index_y+1]='T';
                    b.board[i][index_y+2]='T';

                    draw();
                }
        }
        else if(shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(b.board[1][b.length/2]=='.'&&b.board[2][b.length/2]=='.'&&b.board[2][(b.length/2)+1]=='.'&&b.board[3][b.length/2]=='.'){
                b.board[1][b.length/2]='T';
                b.board[2][b.length/2]='T';
                b.board[2][(b.length/2)+1]='T';
                b.board[3][b.length/2]='T';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }

            draw();            
            if(index_y<=b.length/2){
                for(auto j=b.length/2;j>index_y;j--){
                    b.board[1][j]='.';
                    b.board[2][j]='.';
                    b.board[2][j+1]='.';
                    b.board[3][j]='.';
                    if(b.board[1][j-1]!='.'||b.board[2][j-1]!='.'||b.board[2][j]!='.'||b.board[3][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j-1]='T';
                    b.board[2][j-1]='T';
                    b.board[2][j]='T';
                    b.board[3][j-1]='T';

                    draw();
                }
            }
            else{
                for(auto j=b.length/2;j<index_y;j++){
                    b.board[1][j]='.';
                    b.board[2][j]='.';
                    b.board[2][j+1]='.';
                    b.board[3][j]='.';
                    if(b.board[1][j+1]!='.'||b.board[2][j+1]!='.'||b.board[2][j+2]!='.'||b.board[3][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j+1]='T';
                    b.board[2][j+1]='T';
                    b.board[2][j+2]='T';
                    b.board[3][j+1]='T';

                    draw();
                }  
            }
            for(auto i=4;i<=index_x;i++){
                    b.board[i-1][index_y]='.';
                    b.board[i-2][index_y]='.';
                    b.board[i-2][index_y+1]='.';
                    b.board[i-3][index_y]='.';
                    if(b.board[i][index_y]!='.'||b.board[i-1][index_y]!='.'||b.board[i-1][index_y+1]!='.'||b.board[i-2][index_y]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[i][index_y]='T';
                    b.board[i-1][index_y]='T';
                    b.board[i-1][index_y+1]='T';
                    b.board[i-2][index_y]='T';

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
            if(index_y<=(b.length/2)-1){
                for(auto j=(b.length/2)-1;j>index_y;j--){
                    b.board[3][j]='.';
                    b.board[3][j+1]='.';
                    b.board[2][j+1]='.';
                    b.board[1][j+1]='.';
                    if(b.board[3][j-1]!='.'||b.board[3][j]!='.'||b.board[2][j]!='.'||b.board[1][j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[3][j-1]='J';
                    b.board[3][j]='J';
                    b.board[2][j]='J';
                    b.board[1][j]='J';

                    draw();
                }
            }
            else{
                for(auto j=(b.length/2)-1;j<index_y;j++){
                    b.board[3][j]='.';
                    b.board[3][j+1]='.';
                    b.board[2][j+1]='.';
                    b.board[1][j+1]='.';
                    if(b.board[3][j+1]!='.'||b.board[3][j+2]!='.'||b.board[2][j+2]!='.'||b.board[1][j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[3][j+1]='J';
                    b.board[3][j+2]='J';
                    b.board[2][j+2]='J';
                    b.board[1][j+2]='J';

                    draw();
                }
            }
            for(auto i=4;i<=index_x;i++){
                    b.board[i-1][index_y]='.';
                    b.board[i-1][index_y+1]='.';
                    b.board[i-2][index_y+1]='.';
                    b.board[i-3][index_y+1]='.';
                    if(b.board[i][index_y]!='.'||b.board[i][index_y+1]!='.'||b.board[i-1][index_y+1]!='.'||b.board[i-2][index_y+1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[i][index_y]='J';
                    b.board[i][index_y+1]='J';
                    b.board[i-1][index_y+1]='J';
                    b.board[i-2][index_y+1]='J';

                    draw();
                }
        }
        else if(shape.getRotated()==1){
            draw();            
            rotate_added_shape(shape);
            if(b.board[1][(b.length/2)-1]=='.'&&b.board[2][(b.length/2)-1]=='.'&&b.board[2][(b.length/2)]=='.'&&b.board[2][(b.length/2)+1]=='.'){
                b.board[1][(b.length/2)-1]='J';
                b.board[2][(b.length/2)-1]='J';
                b.board[2][(b.length/2)]='J';
                b.board[2][(b.length/2)+1]='J';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }

            draw();            
            if(index_y<=(b.length/2)-1){
                for(auto j=(b.length/2)-1;j>index_y;j--){
                    b.board[1][j]='.';
                    b.board[2][j]='.';
                    b.board[2][j+1]='.';
                    b.board[2][j+2]='.';
                    if(b.board[1][j-1]!='.'||b.board[2][j-1]!='.'||b.board[2][j]!='.'||b.board[2][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j-1]='J';
                    b.board[2][j-1]='J';
                    b.board[2][j]='J';
                    b.board[2][j+1]='J';

                    draw();
                }
            }
            else{
                for(auto j=(b.length/2)-1;j<index_y;j++){
                    b.board[1][j]='.';
                    b.board[2][j]='.';
                    b.board[2][j+1]='.';
                    b.board[2][j+2]='.';
                    if(b.board[1][j+1]!='.'||b.board[2][j+1]!='.'||b.board[2][j+2]!='.'||b.board[2][j+3]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j+1]='J';
                    b.board[2][j+1]='J';
                    b.board[2][j+2]='J';
                    b.board[2][j+3]='J';

                    draw();
                }
            }
            for(auto i=3;i<=index_x;i++){
                    b.board[i-2][index_y]='.';
                    b.board[i-1][index_y]='.';
                    b.board[i-1][index_y+1]='.';
                    b.board[i-1][index_y+2]='.';
                    if(b.board[i-1][index_y]!='.'||b.board[i][index_y]!='.'||b.board[i][index_y+1]!='.'||b.board[i][index_y+2]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[i-1][index_y]='J';
                    b.board[i][index_y]='J';
                    b.board[i][index_y+1]='J';
                    b.board[i][index_y+2]='J';

                    draw();
                }
        }
        else if(shape.getRotated()==2){
            draw();            
            rotate_added_shape(shape);
            if(b.board[1][(b.length/2)-1]=='.'&&b.board[1][(b.length/2)]=='.'&&b.board[2][(b.length/2)-1]=='.'&&b.board[3][(b.length/2)-1]=='.'){
                b.board[1][(b.length/2)-1]='J';
                b.board[1][(b.length/2)]='J';
                b.board[2][(b.length/2)-1]='J';
                b.board[3][(b.length/2)-1]='J';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            
            draw();            
            if(index_y<=(b.length/2)-1){
                for(auto j=(b.length/2)-1;j>index_y;j--){
                    b.board[1][j]='.';
                    b.board[1][j+1]='.';
                    b.board[2][j]='.';
                    b.board[3][j]='.';
                    if(b.board[1][j-1]!='.'||b.board[1][j]!='.'||b.board[2][j-1]!='.'||b.board[3][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j-1]='J';
                    b.board[1][j]='J';
                    b.board[2][j-1]='J';
                    b.board[3][j-1]='J';

                    draw();
                }
            }
            else{
                for(auto j=(b.length/2)-1;j<index_y;j++){
                    b.board[1][j]='.';
                    b.board[1][j+1]='.';
                    b.board[2][j]='.';
                    b.board[3][j]='.';
                    if(b.board[1][j+1]!='.'||b.board[1][j+2]!='.'||b.board[2][j+1]!='.'||b.board[3][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j+1]='J';
                    b.board[1][j+2]='J';
                    b.board[2][j+1]='J';
                    b.board[3][j+1]='J';

                    draw();
                }
            }
            for(auto i=4;i<=index_x;i++){
                    b.board[i-3][index_y]='.';
                    b.board[i-3][index_y+1]='.';
                    b.board[i-2][index_y]='.';
                    b.board[i-1][index_y]='.';
                    if(b.board[i-2][index_y]!='.'||b.board[i-2][index_y+1]!='.'||b.board[i-1][index_y]!='.'||b.board[i][index_y]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[i-2][index_y]='J';
                    b.board[i-2][index_y+1]='J';
                    b.board[i-1][index_y]='J';
                    b.board[i][index_y]='J';

                    draw();
                }
        }
        else if(shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(b.board[1][(b.length/2)-1]=='.'&&b.board[1][(b.length/2)]=='.'&&b.board[1][(b.length/2)+1]=='.'&&b.board[2][(b.length/2)+1]=='.'){
                b.board[1][(b.length/2)-1]='J';
                b.board[1][(b.length/2)]='J';
                b.board[1][(b.length/2)+1]='J';
                b.board[2][(b.length/2)+1]='J';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if(index_y<=(b.length/2)+1){
                for(auto j=(b.length/2)+1;j>index_y;j--){
                    b.board[1][j-2]='.';
                    b.board[1][j-1]='.';
                    b.board[1][j]='.';
                    b.board[2][j]='.';
                    if(b.board[1][j-3]!='.'||b.board[1][j-2]!='.'||b.board[1][j-1]!='.'||b.board[2][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j-3]='J';
                    b.board[1][j-2]='J';
                    b.board[1][j-1]='J';
                    b.board[2][j-1]='J';

                    draw();
                }
            }
            else{
                for(auto j=(b.length/2)+1;j<index_y;j++){
                    b.board[1][j-2]='.';
                    b.board[1][j-1]='.';
                    b.board[1][j]='.';
                    b.board[2][j]='.';
                    if(b.board[1][j-1]!='.'||b.board[1][j]!='.'||b.board[1][j+1]!='.'||b.board[2][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j-1]='J';
                    b.board[1][j]='J';
                    b.board[1][j+1]='J';
                    b.board[2][j+1]='J';

                    draw();
                }
            }
            for(auto i=3;i<=index_x;i++){
                    b.board[i-2][index_y]='.';
                    b.board[i-2][index_y-1]='.';
                    b.board[i-2][index_y-2]='.';
                    b.board[i-1][index_y]='.';
                    if(b.board[i-1][index_y]!='.'||b.board[i-1][index_y-1]!='.'||b.board[i-1][index_y-2]!='.'||b.board[i][index_y]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[i-1][index_y]='J';
                    b.board[i-1][index_y-1]='J';
                    b.board[i-1][index_y-2]='J';
                    b.board[i][index_y]='J';

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
            if(index_y<=(b.length/2)){
                for(auto j=(b.length/2);j>index_y;j--){
                    b.board[1][j]='.';
                    b.board[2][j]='.';
                    b.board[3][j]='.';
                    b.board[3][j+1]='.';
                    if(b.board[1][j-1]!='.'||b.board[2][j-1]!='.'||b.board[3][j-1]!='.'||b.board[3][j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;  
                    }
                    b.board[1][j-1]='L';
                    b.board[2][j-1]='L';
                    b.board[3][j-1]='L';
                    b.board[3][j]='L';

                    draw();
                }
            }
            else{
                for(auto j=(b.length/2);j<index_y;j++){
                    b.board[1][j]='.';
                    b.board[2][j]='.';
                    b.board[3][j]='.';
                    b.board[3][j+1]='.';
                    if(b.board[1][j+1]!='.'||b.board[2][j+1]!='.'||b.board[3][j+1]!='.'||b.board[3][j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;  
                    }
                    b.board[1][j+1]='L';
                    b.board[2][j+1]='L';
                    b.board[3][j+1]='L';
                    b.board[3][j+2]='L';

                    draw();
                }
            }
            for(auto i=4;i<=index_x;i++){
                    b.board[i-1][index_y]='.';
                    b.board[i-1][index_y+1]='.';
                    b.board[i-2][index_y]='.';
                    b.board[i-3][index_y]='.';
                    if(b.board[i][index_y]!='.'||b.board[i][index_y+1]!='.'||b.board[i-1][index_y]!='.'||b.board[i-2][index_y]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[i][index_y]='L';
                    b.board[i][index_y+1]='L';
                    b.board[i-1][index_y]='L';
                    b.board[i-2][index_y]='L';

                    draw();
                }
        }
        else if(shape.getRotated()==1){
            draw();            
            rotate_added_shape(shape);
            if(b.board[1][(b.length/2)-1]=='.'&&b.board[2][(b.length/2)-1]=='.'&&b.board[1][(b.length/2)]=='.'&&b.board[1][(b.length/2)+1]=='.'){
                b.board[1][(b.length/2)-1]='L';
                b.board[2][(b.length/2)-1]='L';
                b.board[1][(b.length/2)]='L';
                b.board[1][(b.length/2)+1]='L';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();           
            if(index_y<=(b.length/2)-1){
                for(auto j=(b.length/2)-1;j>index_y;j--){
                    b.board[1][j]='.';
                    b.board[1][j+1]='.';
                    b.board[1][j+2]='.';
                    b.board[2][j]='.';
                    if(b.board[1][j-1]!='.'||b.board[1][j]!='.'||b.board[1][j+1]!='.'||b.board[2][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[1][j-1]='L';
                    b.board[1][j]='L';
                    b.board[1][j+1]='L';
                    b.board[2][j-1]='L';

                    draw();
                }
            }
            else{
                for(auto j=(b.length/2)-1;j<index_y;j++){
                    b.board[1][j]='.';
                    b.board[1][j+1]='.';
                    b.board[1][j+2]='.';
                    b.board[2][j]='.';
                    if(b.board[1][j+1]!='.'||b.board[1][j+2]!='.'||b.board[1][j+3]!='.'||b.board[2][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[1][j+1]='L';
                    b.board[1][j+2]='L';
                    b.board[1][j+3]='L';
                    b.board[2][j+1]='L';

                    draw();
                }
            }
            for(auto i=3;i<=index_x;i++){
                    b.board[i-1][index_y]='.';
                    b.board[i-2][index_y]='.';
                    b.board[i-2][index_y+1]='.';
                    b.board[i-2][index_y+2]='.';
                    if(b.board[i][index_y]!='.'||b.board[i-1][index_y]!='.'||b.board[i-1][index_y+1]!='.'||b.board[i-1][index_y+1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[i][index_y]='L';
                    b.board[i-1][index_y]='L';
                    b.board[i-1][index_y+1]='L';
                    b.board[i-1][index_y+2]='L';

                    draw();
                }
        }
        else if(shape.getRotated()==2){
            draw();            
            rotate_added_shape(shape);
            if(b.board[1][(b.length/2)-1]=='.'&&b.board[1][(b.length/2)]=='.'&&b.board[2][(b.length/2)-1]=='.'&&b.board[3][(b.length/2)-1]=='.'){
                b.board[1][(b.length/2)-1]='L';
                b.board[1][(b.length/2)]='L';
                b.board[2][(b.length/2)]='L';
                b.board[3][(b.length/2)]='L';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if(index_y<=(b.length/2)){
                for(auto j=(b.length/2);j>index_y;j--){
                    b.board[1][j-1]='.';
                    b.board[1][j]='.';
                    b.board[2][j]='.';
                    b.board[3][j]='.';
                    if(b.board[1][j-1]!='.'||b.board[1][j-1]!='.'||b.board[2][j-1]!='.'||b.board[3][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[1][j-2]='L';
                    b.board[1][j-1]='L';
                    b.board[2][j-1]='L';
                    b.board[3][j-1]='L';
                        draw();
                }
            }
            else{
                for(auto j=(b.length/2);j<index_y;j++){
                    b.board[1][j-1]='.';
                    b.board[1][j]='.';
                    b.board[2][j]='.';
                    b.board[3][j]='.';
                    if(b.board[1][j]!='.'||b.board[1][j+1]!='.'||b.board[2][j+1]!='.'||b.board[3][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[1][j]='L';
                    b.board[1][j+1]='L';
                    b.board[2][j+1]='L';
                    b.board[3][j+1]='L';
                        draw();
                }
            }
            for(auto i=4;i<=index_x;i++){
                    b.board[i-1][index_y]='.';
                    b.board[i-2][index_y]='.';
                    b.board[i-3][index_y]='.';
                    b.board[i-3][index_y-1]='.';
                    if(b.board[i][index_y]!='.'||b.board[i-1][index_y]!='.'||b.board[i-2][index_y]!='.'||b.board[i-2][index_y-1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[i][index_y]='L';
                    b.board[i-1][index_y]='L';
                    b.board[i-2][index_y]='L';
                    b.board[i-2][index_y-1]='L';

                    draw();
                }
        }
        else if(shape.getRotated()==3){
            draw();            
            rotate_added_shape(shape);
            if(b.board[1][(b.length/2)+1]=='.'&&b.board[2][(b.length/2)-1]=='.'&&b.board[2][(b.length/2)]=='.'&&b.board[2][(b.length/2)+1]=='.'){
                b.board[1][(b.length/2)+1]='L';
                b.board[2][(b.length/2)-1]='L';
                b.board[2][(b.length/2)]='L';
                b.board[2][(b.length/2)+1]='L';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
        
            draw();            
            if(index_y<=(b.length/2)-1){
                for(auto j=(b.length/2)-1;j>index_y;j--){
                    b.board[1][j+2]='.';
                    b.board[2][j]='.';
                    b.board[2][j+1]='.';
                    b.board[2][j+2]='.';
                    if(b.board[1][j+1]!='.'||b.board[2][j-1]!='.'||b.board[2][j]!='.'||b.board[2][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[1][j+1]='L';
                    b.board[2][j-1]='L';
                    b.board[2][j]='L';
                    b.board[2][j+1]='L';

                    draw();
                }
            }
            else{
                for(auto j=(b.length/2)-1;j<index_y;j++){
                    b.board[1][j+2]='.';
                    b.board[2][j]='.';
                    b.board[2][j+1]='.';
                    b.board[2][j+2]='.';
                    if(b.board[1][j+3]!='.'||b.board[2][j+1]!='.'||b.board[2][j+2]!='.'||b.board[2][j+3]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[1][j+3]='L';
                    b.board[2][j+1]='L';
                    b.board[2][j+2]='L';
                    b.board[2][j+3]='L';

                    draw();
                }
            }
            for(auto i=3;i<=index_x;i++){
                    b.board[i-2][index_y+2]='.';
                    b.board[i-1][index_y]='.';
                    b.board[i-1][index_y+1]='.';
                    b.board[i-1][index_y+2]='.';
                    if(b.board[i-1][index_y+2]!='.'||b.board[i][index_y]!='.'||b.board[i][index_y+1]!='.'||b.board[i][index_y+2]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[i-1][index_y+2]='L';
                    b.board[i][index_y]='L';
                    b.board[i][index_y+1]='L';
                    b.board[i][index_y+2]='L';

                    draw();
                }
        }
    }
    else if(shape.getKey()=='S'){
        if(shape.getRotated()==0){
            if(!shape.getAdd()){
                fill_indexes(shape);
                draw();
                return;
            }
            draw();            
            if(index_y<=(b.length/2)-1){
                for(auto j=(b.length/2)-1;j>index_y;j--){
                    b.board[2][j]='.';
                    b.board[2][j+1]='.';
                    b.board[1][j+1]='.';
                    b.board[1][j+2]='.';
                    if(b.board[2][j-1]!='.'||b.board[2][j]!='.'||b.board[1][j-1]!='.'||b.board[1][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[2][j-1]='S';
                    b.board[2][j]='S';
                    b.board[1][j]='S';
                    b.board[1][j+1]='S';

                    draw();
                }
            }
            else{
                for(auto j=(b.length/2)-1;j<index_y;j++){
                    b.board[2][j]='.';
                    b.board[2][j+1]='.';
                    b.board[1][j+1]='.';
                    b.board[1][j+2]='.';
                    if(b.board[2][j+1]!='.'||b.board[2][j+2]!='.'||b.board[1][j+2]!='.'||b.board[1][j+3]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[2][j+1]='S';
                    b.board[2][j+2]='S';
                    b.board[1][j+2]='S';
                    b.board[1][j+3]='S';

                    draw();
                }
                
            }
            for(auto i=3;i<=index_x;i++){
                    b.board[i-1][index_y]='.';
                    b.board[i-1][index_y+1]='.';
                    b.board[i-2][index_y+1]='.';
                    b.board[i-2][index_y+2]='.';
                    if(b.board[i][index_y]!='.'||b.board[i][index_y+1]!='.'||b.board[i-1][index_y+1]!='.'||b.board[i-1][index_y+2]!='.'){
                        fill_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[i][index_y]='S';
                    b.board[i][index_y+1]='S';
                    b.board[i-1][index_y+1]='S';
                    b.board[i-1][index_y+2]='S';

                    draw();
                }
        }
        else if(shape.getRotated()==1){
            draw();            
            rotate_added_shape(shape);
            if(b.board[1][(b.length/2)-1]=='.'&&b.board[2][(b.length/2)-1]=='.'&&b.board[2][(b.length/2)]=='.'&&b.board[3][(b.length/2)]=='.'){
                b.board[1][(b.length/2)-1]='S';
                b.board[2][(b.length/2)-1]='S';
                b.board[2][(b.length/2)]='S';
                b.board[3][(b.length/2)]='S';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if(index_y<=(b.length/2)){
                for(auto j=(b.length/2);j>index_y;j--){
                    b.board[1][j-1]='.';
                    b.board[2][j-1]='.';
                    b.board[2][j]='.';
                    b.board[3][j]='.';
                    if(b.board[1][j-2]!='.'||b.board[2][j-2]!='.'||b.board[2][j-1]!='.'||b.board[3][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break; 
                    }
                    b.board[1][j-2]='S';
                    b.board[2][j-2]='S';
                    b.board[2][j-1]='S';
                    b.board[3][j-1]='S';

                    draw();
                }
            }
            else{
                for(auto j=(b.length/2);j<index_y;j++){
                    b.board[1][j-1]='.';
                    b.board[2][j-1]='.';
                    b.board[2][j]='.';
                    b.board[3][j]='.';
                    if(b.board[1][j]!='.'||b.board[2][j]!='.'||b.board[2][j+1]!='.'||b.board[3][j+1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j]='S';
                    b.board[2][j]='S';
                    b.board[2][j+1]='S';
                    b.board[3][j+1]='S';

                    draw();
                }
            }
            for(auto i=4;i<=index_x;i++){
                    b.board[i-1][index_y]='.';
                    b.board[i-2][index_y]='.';
                    b.board[i-2][index_y-1]='.';
                    b.board[i-3][index_y-1]='.';
                    if(b.board[i][index_y]!='.'||b.board[i-1][index_y]!='.'||b.board[i-1][index_y-1]!='.'||b.board[i-2][index_y-1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[i][index_y]='S';
                    b.board[i-1][index_y]='S';
                    b.board[i-1][index_y-1]='S';
                    b.board[i-2][index_y-1]='S';

                    draw();

                }
        }
    }
    else if(shape.getKey()=='Z'){
        if(shape.getRotated()==0){
            if(!shape.getAdd()){
                fill_indexes(shape);
                draw();
                return;
            }
            draw();            
            if(index_y<=(b.length/2)){
                for(auto j=(b.length/2);j>index_y;j--){
                    b.board[1][j]='.';
                    b.board[1][j-1]='.';
                    b.board[2][j]='.';
                    b.board[2][j+1]='.';
                    if(b.board[1][j-1]!='.'||b.board[1][j-2]!='.'||b.board[2][j-1]!='.'||b.board[2][j]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j-1]='Z';
                    b.board[1][j-2]='Z';
                    b.board[2][j-1]='Z';
                    b.board[2][j]='Z';

                    draw();
                }
            }
            else{
                for(auto j=(b.length/2);j<index_y;j++){
                    b.board[1][j]='.';
                    b.board[1][j-1]='.';
                    b.board[2][j]='.';
                    b.board[2][j+1]='.';

                    if(b.board[1][j+1]!='.'||b.board[1][j]!='.'||b.board[2][j+1]!='.'||b.board[2][j+2]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j+1]='Z';
                    b.board[1][j]='Z';
                    b.board[2][j+1]='Z';
                    b.board[2][j+2]='Z';

                    draw();
                }
                
            }
            for(auto i=3;i<=index_x;i++){
                    b.board[i-1][index_y]='.';
                    b.board[i-1][index_y+1]='.';
                    b.board[i-2][index_y]='.';
                    b.board[i-2][index_y-1]='.';

                    if(b.board[i][index_y]!='.'||b.board[i][index_y+1]!='.'||b.board[i-1][index_y]!='.'||b.board[i-1][index_y-1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[i][index_y]='Z';
                    b.board[i][index_y+1]='Z';
                    b.board[i-1][index_y]='Z';
                    b.board[i-1][index_y-1]='Z';

                    draw();
                }
        }
        else if(shape.getRotated()==1){
            draw();            
            rotate_added_shape(shape);
            if(b.board[1][(b.length/2)+1]=='.'&&b.board[2][(b.length/2)+1]=='.'&&b.board[2][(b.length/2)]=='.'&&b.board[3][(b.length/2)]=='.'){
                b.board[1][(b.length/2)+1]='Z';
                b.board[2][(b.length/2)+1]='Z';
                b.board[2][(b.length/2)]='Z';
                b.board[3][(b.length/2)]='Z';
            }
            else{
                fill_indexes(shape);
                draw();
                return;
            }
            
            draw();            
            if(index_y<=(b.length/2)){
                for(auto j=(b.length/2);j>index_y;j--){
                    b.board[1][j+1]='.';
                    b.board[2][j+1]='.';
                    b.board[2][j]='.';
                    b.board[3][j]='.';

                    if(b.board[1][j]!='.'||b.board[2][j]!='.'||b.board[2][j-1]!='.'||b.board[3][j-1]!='.'){
                        fill_just_y_indexes(shape);
                        draw();
                        break;
                    }
                    b.board[1][j]='Z';
                    b.board[2][j]='Z';
                    b.board[2][j-1]='Z';
                    b.board[3][j-1]='Z';

                    draw();
                }          
            }
            else{
                for(auto j=(b.length/2);j<index_y;j++){
                    b.board[1][j+1]='.';
                    b.board[2][j+1]='.';
                    b.board[2][j]='.';
                    b.board[3][j]='.';

                    if(b.board[1][j+2]!='.'||b.board[2][j+2]!='.'||b.board[2][j+1]!='.'||b.board[3][j+1]!='.'){
                        fill_just_y_indexes(shape);             
                        draw();
                        break;
                    }
                    b.board[1][j+2]='Z';
                    b.board[2][j+2]='Z';
                    b.board[2][j+1]='Z';
                    b.board[3][j+1]='Z';

                    draw();

                }
                
            }
            for(auto i=4;i<=index_x;i++){
                    b.board[i-1][index_y]='.';
                    b.board[i-2][index_y]='.';
                    b.board[i-2][index_y+1]='.';
                    b.board[i-3][index_y+1]='.';

                    if(b.board[i][index_y]!='.'||b.board[i-1][index_y]!='.'||b.board[i-1][index_y+1]!='.'||b.board[i-2][index_y+1]!='.'){
                        fill_indexes(shape);
                        break;
                    }
                    b.board[i][index_y]='Z';
                    b.board[i-1][index_y]='Z';
                    b.board[i-1][index_y+1]='Z';
                    b.board[i-2][index_y+1]='Z';

                    draw();
                }
        }
    }

}

void Tetris:: fill_just_y_indexes(Tetromino &shape){
    // THIS FUNCTION IS TO CHECK IF THERE IS ANY COLLUSION WHEN I MOVE THE TETROMINO RIGHT OR LEFT
    // IF THERE IS A COLLUSION, I PRINT THE TETROMINO JUST CORRECT INDEX WITHOUT MOVING...
    // I NEED TO CHECK EVERY SHAPE AND DIRECTION OF THE SHAPE.
    if(shape.getKey()=='I'){
        if(shape.getRotated()==0){
            b.board[1][index_y]='I';
            b.board[1][index_y+1]='I';
            b.board[1][index_y+1]='I';
            b.board[1][index_y+1]='I';
        }
        else if(shape.getRotated()==1){
            b.board[1][index_y]='I';
            b.board[2][index_y]='I';
            b.board[3][index_y]='I';
            b.board[4][index_y]='I';
        }
    }
    else if(shape.getKey()=='O'){
        b.board[2][index_y]='O';
        b.board[2][index_y+1]='O';
        b.board[1][index_y]='O';
        b.board[1][index_y+1]='O';
    }
    else if(shape.getKey()=='T'){
        if(shape.getRotated()==0){
            b.board[2][index_y]='T';
            b.board[1][index_y]='T';
            b.board[1][index_y-1]='T';
            b.board[1][index_y+1]='T';
        }
        else if(shape.getRotated()==1){
            b.board[3][index_y]='T';
            b.board[2][index_y]='T';
            b.board[2][index_y-1]='T';
            b.board[1][index_y]='T';
        }
        else if(shape.getRotated()==2){
            b.board[2][index_y]='T';
            b.board[2][index_y+1]='T';
            b.board[2][index_y+2]='T';
            b.board[1][index_y+1]='T';
        }
        else if(shape.getRotated()==3){
            b.board[3][index_y]='T';
            b.board[2][index_y]='T';
            b.board[2][index_y+1]='T';
            b.board[1][index_y]='T';
        }
    }
    else if(shape.getKey()=='L'){
        if(shape.getRotated()==0){
            b.board[3][index_y]='L';
            b.board[3][index_y+1]='L';
            b.board[2][index_y]='L';
            b.board[1][index_y]='L';
        }
        else if(shape.getRotated()==1){
            b.board[2][index_y]='L';
            b.board[1][index_y]='L';
            b.board[1][index_y+1]='L';
            b.board[1][index_y+1]='L';
        }
        else if(shape.getRotated()==2){
            b.board[3][index_y]='L';
            b.board[2][index_y]='L';
            b.board[1][index_y]='L';
            b.board[1][index_y-1]='L';
        }
        else if(shape.getRotated()==3){
            b.board[2][index_y]='L';
            b.board[2][index_y+1]='L';
            b.board[2][index_y+2]='L';
            b.board[1][index_y]='L';
        }
    }
    else if(shape.getKey()=='J'){
        if(shape.getRotated()==0){
            b.board[3][index_y]='J';
            b.board[3][index_y+1]='J';
            b.board[2][index_y+1]='J';
            b.board[1][index_y+1]='J';
        }
        else if(shape.getRotated()==1){
            b.board[2][index_y]='J';
            b.board[2][index_y+1]='J';
            b.board[2][index_y+2]='J';
            b.board[1][index_y]='J';
        }
        else if(shape.getRotated()==2){
            b.board[3][index_y]='J';
            b.board[2][index_y]='J';
            b.board[1][index_y]='J';
            b.board[1][index_y+1]='J';
        }
        else if(shape.getRotated()==3){
            b.board[2][index_y]='J';
            b.board[1][index_y]='J';
            b.board[1][index_y-1]='J';
            b.board[1][index_y-2]='J';
        }
    }
    else if(shape.getKey()=='S'){
        if(shape.getRotated()==0){
            b.board[2][index_y]='S';
            b.board[2][index_y+1]='S';
            b.board[1][index_y+1]='S';
            b.board[1][index_y+2]='S';
        }
        else if(shape.getRotated()==1){
            b.board[3][index_y]='S';
            b.board[2][index_y]='S';
            b.board[2][index_y-1]='S';
            b.board[1][index_y-1]='S';
        }
    }
    else if(shape.getKey()=='Z'){
        if(shape.getRotated()==0){
            b.board[2][index_y]='Z';
            b.board[2][index_y+1]='Z';
            b.board[1][index_y]='Z';
            b.board[1][index_y-1]='Z';
        }
        else if(shape.getRotated()==1){
            b.board[3][index_y]='Z';
            b.board[2][index_y]='Z';
            b.board[2][index_y+1]='Z';
            b.board[1][index_y+1]='Z';
        }
    }
}

void Tetris:: fill_indexes(Tetromino &shape){
    // THIS FUNCTION IS TO CHECK IF THERE IS ANY COLLUSION WHEN I MOVE THE TETROMINO
    // IF THERE IS A COLLUSION, I PRINT THE TETROMINO JUST CORRECT INDEX WITHOUT MOVING...
    // I NEED TO CHECK EVERY SHAPE AND DIRECTION OF THE SHAPE.
    if(shape.getKey()=='I'){
        if(shape.getRotated()==0){
            b.board[index_x][index_y]='I';
            b.board[index_x][index_y+1]='I';
            b.board[index_x][index_y+1]='I';
            b.board[index_x][index_y+1]='I';
        }
        else if(shape.getRotated()==1){
            b.board[index_x][index_y]='I';
            b.board[index_x-1][index_y]='I';
            b.board[index_x-2][index_y]='I';
            b.board[index_x-3][index_y]='I';
        }
    }
    else if(shape.getKey()=='O'){
        b.board[index_x][index_y]='O';
        b.board[index_x][index_y+1]='O';
        b.board[index_x-1][index_y]='O';
        b.board[index_x-1][index_y+1]='O';
    }
    else if(shape.getKey()=='T'){
        if(shape.getRotated()==0){
            b.board[index_x][index_y]='T';
            b.board[index_x-1][index_y]='T';
            b.board[index_x-1][index_y-1]='T';
            b.board[index_x-1][index_y+1]='T';
        }
        else if(shape.getRotated()==1){
            b.board[index_x][index_y]='T';
            b.board[index_x-1][index_y]='T';
            b.board[index_x-1][index_y-1]='T';
            b.board[index_x-2][index_y]='T';
        }
        else if(shape.getRotated()==2){
            b.board[index_x][index_y]='T';
            b.board[index_x][index_y+1]='T';
            b.board[index_x][index_y+2]='T';
            b.board[index_x-1][index_y+1]='T';
        }
        else if(shape.getRotated()==3){
            b.board[index_x][index_y]='T';
            b.board[index_x-1][index_y]='T';
            b.board[index_x-1][index_y+1]='T';
            b.board[index_x-2][index_y]='T';
        }
    }
    else if(shape.getKey()=='L'){
        if(shape.getRotated()==0){
            b.board[index_x][index_y]='L';
            b.board[index_x][index_y+1]='L';
            b.board[index_x-1][index_y]='L';
            b.board[index_x-2][index_y]='L';
        }
        else if(shape.getRotated()==1){
            b.board[index_x][index_y]='L';
            b.board[index_x-1][index_y]='L';
            b.board[index_x-1][index_y+1]='L';
            b.board[index_x-1][index_y+1]='L';
        }
        else if(shape.getRotated()==2){
            b.board[index_x][index_y]='L';
            b.board[index_x-1][index_y]='L';
            b.board[index_x-2][index_y]='L';
            b.board[index_x-2][index_y-1]='L';
        }
        else if(shape.getRotated()==3){
            b.board[index_x][index_y]='L';
            b.board[index_x][index_y+1]='L';
            b.board[index_x][index_y+2]='L';
            b.board[index_x-1][index_y+2]='L';
        }
    }
    else if(shape.getKey()=='J'){
        if(shape.getRotated()==0){
            b.board[index_x][index_y]='J';
            b.board[index_x][index_y+1]='J';
            b.board[index_x-1][index_y+1]='J';
            b.board[index_x-2][index_y+1]='J';
        }
        else if(shape.getRotated()==1){
            b.board[index_x][index_y]='J';
            b.board[index_x][index_y+1]='J';
            b.board[index_x][index_y+2]='J';
            b.board[index_x-1][index_y]='J';
        }
        else if(shape.getRotated()==2){
            b.board[index_x][index_y]='J';
            b.board[index_x-1][index_y]='J';
            b.board[index_x-2][index_y]='J';
            b.board[index_x-2][index_y+1]='J';
        }
        else if(shape.getRotated()==3){
            b.board[index_x][index_y]='J';
            b.board[index_x-1][index_y]='J';
            b.board[index_x-1][index_y-1]='J';
            b.board[index_x-1][index_y-2]='J';
        }
    }
    else if(shape.getKey()=='S'){
        if(shape.getRotated()==0){
            b.board[index_x][index_y]='S';
            b.board[index_x][index_y+1]='S';
            b.board[index_x-1][index_y+1]='S';
            b.board[index_x-1][index_y+2]='S';
        }
        else if(shape.getRotated()==1){
            b.board[index_x][index_y]='S';
            b.board[index_x-1][index_y]='S';
            b.board[index_x-1][index_y-1]='S';
            b.board[index_x-2][index_y-1]='S';
        }
    }
    else if(shape.getKey()=='Z'){
        if(shape.getRotated()==0){
            b.board[index_x][index_y]='Z';
            b.board[index_x][index_y+1]='Z';
            b.board[index_x-1][index_y]='Z';
            b.board[index_x-1][index_y-1]='Z';
        }
        else if(shape.getRotated()==1){
            b.board[index_x][index_y]='Z';
            b.board[index_x-1][index_y]='Z';
            b.board[index_x-1][index_y+1]='Z';
            b.board[index_x-2][index_y+1]='Z';
        }
    }
}




//HW1 DECLERATIONS
Tetromino:: Tetromino(enum tetros shape){
        //creating the 2d vector according to the enum shape..
        if(static_cast<char>(shape)=='I'){
            keyword='I';
            tet={ {'.', '.', '.','.'},{'.','.', '.', '.'},{'.', '.', '.','.'},{'I','I','I','I'}};
        }
        else if(static_cast<char>(shape)=='O'){
            keyword='O';
            tet={ {'.', '.', '.','.'}, {'.','.','.','.'}, {'O','O','.','.'},{'O', 'O', '.','.'}};
        }
        else if(static_cast<char>(shape)=='T'){
            keyword='T';
            tet={ {'.', '.', '.','.'}, {'.','.','.','.'} , {'T', 'T', 'T','.'},{'.', 'T', '.','.'}};
        }
        else if(static_cast<char>(shape)=='J'){
            keyword='J';
            tet={ {'.','.','.','.'}, {'.', 'J','.','.'}, {'.','J','.','.'},{'J', 'J', '.','.'}};
        }
        else if(static_cast<char>(shape)=='L'){
            keyword='L';
            tet={ {'.','.', '.','.'}, {'L','.','.','.'}, {'L','.','.','.'},{'L', 'L', '.','.'}};
        }
        else if(static_cast<char>(shape)=='S'){
            keyword='S';
            tet={ {'.', '.', '.','.'}, {'.','.','.','.'}, {'.','S','S','.'},{'S', 'S', '.','.'}};
        }
        else if(static_cast<char>(shape)=='Z'){
            keyword='Z';
            tet={ {'.', '.', '.','.'}, {'.','.','.','.'}, {'Z','Z','.','.'},{'.', 'Z', 'Z','.'}};
        }
        
    }



vector<vector<char> > Tetromino:: loop_for_rotate(vector<vector<char> > shape){
        // this function just for loop, and to keep new rotated shape
        vector< vector<char> > temp={{'.', '.', '.','.'},{'.', '.', '.','.'},{'.', '.', '.','.'},{'.', '.', '.','.'}};
        int index=N-1;
        for(auto i=0;i<N;i++){
            for(auto j=0;j<N;j++){
                temp[j][index]=shape[i][j];
            }
            index--;
        }
        return temp;
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
    // 2D vector temp to keep new rotated shape;
        vector< vector<char> > temp={{'.', '.', '.','.'},{'.', '.', '.','.'},{'.', '.', '.','.'},{'.', '.', '.','.'}};
        int index=N-1;
        if(keyword=='I'){ // for each shape there are some speacial index cases, i check here this cases
            temp=loop_for_rotate(tet);
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
            
            tet=temp;
            rotated++;
        }
        else if(keyword=='T'){  // for each shape there are some speacial index cases, i check here this cases
            temp=loop_for_rotate(tet);
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
                
            tet=temp;
            rotated++;
        }
        else if(keyword=='J'){
            temp=loop_for_rotate(tet);
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
            tet=temp;   
            rotated++;
        }
        else if(keyword=='L'){
            temp=loop_for_rotate(tet);
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
            tet=temp;
            rotated++;
        }
        else if(keyword=='S'){
            temp=loop_for_rotate(tet);
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
            tet=temp;
            rotated++;
        }
        else if(keyword=='Z'){
            temp=loop_for_rotate(tet);
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
            tet=temp;
        }
    }
