//
//  Sentry.h
//  
// Bernadette Veninata
//



#ifndef Sentry_h
#define Sentry_h

#include <stdio.h>
#include "Monster.h"

using namespace std;


class Sentry
: public Monster
{
public:
    Sentry ();
    Sentry (const Position& start);
    Sentry (const Sentry& original);
    virtual ~Sentry ();
    Sentry& operator= (const Sentry& original);
    virtual char getDisplayChar () const;
    virtual Monster* getClone () const;
    Position calculateMove (const Game& game, const Position& player_position);
    
private:
    Position startingPos;
    
};


#endif /* Sentry_h */
