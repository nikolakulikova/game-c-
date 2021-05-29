//
// Created by kulik on 27. 11. 2020.
//

#ifndef PROJEKT_WALL_H
#define PROJEKT_WALL_H
#include "MapObject.h"

class Wall: public MapObject { ;


public:

    static Wall* load(string object);
    bool operator==(Wall other);

    string save() override;

    Wall(int x, int y);

    char repr() override ;
    string type();
    bool isWall() override{ return true;}
};


#endif //PROJEKT_WALL_H
