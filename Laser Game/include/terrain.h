/**
 * @headerfile terrain.h
 * @author
 * @brief Fichier header contenant la définition de la classe terrain
 */

#ifndef TERRAIN_H
#define TERRAIN_H

#include "box.h"
#include "cible.h"
#include "laser.h"
#include "mur.h"
#include "mirroir.h"
#include <iostream>
#include <vector>
#define DIM 20
#define TAILLE_MAX_MUR 7
#define NOMBRE_MAX_MUR 4

using std::string;

/**
 * @class terrain
 */
class terrain
{
    public:

        /**
         * @fn terrain()
         * @brief Constructeur par défaut
         */
        terrain();

        /**
         * @fn laser accesLaser() const
         * @brief Acces au laser du terrain
         * @return d_laser
         */
        laser accesLaser() const;

        /**
         * @fn cible accesCible() const
         * @brief Acces à la cible du terrain
         * @return d_cible
         */
        cible accesCible() const;

        char accesCase(const box b) const;
        void setChar(char c,box b);
        void lanceVersDroite(box& b);
        int lanceVersGauche(box b);
        int lanceVersHaut(box b);
        int lanceVersBas(box b);


        /**
         * @fn int random(int a);
         * @brief Génère un nombre aléatoire différent de a
         * @param a Nombre
         * @return Un nouveau nombre
         */
        int random(int a);

        /**
         * @fn void initialiser()
         * @brief Initialise le terrain
         */

        void initialiser();

        /**
         * @fn void afficheTerrain(std::ostream& ost)
         * @brief Affichage du terrain
         * @param ost Flux de sortie
         */
        void afficheTerrain(std::ostream& ost);

        /**
         * @fn void placeLaserCible()
         * @brief Place le laser et la cible sur le terrain
         */
        void placeLaserCible();

        /**
         * @fn void placeMirroir()
         * @brief Place un miroir sur le terrain
         */
        void placeMirroir();

        /**
         * @fn void placeMur()
         * @brief Place un mur sur le terrain
         */
        void placeMur();
        mur initialisationMur();
        int creationMurVertical(box& b,int taille,int iterateur);
        int creationMurHorizontal(box& b,int taille,int iterateur);
        void sensMur();

        /**
         * @fn placeBox(const box b)
         * @brief Place une case sur le terrain
         * @param b Case à placer
         */
        void placeBox(const box b);

        /**
         * @fn void jouer()
         * @brief Permet de jouer
         */
        void jouer();

        /**
         * @fn void sauvegarderTerrain(string cheminFichier)
         * @brief Sauvegarde le terrain dans un fichier
         * @param cheminFichier Chemin du fichier
         */
        void sauvegarderTerrain(string cheminFichier);

        /**
         * @fn void importerTerrain(string cheminFichier)
         * @brief Importe un terrain depuis un fichier
         * @param cheminFichier Chemin du fichier
         */
        void importerTerrain(string cheminFichier);



    private:
        //Laser
        laser d_laser;
        //mirroir
       std::vector <mirroir> d_mirroir;
        //cible
        cible d_cible;
        //murs
        std::vector <mur> d_mur;
        //terrain sous forme de matrice
        char d_terrain[DIM][DIM];

};


#endif // TERRAIN_H

