#include <iostream>
#include "humanic.h"

using namespace std;


Humanic:: Humanic(): Robot(){
    
}

Humanic:: Humanic(int newType, int newStrength, int newHit, string name):Robot(newType,newStrength,newHit,name){
    
}

int Humanic:: getDamage(){
    
    int damage=Robot:: getDamage(); // GETTING NORMAL DAMAGE
    if(rand()%10==0){ //%10 CHANCE TO EXTRA 50 DAMAGE
        damage+=50;
        cout<<"Extra 50 damage!"<<endl;
    }
    if(type==0 && rand()%15==0){ // IF OPTIMUS PRIME HAS %15 CHANCE, 2X DAMAGE!!
        damage*=2;
        cout<<"2x Damage! "<<endl;
    }
    
    return damage;
}