#include "cible.h"
#include <iostream>
using std::cout;
using std::endl;


cible::cible() : box{0,0,'@'}, d_touched{false}
{}


cible::cible(int x, int y, char c): box{x,y,'@'}, d_touched{false}
{}


void cible::setTouched()
{
    d_touched=true;
    cout<< "----------------  FELICITATIONS ^-^ ----------------------"<<endl;
    cout<< "----------------  vous avez gagné   ----------------------" <<endl;
}


bool cible::touched() const
{
    return d_touched;
}
