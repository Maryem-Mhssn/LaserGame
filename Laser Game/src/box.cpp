#include "box.h"

box::box(int x, int y): d_x{x}, d_y{y}
{

}
box::box(): box{0,0}
{

}
int box::x()const
{
    return d_x;
}
int box::y()const
{
    return d_y;
}
void box::moveTo(int x, int y)
{
    d_x = x;
    d_y = y;
}

