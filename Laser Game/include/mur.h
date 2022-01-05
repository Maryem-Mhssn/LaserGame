/**
 * @headerfile mur.h
 * @author Aurelia Antz
 * @brief Fichier header contenant la classe mur
 */

#ifndef MUR_H
#define MUR_H
#include "box.h"
#include <vector>

/**
 * @class mur
 */
class mur: public box {
public:
    /**
     * @fn mur(int x,int y,int taille)
     * @brief Constructeur
     * @param x Position x du mur
     * @param y Position y du mur
     * @param taille Taille du mur
     */
    mur(int x,int y,int taille);

    /**
     * @fn mur(int x,int y)
     * @brief Constructeur
     * @param x Position x du mur
     * @param y Position y du mur
     */
    mur(int x, int y);

    /**
     * @fn int taille() const
     * @brief Renvoie la valeur de d_taille
     * @return d_taille
     */
    int taille() const;

    /**
     * @fn void cretaionVerticale()
     * @brief créé un mur dans le sens vertical
     */
    void creationVerticale();

    /**
     * @fn void cretaionHorizontale()
     * @brief créé un mur dans le sens horizontal
     */
    void creationHorizontale();

private:

    int d_taille;

};


#endif //MUR_H

