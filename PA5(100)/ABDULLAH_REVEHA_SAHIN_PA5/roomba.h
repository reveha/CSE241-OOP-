#ifndef _ROOMBA_H_
#define _ROOMBA_H_

#include "Robot.h"

using namespace std;

class Roomba: public Robot{
    public:
        Roomba();
        Roomba(int newType, int newStrength, int newHit, string name);
        int getDamage();
        string getType()override;

};

#endif