//
//  Drone.h
//  CS_Assign_6
//


#ifndef Drone_h
#define Drone_h

#include <stdio.h>
#include "Monster.h"

using namespace std;

class Drone
: public Monster
{
public:
    Drone ();
    Drone (const Position& start);
    Drone (const Drone& original);
    virtual ~Drone ();
    Drone& operator= (const Drone& original);
    virtual char getDisplayChar () const;
    virtual Monster* getClone () const;
    Position calculateMove (const Game& game, const Position& player_position);
    
private:
    int faces;
    
    /*
     1 = N
     2 = E
     3 = S
     4 = W
     */
};

#endif /* Drone_h */
