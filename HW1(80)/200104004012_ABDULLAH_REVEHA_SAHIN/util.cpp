#include "util.hpp"

using namespace std;


/*
This is my Tetromino class which contains private 2D char vector, int rotated to understande direction of the shape when we turn it,
and char keyword to understand which shape we are using.
Also Tetromino class has several functions. Firstly my constructor is filling the 2D vector with the correct shape according
to the parameter of enum. vector<vector<char> > loop_for_rotate(vector<vector<char> > shape) function has loop for turning
the shape to the new direction. rotate() function repairs the wrong indexes for each shape, i mean, 
i want to keep al shapes in 4x4 vector and shapes must be located leftest bottom location. When rotated function works
I increased 'int rotated' . When we look at the canFit() function this function returns true or false according to the
shapes information which it takes. For example when L shapes, which rotated 1 times to the left, takes Z shape, which
didn't rotated any direction, there will be a hole, so canFit function returns false and i will send these two shapes
with rotated form again. Finally canFit returns true with correct position of the shapes and I put them into a 2D char
vector which is in Board struct. 

*/




Tetromino:: Tetromino(){}

Tetromino:: Tetromino(enum tetros shape){ 
        //creating the 2d vector according to the enum shape..
        if(static_cast<char>(shape)=='I'){
            keyword='I';
            tet={ {' ', ' ', ' ',' '},{' ',' ', ' ', ' '},{' ', ' ', ' ',' '},{'I','I','I','I'}};
        }
        else if(static_cast<char>(shape)=='O'){
            keyword='O';
            tet={ {' ', ' ', ' ',' '}, {' ',' ',' ',' '}, {'O','O',' ',' '},{'O', 'O', ' ',' '}};
        }
        else if(static_cast<char>(shape)=='T'){
            keyword='T';
            tet={ {' ', ' ', ' ',' '}, {' ',' ',' ',' '} , {'T', 'T', 'T',' '},{' ', 'T', ' ',' '}};
        }
        else if(static_cast<char>(shape)=='J'){
            keyword='J';
            tet={ {' ',' ',' ',' '}, {' ', 'J',' ',' '}, {' ','J',' ',' '},{'J', 'J', ' ',' '}};
        }
        else if(static_cast<char>(shape)=='L'){
            keyword='L';
            tet={ {' ',' ', ' ',' '}, {'L',' ',' ',' '}, {'L',' ',' ',' '},{'L', 'L', ' ',' '}};
        }
        else if(static_cast<char>(shape)=='S'){
            keyword='S';
            tet={ {' ', ' ', ' ',' '}, {' ',' ',' ',' '}, {' ','S','S',' '},{'S', 'S', ' ',' '}};
        }
        else if(static_cast<char>(shape)=='Z'){
            keyword='Z';
            tet={ {' ', ' ', ' ',' '}, {' ',' ',' ',' '}, {'Z','Z',' ',' '},{' ', 'Z', 'Z',' '}};
        }
        print(); // PRINTING EACH TETROMINOS THE USER ENTERED 
    }

vector<vector<char> > Tetromino:: loop_for_rotate(vector<vector<char> > shape){
        // this function just for loop, and to keep new rotated shape
        vector< vector<char> > temp={{' ', ' ', ' ',' '},{' ', ' ', ' ',' '},{' ', ' ', ' ',' '},{' ', ' ', ' ',' '}};
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
        vector< vector<char> > temp={{' ', ' ', ' ',' '},{' ', ' ', ' ',' '},{' ', ' ', ' ',' '},{' ', ' ', ' ',' '}};
        int index=N-1;
        if(keyword=='I'){ // for each shape there are some speacial index cases, i check here this cases
            temp=loop_for_rotate(tet);
            if(temp[1][0]!='I'){ //THESE FOR LOOPS ARE TO REPAIR WRONG INDEXES
                for(auto i=N-1;i>=0;i--){
                    for(auto j=N-1;j>=0;j--){
                        if(temp[i][j]=='I'){
                        //cout<<i<<endl<<j<<endl;
                            temp[i+3][j]='I';
                            temp[i][j]=' ';
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
                                temp[i][j]=' ';
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
                                temp[i][j]=' ';
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
                                temp[i][j]=' ';
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
                                temp[i][j]=' ';
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
                            temp[i][j]=' ';
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
                            temp[i][j]=' ';
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
                            temp[i][j]=' ';
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
                            temp[i][j]=' ';
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
                            temp[i][j]=' ';
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
                            temp[i][j]=' ';
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
                            temp[i][j]=' ';
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
                            temp[i][j]=' ';
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
                            temp[i][j]=' ';
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
                            temp[i][j]=' ';
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
                            temp[i][j]=' ';
                        }
                    }      
                }
            }

            rotated++;
            tet=temp;
        }
    }

