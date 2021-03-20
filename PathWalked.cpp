//
//  PathWalked.cpp
//  Bernadette Veninata
//  SID: 200259971
//

#include "PathWalked.h"
#include <iostream>


using namespace std;


PathWalked::PathWalked (){
    head=nullptr;
    numOfElements=0;
    totalPathLength=0;
}


PathWalked::PathWalked (const PathWalked& original){
    head = copyLinkedList(original.head);
    totalPathLength = original.totalPathLength;
    numOfElements = original.numOfElements;
}


PathWalked::~PathWalked (){
    clear();
}


PathWalked& PathWalked::operator= (const PathWalked& original){
    if (&original != this)
    {
        clear();
        head = copyLinkedList(original.head);
        totalPathLength = original.totalPathLength;
        numOfElements = original.numOfElements;
    }
    return *this;
}

bool PathWalked::empty () const{
    return head==nullptr;
}

float PathWalked::getPathLength () const{
    return totalPathLength;
}


void PathWalked::print () const{
//    for(Element* p=head; p!=nullptr; p=p->next)
//        cout << p->data.x << " " << p->data.y << endl;
    for (const Element* p = head; p != nullptr; p = p->next)
    {
        cout << "(" << p->data.x << ", " << p->data.y << ")" << endl;
//        if (p->next != nullptr)
//            cout << "";
    }
    cout << endl;
}

void PathWalked::add (const Vector2<float>& position){
    if(empty()){
        //special empty case
        //Otherwise this is the first position in the path and the total distance should remain 0.
        totalPathLength=0;
        numOfElements=0;
    }
    else{
        Vector2<float> temp = head->data-position;
        //cout << "Temp norm: "<< temp.getNorm() << endl;
        totalPathLength+=temp.getNorm();
        cout << "Total path length: " << totalPathLength << endl;
        numOfElements++;
    }
    
    // Create new node
    Element* pCurrent = new Element;
    pCurrent->data = position;

    // Insert at head
    pCurrent->next = head;
    head = pCurrent;
}

void PathWalked::clear (){
    if(head==nullptr){
       // numOfElements=0;
       // totalPathLength=0;
        return;
    }
    else{
        Element* deletePtr=head;
        while(deletePtr!=nullptr){
            Element* deleteElementPtr = deletePtr;
            deletePtr=deletePtr->next;
            delete deleteElementPtr;
        }
        numOfElements=0;
        totalPathLength=0;
        head=nullptr;
    }
}


Element* PathWalked::copyLinkedList (const Element* p_original_head){
    if(p_original_head==nullptr)
        return nullptr;
    Element* pHead2 = new Element;
    pHead2->data=p_original_head->data;
    pHead2->next=nullptr;
    Element* p2 = pHead2;
    const Element* p1 = p_original_head;
    while(p1->next!=nullptr)
    {
        p2->next = new Element;
        p1 = p1->next;
        p2 = p2->next;
        p2->data=p1->data;
        p2->next=nullptr;
    }
    p2->next=nullptr;
    return pHead2;
}

