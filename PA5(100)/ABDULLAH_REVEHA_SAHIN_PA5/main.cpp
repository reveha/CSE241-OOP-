
#include "iostream"
#include "Robot.h"
#include "World.h"
#include "humanic.h"
#include "robocop.h"
#include "optimusprime.h"
#include "bulldozer.h"
#include "roomba.h"


using namespace std;

const int STRENGTH_OP=100;
const int STRENGTH_ROBOCOP=30;
const int STRENGTH_ROOMBA=3;
const int STRENGTH_BULLDOZER=50;
const int HITPOINTS_OP=100;
const int HITPOINTS_ROBOCOP=40;
const int HITPOINTS_ROOMBA=10;
const int HITPOINTS_BULLDOZER=200;


int main(){
    srand(time(NULL));

    World w;
    Robocop *r1=new Robocop(1,STRENGTH_ROBOCOP,HITPOINTS_ROBOCOP,"robocop_0");
    OptimusPrime *o1=new OptimusPrime(0,STRENGTH_OP,HITPOINTS_OP,"optimusprime_0");
    Roomba *R1=new Roomba(2,STRENGTH_ROOMBA,HITPOINTS_ROOMBA,"roomba_0");
    Bulldozer *b1=new Bulldozer(3,STRENGTH_BULLDOZER,HITPOINTS_BULLDOZER,"bulldozer_0");
    Robocop *r2=new Robocop(1,STRENGTH_ROBOCOP,HITPOINTS_ROBOCOP,"robocop_1");
    OptimusPrime *o2=new OptimusPrime(0,STRENGTH_OP,HITPOINTS_OP,"optimusprime_1");
    Roomba *R2=new Roomba(2,STRENGTH_ROOMBA,HITPOINTS_ROOMBA,"roomba_1");
    Bulldozer *b2=new Bulldozer(3,STRENGTH_BULLDOZER,HITPOINTS_BULLDOZER,"bulldozer_1");
    Robocop *r3=new Robocop(1,STRENGTH_ROBOCOP,HITPOINTS_ROBOCOP,"robocop_2");
    OptimusPrime *o3=new OptimusPrime(0,STRENGTH_OP,HITPOINTS_OP,"optimusprime_2");
    Roomba *R3=new Roomba(2,STRENGTH_ROOMBA,HITPOINTS_ROOMBA,"roomba_2");
    Bulldozer *b3=new Bulldozer(3,STRENGTH_BULLDOZER,HITPOINTS_BULLDOZER,"bulldozer_2");
    Robocop *r4=new Robocop(1,STRENGTH_ROBOCOP,HITPOINTS_ROBOCOP,"robocop_3");
    OptimusPrime *o4=new OptimusPrime(0,STRENGTH_OP,HITPOINTS_OP,"optimusprime_3");
    Roomba *R4=new Roomba(2,STRENGTH_ROOMBA,HITPOINTS_ROOMBA,"roomba_3");
    Bulldozer *b4=new Bulldozer(3,STRENGTH_BULLDOZER,HITPOINTS_BULLDOZER,"bulldozer_3");
    Robocop *r5=new Robocop(1,STRENGTH_ROBOCOP,HITPOINTS_ROBOCOP,"robocop_4");
    OptimusPrime *o5=new OptimusPrime(0,STRENGTH_OP,HITPOINTS_OP,"optimusprime_4");
    Roomba *R5=new Roomba(2,STRENGTH_ROOMBA,HITPOINTS_ROOMBA,"roomba_4");
    Bulldozer *b5=new Bulldozer(3,STRENGTH_BULLDOZER,HITPOINTS_BULLDOZER,"bulldozer_4");
    w.setAt(0,0,r1);
    w.setAt(1,1,o1);
    w.setAt(2,2,R1);
    w.setAt(3,3,b1);
    
    w.setAt(4,4,r2);
    w.setAt(5,5,o2);
    w.setAt(6,6,R2);
    w.setAt(7,7,b2);
    
    w.setAt(8,8,r3);
    w.setAt(9,9,o3);
    w.setAt(0,1,R3);
    w.setAt(1,2,b3);

    w.setAt(2,3,r4);
    w.setAt(3,4,o4);
    w.setAt(4,5,R4);
    w.setAt(5,6,b4);

    w.setAt(6,5,r5);
    w.setAt(5,4,o5);
    w.setAt(4,3,R5);
    w.setAt(3,2,b5);
    string str;
    while(true){
        //w.Display();
        w.roamingGrid();
        if(w.gameOver()){
            w.printWinner();
            break;
        }
        //getline(cin,str);
    }
    return 0;
}