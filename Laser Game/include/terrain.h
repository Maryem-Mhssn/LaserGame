#ifndef TERRAIN_H
#define TERRAIN_H
#include "box.h"
#include "cible.h"
#include "laser.h"
#include "mur.h"
#include "mirroir.h"

#define DIM 20

#include <vector>

class terrain
{
    public:
        //terrain de forme standard (à définir)
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
       std::vector <mirroir> d_mirroir;
        //cible
        cible d_cible;
        //murs
      std::vector <mur> d_mur;
        //terrain sous forme de matrice
        char d_terrain[DIM][DIM]={' '};

};

#endif // TERRAIN_H
