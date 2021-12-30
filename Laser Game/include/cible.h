#ifndef CIBLE_H
#define CIBLE_H
#include "box.h"

class cible : public box
{
public:
    cible();
    cible(int x, int y, char c);
    void setTouched();
    bool touched() const;

private:
    bool d_touched;

};

#endif // CIBLE_H
