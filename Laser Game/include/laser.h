#ifndef LASER_H
#define LASER_H

#include "box.h"
#include "position.h"

class laser : public box{
public :
    laser(position p);
    laser(int x, int y);
    int x()const;
    int y()const;
    virtual void create(position p)override;
    virtual void moveTo(position p)override;
    void tire();

private :
    position d_pos;

};

#endif // LASER_H
