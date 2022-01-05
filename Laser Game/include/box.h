#ifndef BOX_H
#define BOX_H

class box{
public:
    box(int x, int y,char c);
    box();
    int x()const;
    int y()const;
    char c() const;
    void moveTo(int x, int y);
    void setC(char c);
    bool operator==(const box& b) const;
    bool operator!=(const box& b) const;
private:
    int d_x, d_y;
    char d_c;
};


#endif // BOX_H
