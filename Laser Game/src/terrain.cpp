#include "terrain.h"
#include <iostream>

#define DIM 20
using std::cout;
using std::endl;
using std::cin;

terrain::terrain(): d_cible{},d_laser{}, d_mur{}
{}


void terrain::initialiser()
{

    for (int i=0; i<DIM; i++)
    {
        for(int j=0; j<DIM; j++)
        {
            if(i==0 || j==0 || i==DIM-1 || j==DIM-1) d_terrain[i][j]='*';

        }
    }
    //juste pour tester
    //d_cible.moveTo(0,5);
    //d_laser.moveTo(19,7);
    //d_terrain[d_cible.x()][d_cible.y()]='@';
    //d_terrain[d_laser.x()][d_laser.y()]='#';

}

void terrain:: afficheTerrain()
{

     for (int i=0; i<DIM; i++)
     {  cout<<"   ";
         for (int j=0; j<DIM; j++)
       {
              cout<<d_terrain[i][j]<<" ";
       }
       cout<<endl;
     }

}


void terrain ::placeLaser()
{
    int x=rand()% DIM-1;
    int y=rand()% DIM-1;


    if(x==0||y==0||x==DIM-1||y==DIM-1){
        d_laser.moveTo(x,y);
    }
}



void terrain ::placemirroir()
{
    int x, y;
    char c;
    cout<<"Entrez les coordonnées de votre miroir "<<endl;
    cin>>x>>y;
    while(x>=DIM)
    {
        cout<<"x est trop grand! "<<endl;
        cin>>x;
    }
    while(y>=DIM)
    {
        cout<<"y est trop grand! "<<endl;
        cin>>y;
    }
    do {
            cout<<"Entrez le type de mirroir"<<endl;
        cin>>c;
    }
    while(c=='/'||c!='\\');
    /*{
        cout<<"Mirroir inexistant! "<<endl;
        cin>>c;
    }*/
    mirroir m {x, y, c};
    d_mirroir.push_back(m);
}

void terrain ::placecible()
{
    int x=rand()% DIM-1;
    int y=rand()% DIM-1;

    if(x==0||y==0||x==DIM-1||y==DIM-1){
        d_cible.moveTo(x,y);
    }
}


