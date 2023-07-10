#ifndef _OPTIMUSPRIME_H_
#define _OPTIMUSPRIME_H_

#include "humanic.h"

using namespace std;

class OptimusPrime: public Humanic{
    public:
        OptimusPrime();
        OptimusPrime(int newType, int newStrength, int newHit, string name);
        int getDamage();
        string getType()override;



};


#endif