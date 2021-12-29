#ifndef MIRROIR_H
#define MIRROIR_H
#include "box.hpp"

class mirroir : public box
{
    public:
        mirroir(int x, int y, char type);
        char type() const;

    private:
        char d_type;
};

#endif // MIRROIR_H
