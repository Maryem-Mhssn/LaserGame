#include "cible.h"

cible::cible(position p, bool t) : d_pos{p}, d_touched{false}{}
cible::cible(int x, int y): d_pos{x,y}, d_toucher{false}{}
int cible::x()const
{
    return d_pos.x();
}
int cible::y()const
{
    return d_pos.y();
}
void cible::create(position p)
{
    cible{p, false};
}
void cible::moveTo(position p)
{
    d_pos = p;
}
bool touched()
{
    return d_touched;
}
