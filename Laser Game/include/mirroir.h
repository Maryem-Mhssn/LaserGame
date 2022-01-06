/**
 * @headerfile mirroir.h
 * @author Aurelia Antz , Edona Dibra , Maryem Mouhssine , Malalanirina Rakotomamonjy
 * @brief Fichier header contenant la classe mirroir
 */

#ifndef MIRROIR_H
#define MIRROIR_H

#include "box.h"

/**
 * @class mirroir
 * @inherit box
 */
class mirroir : public box
{
    public:

        /**
         * @fn mirroir(int x, int y, char type)
         * @brief Construit un miroir à partir d'une position et d'un caractère
         * @param x Position x
         * @param y Position y
         * @param type Caractère représentant un miroir
         */
        mirroir(int x, int y, char type);

        /**
         * @fn char type() const
         * @brief Acces au type du miroir
         * @return d_type
         */
        char type() const;

    private:
        char d_type;
};

#endif // MIRROIR_H
