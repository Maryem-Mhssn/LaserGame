#ifndef CIBLE_H
#define CIBLE_H
#include "box.h"

class cible : public box
{
public:
    cible();
    void setTouched();
    bool touched() const;

private:
    bool d_touched;

};

#endif // CIBLE_H
