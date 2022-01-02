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

using std::string;

class terrain
{
    public:
        terrain();
        laser accesLaser() const;
        cible accesCible() const;
        void initialiser();
        void afficheTerrain(std::ostream& ost);
        void placeLaser();
        void placemirroir();
        void placecible();
        void sauvegarderTerrain(string cheminFichier);
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
        char d_terrain[DIM][DIM]={' '};

};


#endif // TERRAIN_H

