#include "terrain.h"
#include <iostream>
#include<fstream>
#include <ctime>
#include<cstdlib>
using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;



terrain::terrain(): d_cible{},d_laser{},d_mur{}
{
   initialiser();
   placeLaserCible();
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
            else d_terrain[i][j]=' ';
        };
    };

}

void terrain::afficheTerrain(std::ostream& ost)
{
     for (int i=0; i<DIM; i++)
     {  ost<<"  ";
         for (int j=0; j<DIM; j++)
       {
              ost<<d_terrain[i][j]<<" ";
       }
       ost<<endl;
     }

}
void terrain::placeLaserCible()
{
    srand(time(0));
    int xc, yc, xl, yl;
    do
    {
        xc=rand()% DIM ;
        yc=rand()% DIM;
    }  while(!(xc==0||yc==0||xc==DIM-1||yc==DIM-1));
     do
    {
           xl=random(xc);
           yl=random(yc);
    }  while(!(xl==0||yl==0||xl==DIM-1||yl==DIM-1));

    d_laser.moveTo(xl,yl);
    placeBox(d_laser);
    d_cible.moveTo(xc,yc);
    placeBox(d_cible);
}
int terrain:: random(int a)
{
    int x;
         x= rand()% DIM ;
    if (x==a){
        random(x);
    }

    return x;
}

void terrain::placeMirroir()
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
    d_mirroir.push_back(m);
    placeBox(m);
}


void terrain::placeMur()
{

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
        for (int j = 0; j < DIM; j++)
        {
              monTerrain >> d_terrain[i][j];
        }
    }
}

void terrain::placeBox(const box b)
{
    d_terrain[b.x()][b.y()]=b.c();
}

void terrain::jouer()
{
    vector<box> jeu = d_laser.tire();
    for (const auto& b : jeu)
        placeBox(b);
    cout<<"oui"<<endl;
}
