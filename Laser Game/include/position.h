#ifndef POSITION_H
#define POSITION_H

class position{
public:
    position(int x, int y);
    int x()const;
    int y()const;
    void moveTo(int x, int y);
    void movePosition(const position& p);

private:
    int d_x, d_y;

};

#endif // POSITION_H
