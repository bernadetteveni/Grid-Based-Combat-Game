//
//  Sentry.cpp
//  CS_Assign_6
//
//

#include "Sentry.h"

Sentry::Sentry ()
:Monster()
{
    damage = 3;
    health = 20;
    points = 50;
    startingPos = toPosition(0, 0);
}

Sentry::Sentry (const Position& start)
:Monster(start)
{
    damage = 3;
    health = 20;
    points = 50;
    startingPos = start;
    
}

Sentry::Sentry (const Sentry& original)
:Monster(original)
{
    damage = original.getDamage();
    health = 20;
    points = original.getPoints();
    startingPos = original.getPosition();
}

Sentry::~Sentry (){
    
}

Sentry& Sentry::operator= (const Sentry& original){
    if(&original != this){
        damage = original.getDamage();
        health = 20;
        points = original.getPoints();
        setPosition(original.getPosition());
        startingPos = original.getPosition();
    }
    return *this;
}

char Sentry::getDisplayChar () const{
    return 'S';
}

Monster* Sentry::getClone () const{
    return new Sentry(*this);
}

Position Sentry::calculateMove (const Game& game, const Position& player_position){
    double distance = calculateDistance(startingPos, player_position);
    if(distance>6){
        return calculateToPosition(game, startingPos);
    }
    else
        return calculateToPosition(game, player_position);
    
}
