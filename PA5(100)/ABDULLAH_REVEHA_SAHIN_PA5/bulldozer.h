#ifndef _BULLDOZER_H_
#define _BULLDOZER_H_

#include "Robot.h"

using namespace std;

class Bulldozer: public Robot{
    public:
        Bulldozer();
        Bulldozer(int newType, int newStrength, int newHit, string name);
        int getDamage();
        string getType()override;

};


#endif
