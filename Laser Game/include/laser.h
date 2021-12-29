#ifndef LASER_H
#define LASER_H
#include "box.hpp"



class laser : public box{
    static constexpr int degre = 90;
    
public :
    laser();
    laser(int x,int y);
    void tire();
    void changeTrajectoirDroite();
    void changeTrajectoirGauche();

};

#endif // LASER_H
