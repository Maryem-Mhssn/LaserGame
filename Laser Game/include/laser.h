/**
 * @headerfile laser.h
 * @author
 * @brief Fichier header contenant la classe laser
 */

#ifndef LASER_H
#define LASER_H
#include "box.h"
#include <vector>
#define DIM 20
using std::vector;

/**
 @class laser derivée de box
 */
class laser : public box{
    static constexpr int degre = 90;

public :
    /**
     * @fn laser ()
     * @brief Constructeur
     *
     */
    laser();
    
    /**
        @fn laser(int x, int y)
        @brief Constructeur
        @param x position x du laser
        @param y position y du laser
    */
    laser(int x,int y);
    
    
    /**
     @fn tire()
     @brief le laser tire
     @return boxes où les tires sont lancé
     */
    vector<box> tire();
    
    
    
    /**
     @fn changeTrajectoirDroite()
     @brief change trajectoir vers la droite lors de la rencontre avec un mirroir
     */
    void changeTrajectoirDroite();
    
    
    
    /**
     @fn changeTrajectoirGauche()
     @brief change trajectoir vers la gauche lors de la rencontre avec un mirroir
     */
    void changeTrajectoirGauche();

};

#endif
