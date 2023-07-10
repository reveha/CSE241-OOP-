#include <iostream>
#include "world.h"

using namespace std;


int World:: counter=0;

World:: World(){ // basic constructor
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            grid[i][j]=nullptr;
        }
    }
}

World:: ~World(){ // basic destructor
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            delete grid[i][j];
        }
    }
}

Robot* World:: getAt(const int x, const int y){
    if(x>=0 && x<SIZE && y>=0 && y<SIZE){ // checking index of x,y are valid
        return grid[x][y];
    }
    return nullptr;
}



void World:: setAt(const int x, const int y, Robot* org){
    if(x>=0 && x<SIZE && y>=0 && y<SIZE){ // checking index of x,y are valid
        grid[x][y]=org;
    }
    counter++;
}

void World:: Display(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){ // according to the type of robot printing table of grid!
            if(grid[i][j]==nullptr){
                cout<<".";
            }
            else if(grid[i][j]->getType()=="optimusprime"){
                cout<<"O";
            }
            else if(grid[i][j]->getType()=="robocop"){
                cout<<"R";
            }
            else if(grid[i][j]->getType()=="roomba"){
                cout<<"r";
            }
            else{
                cout<<"B";
            }
        }
        cout<<endl;
    }
}


bool World:: isEmpty(const int x, const int y){
    return grid[x][y]==nullptr;
}
// Function to move an object in the grid in one of the four directions (right, left, up, down)
bool World::move(const int x, const int y){
    int direction;
    // Infinite loop to decide the direction of the movement
    while(true){
        // Generate a random direction: 0 means right, 1 means left, 2 means up, 3 means down
        direction=rand()%4; 

        // Check edge cases to prevent moving out of the grid
        // If the object is in the top left corner, it cannot move left or up
        if(x==0 && y==0 && (direction==1 || direction==2)){
            continue;
        }
        // If the object is in the bottom right corner, it cannot move right or down
        else if(y==SIZE-1 && x==SIZE-1 && (direction==0 || direction==3)){
            continue;
        }
        // If the object is in the bottom left corner, it cannot move left or down
        else if(x==SIZE-1 && y==0 && (direction==1 || direction==3)){
            continue;
        }
        // If the object is in the top right corner, it cannot move right or up
        else if(x==0 && y==SIZE-1 && (direction==0 || direction==2)){
            continue;
        }
        // If the object is on the top edge, it cannot move up
        else if(x==0 && direction==2){
            continue;
        }
        // If the object is on the bottom edge, it cannot move down
        else if(x==SIZE-1 && direction==3){
            continue;
        }
        // If the object is on the left edge, it cannot move left
        else if(y==0 && direction==1){
            continue;
        }
        // If the object is on the right edge, it cannot move right
        else if(y==SIZE-1 && direction==0){
            continue;
        }
        // If none of the above conditions is met, break the loop and proceed with the movement
        else{
            break;
        }
    }

    // Set the current grid cell as moved
    grid[x][y]->setMoved(true);
    
    // Move right
    if(direction==0){
        // If the destination cell is not empty, initiate a fight
        if(!isEmpty(x,y+1)){
            // If the current object wins the fight, move it to the destination cell and remove it from the current cell
            if(grid[x][y]->fight(grid[x][y+1])){
                grid[x][y+1]=grid[x][y];
                grid[x][y]=nullptr;
            }
            // If the current object loses the fight, remove it from the current cell
            else{
                grid[x][y]=nullptr;
            }
            // Decrement the counter
            counter--;
            return true;
        }
        // If the destination cell is empty, simply move the object and remove it from the current cell
        else{
            grid[x][y+1]=grid[x][y];
            grid[x][y]=nullptr;
        }
        
    }
    // Similar logic applies for moving left
    else if(direction==1){
        if(!isEmpty(x,y-1)){
            if(grid[x][y]->fight(grid[x][y-1])){
                grid[x][y-1]=grid[x][y];
                grid[x][y]=nullptr;
            }
            else{
                grid[x][y]=nullptr;
            }
            counter--;
            return true;
        }
        else{
            grid[x][y-1]=grid[x][y];
            grid[x][y]=nullptr;
        }
        
    }
    // Similar logic applies for moving up
    else if(direction==2){
        if(!isEmpty(x-1,y)){
            if(grid[x][y]->fight(grid[x-1][y])){
                grid[x-1][y]=grid[x][y];
                grid[x][y]=nullptr;
            }
            else{
                grid[x][y]=nullptr;
            }
            counter--;
            return true;
        }
        else{
            grid[x-1][y]=grid[x][y];
            grid[x][y]=nullptr;
        }
        
    }
    // Similar logic applies for moving down
    else{
        if(!isEmpty(x+1,y)){
            if(grid[x][y]->fight(grid[x+1][y])){
                grid[x+1][y]=grid[x][y];
                grid[x][y]=nullptr;
            }
            else{
                grid[x][y]=nullptr;
            }
            counter--;
            return true;
        }
        else{
            grid[x+1][y]=grid[x][y];
            grid[x][y]=nullptr;
        }
    }
    return false; // That means there is no fight
}
 



// Function to reset the round if all elements have moved and fought
void World::RepeatRound(){
    int counter=0;

    // Iterate over each cell in the grid
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            // If a cell is not empty and the element in the cell has moved and fought
            if(grid[i][j]!=nullptr && grid[i][j]->getMoved()==true && grid[i][j]->getFought()==true){
                // Increment the counter
                counter++;
            }
        }
    }

    // If the counter equals the current counter (i.e., all elements have moved and fought)
    if(counter==this->counter){
    
        //cout<<this->counter<<" kisi kaldi ve hepsi hareket etti. round tekrar bastan baslayacak"<<endl; // round bitmis 
        // Iterate over each cell in the grid again
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                // If a cell is not empty
                if(grid[i][j]!=nullptr){
                    // Set the moved and fought properties of the element in the cell to false, indicating they haven't moved or fought in the new round
                    grid[i][j]->setMoved(false);
                    grid[i][j]->setFight(false);
                }
            }
        }
    }
}


// Function to roam the grid and move each object in the grid
void World::roamingGrid(){
    
    // Check if the current round is over or not
    this->RepeatRound(); 
    
    // Iterate over each cell in the grid
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            // If a cell is not empty and the object in the cell has moved but not fought
            if(grid[i][j]!=nullptr && grid[i][j]->getMoved()==true && grid[i][j]->getFought()==false){
                //cout<<"moved: "<<"i: "<<i<<" j: "<<j<<endl;

                // Move the object in the cell
                move(i,j); 
                // Exit the function
                return;
            }
        }
    }

    // If all objects have moved and fought, iterate over each cell in the grid again
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            // If a cell is not empty and the object in the cell hasn't moved
            if(grid[i][j]!=nullptr && grid[i][j]->getMoved()==false){
                //cout<<"unmoved: "<<"i: "<<i<<" j: "<<j;
                //cout<<" "<<grid[i][j]->getName()<<endl;

                // Move the object in the cell
                move(i,j); 
                // Exit the function
                return;
            }
        }
    }
}


bool World::gameOver()const{ // returns true if only 1 robot alive
    return counter==1;
}

void World:: printWinner()const{ // THIS FUNCTION WILL BE CALLED ONLY ONE TIME, WHEN ONLY ONE ROBOT ALIVE
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(grid[i][j]!=nullptr){
                cout<<grid[i][j]->getName()<<" won the game!!"<<endl;
                break;
            }
        }
    }
}