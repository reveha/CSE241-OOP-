import java.util.Scanner;

public class Tetromino{

    public enum Tetros{
        shape_I, shape_O, shape_T, shape_J, shape_L, shape_S, shape_Z;
    }


    private final int N=4;
    private char keyword;
    private boolean added=false;// to understand the shape was added the top of the up or not. according to this variable i will print or not.
    private int rotated=0; // to understand direction of the shape;
    char [][]tet;




    public final char getKey(){return keyword;}

    public final int getRotated(){return rotated;}

    public final boolean getAdd(){return added;}

    public void setAdd(boolean a){added=a;}

    public Tetromino(Tetros shape){
        tet=new char[4][4];

        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                tet[i][j]='.';
            }
        }
        // initilazing tetrominos
        if(shape==Tetros.shape_I){
            keyword='I';
            tet[3][0]='I'; tet[3][1]='I'; tet[3][2]='I'; tet[3][3]='I';
        }
        else if(shape==Tetros.shape_O){
            keyword='O';
            tet[2][0]='O'; tet[2][1]='O'; tet[3][0]='O'; tet[3][1]='O';
        }
        else if(shape==Tetros.shape_T){
            keyword='T';
            tet[2][0]='T'; tet[2][1]='T'; tet[2][2]='T'; tet[3][1]='T';
        }
        else if(shape==Tetros.shape_J){
            keyword='J';
            tet[1][1]='J'; tet[2][1]='J'; tet[3][1]='J'; tet[3][0]='J';
        }
        else if(shape==Tetros.shape_L){
            keyword='L';
            tet[1][0]='L'; tet[2][0]='L'; tet[3][0]='L'; tet[3][1]='L';
        }
        else if(shape==Tetros.shape_S){
            keyword='S';
            tet[3][0]='S'; tet[3][1]='S'; tet[2][1]='S'; tet[2][2]='S';
        }
        else if(shape==Tetros.shape_Z){
            keyword='Z';
            tet[2][0]='Z'; tet[2][1]='Z'; tet[3][1]='Z'; tet[3][2]='Z';
        }
        
    }

    public void rotate(){
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
        char [][]temp=new char[4][4];

        int index=N-1;
        if(keyword=='I'){ // for each shape there are some speacial index cases, i check here this cases
            if(temp[1][0]!='I'){ //THESE FOR LOOPS ARE TO REPAIR WRONG INDEXES
                for(int i=N-1;i>=0;i--){
                    for(int j=N-1;j>=0;j--){
                        if(temp[i][j]=='I'){
                        //cout<<i<<endl<<j<<endl;
                            temp[i+3][j]='I';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            
            this.tet=temp; 
            rotated++;
        }
        else if(keyword=='T'){  // for each shape there are some speacial index cases, i check here this cases
                if(rotated==0){ // checking to understand current rotate of the shape
                    for(int i=N-1;i>=0;i--){
                        for(int j=N-1;j>=0;j--){
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
                    for(int i=N-1;i>=0;i--){
                        for(int j=N-1;j>=0;j--){
                            if(temp[i][j]=='T'){
                                //cout<<i<<endl<<j<<endl;
                                temp[i+2][j]='T';
                                temp[i][j]='.';
                            }
                        }      
                    } 
                }
                else if(rotated==2){
                    for(int i=N-1;i>=0;i--){
                        for(int j=N-1;j>=0;j--){
                            if(temp[i][j]=='T'){
                                //cout<<i<<endl<<j<<endl;
                                temp[i+1][j]='T';
                                temp[i][j]='.';
                            }
                        }      
                    } 
                }
                else{
                    for(int i=N-1;i>=0;i--){
                        for(int j=N-1;j>=0;j--){
                            if(temp[i][j]=='T'){
                                //cout<<i<<endl<<j<<endl;
                                temp[i+2][j]='T';
                                temp[i][j]='.';
                            }
                        }      
                    } 
                }
                
            this.tet=temp; 
            rotated++;
        }
        else if(keyword=='J'){
            if(rotated==0){
                for(int i=N-1;i>=0;i--){
                    for(int j=N-1;j>=0;j--){
                        if(temp[i][j]=='J'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+2][j]='J';
                            temp[i][j]='.';
                        }
                    }      
                }  
            }
            else if(rotated==1){
                for(int i=N-1;i>=0;i--){
                    for(int j=N-1;j>=0;j--){
                        if(temp[i][j]=='J'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+1][j]='J';
                            temp[i][j]='.';
                        }
                    }      
                }  
            }
            else{
                for(int i=N-1;i>=0;i--){
                    for(int j=N-1;j>=0;j--){
                        if(temp[i][j]=='J'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+1][j]='J';
                            temp[i][j]='.';
                        }
                    }      
                } 
            }
            this.tet=temp;    
            rotated++;
        }
        else if(keyword=='L'){
            if(rotated==0){
                for(int i=N-1;i>=0;i--){
                    for(int j=N-1;j>=0;j--){
                        if(temp[i][j]=='L'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+2][j]='L';
                            temp[i][j]='.';
                        }
                    }      
                } 
            }
            else if(rotated==1){
                for(int i=N-1;i>=0;i--){
                    for(int j=N-1;j>=0;j--){
                        if(temp[i][j]=='L'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+1][j]='L';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            else if(rotated==2){
                for(int i=N-1;i>=0;i--){
                    for(int j=N-1;j>=0;j--){
                        if(temp[i][j]=='L'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+2][j]='L';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            else{
                for(int i=N-1;i>=0;i--){
                    for(int j=N-1;j>=0;j--){
                        if(temp[i][j]=='L'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+1][j]='L';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            this.tet=temp; 
            rotated++;
        }
        else if(keyword=='S'){
            if(rotated==0){
                for(int i=N-1;i>=0;i--){
                    for(int j=N-1;j>=0;j--){
                        if(temp[i][j]=='S'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+1][j]='S';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            else{
                for(int i=N-1;i>=0;i--){
                    for(int j=N-1;j>=0;j--){
                        if(temp[i][j]=='S'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+2][j]='S';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            this.tet=temp; 
            rotated++;
        }
        else if(keyword=='Z'){
            if(rotated==0){
                for(int i=N-1;i>=0;i--){
                    for(int j=N-1;j>=0;j--){
                        if(temp[i][j]=='Z'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+1][j]='Z';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            else{
                for(int i=N-1;i>=0;i--){
                    for(int j=N-1;j>=0;j--){
                        if(temp[i][j]=='Z'){
                            //cout<<i<<endl<<j<<endl;
                            temp[i+2][j]='Z';
                            temp[i][j]='.';
                        }
                    }      
                }
            }
            rotated++;
            this.tet=temp; 
        }
    }
}

class main2{
    public static void main(String arg[]){
        
    }
}

