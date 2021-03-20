//
//  Vector2.cpp
//
//  Bernadette Veninata
//  SID: 200259971
//

#include "Vector2.h"
#include <cmath>

template <typename ItemType>
Vector2<ItemType>::Vector2 ()
    : x(), y() {

}

template <typename ItemType>
Vector2<ItemType>::Vector2 (const ItemType& x1, const ItemType& y1)
    : x(x1), y(y1){
    
}

template <typename ItemType>
Vector2<ItemType>::Vector2 (const Vector2<ItemType>& original)
    : x(original.x), y(original.y){
    
}

template <typename ItemType>
Vector2<ItemType>::~Vector2 (){ // empty
    
}

template <typename ItemType>
Vector2<ItemType>& Vector2<ItemType>::operator= (const Vector2<ItemType>& original){
    x=original.x;
    y=original.y;
    
    return *this;
}

template <typename ItemType>
bool Vector2<ItemType>::operator== (const Vector2<ItemType>& other) const{
    if(x!=other.x)
        return false;
    if(y!=other.y)
        return false;
    return true;
}

template <typename ItemType>
Vector2<ItemType> Vector2<ItemType>::operator+ (const Vector2<ItemType>& addend) const{
    Vector2 <ItemType>v;
    v=*this;
    v.x+=addend.x;
    v.y+=addend.y;
    return v;
}

template <typename ItemType>
Vector2<ItemType> Vector2<ItemType>::operator- (const Vector2<ItemType>& subtrahend) const{
    Vector2 <ItemType>v;
    v=*this;
    v.x-=subtrahend.x;
    v.y-=subtrahend.y;
    return v;
}

template <typename ItemType>
float Vector2<ItemType>::getNorm () const{
    return sqrt(pow(x,2)+pow(y,2));
}

template class Vector2<int>;
template class Vector2<float>;
template class Vector2<double>;
