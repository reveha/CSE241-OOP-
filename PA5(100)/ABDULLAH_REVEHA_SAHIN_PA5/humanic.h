#ifndef _HUMANIC_H_h
#define _HUMANIC_H_h

#include "Robot.h"

using namespace std;

class Humanic: public Robot{
    public:
        Humanic();
        Humanic(int newType, int newStrength, int newHit, string name);
        int getDamage();

};


#endif