
#include "mur.hpp"
/**
 * \file mur.h
 * \author Aurelia Antz
 * \brief Définition des méthodes de la classe mur
 */


/**
 * @fn mur(int x,int y,int taille)
 * @brief Constructeur
 * @param x Position x du mur
 * @param y Position y du mur
 * @param taille Taille du mur
 */
mur::mur(int x, int y, int taille) : box{x,y,'X'}, d_taille{taille} {}

/**
 * @fn mur(int x,int y)
 * @brief Constructeur
 * @param x Position x du mur
 * @param y Position y du mur
 */
mur::mur(int x, int y) : box{x,y,'X'}, d_taille{1} {}



/**
 * @fn int taille() const
 * @brief Renvoie la valeur de d_taille
 * @return d_taille
 */
int mur::taille() const {
    return d_taille;
}

/**
 * @fn void cretaionVerticale()
 * @brief créé un mur dans le sens vertical
 */
void mur::creationVerticale() {
    
    for(int i =x() ;i < d_taille;i++){
        mur m{i,y()};
    }
}

/**
 * @fn void cretaionHorizontale()
 * @brief créé un mur dans le sens horizontal
 */
void mur::creationHorizontale() {
    for(int i = y();i < d_taille;i++){
        mur m{x(),i};
    }
}
