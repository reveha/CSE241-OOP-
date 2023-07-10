import java.util.Scanner;

public class Tetris{
    private int height;
    private int length;
    private char [][]board;
    private int index_x;
    private int index_y;


    public Tetris(){
        /*
        THIS IS MY CONSTRUCTOR WHICH DOES ASSIGNMENT FOR HEIGHT AND LENGTH AND CREATE BOARD;
        */
        this.height=15;
        this.length=15;
        create_board();
        fill_board();
    }


    public Tetris(int h, int l){
        /*
        THIS IS MY CONSTRUCTOR WHICH DOES ASSIGNMENT FOR HEIGHT AND LENGTH AND CREATE BOARD;
        */
        height=h;
        length=l;
        create_board();
        fill_board();
    }

    public void driver_test(){ // just for testing functions . for driver1.cpp
        for(int i=1;i<length-1;i++){
            if(board[height-2][i]=='.'){
                board[height-2][i]='A';
            }
        }
    }

    public Tetris Add(Tetromino shape){
        /*
        NEW Add() FUNCTION ADDS THE TETROMINO TO THE BOARD ACCORDING TO THE ITS SHAPE
        ONLY IF THE BOARD IS AVALIABLE TO PRINT TOP BOTTOM
        */
        if(shape.getKey()=='I'){
            if(board[1][(length/2)-2]=='.'&&board[1][(length/2)-1]=='.'&&board[1][(length/2)]=='.'&&board[1][(length/2)+1]=='.'){
                board[1][(length/2)-2]='I';
                board[1][(length/2)-1]='I';
                board[1][(length/2)]='I';
                board[1][(length/2)+1]='I';
                shape.setAdd(true); // that means the shape are printed the top bottom screen
            }
            else{
                shape.setAdd(false);//that means i couldn't do it
            } 
        }
        else if(shape.getKey()=='O'){
            if(board[1][(length/2)-1]=='.'&&board[2][(length/2)-1]=='.'&&board[1][(length/2)]=='.'&&board[2][(length/2)]=='.'){
                board[1][(length/2)-1]='O';
                board[2][(length/2)-1]='O';
                board[1][(length/2)]='O';
                board[2][(length/2)]='O';
                
                shape.setAdd(true);
            }
            else{
                shape.setAdd(false);
            } 
        }
        else if(shape.getKey()=='T'){
            if(board[1][length/2]=='.'&&board[1][(length/2)-1]=='.'&&board[1][(length/2)+1]=='.'&&board[2][length/2]=='.'){
                board[1][length/2]='T';
                board[1][(length/2)-1]='T';
                board[1][(length/2)+1]='T';
                board[2][length/2]='T';
                shape.setAdd(true);
            }
            else{
                shape.setAdd(false);
            }       
        }
        else if(shape.getKey()=='J'){
            if(board[1][length/2]=='.'&&board[2][length/2]=='.'&&board[3][length/2]=='.'&&board[3][(length/2)-1]=='.'){
                board[1][length/2]='J';
                board[2][length/2]='J';
                board[3][length/2]='J';
                board[3][(length/2)-1]='J';
                shape.setAdd(true);
            }
            else{
                shape.setAdd(false);
            }
        }
        else if(shape.getKey()=='L'){
            if(board[1][length/2]=='.'&&board[2][length/2]=='.'&&board[3][length/2]=='.'&&board[3][(length/2)+1]=='.'){
                board[1][length/2]='L';
                board[2][length/2]='L';
                board[3][length/2]='L';
                board[3][(length/2)+1]='L';
                shape.setAdd(true);
            }
            else{
                shape.setAdd(false);
            }
        }
        else if(shape.getKey()=='S'){
            if(board[1][length/2]=='.'&&board[2][length/2]=='.'&&board[1][(length/2)+1]=='.'&&board[2][(length/2)-1]=='.'){
                board[1][length/2]='S';
                board[2][length/2]='S';
                board[1][(length/2)+1]='S';
                board[2][(length/2)-1]='S';
                shape.setAdd(true);
            }
            else{
                shape.setAdd(false);
            }
        }
        else if(shape.getKey()=='Z'){
            if(board[1][length/2]=='.'&&board[2][length/2]=='.'&&board[1][(length/2)-1]=='.'&&board[2][(length/2)+1]=='.'){
                board[1][length/2]='Z';
                board[2][length/2]='Z';
                board[1][(length/2)-1]='Z';
                board[2][(length/2)+1]='Z';
                shape.setAdd(true);
            }
            else{
                shape.setAdd(false);
            }
        }
        draw();
        return this;
    }

    public void rotate_added_shape(final Tetromino shape){
        //WHEN I NEED TO ROTATE A TETROMINO
        // I PRINT IT AFTER Add() FUNCTION
        //SO, IN THIS FUNCTION I NEED TO CLEAR UNROTATED TETROMINO FROM THE TOP MIDDLE
        for(int i=1;i<4;i++){
            for(int j=1;j<length-1;j++){
                if(shape.getKey()=='I' && shape.getAdd()){
                        board[1][(length/2)-2]='.';
                        board[1][(length/2)-1]='.';
                        board[1][(length/2)]='.';
                        board[1][(length/2)+1]='.';
                }
                else if(shape.getKey()=='O' && shape.getAdd()){
                        board[1][(length/2)-1]='.';
                        board[2][(length/2)-1]='.';
                        board[1][(length/2)]='.';
                        board[2][(length/2)]='.';
                }
                else if(shape.getKey()=='T' && shape.getAdd()){
                        board[1][length/2]='.';
                        board[1][(length/2)-1]='.';
                        board[1][(length/2)+1]='.';
                        board[2][length/2]='.';
                }
                else if(shape.getKey()=='J' && shape.getAdd()){
                        board[1][length/2]='.';
                        board[2][length/2]='.';
                        board[3][length/2]='.';
                        board[3][(length/2)-1]='.';
                }
                else if(shape.getKey()=='L' && shape.getAdd()){
                        board[1][length/2]='.';
                        board[2][length/2]='.';
                        board[3][length/2]='.';
                        board[3][(length/2)+1]='.';
                }
                else if(shape.getKey()=='S' && shape.getAdd()){
                        board[1][length/2]='.';
                        board[2][length/2]='.';
                        board[1][(length/2)+1]='.';
                        board[2][(length/2)-1]='.';
                }
                else if(shape.getKey()=='Z' && shape.getAdd()){
                        board[1][length/2]='.';
                        board[2][length/2]='.';
                        board[1][(length/2)-1]='.';
                        board[2][(length/2)+1]='.';
                }
            }
        }
    }