bool Tetromino:: canFit(Tetromino &oth){
    /*
    IN THIS FUNCTION I CHECKED EVERY WORDS WITH POSSIBLE FITS
    SO I RETURN FALSE OR TRUE TO GET BEST HORIZANTALLY FIT
    IN SOME CASES SHAPES MUST BE ROTATED SO I RETURNED FALSE IN FILL_TABLE() FUNCTION
    ACCORDING TO THE FALSE I ROTATED SHAPES AND I SEND IT AGAIN INTO canFit() FUNCTION

    REMEMBER int rotated parameter is to understand direction of the shapes.
    WHEN THE SHAPE ROTATED ONE TIME TO RIGHT int rotated WILL INCREASE ONE ---->> rotated++;
    */
        static int index=0;
        int check=0;
        if(keyword=='I' && oth.keyword=='T' && oth.rotated==2){
            check=1;
        }
        else if(keyword=='I' && oth.keyword=='J' && oth.rotated==1){
            check=1;
        }
        else if(keyword=='I' && oth.keyword=='I'){
            check=1;
        }
        else if(keyword=='I' && oth.keyword=='O'){
            check=1;
        }
        else if(keyword=='I' && oth.keyword=='L' && oth.rotated==3){
            check=1;
        }
        else if(keyword=='I' && oth.keyword=='S'){
            check=1;
        }
        else if(keyword=='I' && oth.keyword=='Z'){
            check=1;
        }
        else if(keyword=='O' && oth.keyword=='I'){
            check=1;
        }
        else if(keyword=='O' && oth.keyword=='O'){
            check=1;
        }
        else if(keyword=='O' && oth.keyword=='T' && oth.rotated==2){
            check=1;
        }
        else if(keyword=='O' && oth.keyword=='J' && oth.rotated==1){
            check=1;
        }
        else if(keyword=='O' && oth.keyword=='L' && oth.rotated==3){
            check=1;
        }
        else if(keyword=='O' && oth.keyword=='S'){
            check=1;
        }
        else if(keyword=='O' && oth.keyword=='Z' && oth.rotated==1){
            check=1;
        }
        else if(keyword=='T' && oth.keyword=='I' && rotated==2){
            check=1;
        }
        else if(keyword=='T' && oth.keyword=='O' && rotated==2){
            check=1;
        }
        else if(keyword=='T' && oth.keyword=='T' && rotated==2 && oth.rotated==2){
            check=1;
        }
        else if(keyword=='T' && oth.keyword=='J' && rotated==2 && oth.rotated==1){
            check=1;
        }
        else if(keyword=='T' && oth.keyword=='L' && rotated==2 && oth.rotated==3){
            check=1;
        }
        else if(keyword=='T' && oth.keyword=='S' && rotated==2 && oth.rotated==1){
            check=1;
        }
        else if(keyword=='T' && oth.keyword=='Z' && rotated==2){
            check=1;
        }
        else if((keyword=='J' && oth.keyword=='I' && rotated==1) || (keyword=='J' && oth.keyword=='I')){
            check=1;
        }
        else if((keyword=='J' && oth.keyword=='O' && rotated==1) || (keyword=='J' && oth.keyword=='O')){
            check=1;
        }
        else if((keyword=='J' && oth.keyword=='T' && rotated==1 && oth.rotated==2) || (keyword=='J' && oth.keyword=='T' && oth.rotated==2)){
            check=1;
        }
        else if((keyword=='J' && oth.keyword=='J' && rotated==1 && oth.rotated==1) || (keyword=='J' && oth.keyword=='J' && oth.rotated==1)){
            check=1;
        }
        else if((keyword=='J' && oth.keyword=='L' && rotated==1 && oth.rotated==3) || (keyword=='J' && oth.keyword=='L' && oth.rotated==3)){
            check=1;
        }
        else if((keyword=='J' && oth.keyword=='S' && rotated==1)){
            check=1;
        }
        else if((keyword=='J' && oth.keyword=='S' && rotated==0 && oth.rotated==0)){
            check=1;
        }
        else if((keyword=='J' && oth.keyword=='Z' && rotated==1) || (keyword=='J' && oth.keyword=='Z' && oth.rotated==1)){
            check=1;
        }
        else if(keyword=='L' && oth.keyword=='I' && rotated==3){
            check=1;
        }
        else if(keyword=='L' && oth.keyword=='O' && rotated==3){
            check=1;
        }
        else if(keyword=='L' && oth.keyword=='T' && rotated==3 && oth.rotated==2){
            check=1;
        }
        else if(keyword=='L' && oth.keyword=='J' && rotated==3 && oth.rotated==1){
            check=1;
        }
        else if(keyword=='L' && oth.keyword=='L' && rotated==3 && oth.rotated==3){
            check=1;
        }
        else if(keyword=='L' && oth.keyword=='S' && rotated==3){
            check=1;
        }
        else if(keyword=='L' && oth.keyword=='Z' && rotated==3 && oth.rotated==1){
            check=1;
        }
        else if((keyword=='S' && oth.keyword=='I' && rotated==0)|| (keyword=='S' && oth.keyword=='I' && rotated==1)){
            check=1;
        }
        else if((keyword=='S' && oth.keyword=='O')){
            check=1;
        }
        else if((keyword=='S' && oth.keyword=='T' && oth.rotated==2)){
            check=1;
        }
        else if((keyword=='S' && oth.keyword=='J' && rotated==0) || (keyword=='S' && oth.keyword=='J' && rotated==1 && oth.rotated==1)){
            check=1;
        }
        else if((keyword=='S' && oth.keyword=='L' && oth.rotated==3)){
            check=1;
        }
        else if((keyword=='S' && oth.keyword=='S')){
            check=1;
        }
        else if((keyword=='S' && oth.keyword=='Z' && rotated==1 && oth.rotated==1)){
            check=1;
        }
        else if((keyword=='Z' && oth.keyword=='I')){
            check=1;
        }
        else if((keyword=='Z' && oth.keyword=='O')){
            check=1;
        }
        else if((keyword=='Z' && oth.keyword=='T' && oth.rotated==2)){
            check=1;
        }
        else if((keyword=='Z' && oth.keyword=='J' && oth.rotated==1) || (keyword=='Z' && oth.keyword=='J' && rotated==1)){
            check=1;
        }
        else if((keyword=='Z' && oth.keyword=='L' && oth.rotated==3)){
            check=1;
        }
        else if((keyword=='Z' && oth.keyword=='S' && oth.rotated==1 && rotated==1)){
            check=1;
        }
        else if((keyword=='Z' && oth.keyword=='S' && oth.rotated==0 && rotated==1)){
            check=1;
        }
        else if((keyword=='Z' && oth.keyword=='S' && oth.rotated==1 && rotated==0)){
            check=1;
        }
        else if((keyword=='Z' && oth.keyword=='Z')){
            check=1;
        }
        if(check){return true;}
        
        return false;
    }


