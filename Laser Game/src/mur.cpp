/**
 * \file mur.h
 * \author Aurelia Antz
 * \brief Définition des méthodes de la classe mur
 */

#include "mur.h"

/**
 * @fn mur(int x,int y,int taille)
 * @brief Constructeur
 * @param x Position x du mur
 * @param y Position y du mur
 * @param taille Taille du mur
 */
mur::mur(int x, int y, int taille) : d_c{'X'}, d_x{x}, d_y{y}, d_taille{taille} {}

/**
 * @fn mur(int x,int y)
 * @brief Constructeur
 * @param x Position x du mur
 * @param y Position y du mur
 */
mur::mur(int x, int y) : d_c{'X'}, d_x{x}, d_y{y}, d_taille{1} {}

/**
 * @fn char c() const
 * @brief Renvoie la valeur de d_c
 * @return d_c
 */
char mur::c() const {
    return d_c;
}

/**
 * @fn int x() const
 * @brief Renvoie la valeur de d_x
 * @return d_x
 */
int mur::x() const {
    return d_x;
}

/**
 * @fn int y() const
 * @brief Renvoie la valeur de d_y
 * @return d_y
 */
int mur::y() const {
    return d_y;
}

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
    for(int i = d_x;i < d_taille;i++){
        mur m{i,d_y};
    }
}

/**
 * @fn void cretaionHorizontale()
 * @brief créé un mur dans le sens horizontal
 */
void mur::creationHorizontale() {
    for(int i = d_y;i < d_taille;i++){
        mur m{d_x,i};
    }
}