    public void Animate(Tetromino shape, int count_move, int count_rotate, String direction){
        /*
        1. Draw the board with Tetromino at the top 
        2. Ask the user rotation direction and rotation count 
        3. Ask the user move direction and count 
        4. Rotate and move the Tetromino 
        5. Draw the board 
        6. Sleep 50 miliseconds
        7. Lower the Tetromino one level and go to step 5 until it hits the bottom.
        */
        for(int i=0;i<count_rotate;i++){// ROTATING THE SHAPES THE USER ENTERED COUNT TIMES
            shape.rotate();
        }
        //*this+=shape; // operator overloading to add tetromino the top bottom
        //draw();
        clear_top(shape);
        Add(shape);
        if(check_index(shape,count_move,direction)){// THAT MEANS THE SHAPE WITH ROTATED FORM CAN BE FITTED TO THE BOARD
            move_animation(shape);
            clear();
            draw();
        } 
        else{
            System.err.println("\nThe shape cannot be fitted that index\n");
            clear_top(shape);
            //draw();
        }
        
    }

    public void clear_top(final Tetromino shape){
        // WHEN THE TETROMINO CANNOT BE FITTED THE INDEXES OF USER ENTERED, I NEED TO CLEAR TETROMINO FROM THE TOP BOTTOM
        //SINCE EVERY TETROMINO HAS DIFFERENT INDEXES, I CHECK EACH ONE
        if(shape.getKey()=='I'){
            board[1][(length/2)-2]='.'; board[1][(length/2)-1]='.';
            board[1][(length/2)]='.'; board[1][(length/2)+1]='.';
        }
        else if(shape.getKey()=='O'){
            board[1][(length/2)-1]='.'; board[1][(length/2)]='.';
            board[2][(length/2)-1]='.'; board[2][(length/2)]='.';
        }
        else if(shape.getKey()=='T'){
            board[2][(length/2)]='.'; board[1][(length/2)]='.';
            board[1][(length/2)-1]='.'; board[1][(length/2)+1]='.';
        }
        else if(shape.getKey()=='J'){
            board[3][(length/2)-1]='.'; board[3][(length/2)]='.';
            board[2][(length/2)]='.'; board[1][(length/2)]='.';
        }
        else if(shape.getKey()=='L'){
            board[3][(length/2)]='.'; board[2][(length/2)]='.';
            board[1][(length/2)]='.'; board[3][(length/2)+1]='.';
        }
        else if(shape.getKey()=='S'){
            board[2][(length/2)-1]='.'; board[2][(length/2)]='.';
            board[1][(length/2)]='.'; board[1][(length/2)+1]='.';
        }
        else if(shape.getKey()=='Z'){
            board[2][(length/2)]='.'; board[2][(length/2)+1]='.';
            board[1][(length/2)]='.'; board[1][(length/2)-1]='.';
        }
    }

