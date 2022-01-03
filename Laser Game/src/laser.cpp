#include "laser.h"

laser::laser(): box{0,0,'#'}
{}


laser::laser(int x,int y): box(x, y,'#')
{}

vector<box> laser::tire(){
    vector<box> boxes{};
    if(x()==0 || x() == DIM-1){
        box b{x(),y()+1,c()};
        while(b.c() != '\\' && b.c() != '/'){
            b = box{b.x(),b.y(),'-'};
            boxes.push_back(b);
            b = box{b.x(),b.y()+1,c()};
        }
    }
    else if(y()==0 || y() == DIM-1){
        box b{x()+1,y(),c()};
        while(b.c() != '\\' && b.c() != '/'){
            b = box{b.x(),b.y(),'|'};
            boxes.push_back(b);
            b = box{b.x()+1,b.y(),c()};
        }
    }

    return boxes;

}

void laser::changeTrajectoirDroite(){

}



