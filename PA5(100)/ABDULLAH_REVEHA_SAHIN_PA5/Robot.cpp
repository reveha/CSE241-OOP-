#include <iostream>
#include "Robot.h"

using namespace std;


Robot:: Robot(){ // default constructor
    this->moved=false;
    this->fought=false;
}

Robot:: Robot(int newType, int newStrength, int newHit, string name){ // parameter constructor
    this->moved=false;
    this->fought=false;
    this->type=newType;
    this->strength=newStrength;
    this->hitpoints=newHit;
    this->name=name;
}

Robot:: ~Robot(){

}

string Robot:: getType(){ // this is abstract method
    switch(type){
        case 0:
            return "optimusprime";
        case 1:
            return "robocop";
        case 2:
            return "roomba";
        case 3:
            return "bulldozer";
    }
    return "unknown";
}

int Robot:: getDamage(){
    
    int damage;
    damage=(rand()%strength)+1; // getting random number
    cout<<getType()<<" attacks for "<<damage<<" points!"<<endl;
    if(type==2){ // if roomba attacking makeing 2x
        int damage2=(rand()%strength)+1; // getting random number
        cout<<getType()<<" attacks again for "<<damage2<<" points!"<<endl;
        cout<<"Attacked Twice!"<<endl;
        damage+=damage2;
    }
    return damage;
}

// Function to handle a fight between two robots
bool Robot::fight(Robot* oth){
    int attacker;
    int victim;
    
    // Infinite loop to simulate the fight until one robot's hit points fall to 0 or below
    while(true){
        // The current robot attacks the other robot
        attacker=this->getDamage();
        cout<<this->name<<"("<<this->hitpoints<<")"<<" hits "<<oth->name<<"("<<oth->hitpoints<<")"<<" with "<<attacker<<endl;
        // The other robot takes damage
        oth->takingDamage(attacker);
        cout<<"The new hitpoints of "<<oth->name<<" "<<oth->hitpoints<<endl;
        
        // If the other robot's hit points fall to 0 or below, the current robot wins the fight
        if(oth->getHitPoints()<=0){     
            this->fought=true;
            cout<<oth->getName()<<" is dead"<<endl;
            cout<<endl;
            return true;
        }

        // The other robot counterattacks the current robot
        victim=oth->getDamage();
        cout<<oth->name<<"("<<oth->hitpoints<<")"<<" hits "<<this->name<<"("<<this->hitpoints<<")"<<" with "<<victim<<endl;
        // The current robot takes damage
        this->takingDamage(victim);
        cout<<"The new hitpoints of "<<this->name<<" "<<this->hitpoints<<endl;
        
        // If the current robot's hit points fall to 0 or below, the fight ends and the current robot loses
        if(this->getHitPoints()<=0){
            cout<<this->getName()<<" is dead"<<endl;
            break;
        }
    }
    cout<<endl;
    return false;
}


int Robot:: getStrength()const{
    return this->strength;
}

int Robot:: getHitPoints()const{
    return this->hitpoints;
}

string Robot:: getName()const{
    return this->name;
}

bool Robot:: getMoved()const{
    return this->moved;
}

bool Robot:: getFought()const{
    return this->fought;
}

void Robot:: setMoved(bool moved){
    this->moved=moved;
}

void Robot:: setType(const int eType){
    if(eType<5 && eType>-1){
        this->type=eType;
    }
}

void Robot:: setName(const string name){
    this->name=name;
}

void Robot:: setFight(bool fought){
    this->fought=fought;
}

void Robot:: setStrength(const int eStrength){
    this->strength=eStrength;
}

void Robot:: setHitPoints(const int eHitPoints){
    this->hitpoints=eHitPoints;
}

bool Robot:: isDead()const{
    return hitpoints<=0;
}

void Robot:: takingDamage(int d_r){
    hitpoints-=d_r;
}
























