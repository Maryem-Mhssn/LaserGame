#ifndef LASER_H
#define LASER_H
#include "box.h"
#include <vector>
#define DIM 20
using std::vector;

class laser : public box{
    static constexpr int degre = 90;

public :
    laser();
    laser(int x,int y);
    vector<box> tire();
    void changeTrajectoirDroite();
    void changeTrajectoirGauche();

};

#endif // LASER_H