    public boolean check_index(final Tetromino shape, int count, String direction){
        //these function to get indexes the user want;
        //for example shape is T tetromino without rotated;
        //user wants to move it 2 times to right;
        //i check the downest index the shape can be fitted;
        //and i keep that index in my index_x and index_y variables which is coming from Tetris class
        if((length/2)+count>length){
            System.err.println("Out of the range!\n");
            return false;
        }
        if(direction.equals("L")){
            count*=-1;
        }
        if(shape.getKey()=='I'){
            for(int i=height-1;i>0;i--){
                if(board[i][(length/2)-2+count]=='.'&&board[i][(length/2)-1+count]=='.'&&
                board[i][(length/2)+count]=='.'&&board[i][(length/2)+1+count]=='.'&&
                (shape.getRotated()==0||shape.getRotated()==2)){
                //The if for I tetromino which is not rotated;
                    index_y=(length/2)-2+count;
                    index_x=i;
                    return true;
                                
            }
            else if(board[i][(length/2)+count]=='.'&&board[i-1][(length/2)+count]=='.'&&
            board[i-2][(length/2)+count]=='.'&&board[i-3][(length/2)+count]=='.'&&
            (shape.getRotated()==1||shape.getRotated()==3)){
                 //The if for I tetromino which is rotated;
                index_y=(length/2)+count;
                index_x=i;
                return true;
                }
            }
        }
            else if(shape.getKey()=='O'){
                for(int i=height-1;i>0;i--){
                    if(board[i][(length/2)-1+count]=='.'&&board[i][(length/2)+count]=='.'&&
                    board[i-1][(length/2)-1+count]=='.'&&board[i-1][(length/2)+count]=='.'){
                        //The if for O tetromino
                        index_y=(length/2)-1+count;
                        index_x=i;
                        return true;
                    }
                }
            }
            else if(shape.getKey()=='T'){
                for(int i=height-1;i>0;i--){
                    if(board[i][(length/2)+count]=='.'&&board[i-1][(length/2)+count]=='.'&&
                    board[i-1][(length/2)-1+count]=='.'&&board[i-1][(length/2)+1+count]=='.'&&
                    shape.getRotated()==0){
                        //The if for T tetromino which is not rotated;
                        index_y=(length/2)+count;
                        index_x=i;
                        return true;
                    }
                    else if(board[i][(length/2)+count]=='.'&&board[i-1][(length/2)+count]=='.'&&
                    board[i-1][(length/2)-1+count]=='.'&&board[i-2][(length/2)+count]=='.'&&
                    shape.getRotated()==1){
                        //The if for T tetromino which is rotated 1 times to right;
                        index_y=(length/2)+count;
                        index_x=i;
                        return true;
                    }
                    else if(board[i][(length/2)-1+count]=='.'&&board[i][(length/2)+count]=='.'&&
                    board[i][(length/2)+1+count]=='.'&&board[i-1][(length/2)+count]=='.'&&
                    shape.getRotated()==2){
                        //The if for T tetromino which is rotated 2 times to right;
                        index_y=(length/2)-1+count;
                        index_x=i;
                        return true;
                    }
                    else if(board[i][(length/2)+count]=='.'&&board[i-1][(length/2)+count]=='.'&&
                    board[i-1][(length/2)+1+count]=='.'&&board[i-2][(length/2)+count]=='.'&&
                    shape.getRotated()==3){
                        //The if for T tetromino which is rotated 3 times to right;
                        index_y=(length/2)+count;
                        index_x=i;
                        return true;
                    }
                }
            }
            else if(shape.getKey()=='J'){
                for(int i=height-1;i>0;i--){
                    if(board[i][(length/2)-1+count]=='.'&&board[i][(length/2)+count]=='.'&&
                    board[i-1][(length/2)+count]=='.'&&board[i-2][(length/2)+count]=='.'&&
                    shape.getRotated()==0){
                        //The if for J tetromino which is rotated 0 times to right;
                        index_y=(length/2)-1+count;
                        index_x=i;
                        return true;
                    }
                    else if(board[i][(length/2)-1+count]=='.'&&board[i][(length/2)+count]=='.'&&
                    board[i][(length/2)+1+count]=='.'&&board[i-1][(length/2)-1+count]=='.'&&
                    shape.getRotated()==1){
                        //The if for J tetromino which is rotated 1 times to right;
                        index_y=(length/2)-1+count;
                        index_x=i;
                        return true;
                    }
                    else if(board[i][(length/2)-1+count]=='.'&&board[i-1][(length/2)-1+count]=='.'&&
                    board[i-2][(length/2)-1+count]=='.'&&board[i-2][(length/2)+count]=='.'&&
                    shape.getRotated()==2){
                        //The if for J tetromino which is rotated 2 times to right;
                        index_y=(length/2)-1+count;
                        index_x=i;
                        return true;
                    }
                    else if(board[i][(length/2)+1+count]=='.'&&board[i-1][(length/2)+1+count]=='.'&&
                    board[i-1][(length/2)+count]=='.'&&board[i-1][(length/2)-1+count]=='.'&&
                    shape.getRotated()==3){
                        //The if for J tetromino which is rotated 3 times to right;
                        index_y=(length/2)+1+count;
                        index_x=i;
                        return true;
                    }
                }
            }
            else if(shape.getKey()=='L'){
                for(int i=height-1;i>0;i--){
                    if(board[i][(length/2)+count]=='.'&&board[i-1][(length/2)+count]=='.'&&
                    board[i-2][(length/2)+count]=='.'&&board[i][(length/2)+1+count]=='.'&&
                    shape.getRotated()==0){
                        //The if for L tetromino which is rotated 0 times to right;
                        index_y=(length/2)+count;
                        index_x=i;
                        return true;
                    }
                    else if(board[i][(length/2)-1+count]=='.'&&board[i-1][(length/2)-1+count]=='.'&&
                    board[i-1][(length/2)+count]=='.'&&board[i-1][(length/2)+1+count]=='.'&&
                    shape.getRotated()==1){
                        //The if for L tetromino which is rotated 1 times to right;
                        index_y=(length/2)-1+count;
                        index_x=i;
                        return true;
                    }
                    else if(board[i][(length/2)+count]=='.'&&board[i-1][(length/2)+count]=='.'&&
                    board[i-2][(length/2)+count]=='.'&&board[i-2][(length/2)-1+count]=='.'&&
                    shape.getRotated()==2){
                        //The if for L tetromino which is rotated 2 times to right;
                        index_y=(length/2)+count;
                        index_x=i;
                        return true;
                    }
                    else if(board[i][(length/2)-1+count]=='.'&&board[i][(length/2)+count]=='.'&&
                    board[i][(length/2)+1+count]=='.'&&board[i-1][(length/2)+1+count]=='.'&&
                    shape.getRotated()==3){
                        //The if for L tetromino which is rotated 3 times to right;
                        index_y=(length/2)-1+count;
                        index_x=i;
                        return true;
                    }
                }
            }
            else if(shape.getKey()=='S'){
                for(int i=height-1;i>0;i--){
                    if(board[i][(length/2)-1+count]=='.'&&board[i][(length/2)+count]=='.'&&
                    board[i-1][(length/2)+count]=='.'&&board[i-1][(length/2)+1+count]=='.'&&
                    (shape.getRotated()==0||shape.getRotated()==2)){
                        //The if for S tetromino which is rotated 0 times to right;
                        index_y=(length/2)-1+count;
                        index_x=i;
                        return true;
                    }
                    else if(board[i][(length/2)+count]=='.'&&board[i-1][(length/2)+count]=='.'&&
                    board[i-1][(length/2)-1+count]=='.'&&board[i-2][(length/2)-1+count]=='.'&&
                    (shape.getRotated()==1||shape.getRotated()==3)){
                        //The if for S tetromino which is rotated 1 times to right;
                        index_y=(length/2)+count;
                        index_x=i;
                        return true;
                    }
                }
            }
            else if(shape.getKey()=='Z'){
                for(int i=height-1;i>0;i--){
                    if(board[i][(length/2)+count]=='.'&&board[i][(length/2)+1+count]=='.'&&
                    board[i-1][(length/2)+count]=='.'&&board[i-1][(length/2)-1+count]=='.'&&
                    (shape.getRotated()==0||shape.getRotated()==2)){
                        //The if for Z tetromino which is rotated 0 times to right;
                        index_y=(length/2)+count;
                        index_x=i;
                        return true;
                    }
                    else if(board[i][(length/2)+count]=='.'&&board[i-1][(length/2)+count]=='.'&&
                    board[i-1][(length/2)+1+count]=='.'&&board[i-2][(length/2)+1+count]=='.'&&
                    (shape.getRotated()==1||shape.getRotated()==3)){
                        //The if for Z tetromino which is rotated 1 times to right;
                        index_y=(length/2)+count;
                        index_x=i;
                        return true;
                    }
                }
            }
        return false;
    }

    public final boolean game_over(){
        //CHECKING IF THE BOARD IS FULL OR NOT
        int counter=0;
        for(int j=1;j<length-1;j++){
            if(board[2][j]!='.'){
                counter++;
            }
        }
        if(counter>(length/2)){
            return false;
        }
        return true;
    }

    public void create_board(){
        char [][]temp=new char[height][length];
        board=temp;
    }

    public void fill_board(){
        // FILLING THE EMPTY BOARD WITH SIZES
        for(int i=0;i<height;i++){ 
            for(int j=0;j<length;j++){
                if(j==0 || j==length-1){
                    board[i][j]='X';
                }
                else if(i==0 || i==height-1){
                    board[i][j]='X';
                }
                else{
                    board[i][j]='.';
                }
            }
        }
    }