void Tetromino:: fill_second_shape(Board &b, Tetromino &oth){
    /*
    SINCE I USE 2 SHAPES EVERY TIME TO GET CORRECT FIT FROM canFit() FUNCTION, THERE IS A CASE WHICH I NEED TO CHECK
    THIS IS WHEN FIRST 2 SHAPES FITTED WITH TOGETHER I NEED TO CHECK SECOND SHAPE

    FOR EXAMPLE:
    SHAPES: J L T S Z
    I CHECK THIS SHAPE LIKE THIS: J-L , L-T , T-S , S-Z  
    I MEAN SECOND SHAPE MUST BE ROTATED ACCORDING TO THE PREVIOUS SHAPE AND IT'S DIRECTION
    IN THIS FUNCTION I CHECKED THIS STATEMENTS
    FINALLY I PUT IT TOGETHER INTO MY BEST_FIT_BOARD ----->>>> Struct Board b.board;
    */
                int k=0;
                int j=0;
                int i=N-1;
                bool check=false;
            while(!check){             
                if(oth.tet[i][k]==oth.keyword && b.board[i][j]==' ' && j!=0 && b.board[i-1][j]==' '){
                    if(oth.keyword=='T'){
                        if(keyword=='S' && rotated==0){
                            b.board[i][j-1]='T';
                            b.board[i][j]='T';
                            b.board[i-1][j]='T';
                            b.board[i][j+1]='T';
                        }
                        else if(keyword=='S'){
                            b.board[i][j]='T';
                            b.board[i][j+1]='T';
                            b.board[i-1][j+1]='T';
                            b.board[i][j+2]='T';
                        }
                        
                        else if(keyword=='Z' && rotated==1){
                            b.board[i][j-1]='T';
                            b.board[i][j]='T';
                            b.board[i-1][j]='T';
                            b.board[i][j+1]='T';
                        }
                        else if(b.board[i-1][j]==' '){
                            b.board[i][j]='T';
                            b.board[i][j+1]='T';
                            b.board[i-1][j+1]='T';
                            b.board[i][j+2]='T';
                        }    
                        else{
                            b.board[i][j+1]='T';
                            b.board[i][j+2]='T';
                            b.board[i-1][j+2]='T';
                            b.board[i][j+3]='T';
                        }
                    }
                    else if(oth.keyword=='O'){
                        if(b.board[i-1][j]==' '){
                            b.board[i][j]='O';
                            b.board[i-1][j]='O';
                            b.board[i][j+1]='O';
                            b.board[i-1][j+1]='O';
                        }
                        else{
                            b.board[i][j+1]='O';
                            b.board[i-1][j+1]='O';
                            b.board[i][j+2]='O';
                            b.board[i-1][j+2]='O';
                        }
                    }
                    else if(oth.keyword=='J'){
                        if(oth.rotated==0 || oth.rotated==4){
                            if(keyword=='Z' && rotated==1){
                                b.board[i][j-1]='J';
                                b.board[i][j]='J';
                                b.board[i-1][j]='J';
                                b.board[i-2][j]='J';
                            }
                            else if(keyword=='S' && rotated==0){
                                b.board[i][j-1]='J';
                                b.board[i][j]='J';
                                b.board[i-1][j]='J';
                                b.board[i-2][j]='J';
                            }
                            else if(b.board[i-1][j]==' '){
                                b.board[i][j]='J';
                                b.board[i][j+1]='J';
                                b.board[i-1][j+1]='J';
                                b.board[i-2][j+1]='J';
                            }
                            else{
                                b.board[i][j+1]='J';
                                b.board[i][j+2]='J';
                                b.board[i-1][j+2]='J';
                                b.board[i-2][j+2]='J';
                            }
                        }
                        else if(oth.rotated==1){
                            if(b.board[i-1][j]==' '){
                                b.board[i][j]='J';
                                b.board[i][j+1]='J';
                                b.board[i][j+2]='J';
                                b.board[i-1][j]='J';
                            }
                            else{
                                b.board[i][j+1]='J';
                                b.board[i][j+2]='J';
                                b.board[i][j+3]='J';
                                b.board[i-1][j+1]='J';
                            }
                        }
                    }
                    else if(oth.keyword=='L'){
                        if(keyword=='S' && rotated==0){
                            b.board[i][j-1]='L';
                            b.board[i][j]='L';
                            b.board[i][j+1]='L';
                            b.board[i-1][j+1]='L';
                        }
                        else if(keyword=='Z' && rotated==1){
                            b.board[i][j-1]='L';
                            b.board[i][j]='L';
                            b.board[i][j+1]='L';
                            b.board[i-1][j+1]='L';
                        }
                        
                        else if(b.board[i-1][j]==' '){
                            b.board[i][j]='L';
                            b.board[i][j+1]='L';
                            b.board[i][j+2]='L';
                            b.board[i-1][j+2]='L';
                        }
                        else{
                            b.board[i][j+1]='L';
                            b.board[i][j+2]='L';
                            b.board[i][j+3]='L';
                            b.board[i-1][j+3]='L';
                        }
                    }
                    else if(oth.keyword=='S'){
                        if(oth.rotated==0 || oth.rotated==2){
                            if(keyword=='Z' && rotated==1){
                                b.board[i][j-1]='S';
                                b.board[i][j]='S';
                                b.board[i-1][j]='S';
                                b.board[i-1][j+1]='S';
                            }
                            else if(keyword=='S' && rotated==0){
                                b.board[i][j-1]='S';
                                b.board[i][j]='S';
                                b.board[i-1][j]='S';
                                b.board[i-1][j+1]='S';
                            }
                            else if(b.board[i-1][j]==' '){
                                b.board[i][j]='S';
                                b.board[i][j+1]='S';
                                b.board[i-1][j+1]='S';
                                b.board[i-1][j+2]='S';
                            }
                            else{
                                b.board[i][j+1]='S';
                                b.board[i][j+2]='S';
                                b.board[i-1][j+2]='S';
                                b.board[i-1][j+3]='S';
                            }
                        }
                        else if(oth.rotated==1){
                            if(keyword=='Z' && rotated==1){
                                b.board[i][j+1]='S';
                                b.board[i-1][j+1]='S';
                                b.board[i-1][j]='S';
                                b.board[i-2][j]='S';
                            }
                            else if(b.board[i-1][j]==' '){
                                b.board[i][j]='S';
                                b.board[i-1][j]='S';
                                b.board[i-1][j-1]='S';
                                b.board[i-2][j-1]='S';
                            }
                            else{
                                b.board[i][j+1]='S';
                                b.board[i-1][j+1]='S';
                                b.board[i-1][j]='S';
                                b.board[i-2][j]='S';
                            }
                        }
                    }
                    else if(oth.keyword=='Z'){
                        if(oth.rotated==0){
                            if(b.board[i-1][j]==' '){
                                b.board[i][j]='Z';
                                b.board[i][j+1]='Z';
                                b.board[i-1][j]='Z';
                                b.board[i-1][j-1]='Z';
                            }
                            else{
                                b.board[i][j+1]='Z';
                                b.board[i][j+2]='Z';
                                b.board[i-1][j+1]='Z';
                                b.board[i-1][j]='Z';
                            }
                        }
                        else if(oth.rotated==1){
                            if(b.board[i-1][j]==' '){
                                b.board[i][j]='Z';
                                b.board[i-1][j]='Z';
                                b.board[i-1][j+1]='Z';
                                b.board[i-2][j+1]='Z';
                            }
                            else{
                                b.board[i][j+1]='Z';
                                b.board[i-1][j+1]='Z';
                                b.board[i-1][j+2]='Z';
                                b.board[i-2][j+2]='Z';
                            }
                        }
                    }
                    else if(oth.keyword=='I'){
                        if(keyword=='S' && rotated==0){
                            b.board[i][j-1]='I';
                            b.board[i][j]='I';
                            b.board[i][j+1]='I';
                            b.board[i][j+2]='I';
                        }
                        else if(keyword=='Z' && rotated==1){
                            b.board[i][j-1]='I';
                            b.board[i][j]='I';
                            b.board[i][j+1]='I';
                            b.board[i][j+2]='I';
                        }
                        else{
                            b.board[i][j]='I';
                            b.board[i][j+1]='I';
                            b.board[i][j+2]='I';
                            b.board[i][j+3]='I';
                        }    
                    }
                    check=true;
                }
                else if(oth.tet[i][k]==' '){
                    k++;
                }
                j++;
            }

    }    

