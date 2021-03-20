//
//  Attacker.cpp
//  CS_Assign_6
//

#include "Attacker.h"

using namespace std;

Attacker:: Attacker ()
:Monster()
{
    damage = 2;
    health = 10;
    points = 20;
}

Attacker::Attacker (const Position& start)
:Monster(start)
{
    damage = 2;
    health = 10;
    points = 20;
}

Attacker::Attacker (const Attacker& original)
:Monster(original)
{
    damage = original.getDamage();
    health = 10;
    points =  original.getPoints();
}

Attacker::~Attacker (){
    
}

Attacker& Attacker::operator= (const Attacker& original){
    if(&original != this){
        damage = original.getDamage();
        health = 10;
        points = original.getPoints();
        setPosition(original.getPosition());
    }
    return *this;
}

char Attacker::getDisplayChar () const{
    return 'A';
}

Monster* Attacker::getClone () const

{
    return new  Attacker(*this);
}

Position Attacker::calculateMove (const Game& game, const Position& player_position){
    return calculateToPosition(game, player_position);
}