    public void clear(){
        //this function to clear horizantal fully tables;
        //also it moves every index to down
        int counter=0;
        for(int i=height-2;i>0;i--){
            for(int j=1;j<length-1;j++){
                if(board[i][j]!='.'){counter++;}
            }
            if(counter==length-2){
                for(int k=i-1;k>0;k--){
                    for(int t=1;t<length-1;t++){
                        board[k+1][t]=board[k][t];
                    }
                }
                for(int t=1;t<length-1;t++){
                    board[1][t]='.';
                }
                i=height-1;
            }
            counter=0;
        }
    }

    public final void draw() {
        // MY DRAW FUNCTION, DRAWING THE BOARD WITH TETROMINOS
        try{
            Thread.sleep(500);
        }catch(Exception e){
            
        }
        System.out.print("\033[H\033[2J");

        for(int i=0;i<height;i++){
            for(int j=0;j<length;j++){
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
    }

    public void fill_just_y_indexes(final Tetromino shape){
        // THIS FUNCTION IS TO CHECK IF THERE IS ANY COLLUSION WHEN I MOVE THE TETROMINO RIGHT OR LEFT
        // IF THERE IS A COLLUSION, I PRINT THE TETROMINO JUST CORRECT INDEX WITHOUT MOVING...
        // I NEED TO CHECK EVERY SHAPE AND DIRECTION OF THE SHAPE.
        if(shape.getKey()=='I'){
            if(shape.getRotated()==0){
                board[1][index_y]='I';
                board[1][index_y+1]='I';
                board[1][index_y+1]='I';
                board[1][index_y+1]='I';
            }
            else if(shape.getRotated()==1){
                board[1][index_y]='I';
                board[2][index_y]='I';
                board[3][index_y]='I';
                board[4][index_y]='I';
            }
        }
        else if(shape.getKey()=='O'){
            board[2][index_y]='O';
            board[2][index_y+1]='O';
            board[1][index_y]='O';
            board[1][index_y+1]='O';
        }
        else if(shape.getKey()=='T'){
            if(shape.getRotated()==0){
                board[2][index_y]='T';
                board[1][index_y]='T';
                board[1][index_y-1]='T';
                board[1][index_y+1]='T';
            }
            else if(shape.getRotated()==1){
                board[3][index_y]='T';
                board[2][index_y]='T';
                board[2][index_y-1]='T';
                board[1][index_y]='T';
            }
            else if(shape.getRotated()==2){
                board[2][index_y]='T';
                board[2][index_y+1]='T';
                board[2][index_y+2]='T';
                board[1][index_y+1]='T';
            }
            else if(shape.getRotated()==3){
                board[3][index_y]='T';
                board[2][index_y]='T';
                board[2][index_y+1]='T';
                board[1][index_y]='T';
            }
        }
        else if(shape.getKey()=='L'){
            if(shape.getRotated()==0){
                board[3][index_y]='L';
                board[3][index_y+1]='L';
                board[2][index_y]='L';
                board[1][index_y]='L';
            }
            else if(shape.getRotated()==1){
                board[2][index_y]='L';
                board[1][index_y]='L';
                board[1][index_y+1]='L';
                board[1][index_y+1]='L';
            }
            else if(shape.getRotated()==2){
                board[3][index_y]='L';
                board[2][index_y]='L';
                board[1][index_y]='L';
                board[1][index_y-1]='L';
            }
            else if(shape.getRotated()==3){
                board[2][index_y]='L';
                board[2][index_y+1]='L';
                board[2][index_y+2]='L';
                board[1][index_y]='L';
            }
        }
        else if(shape.getKey()=='J'){
            if(shape.getRotated()==0){
                board[3][index_y]='J';
                board[3][index_y+1]='J';
                board[2][index_y+1]='J';
                board[1][index_y+1]='J';
            }
            else if(shape.getRotated()==1){
                board[2][index_y]='J';
                board[2][index_y+1]='J';
                board[2][index_y+2]='J';
                board[1][index_y]='J';
            }
            else if(shape.getRotated()==2){
                board[3][index_y]='J';
                board[2][index_y]='J';
                board[1][index_y]='J';
                board[1][index_y+1]='J';
            }
            else if(shape.getRotated()==3){
                board[2][index_y]='J';
                board[1][index_y]='J';
                board[1][index_y-1]='J';
                board[1][index_y-2]='J';
            }
        }
        else if(shape.getKey()=='S'){
            if(shape.getRotated()==0){
                board[2][index_y]='S';
                board[2][index_y+1]='S';
                board[1][index_y+1]='S';
                board[1][index_y+2]='S';
            }
            else if(shape.getRotated()==1){
                board[3][index_y]='S';
                board[2][index_y]='S';
                board[2][index_y-1]='S';
                board[1][index_y-1]='S';
            }
        }
        else if(shape.getKey()=='Z'){
            if(shape.getRotated()==0){
                board[2][index_y]='Z';
                board[2][index_y+1]='Z';
                board[1][index_y]='Z';
                board[1][index_y-1]='Z';
            }
            else if(shape.getRotated()==1){
                board[3][index_y]='Z';
                board[2][index_y]='Z';
                board[2][index_y+1]='Z';
                board[1][index_y+1]='Z';
            }
        }
    }

    public void fill_indexes(final Tetromino shape){
        // THIS FUNCTION IS TO CHECK IF THERE IS ANY COLLUSION WHEN I MOVE THE TETROMINO
        // IF THERE IS A COLLUSION, I PRINT THE TETROMINO JUST CORRECT INDEX WITHOUT MOVING...
        // I NEED TO CHECK EVERY SHAPE AND DIRECTION OF THE SHAPE.
        if(shape.getKey()=='I'){
            if(shape.getRotated()==0){
                board[index_x][index_y]='I';
                board[index_x][index_y+1]='I';
                board[index_x][index_y+2]='I';
                board[index_x][index_y+3]='I';
            }
            else if(shape.getRotated()==1){
                board[index_x][index_y]='I';
                board[index_x-1][index_y]='I';
                board[index_x-2][index_y]='I';
                board[index_x-3][index_y]='I';
            }
        }
        else if(shape.getKey()=='O'){
            board[index_x][index_y]='O';
            board[index_x][index_y+1]='O';
            board[index_x-1][index_y]='O';
            board[index_x-1][index_y+1]='O';
        }
        else if(shape.getKey()=='T'){
            if(shape.getRotated()==0){
                board[index_x][index_y]='T';
                board[index_x-1][index_y]='T';
                board[index_x-1][index_y-1]='T';
                board[index_x-1][index_y+1]='T';
            }
            else if(shape.getRotated()==1){
                board[index_x][index_y]='T';
                board[index_x-1][index_y]='T';
                board[index_x-1][index_y-1]='T';
                board[index_x-2][index_y]='T';
            }
            else if(shape.getRotated()==2){
                board[index_x][index_y]='T';
                board[index_x][index_y+1]='T';
                board[index_x][index_y+2]='T';
                board[index_x-1][index_y+1]='T';
            }
            else if(shape.getRotated()==3){
                board[index_x][index_y]='T';
                board[index_x-1][index_y]='T';
                board[index_x-1][index_y+1]='T';
                board[index_x-2][index_y]='T';
            }
        }
        else if(shape.getKey()=='L'){
            if(shape.getRotated()==0){
                board[index_x][index_y]='L';
                board[index_x][index_y+1]='L';
                board[index_x-1][index_y]='L';
                board[index_x-2][index_y]='L';
            }
            else if(shape.getRotated()==1){
                board[index_x][index_y]='L';
                board[index_x-1][index_y]='L';
                board[index_x-1][index_y+1]='L';
                board[index_x-1][index_y+1]='L';
            }
            else if(shape.getRotated()==2){
                board[index_x][index_y]='L';
                board[index_x-1][index_y]='L';
                board[index_x-2][index_y]='L';
                board[index_x-2][index_y-1]='L';
            }
            else if(shape.getRotated()==3){
                board[index_x][index_y]='L';
                board[index_x][index_y+1]='L';
                board[index_x][index_y+2]='L';
                board[index_x-1][index_y+2]='L';
            }
        }
        else if(shape.getKey()=='J'){
            if(shape.getRotated()==0){
                board[index_x][index_y]='J';
                board[index_x][index_y+1]='J';
                board[index_x-1][index_y+1]='J';
                board[index_x-2][index_y+1]='J';
            }
            else if(shape.getRotated()==1){
                board[index_x][index_y]='J';
                board[index_x][index_y+1]='J';
                board[index_x][index_y+2]='J';
                board[index_x-1][index_y]='J';
            }
            else if(shape.getRotated()==2){
                board[index_x][index_y]='J';
                board[index_x-1][index_y]='J';
                board[index_x-2][index_y]='J';
                board[index_x-2][index_y+1]='J';
            }
            else if(shape.getRotated()==3){
                board[index_x][index_y]='J';
                board[index_x-1][index_y]='J';
                board[index_x-1][index_y-1]='J';
                board[index_x-1][index_y-2]='J';
            }
        }
        else if(shape.getKey()=='S'){
            if(shape.getRotated()==0){
                board[index_x][index_y]='S';
                board[index_x][index_y+1]='S';
                board[index_x-1][index_y+1]='S';
                board[index_x-1][index_y+2]='S';
            }
            else if(shape.getRotated()==1){
                board[index_x][index_y]='S';
                board[index_x-1][index_y]='S';
                board[index_x-1][index_y-1]='S';
                board[index_x-2][index_y-1]='S';
            }
        }
        else if(shape.getKey()=='Z'){
            if(shape.getRotated()==0){
                board[index_x][index_y]='Z';
                board[index_x][index_y+1]='Z';
                board[index_x-1][index_y]='Z';
                board[index_x-1][index_y-1]='Z';
            }
            else if(shape.getRotated()==1){
                board[index_x][index_y]='Z';
                board[index_x-1][index_y]='Z';
                board[index_x-1][index_y+1]='Z';
                board[index_x-2][index_y+1]='Z';
            }
        }
    }

    public void move_animation(Tetromino shape){
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
                if(index_y<=(length/2)-2){
                    // THIS IF TO UNDERSTAND WILL I MOVE THE SHAPE TO THE RIGHT OR LEFT!!!/ IF IS TRUE I WILL MOVE LEFT
                    for(int j=(length/2)-2;j>index_y;j--){
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
                    for(int j=(length/2)-2;j<index_y;j++){
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
                for(int i=2;i<=index_x;i++){
                    // THIS FOR LOOP FOR MOVING DOWN
                        board[i-1][index_y]='.';
                        board[i-1][index_y+1]='.';
                        board[i-1][index_y+2]='.';
                        board[i-1][index_y+3]='.';
                        if(board[i][index_y]!='.'||board[i][index_y+1]!='.'||board[i][index_y+2]!='.'||board[i][index_y+3]!='.'){
                            fill_indexes(shape);
                            draw();
                            break;
                        }
                        board[i][index_y]='I';
                        board[i][index_y+1]='I';
                        board[i][index_y+2]='I';
                        board[i][index_y+3]='I';

                        draw();
                    }
            }
            else{// THIS ELSE MEANS THE SHAPE ROTATED
                draw();            
                rotate_added_shape(shape);
                if(board[1][length/2]=='.'&&board[2][length/2]=='.'&&board[3][length/2]=='.'&&board[4][length/2]=='.'){
                    board[1][length/2]='I';
                    board[2][length/2]='I';
                    board[3][length/2]='I';
                    board[4][length/2]='I';
                }
                else{
                    fill_indexes(shape);
                    draw();
                    return;
                }
                
                
                draw(); 
                if(index_y<=(length/2)){// TO UNDERSTAND MOVING RIGHT OR LEFT.. MOVING LEFT
                    for(int j=length/2;j>index_y;j--){
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
                    for(int j=length/2;j<index_y;j++){
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
                for(int i=5;i<=index_x;i++){
                    //MOVING DOWN LOOP
                        board[i-1][index_y]='.';
                        board[i-2][index_y]='.';
                        board[i-3][index_y]='.';
                        board[i-4][index_y]='.';
                        if(board[i][index_y]!='.'||board[i-1][index_y]!='.'||board[i-2][index_y]!='.'||board[i-3][index_y]!='.'){
                            fill_indexes(shape);
                            draw();
                            break;
                        }
                        board[i][index_y]='I';
                        board[i-1][index_y]='I';
                        board[i-2][index_y]='I';
                        board[i-3][index_y]='I';

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
            if(index_y<=(length/2)-1){ // THAT MEANS THE SHAPE WILL MOVE LEFT
                for(int j=(length/2)-1;j>index_y;j--){
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
                for(int j=(length/2)-1;j<index_y;j++){
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
            for(int i=3;i<=index_x;i++){ // THIS LOOP TO SHAPE TO MOVE DOWN
                    board[i-1][index_y]='.';
                    board[i-1][index_y+1]='.';
                    board[i-2][index_y]='.';
                    board[i-2][index_y+1]='.';
                    if(board[i][index_y]!='.'||board[i][index_y+1]!='.'||board[i-1][index_y]!='.'||board[i-1][index_y+1]!='.'){
                        fill_indexes(shape);
                        draw();
                        break;
                    }
                    board[i][index_y]='O';
                    board[i][index_y+1]='O';
                    board[i-1][index_y]='O';
                    board[i-1][index_y+1]='O';
                    
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
                if(index_y<=length/2){
                    for(int j=length/2;j>index_y;j--){
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
                    for(int j=length/2;j<index_y;j++){
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
                for(int i=3;i<=index_x;i++){
                        board[i-1][index_y]='.';
                        board[i-2][index_y]='.';
                        board[i-2][index_y-1]='.';
                        board[i-2][index_y+1]='.';
                        if(board[i][index_y]!='.'||board[i-1][index_y]!='.'||board[i-1][index_y-1]!='.'||board[i-1][index_y+1]!='.'){
                            fill_indexes(shape);
                            draw();
                            break;
                        }
                        board[i][index_y]='T';
                        board[i-1][index_y]='T';
                        board[i-1][index_y-1]='T';
                        board[i-1][index_y+1]='T';

                        draw();
                    }
            }
            else if(shape.getRotated()==1){
                draw();            
                rotate_added_shape(shape);
                if(board[1][(length/2)]=='.'&&board[2][(length/2)]=='.'&&board[2][(length/2)-1]=='.'&&board[3][(length/2)]=='.'){
                    board[1][(length/2)]='T';
                    board[2][(length/2)]='T';
                    board[2][(length/2)-1]='T';
                    board[3][(length/2)]='T';
                }
                else{
                    fill_indexes(shape);
                    draw();
                    return;
                }
                
                draw();            
                if(index_y<=(length/2)){
                    for(int j=(length/2);j>index_y;j--){
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
                    for(int j=(length/2);j<index_y;j++){
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
                for(int i=4;i<=index_x;i++){
                        board[i-1][index_y]='.';
                        board[i-2][index_y]='.';
                        board[i-2][index_y-1]='.';
                        board[i-3][index_y]='.';
                        if(board[i][index_y]!='.'||board[i-1][index_y]!='.'||board[i-1][index_y-1]!='.'||board[i-2][index_y]!='.'){
                            fill_indexes(shape);
                            draw();
                            break;
                        }
                        board[i][index_y]='T';
                        board[i-1][index_y]='T';
                        board[i-1][index_y-1]='T';
                        board[i-2][index_y]='T';

                        draw();
                    }
            }
            else if(shape.getRotated()==2){
                draw();            
                rotate_added_shape(shape);
                if(board[1][(length/2)]=='.'&&board[2][(length/2)]=='.'&&board[2][(length/2)-1]=='.'&&board[2][(length/2)+1]=='.'){
                    board[1][(length/2)]='T';
                    board[2][(length/2)]='T';
                    board[2][(length/2)-1]='T';
                    board[2][(length/2)+1]='T';
                }
                else{
                    fill_indexes(shape);
                    draw();
                    return;
                }
                
                draw();           
                if(index_y<=(length/2)-1){
                    for(int j=(length/2)-1;j>index_y;j--){
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
                    for(int j=(length/2)-1;j<index_y;j++){
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
                for(int i=3;i<=index_x;i++){
                        board[i-1][index_y]='.';
                        board[i-1][index_y+1]='.';
                        board[i-2][index_y+1]='.';
                        board[i-1][index_y+2]='.';
                        if(board[i][index_y]!='.'||board[i][index_y+1]!='.'||board[i-1][index_y+1]!='.'||board[i][index_y+2]!='.'){
                            fill_indexes(shape);
                            draw();
                            break;
                        }
                        board[i][index_y]='T';
                        board[i][index_y+1]='T';
                        board[i-1][index_y+1]='T';
                        board[i][index_y+2]='T';

                        draw();
                    }
            }
            else if(shape.getRotated()==3){
                draw();            
                rotate_added_shape(shape);
                if(board[1][length/2]=='.'&&board[2][length/2]=='.'&&board[2][(length/2)+1]=='.'&&board[3][length/2]=='.'){
                    board[1][length/2]='T';
                    board[2][length/2]='T';
                    board[2][(length/2)+1]='T';
                    board[3][length/2]='T';
                }
                else{
                    fill_indexes(shape);
                    draw();
                    return;
                }

                draw();            
                if(index_y<=length/2){
                    for(int j=length/2;j>index_y;j--){
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
                    for(int j=length/2;j<index_y;j++){
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
                for(int i=4;i<=index_x;i++){
                        board[i-1][index_y]='.';
                        board[i-2][index_y]='.';
                        board[i-2][index_y+1]='.';
                        board[i-3][index_y]='.';
                        if(board[i][index_y]!='.'||board[i-1][index_y]!='.'||board[i-1][index_y+1]!='.'||board[i-2][index_y]!='.'){
                            fill_indexes(shape);
                            draw();
                            break;
                        }
                        board[i][index_y]='T';
                        board[i-1][index_y]='T';
                        board[i-1][index_y+1]='T';
                        board[i-2][index_y]='T';

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
                if(index_y<=(length/2)-1){
                    for(int j=(length/2)-1;j>index_y;j--){
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
                    for(int j=(length/2)-1;j<index_y;j++){
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
                for(int i=4;i<=index_x;i++){
                        board[i-1][index_y]='.';
                        board[i-1][index_y+1]='.';
                        board[i-2][index_y+1]='.';
                        board[i-3][index_y+1]='.';
                        if(board[i][index_y]!='.'||board[i][index_y+1]!='.'||board[i-1][index_y+1]!='.'||board[i-2][index_y+1]!='.'){
                            fill_indexes(shape);
                            draw();
                            break;
                        }
                        board[i][index_y]='J';
                        board[i][index_y+1]='J';
                        board[i-1][index_y+1]='J';
                        board[i-2][index_y+1]='J';

                        draw();
                    }
            }
            else if(shape.getRotated()==1){
                draw();            
                rotate_added_shape(shape);
                if(board[1][(length/2)-1]=='.'&&board[2][(length/2)-1]=='.'&&board[2][(length/2)]=='.'&&board[2][(length/2)+1]=='.'){
                    board[1][(length/2)-1]='J';
                    board[2][(length/2)-1]='J';
                    board[2][(length/2)]='J';
                    board[2][(length/2)+1]='J';
                }
                else{
                    fill_indexes(shape);
                    draw();
                    return;
                }

                draw();            
                if(index_y<=(length/2)-1){
                    for(int j=(length/2)-1;j>index_y;j--){
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
                    for(int j=(length/2)-1;j<index_y;j++){
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
                for(int i=3;i<=index_x;i++){
                        board[i-2][index_y]='.';
                        board[i-1][index_y]='.';
                        board[i-1][index_y+1]='.';
                        board[i-1][index_y+2]='.';
                        if(board[i-1][index_y]!='.'||board[i][index_y]!='.'||board[i][index_y+1]!='.'||board[i][index_y+2]!='.'){
                            fill_indexes(shape);
                            draw();
                            break;
                        }
                        board[i-1][index_y]='J';
                        board[i][index_y]='J';
                        board[i][index_y+1]='J';
                        board[i][index_y+2]='J';

                        draw();
                    }
            }
            else if(shape.getRotated()==2){
                draw();            
                rotate_added_shape(shape);
                if(board[1][(length/2)-1]=='.'&&board[1][(length/2)]=='.'&&board[2][(length/2)-1]=='.'&&board[3][(length/2)-1]=='.'){
                    board[1][(length/2)-1]='J';
                    board[1][(length/2)]='J';
                    board[2][(length/2)-1]='J';
                    board[3][(length/2)-1]='J';
                }
                else{
                    fill_indexes(shape);
                    draw();
                    return;
                }
                
                
                draw();            
                if(index_y<=(length/2)-1){
                    for(int j=(length/2)-1;j>index_y;j--){
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
                    for(int j=(length/2)-1;j<index_y;j++){
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
                for(int i=4;i<=index_x;i++){
                        board[i-3][index_y]='.';
                        board[i-3][index_y+1]='.';
                        board[i-2][index_y]='.';
                        board[i-1][index_y]='.';
                        if(board[i-2][index_y]!='.'||board[i-2][index_y+1]!='.'||board[i-1][index_y]!='.'||board[i][index_y]!='.'){
                            fill_indexes(shape);
                            draw();
                            break;
                        }
                        board[i-2][index_y]='J';
                        board[i-2][index_y+1]='J';
                        board[i-1][index_y]='J';
                        board[i][index_y]='J';

                        draw();
                    }
            }
            else if(shape.getRotated()==3){
                draw();            
                rotate_added_shape(shape);
                if(board[1][(length/2)-1]=='.'&&board[1][(length/2)]=='.'&&board[1][(length/2)+1]=='.'&&board[2][(length/2)+1]=='.'){
                    board[1][(length/2)-1]='J';
                    board[1][(length/2)]='J';
                    board[1][(length/2)+1]='J';
                    board[2][(length/2)+1]='J';
                }
                else{
                    fill_indexes(shape);
                    draw();
                    return;
                }
                
                draw();            
                if(index_y<=(length/2)+1){
                    for(int j=(length/2)+1;j>index_y;j--){
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
                    for(int j=(length/2)+1;j<index_y;j++){
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
                for(int i=3;i<=index_x;i++){
                        board[i-2][index_y]='.';
                        board[i-2][index_y-1]='.';
                        board[i-2][index_y-2]='.';
                        board[i-1][index_y]='.';
                        if(board[i-1][index_y]!='.'||board[i-1][index_y-1]!='.'||board[i-1][index_y-2]!='.'||board[i][index_y]!='.'){
                            fill_indexes(shape);
                            draw();
                            break;
                        }
                        board[i-1][index_y]='J';
                        board[i-1][index_y-1]='J';
                        board[i-1][index_y-2]='J';
                        board[i][index_y]='J';

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
                if(index_y<=(length/2)){
                    for(int j=(length/2);j>index_y;j--){
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
                    for(int j=(length/2);j<index_y;j++){
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
                for(int i=4;i<=index_x;i++){
                        board[i-1][index_y]='.';
                        board[i-1][index_y+1]='.';
                        board[i-2][index_y]='.';
                        board[i-3][index_y]='.';
                        if(board[i][index_y]!='.'||board[i][index_y+1]!='.'||board[i-1][index_y]!='.'||board[i-2][index_y]!='.'){
                            fill_indexes(shape);
                            draw();
                            break; 
                        }
                        board[i][index_y]='L';
                        board[i][index_y+1]='L';
                        board[i-1][index_y]='L';
                        board[i-2][index_y]='L';

                        draw();
                    }
            }
            else if(shape.getRotated()==1){
                draw();            
                rotate_added_shape(shape);
                if(board[1][(length/2)-1]=='.'&&board[2][(length/2)-1]=='.'&&board[1][(length/2)]=='.'&&board[1][(length/2)+1]=='.'){
                    board[1][(length/2)-1]='L';
                    board[2][(length/2)-1]='L';
                    board[1][(length/2)]='L';
                    board[1][(length/2)+1]='L';
                }
                else{
                    fill_indexes(shape);
                    draw();
                    return;
                }
                
                draw();           
                if(index_y<=(length/2)-1){
                    for(int j=(length/2)-1;j>index_y;j--){
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
                    for(int j=(length/2)-1;j<index_y;j++){
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
                for(int i=3;i<=index_x;i++){
                        board[i-1][index_y]='.';
                        board[i-2][index_y]='.';
                        board[i-2][index_y+1]='.';
                        board[i-2][index_y+2]='.';
                        if(board[i][index_y]!='.'||board[i-1][index_y]!='.'||board[i-1][index_y+1]!='.'||board[i-1][index_y+1]!='.'){
                            fill_indexes(shape);
                            draw();
                            break; 
                        }
                        board[i][index_y]='L';
                        board[i-1][index_y]='L';
                        board[i-1][index_y+1]='L';
                        board[i-1][index_y+2]='L';

                        draw();
                    }
            }
            else if(shape.getRotated()==2){
                draw();            
                rotate_added_shape(shape);
                if(board[1][(length/2)-1]=='.'&&board[1][(length/2)]=='.'&&board[2][(length/2)-1]=='.'&&board[3][(length/2)-1]=='.'){
                    board[1][(length/2)-1]='L';
                    board[1][(length/2)]='L';
                    board[2][(length/2)]='L';
                    board[3][(length/2)]='L';
                }
                else{
                    fill_indexes(shape);
                    draw();
                    return;
                }
                
                draw();            
                if(index_y<=(length/2)){
                    for(int j=(length/2);j>index_y;j--){
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
                    for(int j=(length/2);j<index_y;j++){
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
                for(int i=4;i<=index_x;i++){
                        board[i-1][index_y]='.';
                        board[i-2][index_y]='.';
                        board[i-3][index_y]='.';
                        board[i-3][index_y-1]='.';
                        if(board[i][index_y]!='.'||board[i-1][index_y]!='.'||board[i-2][index_y]!='.'||board[i-2][index_y-1]!='.'){
                            fill_indexes(shape);
                            draw();
                            break; 
                        }
                        board[i][index_y]='L';
                        board[i-1][index_y]='L';
                        board[i-2][index_y]='L';
                        board[i-2][index_y-1]='L';

                        draw();
                    }
            }
            else if(shape.getRotated()==3){
                draw();            
                rotate_added_shape(shape);
                if(board[1][(length/2)+1]=='.'&&board[2][(length/2)-1]=='.'&&board[2][(length/2)]=='.'&&board[2][(length/2)+1]=='.'){
                    board[1][(length/2)+1]='L';
                    board[2][(length/2)-1]='L';
                    board[2][(length/2)]='L';
                    board[2][(length/2)+1]='L';
                }
                else{
                    fill_indexes(shape);
                    draw();
                    return;
                }
            
                draw();            
                if(index_y<=(length/2)-1){
                    for(int j=(length/2)-1;j>index_y;j--){
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
                    for(int j=(length/2)-1;j<index_y;j++){
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
                for(int i=3;i<=index_x;i++){
                        board[i-2][index_y+2]='.';
                        board[i-1][index_y]='.';
                        board[i-1][index_y+1]='.';
                        board[i-1][index_y+2]='.';
                        if(board[i-1][index_y+2]!='.'||board[i][index_y]!='.'||board[i][index_y+1]!='.'||board[i][index_y+2]!='.'){
                            fill_indexes(shape);
                            draw();
                            break; 
                        }
                        board[i-1][index_y+2]='L';
                        board[i][index_y]='L';
                        board[i][index_y+1]='L';
                        board[i][index_y+2]='L';

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
                if(index_y<=(length/2)-1){
                    for(int j=(length/2)-1;j>index_y;j--){
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
                    for(int j=(length/2)-1;j<index_y;j++){
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
                for(int i=3;i<=index_x;i++){
                        board[i-1][index_y]='.';
                        board[i-1][index_y+1]='.';
                        board[i-2][index_y+1]='.';
                        board[i-2][index_y+2]='.';
                        if(board[i][index_y]!='.'||board[i][index_y+1]!='.'||board[i-1][index_y+1]!='.'||board[i-1][index_y+2]!='.'){
                            fill_indexes(shape);
                            draw();
                            break; 
                        }
                        board[i][index_y]='S';
                        board[i][index_y+1]='S';
                        board[i-1][index_y+1]='S';
                        board[i-1][index_y+2]='S';

                        draw();
                    }
            }
            else if(shape.getRotated()==1 || shape.getRotated()==3){
                draw();            
                rotate_added_shape(shape);
                if(board[1][(length/2)-1]=='.'&&board[2][(length/2)-1]=='.'&&board[2][(length/2)]=='.'&&board[3][(length/2)]=='.'){
                    board[1][(length/2)-1]='S';
                    board[2][(length/2)-1]='S';
                    board[2][(length/2)]='S';
                    board[3][(length/2)]='S';
                }
                else{
                    fill_indexes(shape);
                    draw();
                    return;
                }
                
                draw();            
                if(index_y<=(length/2)){
                    for(int j=(length/2);j>index_y;j--){
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
                    for(int j=(length/2);j<index_y;j++){
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
                for(int i=4;i<=index_x;i++){
                        board[i-1][index_y]='.';
                        board[i-2][index_y]='.';
                        board[i-2][index_y-1]='.';
                        board[i-3][index_y-1]='.';
                        if(board[i][index_y]!='.'||board[i-1][index_y]!='.'||board[i-1][index_y-1]!='.'||board[i-2][index_y-1]!='.'){
                            fill_indexes(shape);
                            draw();
                            break;
                        }
                        board[i][index_y]='S';
                        board[i-1][index_y]='S';
                        board[i-1][index_y-1]='S';
                        board[i-2][index_y-1]='S';

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
                if(index_y<=(length/2)){
                    for(int j=(length/2);j>index_y;j--){
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
                    for(int j=(length/2);j<index_y;j++){
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
                for(int i=3;i<=index_x;i++){
                        board[i-1][index_y]='.';
                        board[i-1][index_y+1]='.';
                        board[i-2][index_y]='.';
                        board[i-2][index_y-1]='.';

                        if(board[i][index_y]!='.'||board[i][index_y+1]!='.'||board[i-1][index_y]!='.'||board[i-1][index_y-1]!='.'){
                            fill_indexes(shape);
                            draw();
                            break;
                        }
                        board[i][index_y]='Z';
                        board[i][index_y+1]='Z';
                        board[i-1][index_y]='Z';
                        board[i-1][index_y-1]='Z';

                        draw();
                    }
            }
            else if(shape.getRotated()==1 || shape.getRotated()==3){
                draw();            
                rotate_added_shape(shape);
                if(board[1][(length/2)+1]=='.'&&board[2][(length/2)+1]=='.'&&board[2][(length/2)]=='.'&&board[3][(length/2)]=='.'){
                    board[1][(length/2)+1]='Z';
                    board[2][(length/2)+1]='Z';
                    board[2][(length/2)]='Z';
                    board[3][(length/2)]='Z';
                }
                else{
                    fill_indexes(shape);
                    draw();
                    return;
                }
                
                draw();            
                if(index_y<=(length/2)){
                    for(int j=(length/2);j>index_y;j--){
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
                    for(int j=(length/2);j<index_y;j++){
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
                for(int i=4;i<=index_x;i++){
                        board[i-1][index_y]='.';
                        board[i-2][index_y]='.';
                        board[i-2][index_y+1]='.';
                        board[i-3][index_y+1]='.';

                        if(board[i][index_y]!='.'||board[i-1][index_y]!='.'||board[i-1][index_y+1]!='.'||board[i-2][index_y+1]!='.'){
                            fill_indexes(shape);
                            break;
                        }
                        board[i][index_y]='Z';
                        board[i-1][index_y]='Z';
                        board[i-1][index_y+1]='Z';
                        board[i-2][index_y+1]='Z';

                        draw();
                    }
            }
        }

    }
}