void Tetromino:: fill_table(struct Board &b){
    /*
    I OVERLOADED THIS FUNCTION BECAUSE WHEN THE USER ENTER ONLY ONE SHAPE OTHER FUNCTION WILL NOT WORK
    THIS JUST PRINT FOR ONLY ONE SHAPE IF THE USER ENTER NUMBER OF SHAPES = 1;
    */
    if(keyword=='T'){
        rotate();
        rotate();
    }
    else if(keyword=='J'){
        rotate();
    }
    else if(keyword=='L'){
        rotate();
        rotate();
        rotate();
    }
    else if(keyword=='Z'){
        rotate();
    }
    for(auto i=0;i<b.board.size();i++){
        for(auto j=0;j<b.board[i].size();j++){
            b.board[i][j]=tet[i][j];
        }
    }
}


bool Tetromino:: fill_table(Tetromino &oth, struct Board &b){
    /*
    IN THIS FUNCTION I CALLED EVERY TIME canFit() FUNCTION
    ACCORDING TO THE RETURNED VALUE FROM CANFIT() I FILLED THE TABLE OR I ROTATED THE SHAPES
    ALSO I CREATED A static int counter VARIABLE TO UNDERSTAND SHOULD I FIT THE FIRST SHAPE OR NOT
    THAT MEANS I USE THESE FUNCTION WITH TWO SHAPES. WHEN I FIT FIRST 2 SHAPES IT'S OKEY
    FOR EXAMPLE:
    SHAPES: J L Z T S 
    J-L , L-Z , Z-T , T-S 
    I FITTED J AND L FIRSTLY (counter=0), AFTER THAT I SHOULD NOT FIT L AGAIN WITH Z (counter=1)
    IF counter is zero I FIT LEFTEST SHAPE INTO BOARD THAT'S SHORT


    IF CANFIT RETURNS FALSE, ACCORDING TO THE 2 SHAPES I ROTATED THESE SHAPES TO GET BEST HORIZONTALLY FIT
    */
        static int counter=0; // to fit only one time leftest shape
        int i=0,k=0,j=0;
        if(canFit(oth)){
            /*
            THERE ARE SOME CASES WHICH I CAN ONLY UNDERSTAND WITH RETURNED VALUE FROM CANFIT()
            THESE ARE BELOW IF STATEMENTS
            CANFIT() SOMETIMES RETURNS TRUE BUT IT DOES NOT GIVE ME THE BEST FIT
            I AM CHECKING THESE HERE
            */
            if(keyword=='J' && oth.keyword=='S' && counter==0){ // SPECIAL IF CASES FOR J-S TO GET BEST FIT
                rotate();
                oth.rotate();
            }
            else if(keyword=='J' && oth.keyword=='I' && counter==0){
                rotate();
            }
            else if(keyword=='Z' && oth.keyword=='T' && counter==0){
                rotate();
            }
            else if(keyword=='Z' && oth.keyword=='J' && counter==0){
                rotate();
                oth.rotate();
                oth.rotate();
                oth.rotate();
            }
            else if(keyword=='Z' && oth.keyword=='L' && counter==0){
                rotate();
            }
            if(counter==0){ // FILLING THE FIRST SHAPE THE USER ENTERED, I CHECKED THE COUNTER
                for(i=0;i<N;i++){
                    for(j=0;j<N;j++){
                        if(tet[i][j]!=' '){
                            b.board[i][j]=tet[i][j];
                        }
                    }
                }
                fill_second_shape(b,oth); //FILLING THE TABLE WITH SECOND SHAPE
            }
            else{
                fill_second_shape(b,oth);  
            }
            //cout<<"I AM IN CORRECT"<<endl;
        }
        else{
            //cout<<"I AM IN NOT CORRECT" <<endl;
            if(keyword=='I' && oth.keyword=='T'){
            oth.rotate();
            oth.rotate();
        }
        else if(keyword=='I' && oth.keyword=='J'){
            oth.rotate();
        }
        else if(keyword=='I' && oth.keyword=='L'){
            oth.rotate();
            oth.rotate();
            oth.rotate();
        }
        else if(keyword=='O' && oth.keyword=='T'){
            oth.rotate();
            oth.rotate();
        }
        else if(keyword=='O' && oth.keyword=='J'){
            oth.rotate();
        }
        else if(keyword=='O' && oth.keyword=='L'){
            oth.rotate();
            oth.rotate();
            oth.rotate();
        }
        else if(keyword=='O' && oth.keyword=='Z'){
            oth.rotate();
        }
        else if(keyword=='T' && oth.keyword=='I'){
            if(counter==0){
                rotate();
                rotate();
            }
        }   
        else if(keyword=='T' && oth.keyword=='O'){
            if(counter==0){
                rotate();
                rotate();
            }
        }
        else if(keyword=='T' && oth.keyword=='T'){
            if(counter==0){
                rotate();
                rotate();
            }
            oth.rotate();
            oth.rotate();
        }
        else if(keyword=='T' && oth.keyword=='J'){
            if(counter==0){
                rotate();
                rotate();
            }
            oth.rotate();
        }
        else if(keyword=='T' && oth.keyword=='L'){
            if(counter==0){
                rotate();
                rotate();
            }
            oth.rotate();
            oth.rotate();
            oth.rotate();
        }
        else if(keyword=='T' && oth.keyword=='S'){
            if(counter==0){
                rotate();
                rotate();
            }
            oth.rotate();
        }
        else if(keyword=='T' && oth.keyword=='Z'){
            if(counter==0){
                rotate();
                rotate();
            }
            oth.rotate();
        }
        else if(keyword=='J' && oth.keyword=='T'){
            if(counter==0){
                rotate();
            }
            oth.rotate();
            oth.rotate();
        }
        else if((keyword=='J' && oth.keyword=='J')){
            if(counter==0){
                rotate();
            }
            oth.rotate();
        }
        else if((keyword=='J' && oth.keyword=='S')){
            if(counter==0){
                rotate();
            }
            oth.rotate();
        }
        else if((keyword=='J' && oth.keyword=='L')){
            if(counter==0){
                rotate();
            }
            oth.rotate();
            oth.rotate();
            oth.rotate();
        }
        else if(keyword=='J' && oth.keyword=='Z' && (rotated==0 || rotated==4)){
            oth.rotate();
        }
        else if(keyword=='L' && oth.keyword=='I'){
            if(counter==0){
                rotate();
                rotate();
                rotate();
            } 
        }
        else if(keyword=='L' && oth.keyword=='O'){
            if(counter==0){
                rotate();
                rotate();
                rotate();
            }
        }
        else if(keyword=='L' && oth.keyword=='T'){
            if(counter==0){
                rotate();
                rotate();
                rotate();
            }
            oth.rotate();
            oth.rotate();
        }
        else if(keyword=='L' && oth.keyword=='J'){
            if(counter==0){
                rotate();
                rotate();
                rotate();
            }
            oth.rotate();
        }
        else if(keyword=='L' && oth.keyword=='L'){
            if(counter==0){
                rotate();
                rotate();
                rotate();
            }
            oth.rotate();
            oth.rotate();
            oth.rotate();
        }
        else if(keyword=='L' && oth.keyword=='S'){
            if(counter==0){
                rotate();
                rotate();
                rotate();
            }
        }
        else if(keyword=='L' && oth.keyword=='Z'){
            if(counter==0){
                rotate();
                rotate();
                rotate();
            }
            oth.rotate();
        }
        else if((keyword=='S' && oth.keyword=='T')){
            oth.rotate();
            oth.rotate();
        }
        else if((keyword=='S' && oth.keyword=='J')){
            oth.rotate();
        }
        else if((keyword=='S' && oth.keyword=='L')){
            oth.rotate();
            oth.rotate();
            oth.rotate();
        }
        else if((keyword=='S' && oth.keyword=='Z')){
            if(rotated==0){
                rotate();
            }
            oth.rotate();
        }
        else if((keyword=='Z' && oth.keyword=='T')){
            oth.rotate();
            oth.rotate();
        }
        else if((keyword=='Z' && oth.keyword=='J')){
            oth.rotate();
        }
        else if((keyword=='Z' && oth.keyword=='L')){
            oth.rotate();
            oth.rotate();
            oth.rotate();
        }
        else if((keyword=='Z' && oth.keyword=='S')){
            if(counter==0){
                rotate();
                
            }
            else if(counter!=0){
                oth.rotate();
            }
            
        }     
        return false;
    }
    counter++;
    return true;
    } 

void Tetromino:: create_table(struct Board &b, int number){
    /*
    THIS FUNCTION FILLED THE TABLE WITH ' ' 
    */
        for(auto i=0;i<N;i++){
            vector<char> temp;
            for(auto j=0;j<N*number;j++){
                temp.push_back(' ');
            }
            b.board.push_back(temp);
        }
        
    }

void Tetromino:: print() const{
    // THIS FUNCTION PRINTS EACH TETROMINO THE USER ENTERED
        for(auto i=0;i<N;i++){
            for(auto j=0;j<N;j++){
                cout<<tet[i][j];
            }
            cout<<endl;
        }         
    }

void Tetromino:: print_best_horizantal_fit(struct Board b){
    //THIS FUNCTION PRINTS BEST-FIT HORIZONTALLY
    cout<<"Best Horizontal-Fit:"<<endl;
        for(auto i: b.board){ // THIS IS RANGE BASED FOR LOOP
            for(auto j: i){
                cout<<j;
            }
            cout<<endl;
        }
    }