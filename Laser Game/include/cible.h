/**
 * @headerfile cible.h
 * @author Aurelia Antz , Edona Dibra , Maryem Mouhssine , Malalanirina Rakotomamonjy
 * @brief Fichier header contenant la classe cible
 */
#ifndef CIBLE_H
#define CIBLE_H
#include "box.h"

/**
 * @class cible derivée de box
 */
class cible : public box
{
public:

    /**
     * @fn cible ()
     * @brief Constructeur
     *
     */
    cible();

    /**
        @fn cible(int x, int y, char c)
        @brief Constructeur
        @param x position x de la cible
        @param y position y de la cible
        @param c caractere x de la cible
    */
    cible(int x, int y, char c);

    /**
     * @fn void setTouched()
     * @brief définit la cible comme étant touchée
     */
    void setTouched();


    /**
     * @fn void touched()
     * @brief renvoie si la cible a été touché ou non
     * @return d_touched
     */
    bool touched() const;

private:
    bool d_touched;

};

#endif // CIBLE_H
