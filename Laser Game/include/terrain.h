#ifndef TERRAIN_H
#define TERRAIN_H
#include "box.h"
#include "cible.h"
#include "laser.h"
#define DIM 20

class terrain
{
    public:
        //terrain de forme standard (� d�finir)
        terrain();
        void initialiser();
        void afficheTerrain();
        void placeLaser();
        void placemirroir();
        void placecible();
        void sauvegarderTerrain();
        void importerTerrain();

    private:
        //Laser
        laser d_laser;
        //mirroir
       // vector <mirroir> d_mirroir;
        //cible
        cible d_cible;
        //murs
      // vector <mur> d_mur;
        //terrain sous forme de matrice
        char d_terrain[DIM][DIM]={' '};

};

#endif // TERRAIN_H
