//
//  PathWalked.h
//  Bernadette Veninata
//  SID: 200259971
//

#include "Vector2.h"

#ifndef PathWalked_h
#define PathWalked_h

#include <stdio.h>


struct Element{
    Vector2<float> data;
    Element* next;
};


class PathWalked{
public:
    PathWalked ();
    PathWalked (const PathWalked& original);
    ~PathWalked ();
    PathWalked& operator= (const PathWalked& original);
    bool empty () const;
    float getPathLength () const;
    void print () const;
    void add (const Vector2<float>& position);
    void clear ();

private:
    Element* copyLinkedList (const Element* p_original_head);
    Element* head;
    unsigned int numOfElements;
    float totalPathLength;
    
};

#endif /* PathWalked_h */
