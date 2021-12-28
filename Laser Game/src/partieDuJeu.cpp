#include "partieDuJeu.h"


partieJeu::partieJeu()
{
    lancerPartie();
}

void partieJeu::lancerPartie()
{

    char choice;
    bool quitBool = false;

                cout << "Bienvenue au LASER GAME!" << endl;
            do
                {

                cout << endl;

                cout << "     ----------------------------------" << endl;

                cout << "     ----------------MENU--------------" << endl;

                cout << "     ----------------------------------" << endl;

                cout<<"             COMMENT JOUER [H] "<<endl;
                cout<<"             DEMARRER LE JEU [P] "<<endl;
                cout<<"             QUITTER LE JEU [Q] " <<endl<< endl;

                cout << endl;

                cout << "             ENTRER VOTRE CHOIX:" << endl;

                cin >> choice;

                cout << "     ----------------------------------" << endl;
                switch(choice)
                {

                    case 'H':
                    case 'h':

                        cout<<"            ---Regles du jeu---"<<endl;

                        cout<<"     1. Vous pouvez jouer sur un nouveau terrain ou importer un ancien."<<endl;

                        cout<<"     2. Vous devez mettre en place vos miroirs"<<endl;

                        cout<<"     3. Le jeu terminera quand la cible est atteinte"<<endl;

                        cout<<endl;

                        cout<<"            ---Choses a noter---"<<endl;

                        cout<<"     1. Vous n'avez que 3 miroirs"<<endl;

                        cout<<"     2. Vous n'avez qu'une seule tentative"<<endl;

                        cout<<endl;

                        cout << "     ----------------------------------" << endl;

                        break;
                    case 'P':
                    case 'p':
                        //cout<<"Oups! toujours en réalisation ;-)";
                        {
                        cout << "                 LASER GAME" << endl;
                        terrain t{};
                        t.initialiser();
                        t.afficheTerrain();
                        for(int i=0; i<=2; ++i)
                        {
                            t.placemirroir();
                        }
                        t.afficheTerrain();
                        quitBool = true;
                        break;
                        }
                    case 'Q':
                    case 'q':
                        cout<<"        ---Au revoir petit gamer!---";
                        quitBool = true;
                        break;


                }
            }while(!quitBool);


}
