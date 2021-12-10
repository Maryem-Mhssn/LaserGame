#include "position.h"

position::position(int x, int y): d_x{x}, d_y{y} {}

int position::x()const
{
    return d_x;
}
int position::y()const
{
    return d_y;
}
void position::moveTo(int x, int y)
{
    d_x = x;
    d_y = y;
}
void position::movePosition(const position& p)
{
    d_x=p.d_x;
    d_y=p.d_y;
}
