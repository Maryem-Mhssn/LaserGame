#ifndef TERRAIN_H
#define TERRAIN_H


class terrain
{
    public:
        // terrain initialisé par le joueur
        terrain(int dimensions);
        //terrain de forme standard (à définir)
        terrain();
        void afficheTerrain();
        void placeLaser();
        void placemirroir();
        void place(cible);

    private:
        //dimension du terrain
        int d_dim;
        //Laser
        Laser d_laser;
        //mirroir
        vector <mirroir> d_mirroir;
        //cible
        cible d_cible;




};

#endif // TERRAIN_H
