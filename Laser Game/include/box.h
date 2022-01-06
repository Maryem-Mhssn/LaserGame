/**
 * @headerfile box.h
 * @author Aurelia Antz , Edona Dibra , Maryem Mouhssine , Malalanirina Rakotomamonjy
 * @brief Fichier header contenant la classe box
 */

#ifndef BOX_H
#define BOX_H

/**
 * @class box
 * @brief Représente une case du terrain
 */
class box{
public:

    /**
     * @fn box(int x,int y,char c)
     * @brief Construit une box
     * @param x Position x
     * @param y Position y
     * @param c Caractère de la box
     */
    box(int x, int y,char c);

    /**
     * @fn box()
     * @brief Constructeur par défaut
     */
    box();

    /**
     * @fn int x() const
     * @brief Acces à la valeur de x
     * @return Position x de la box
     */
    int x()const;

    /**
     * @fn int y() const
     * @brief Acces à la valeur de y
     * @return Position y de la box
     */
    int y()const;

    /**
     * @fn int c() const
     * @brief Acces à la valeur de c
     * @return Caractère de la box
     */
    char c() const;

    /**
     * @fn void moveTo(int x,int y)
     * @brief Déplace à la box à la position (x,y)
     * @param x Nouvelle position x
     * @param y Nouvelle position y
     */
    void moveTo(int x, int y);

    /**
     * @fn void setC(char c)
     * @brief Changer le caractère par c
     * @param c Nouveau caractere c
     */
    void setC(char c);



    /**
     * @fn bool operator==(const box& b) const
     * @brief Surcharge de l'opérateur ==
     * @param b Box
     * @return true si les boxes sont égales, false sinon
     */

    bool operator==(const box& b) const;

    /**
     * @fn bool operator!=(const box& b) const
     * @brief Surcharge de l'opérateur !=
     * @param b Box
     * @return true si les boxes sont différentes, false sinon
     */
    bool operator!=(const box& b) const;

private:
    int d_x, d_y;
    char d_c;
};


#endif // BOX_H
