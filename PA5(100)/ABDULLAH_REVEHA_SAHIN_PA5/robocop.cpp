#include <iostream>

#include "robocop.h"

using namespace std;


Robocop:: Robocop(): Humanic(){

}

Robocop:: Robocop(int newType, int newStrength, int newHit, string name):Humanic(newType,newStrength,newHit,name){
    
}

int Robocop:: getDamage(){
    return Humanic:: getDamage();
}

string Robocop:: getType(){
    return "robocop";
}