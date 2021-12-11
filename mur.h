/**
 * \file mur.h
 * \author Aurelia Antz
 * \brief Fichier header contenant la classe mur
 */

#ifndef MUR_H
#define MUR_H

/**
 * @class mur
 */
class mur {
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
     * @fn char c() const
     * @brief Renvoie la valeur de d_c
     * @return d_c
     */
    char c() const;

    /**
     * @fn int x() const
     * @brief Renvoie la valeur de d_x
     * @return d_x
     */
    int x() const;

    /**
     * @fn int y() const
     * @brief Renvoie la valeur de d_y
     * @return d_y
     */
    int y() const;

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
    char d_c;
    int d_x;
    int d_y;
    int d_taille;

};


#endif //MUR_H
