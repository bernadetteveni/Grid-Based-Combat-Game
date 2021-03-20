//
//  Drone.cpp
//  CS_Assign_6
//
//

#include "Drone.h"
#include "Game.h"

using namespace std;

Drone::Drone ()
:Monster()
{
    damage = 5;
    health = 50;
    points = 10;
    faces = 1;
}

Drone::Drone (const Position& start)
:Monster(start)
{
    damage = 5;
    health = 50;
    points = 10;
    faces = 1;
}

Drone::Drone (const Drone& original)
:Monster(original)
{
    damage = original.getDamage();
    health = 50;
    points = original.getPoints();
    faces = original.faces;
}

Drone::~Drone (){
    
}

Drone& Drone::operator= (const Drone& original){
    if(&original != this){
        damage = original.getDamage();
        health = 50;
        points = original.getPoints();
        setPosition(original.getPosition());
        faces = original.faces;
        //startingPos = original.getPosition();
    }
    return *this;
}

char Drone::getDisplayChar () const{
    return 'D';
}

Monster* Drone::getClone () const{
    return new Drone(*this);
}


Position Drone::calculateMove (const Game& game, const Position& player_position){
    switch(faces){
        case 1://north
        {
            Position north = getPosition();
            north.row--;
            if(isValid(north)||game.isBlockedForMonster(north)){
                faces++;
                if(faces==5)
                    faces = 1;
                return getPosition();
            }
            else
                return north;
            break;
        }
        case 2://east
        {
            Position east = getPosition();
            east.column++;
            if(isValid(east)||game.isBlockedForMonster(east)){
                faces++;
                if(faces==5)
                    faces = 1;
                return getPosition();
            }
            else
                return east;
            break;
        }
            
        case 3://south
        {
            Position south = getPosition();
            south.row++;
            if(isValid(south)||game.isBlockedForMonster(south)){
                faces++;
                if(faces==5)
                    faces = 1;
                return getPosition();
            }
            else
                return south;
            break;
        }
            
        case 4://west
        {
            Position west = getPosition();
            west.column--;
            if(isValid(west)||game.isBlockedForMonster(west)){
                faces++;
                if(faces==5)
                    faces = 1;
                return getPosition();
            }
            else
                return west;
            break;
        }
    }
   
  //  cout << "Error moving the drone" << endl;
    
    return getPosition();
}
