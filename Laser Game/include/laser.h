/**
 * @headerfile laser.h
 * @author Aurelia Antz , Edona Dibra , Maryem Mouhssine , Malalanirina Rakotomamonjy
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

};

#endif
