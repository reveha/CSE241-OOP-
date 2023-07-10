#include "util.hpp"

using namespace std;


int main(){
    Board b;
    int number;
    // I AM GETTING THE NUMBER OF SHAPES
    do{
        cout<<"How many tetrominos?"<<endl;
        cin>>number;
        if(number<=0){
            cout<<"Enter valid number!\n"<<endl;
        }
        cin.ignore();   
    }while(number<=0);
    
    string choice[number];
    
    cout<<"What are the types? (I-O-T-J-L-S-Z)"<<endl;
    for(auto i=0;i<number;i++){
        // I GET THE TYPE OF SHAPES WITH STRING VARIABLE TO BLOCK ANY INVALID ERROR
        getline(cin,choice[i]);
        if(choice[i]!="I" && choice[i]!="O" && choice[i]!="T" && choice[i]!="J" && choice[i]!="L" && choice[i]!="S" && choice[i]!="Z"){
            system("clear");
            cout<<"Enter valid entry!!\n"<<endl;     
            cout<<"What are the types? (I-O-T-J-L-S-Z)"<<endl;
            i=-1;
        }
    }
    Tetromino tet[number];// I CREATED ARRAY OF Tetromino WITH NUMBER OF SHAPES
    cout<<"Your tetrominos"<<endl;
    for(auto i=0;i<number;i++){
        // IN THIS FOR LOOP I CHECKED THE WORDS(SHAPES) WITH STRONG ENUM
        if(choice[i]=="I"){
            tet[i]= Tetromino(tetros::shape_I);
        }
        else if(choice[i]=="O"){
            tet[i]=Tetromino(tetros::shape_O);
        }
        else if(choice[i]=="T"){
            tet[i]=Tetromino(tetros::shape_T);
        }
        else if(choice[i]=="J"){
            tet[i]=Tetromino(tetros::shape_J);
        }
        else if(choice[i]=="L"){
            tet[i]=Tetromino(tetros::shape_L);
        }
        else if(choice[i]=="S"){
            tet[i]=Tetromino(tetros::shape_S);
        }
        else if(choice[i]=="Z"){
            tet[i]=Tetromino(tetros::shape_Z);
        }
    }
    int i=0;
    tet[0].create_table(b,number);// CREATING A HOLE TABLE
    
    while(i<number){
        //cout<<i<<endl;
        if(i!=number-1){
            if(tet[i].fill_table(tet[i+1],b)){
                //FILL TABLE RETURNS TRUE OR FALSE ACCORDING TO THE RETURNED VALUE I CALLED AFTER SHAPES
                i++;
            }
            
        }
        if(i==number-1){
            break; // END OF THE ARRAY OF Tetromino
        }
        
        //cout<<"Hello"<<endl;
    }
    if(number==1){
        tet[0].fill_table(b);
    }
    tet[0].print_best_horizantal_fit(b); //PRINTING THE BEST-FIT HORIZONTALLY
    return 0;
}