//
// Created by kulik on 27. 11. 2020.
//

#ifndef PROJEKT_MAPOBJECT_H
#define PROJEKT_MAPOBJECT_H

#include <iostream>

using namespace std;

class MapObject {
public:
    int x;
    int y;
    int getX() {return x;};
    int getY() {return y;};
    virtual char repr()=0;
    void move(string where);
    virtual bool operator==(MapObject *other)=0;
    virtual bool isWall(){return false;};

    virtual string save() =0;
    virtual string type()=0;


};


#endif //PROJEKT_MAPOBJECT_H
