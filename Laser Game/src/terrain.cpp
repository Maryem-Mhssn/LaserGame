#include "terrain.h"

terrain::terrain(int dimensions): d_dim{dimensions}
{

}

terrain::terrain(): terrain{10}
{

}
void terrain:: afficheTerrain()
{
    //initialisation
    char tab[d_dim][d_dim]={' '};
    for (int i=0; i<d_dim; i++){
        for(int j=0; j<d_dim; j++){
            if(i==0 || j==0 || i==d_dim-1 || j==d_dim-1) tab[i][j]='x';
        };
    };
    //pour afficher le laser
    tab[d_laser.x()][d_laser.y()]='@';
    //On fait pareil pour la cible et les mirroirs.
    //...

    //Affichage
     for (int i=0; i<length; i++)
     {
         for (int j=0; j<length; j++)
       {
              cout<<tab[i][j]<<" ";
       }
       cout<<endl;
     };

}
void terrain ::placeLaser()
{

}
void terrain ::placemirroir()
{

}
void terrain ::place(cible)
{

}
