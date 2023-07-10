#include <iostream>

#include "bulldozer.h"

using namespace std;


Bulldozer:: Bulldozer(): Robot(){

}

Bulldozer:: Bulldozer(int newType, int newStrength, int newHit, string name):Robot(newType,newStrength,newHit,name){

}

int Bulldozer:: getDamage(){
    return Robot:: getDamage();
}

string Bulldozer:: getType(){
    return "bulldozer";
}