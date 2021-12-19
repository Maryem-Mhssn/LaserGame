#include "mirroir.h"

mirroir::mirroir(int x, int y, char type): box{x,y}, d_type{type}
{

}
char mirroir::type() const
{
    return d_type;
}
