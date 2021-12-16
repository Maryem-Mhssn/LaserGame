#include "laser.h"

laser::laser(position p): d_pos{p} {}
int laser::x()const
{
    return d_pos.x();
}
int laser::y()const
{
    return d_pos.y();
}
void laser::create(position p)
{
    laser{p};
}
void laser::moveTo(position p)
{
    d_pos = p;
}
void laser::tire()
{
    //
}
