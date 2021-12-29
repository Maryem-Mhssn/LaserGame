
#include "mirroir.hpp"



mirroir::mirroir(int x, int y, char type): box{x,y,type}
{}

char mirroir::type() const
{
    return d_type;
}
