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
   //placeLaserCible();


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
    d_laser.moveTo(5,DIM-1);
    placeBox(d_laser);
    d_cible.moveTo(8,DIM-1);
    placeBox(d_cible);

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
{/*
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
    if (accesCase(m)!=m.c())
    {
    mirroir m {x, y, c};
    d_mirroir.push_back(m);
    placeBox(m);
    }
    else {
        cout<<"mirroir existe déjà"<<endl;
        placeMirroir();
    }
    */
    mirroir m {5, 7, '/'};
    d_mirroir.push_back(m);
    placeBox(m);

   // mirroir m1 {10, 7, '/'};
    //d_mirroir.push_back(m1);
    //placeBox(m1);

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

char terrain::accesCase(const box b) const
{
    return d_terrain[b.x()][b.y()];
}

void terrain::jouer()
{
   box current {d_laser.x(),d_laser.y(),' '};
   int i=lanceVersGauche(d_laser);
   current.moveTo(current.x(),current.y()-i-1);
   char c=accesCase(current);
   do
   {
   if (c=='/')
       {
           i=lanceVersBas(current);
           current.moveTo(current.x()+i+1,current.y());
       }
  /* else if (c=='\\')
       {
           i=lanceVersHaut(current);
           current.moveTo(current.x()-i-1,current.y());
                      cout<<"wla hna";

       }
*/

   }
   while(c==' ');



       /* if(accesCase(suivant)=='@')
            {
                d_cible.setTouched();
            }*/
    //while (d_cible.touched()==false||accesCase(suivant)=='*');

}
void terrain::setChar(char c,box b)
{
    d_terrain[b.x()][b.y()]= c;
}

void terrain::lanceVersDroite(box& b)
{


   /*int step=1;
   char next = d_terrain[b.x()][b.y()+step];
   while(next!='/')||next!='\\')
  {
      setChar('-',next);
      placeBox(next);
      step++;
  }


  box test{b.x(),b.y(),' '};
  while(b.c()!='/'&&b.c()!='\\')
  {
      test.moveTo(test.x(),test.y()+1);
      setChar('-',test);
  }



box next{b.x(),b.y()+step,'-'};
while(b.c()!='/'&&b.c()!='\\')
   {
    placeBox(next);
    step++;
   }
   */


   char next = d_terrain[b.x()][b.y()+1];
   if (next!='/'&&next!='\\')
   {
       if(next=='@')
        {
           d_cible.setTouched();
        }
       else
        {
           box next{b.x(),b.y()+1,'-'};
           placeBox(next);
           lanceVersDroite(next);
        }
   }

}
int terrain::lanceVersGauche(box b)
{   int i=0;
   char next = d_terrain[b.x()][b.y()-1];
   if (next!='/'&&next!='\\')
   {
        if(next=='@')
        {
           d_cible.setTouched();
        }
       else if(next==' ')
       {
           box next{b.x(),b.y()-1,'-'};
           placeBox(next);
           i+=lanceVersGauche(next)+1;
       }
   }
   return i;

}
int terrain::lanceVersHaut(box b)
{
    int i=0;
   char next = d_terrain[b.x()-1][b.y()];
   if (next!='/'&&next!='\\')
   {
       if(next=='@')
        {
           d_cible.setTouched();
        }
       else if(next==' ')
        {
           box next{b.x()-1,b.y(),'|'};
           placeBox(next);
           i=lanceVersHaut(next)+1;
        }
   }
   return i;
}
int terrain::lanceVersBas(box b)
{
    int i=0;
    char next = d_terrain[b.x()+1][b.y()];
   if (next!='/'&&next!='\\')
   {
       if(next=='@')
        {
           d_cible.setTouched();
        }
        else if(next==' ')
        {
           box next{b.x()+1,b.y(),'|'};
           placeBox(next);
           i+=lanceVersBas(next)+1;
        }
   }
   return i;
}
