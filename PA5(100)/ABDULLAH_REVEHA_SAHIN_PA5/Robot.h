#ifndef _ROBOT_H_
#define _ROBOT_H_
#include "world.h"

using namespace std;

class Robot{
    public:
        Robot();
        Robot(int newType, int newStrength, int newHit, string name);
        virtual ~Robot();
        virtual string getType()=0; // abstract method
        virtual int getDamage(); // virtual method
        int getStrength()const;
        int getHitPoints()const;
        string getName()const;
        bool getMoved()const;
        bool getFought()const;
        void setFight(bool fought);
        void setMoved(bool moved);
        void setType(const int eType);
        void setName(const string name);
        void setStrength(const int eStrength);
        void setHitPoints(const int eHitPoints);
        bool isDead()const; // Checking robot is dead or not
        void takingDamage(int d_r); // Decreasing hitpoint 
        bool fight(Robot* oth); // Fight loop method

    protected:
        int type; // To keep type of robot, 0 means op, 1 means robocop, 2 means roomba, 3 means bulldozer
        string name;
        int strength;
        int hitpoints;
        bool moved; // to understand robot is moved or not
        bool fought; // to understand robot fought or not
};


#endif