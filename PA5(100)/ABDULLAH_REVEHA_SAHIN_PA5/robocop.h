#ifndef _ROBOCOP_H_
#define _ROBOCOP_H_

#include "humanic.h"

using namespace std;

class Robocop: public Humanic{
    public:
        Robocop();
        Robocop(int newType, int newStrength, int newHit, string name);
        int getDamage();
        string getType()override;




};


#endif