#include "mur.h"

mur::mur(int x, int y, int taille) : box{x,y,'X'}, d_taille{taille} {}

mur::mur(int x, int y) : box{x,y,'X'}, d_taille{1} {}

int mur::taille() const {
    return d_taille;
}

void mur::creationVerticale() {

    for(int i = x() ;i < d_taille;i++){
        mur m{i,y()};
    }

}

void mur::creationHorizontale() {
    for(int i = y();i < d_taille;i++){
        mur m{x(),i};
    }
}
