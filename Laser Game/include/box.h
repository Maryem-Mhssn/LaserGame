#ifndef BOX_H
#define BOX_H

class box{
public:
    box(int x, int y);
    box();
    int x()const;
    int y()const;
    void moveTo(int x, int y);
private:
    int d_x, d_y;
};


#endif // BOX_H
