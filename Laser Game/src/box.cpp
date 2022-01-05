#include "box.h"


box::box(int x, int y,char c): d_x{x}, d_y{y}, d_c{c}
{}

box::box(): box{0,0,' '}
{}

int box::x()const
{
    return d_x;
}

int box::y()const
{
    return d_y;
}


char box::c()const{
    return  d_c;
}

void box::moveTo(int x, int y)
{
    d_x = x;
    d_y = y;
}
void box::setC(char c)
{
    d_c=c;
}


bool box::operator==(const box& b) const
{
  return (d_x == b.d_x) && (d_y == b.d_y) && (d_c==b.d_c);
}

bool box::operator!=(const box& b) const
{
  return (d_x != b.d_x) || (d_y != b.d_y) || (d_c != b.d_y) ;
}
