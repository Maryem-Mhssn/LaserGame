/**
 * @headerfile terrain.h
 * @author Aurelia Antz , Edona Dibra , Maryem Mouhssine , Malalanirina Rakotomamonjy
 * @brief Fichier header contenant la définition de la classe terrain
 */

#ifndef TERRAIN_H
#define TERRAIN_H

#include "box.h"
#include "cible.h"
#include "laser.h"
#include "mur.h"
#include "mirroir.h"
#include <iostream>
#include <vector>
#define DIM 20
#define TAILLE_MAX_MUR 7
#define NOMBRE_MAX_MUR 4

using std::string;

/**
 * @class terrain
 */
class terrain
{
public:

    /**
     * @fn terrain()
     * @brief Constructeur par défaut
     */
    terrain();

    /**
     * @fn laser accesLaser() const
     * @brief Acces au laser du terrain
     * @return d_laser
     */
    laser accesLaser() const;

    /**
     * @fn cible accesCible() const
     * @brief Acces à la cible du terrain
     * @return d_cible
     */
    cible accesCible() const;

    /**
     * @fn char accesCase(const box b) const
     * @brief Acces à la valeur de la case b
     * @param b Case dont on veut la valeur
     * @return Valeur de la case b
     */
    char accesCase(const box b) const;

    /**
     * @fn void setChar(char c,box b)
     * @brief Met le caractère c dans la box b
     * @param c Caractère à placer
     * @param b Case
     */
    void setChar(char c,box b);

    /**
     * @fn int lanceVersDroite(box& b)
     * @brief Tire le laser vers la droite
     * @param b Box où le tir passe
     */
    int lanceVersDroite(box& b);

    /**
     * @fn int lanceVersGauche(box& b)
     * @brief Tire le laser vers la gauche
     * @param b Box où le tir passe
     */
    int lanceVersGauche(box& b);

    /**
     * @fn int lanceVersHaut(box& b)
     * @brief Tire le laser vers le haut
     * @param b Box où le tir passe
     */
    int lanceVersHaut(box& b);

    /**
     * @fn int lanceVersBas(box& b)
     * @brief Tire le laser vers le bas
     * @param b Box où le tir passe
     */
    int lanceVersBas(box& b);

    /**
     * @fn int lanceVersBas(box& b)
     * @brief Tire le laser vers le bas
     * @param testSens nouveau sens de tir
     * @param testCharacter caractere de la box
     * @param testCurrent box ou le tir passe
     */
    void execution (char& testSens, char& testCharacter, box& testCurrent);

    /**
     * @fn char sensLaser(box& b)
     * @brief Renvoie le sens de tir du laser
     * @param b Box où le tir passe
     * @return un char donnant le sens de tir
     */
    char sensLaser(box& b);


    /**
     * @fn int random(int a);
     * @brief Génère un nombre aléatoire différent de a
     * @param a Nombre
     * @return Un nouveau nombre
     */
    int random(int a);

    /**
     * @fn void initialiser()
     * @brief Initialise le terrain
     */

    void initialiser();

    /**
     * @fn void afficheTerrain(std::ostream& ost)
     * @brief Affichage du terrain
     * @param ost Flux de sortie
     */
    void afficheTerrain(std::ostream& ost);

    /**
     * @fn void placeLaserCible()
     * @brief Place le laser et la cible sur le terrain
     */
    void placeLaserCible();

    /**
     * @fn void placeMirroir()
     * @brief Place un miroir sur le terrain
     */
    void placeMirroir();



    /**
     * @fn void placeMur()
     * @brief Place un mur sur le terrain
     */
    void placeMur();

    /**
     * @fn mur initialisationMur()
     * @brief Initialise un mur
     * @return Mur initialisé
     */
    mur initialisationMur();

    /**
     * @fn int creationMurVertical(box& b, int taille, int iterateur)
     * @param b Box
     * @param taille Taille finale du mur
     * @param iterateur Taille actuelle
     * @return
     */
    int creationMurVertical(box& b,int taille,int iterateur);

    /**
     * @fn int creationMurHorizontal(box& b, int taille, int iterateur)
     * @param b Box
     * @param taille Taille finale du mur
     * @param iterateur Taille actuelle
     * @return
     */
    int creationMurHorizontal(box& b,int taille,int iterateur);

    /**
     * @fn void sensMur()
     * @brief Définit le sens du mur à créer
     */
    void sensMur();

    /**
     * @fn placeBox(const box b)
     * @brief Place une case sur le terrain
     * @param b Case à placer
     */
    void placeBox(const box b);

    /**
     * @fn void jouer()
     * @brief Permet de jouer
     */
    void jouer();

    /**
     * @fn void sauvegarderTerrain(string cheminFichier)
     * @brief Sauvegarde le terrain dans un fichier
     * @param cheminFichier Chemin du fichier
     */
    void sauvegarderTerrain(string cheminFichier);

    /**
     * @fn void importerTerrain(string cheminFichier)
     * @brief Importe un terrain depuis un fichier
     * @param cheminFichier Chemin du fichier
     */
    void importerTerrain(string cheminFichier);



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
    char d_terrain[DIM][DIM];

};


#endif // TERRAIN_H
