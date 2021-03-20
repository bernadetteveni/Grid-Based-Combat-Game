//
//  Attacker.h
//  CS_Assign_6
//


#ifndef Attacker_h
#define Attacker_h

#include <stdio.h>
#include "Monster.h"


using namespace std;

class Attacker
: public Monster
{
public:
    Attacker ();
    Attacker (const Position& start);
    Attacker (const Attacker& original);
    virtual ~Attacker ();
    Attacker& operator= (const Attacker& original);
    virtual char getDisplayChar () const;
    virtual Monster* getClone () const;
    Position calculateMove (const Game& game, const Position& player_position);

};

#endif /* Attacker_h */
