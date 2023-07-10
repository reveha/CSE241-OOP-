#ifndef _WORLD_H_
#define _WORLD_H_
#include "Robot.h"


using namespace std;
class Robot;
class Humanic;
class Robocop;
class OptimusPrime;
class Roomba;
class Bulldozer;
const int SIZE=10;
class World{
    friend class Robot;
    friend class Humanic;
    friend class Robocop;
    friend class OptimusPrime;
    friend class Roomba;
    friend class Bulldozer;
    public:
        World();
        ~World();
        Robot* getAt(const int x, const int y); // getter
        void setAt(const int x, const int y, Robot *org); // setting x,y point of to Robot object
        void Display(); // printing grid
        void roamingGrid(); // roaming grid with this method
        bool isEmpty(const int x, const int y); // checking index of x,y empty or not
        bool move(const int x, const int y); // robot moves in this method 
        bool gameOver()const;
        void RepeatRound(); // to understand if grid is over but, there are robots which are alive
        void printWinner()const;
        Robot* grid[SIZE][SIZE]; // grid variable
    private:
        static int counter; // to count number of robot
};

#endif