#include <iostream>

#include "roomba.h"

using namespace std;


Roomba:: Roomba(): Robot(){

}

Roomba:: Roomba(int newType, int newStrength, int newHit, string name):Robot(newType,newStrength,newHit,name){

}

int Roomba:: getDamage(){
    return Robot:: getDamage();
}

string Roomba:: getType(){
    return "roomba";
}