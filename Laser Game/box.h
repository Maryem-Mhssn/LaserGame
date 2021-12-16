#ifndef BOX_H
#define BOX_H

class position;

class box{
public:
    virtual ~box()=default;
    virtual void create(position p)=0;
    virtual void moveTo(position p)=0;

};



#endif // BOX_H
