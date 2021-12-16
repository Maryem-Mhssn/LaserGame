#ifndef CIBLE_H
#define CIBLE_H

#include "box.h"
#include "position.h"

class cible : public box
{
public:
    cible(position p, bool t);
    cible(int x, int y);
    int x()const;
    int y()const;
    virtual void create(position p)override;
    virtual void moveTo(position)override;
    bool touched();

private:
    position d_pos;
    bool d_touched;

};

#endif // CIBLE_H
