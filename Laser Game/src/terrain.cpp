#include "terrain.h"
#include <iostream>
using std::cout;
using std::endl;

terrain::terrain(): d_cible{},d_laser{}
{}


void terrain::initialiser()
{
    for (int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            if(i==0 || j==0 || i==19 || j==19) d_terrain[i][j]='*';
        };
    };
    //juste pour tester
    //d_cible.moveTo(0,5);
    //d_laser.moveTo(19,7);
    d_terrain[d_cible.x()][d_cible.y()]='@';
    d_terrain[d_laser.x()][d_laser.y()]='#';

}

void terrain:: afficheTerrain()
{

     for (int i=0; i<20; i++)
     {
         for (int j=0; j<20; j++)
       {
              cout<<d_terrain[i][j]<<" ";
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
void terrain ::placecible()
{

}
