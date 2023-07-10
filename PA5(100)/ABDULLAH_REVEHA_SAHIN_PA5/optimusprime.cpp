#include <iostream>

#include "optimusprime.h"

using namespace std;


OptimusPrime:: OptimusPrime(): Humanic(){

}

OptimusPrime:: OptimusPrime(int newType, int newStrength, int newHit, string name):Humanic(newType,newStrength,newHit,name){
    
}

int OptimusPrime:: getDamage(){
    return Humanic:: getDamage();
}

string OptimusPrime:: getType(){
    return "optimusprime";
}