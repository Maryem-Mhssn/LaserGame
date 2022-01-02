#include "terrain.h"
#include <iostream>
#include<fstream>
#include <ctime>
using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;



terrain::terrain(): d_cible{},d_laser{},d_mur{}
{

}

cible terrain::accesCible() const {
    return d_cible;
}

laser terrain::accesLaser() const {
    return d_laser;
}


void terrain::initialiser()
{
    for (int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            if(i==0 || j==0 || i==DIM-1 || j==DIM-1) d_terrain[i][j]='*';
        };
    };

}

void terrain::afficheTerrain(std::ostream& ost)
{

     for (int i=0; i<DIM; i++)
     {  ost<<"   ";
         for (int j=0; j<DIM; j++)
       {
              ost<<d_terrain[i][j]<<" ";
       }
       ost<<endl;
     }

}
void terrain::placeLaser()
{
    srand(time(0));
    int x=0, y=0;
    do
    {
        x=rand()% DIM;
        y=rand()% DIM;
    }
    while(!(x==0||y==0||x==DIM||y==DIM));
    d_laser.moveTo(x,y);
    d_terrain[x][y]=d_laser.c();
}

void terrain::placemirroir()
{
    int x, y;
    char c;
    cout<<"Entrez les coordonnees de votre miroir "<<endl;
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
    cout<<"Entrez le type de mirroir"<<endl;
    cin>>c;
    while(c!='/'&& c!='\\')
    {
        cout<<"Mirroir inexistant! "<<endl;
        cin>>c;
    }
    mirroir m {x, y, c};
    //d_mirroir.push_back(m);
    d_terrain[x][y]=c;
}

void terrain::placecible()
{
    int x=0, y=0;
    do
    {
        x=rand()% DIM;
        y=rand()% DIM;
    }
    while(!(x==0||y==0||x==DIM||y==DIM));
    d_cible.moveTo(x,y);
    d_terrain[x][y]=d_cible.c();
}

void terrain::sauvegarderTerrain(string cheminFichier)
{
ofstream monTerrain(cheminFichier);
monTerrain<<DIM<<endl;
afficheTerrain(monTerrain);
}

void terrain::importerTerrain(string cheminFichier)
 {
ifstream monTerrain(cheminFichier);
int dimension;
monTerrain >> dimension;

if (dimension>DIM)
  {
  cout << "terrain trop grand";
  return;
  }
for (int i = 0; i < DIM; i++)
{
    for (int j = 0; j < DIM; j++){
          monTerrain >> d_terrain[i][j];
    }
}
 }


