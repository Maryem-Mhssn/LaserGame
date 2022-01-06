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
    placeMur();
}

cible terrain::accesCible() const
{
    return d_cible;
}

laser terrain::accesLaser() const
{
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


int terrain::random(int a)
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
    if (accesCase(m)!=m.c())
    {
        mirroir m {x, y, c};
        d_mirroir.push_back(m);
        placeBox(m);
    }
    else {
        cout<<"mirroir existe d�j�"<<endl;
        placeMirroir();
    }

}

mur terrain::initialisationMur()
{
    srand(time(0));
    int x = 1 + rand() / (RAND_MAX/(DIM-2));
    int y = 1 + rand() / (RAND_MAX/(DIM-2));
    int taille = 1 + rand() / (RAND_MAX/(TAILLE_MAX_MUR-1));
    mur m{x,y,taille};
    d_mur.push_back(m);
    return m;
}

int terrain::creationMurHorizontal(box& b,int taille,int iterateur)
{
    int i = 0;
    char next = d_terrain[b.x()][b.y()-1];
    char prev = d_terrain[b.x()][b.y()+1];
    char up = d_terrain[b.x()+1][b.y()];
    char down = d_terrain[b.x()-1][b.y()];

    if((next!='*') && (iterateur < taille)
       && (next!='#' && prev!='#' && up!='#' && down!='#')
       && (next!='@' && prev!='@' && up!='@' && down!='@')
            ){
        box nextBox{b.x(),b.y()-1,'X'};
        placeBox(nextBox);
        iterateur++;
        i+= creationMurHorizontal(nextBox,taille,iterateur)+1;
    }

    return i;
}


int terrain::creationMurVertical(box& b,int taille,int iterateur)
{
    int i = 0;
    char next = d_terrain[b.x()][b.y() - 1];
    char prev = d_terrain[b.x()][b.y() + 1];
    char up = d_terrain[b.x() + 1][b.y()];
    char down = d_terrain[b.x() - 1][b.y()];

    if ((next != '*') && (iterateur < taille)
        && (next != '#' && prev != '#' && up != '#' && down != '#')
        && (next != '@' && prev != '@' && up != '@' && down != '@')
            ) {
        box nextBox{b.x() - 1, b.y(), 'X'};
        placeBox(nextBox);
        iterateur++;
        i += creationMurVertical(nextBox, taille, iterateur) + 1;
    }

    return i;
}


void terrain::sensMur()
{
    srand(time(NULL));
    int sens = rand()%2;
    if(sens == 1){
        mur m = initialisationMur();
        placeBox(m);
        box next{m.x()-1, m.y(), m.c()};
        creationMurVertical(next,m.taille(),0);
        placeBox(next);
    }
    else{
        mur n = initialisationMur();
        placeBox(n);
        box prev{n.x(),n.y()-1,n.c()};
        creationMurHorizontal(prev,n.taille(),0);
        placeBox(prev);
    }
}

void terrain::placeMur()
{

    srand(time(NULL));
    int nbMaxMurs = 0;
    int choix;
    cout<<"Choississez un niveau de difficulté (veuillez entrer le numéro correspondant) : \n1. Facile\n2. Moyen\n3. Difficile\n";
    cin>>choix;

    do{
        switch (choix) {
            case 1:
                nbMaxMurs = 2;
                break;
            case 2:
                nbMaxMurs = 4;
                break;
            case 3:
                nbMaxMurs = 7;
                break;
            default:
                cout<<"Veuillez entrer un numéro valide !\n";
                cin>>choix;
        }
    }while((choix!=1) && (choix!=2) && (choix!=3));

    int nbMurs = 1 + rand() / (RAND_MAX/(nbMaxMurs-1));

    for(int i = 0;i < nbMurs;i++)
    {
        sensMur();
    }


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
    int i;
    char ch;
    box current {d_laser.x(),d_laser.y(),' '};
    if(d_laser.y()==DIM-1)
    {
        i=lanceVersGauche(d_laser);
        current.moveTo(current.x(),current.y()-i-1);
    }
    if(d_laser.y()==0)
    {
        i=lanceVersDroite(d_laser);
        current.moveTo(current.x(),current.y()+i+1);
    }
    if(d_laser.x()==DIM-1)
    {
        i=lanceVersHaut(d_laser);
        current.moveTo(current.x()-i-1,current.y());
    }
    if(d_laser.x()==0)
    {
        i=lanceVersBas(d_laser);
        current.moveTo(current.x()+i+1,current.y());
    }
    ch=d_terrain[current.x()][current.y()];
    char sens=sensLaser(current);
    execution(sens,ch,current);
}

