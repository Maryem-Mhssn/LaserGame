/**
 * @headerfile partieDuJeu.h
 * @author Aurelia Antz , Edona Dibra , Maryem Mouhssine , Malalanirina Rakotomamonjy
 * @brief Fichier header gérant une partie de jeu
 */

#ifndef PARTIE_DU_JEU_H
#define PARTIE_DU_JEU_H

#include <iostream>
#include "terrain.h"

using std::cout;
using std::endl;
using std::cin;

/**
 * @class partieJeu
 */
class partieJeu
{
    public:
        /**
         * @fn partieJeu()
         * @brief Constructeur par défaut
         */
        partieJeu();

        /**
         * @fn void lancerPartie()
         * @brief Lance une partie de jeu
         */
        void lancerPartie();

};

#endif // PARTIE_DU_JEU_H
