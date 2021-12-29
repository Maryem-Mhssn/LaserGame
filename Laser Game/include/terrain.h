#ifndef TERRAIN_H
#define TERRAIN_H
#include "box.hpp"
#include "cible.hpp"
#include "Laser.hpp"
#include "mur.hpp"
#include "mirroir.hpp"
#include <vector>




#define DIM 20

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