void terrain ::execution (char& testSens, char& testCharacter, box& testCurrent)
{
        int i=0;
        if (testCharacter != '*' && testCharacter != '@'&& testCharacter != 'X')
            {
                if(testSens=='h')
                {
                    if (testCharacter=='/')
                    {
                           i=lanceVersGauche(testCurrent);
                           testCurrent.moveTo(testCurrent.x(),testCurrent.y()-i-1);
                           testSens='d';
                    }
                    else if (testCharacter=='\\')
                    {
                           i=lanceVersDroite(testCurrent);
                           testCurrent.moveTo(testCurrent.x(),testCurrent.y()+i+1);
                           testSens='d';
                    }

                       testCharacter=d_terrain[testCurrent.x()][testCurrent.y()];
                }
                if(testSens=='b')
                {
                    if (testCharacter=='\\')
                    {
                           i=lanceVersGauche(testCurrent);
                           testCurrent.moveTo(testCurrent.x(),testCurrent.y()-i-1);
                           testSens='g';
                    }
                    else if (testCharacter=='/')
                    {
                           i=lanceVersDroite(testCurrent);
                           testCurrent.moveTo(testCurrent.x(),testCurrent.y()+i+1);
                           testSens='d';
                    }

                       testCharacter=d_terrain[testCurrent.x()][testCurrent.y()];

                }

                    else if(testSens=='d')
                {
                    if (testCharacter=='/')
                       {
                           i=lanceVersBas(testCurrent);
                           testCurrent.moveTo(testCurrent.x()+i+1,testCurrent.y());
                            testSens='b';
                       }
                    else if (testCharacter=='\\')
                       {
                           i=lanceVersHaut(testCurrent);
                           testCurrent.moveTo(testCurrent.x()-i-1,testCurrent.y());
                            testSens='h';
                       }
                       testCharacter=d_terrain[testCurrent.x()][testCurrent.y()];

                }
                else if(testSens=='g')
                {
                    if (testCharacter=='\\')
                       {
                           i=lanceVersBas(testCurrent);
                           testCurrent.moveTo(testCurrent.x()+i+1,testCurrent.y());
                           testSens='b';
                       }
                    else if (testCharacter=='/')
                       {
                           i=lanceVersHaut(testCurrent);
                           testCurrent.moveTo(testCurrent.x()-i-1,testCurrent.y());
                           testSens='h';
                       }
                       testCharacter=d_terrain[testCurrent.x()][testCurrent.y()];

                }
                 execution(testSens,testCharacter,testCurrent);
        }
       else  if (testCharacter == '@')
       {
            d_cible.setTouched();
       }
       else if (testCharacter == 'X'||testCharacter == '*')
       {
            cout<<" ----------------Vous avez touche un mur ------------------"<<endl;
            cout<<" -------------------Vous avez Perdu ! ---------------------"<<endl;
       }

}

char terrain :: sensLaser(box& b)
{
        char sens;
        int x=b.x();
        int y=b.y();
        if (d_terrain[x+1][y]=='|')

        {
            sens='b';
        }
        else if(d_terrain[x-1][y]=='|')
        {
            sens='h';
        }
        else if (d_terrain[x][y+1]=='-'||d_terrain[x][y-1]=='-')
        {
            sens='d';
        }
        else if (d_terrain[x][y-1]=='-')
        {
            sens='g';
        }

        return sens;
}

void terrain::setChar(char c,box b)
{
    d_terrain[b.x()][b.y()]= c;
}

int terrain::lanceVersDroite(box& b)
{
    int i=0;
    char next = d_terrain[b.x()][b.y()+1];
    if(next==' ')
    {
        box next{b.x(),b.y()+1,'-'};
        placeBox(next);
        i+=1+lanceVersDroite(next);
    }
    return i;

}
int terrain::lanceVersGauche(box& b)
{   int i=0;
    char next = d_terrain[b.x()][b.y()-1];
    if(next==' ')
    {
        box next{b.x(),b.y()-1,'-'};
        placeBox(next);
        i+=lanceVersGauche(next)+1;

    }
    return i;

}

int terrain::lanceVersHaut(box& b)
{
    int i=0;
    char next = d_terrain[b.x()-1][b.y()];
    if(next==' ')
    {
        box next{b.x()-1,b.y(),'|'};
        placeBox(next);
        i=lanceVersHaut(next)+1;
    }
    return i;
}

int terrain::lanceVersBas(box& b)
{
    int i=0;
    char next = d_terrain[b.x()+1][b.y()];
    if(next==' ')
    {
        box next{b.x()+1,b.y(),'|'};
        placeBox(next);
        i+=lanceVersBas(next)+1;
    }
    return i;
}
