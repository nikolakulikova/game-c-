//
// Created by kulik on 14. 11. 2020.
//

#ifndef PROJEKT_UNIT_H
#define PROJEKT_UNIT_H
#include "MapObject.h"

class Unit: public MapObject {
public:
    void setAttack(int num);
    void setDefense(int num);
    void setHealth(int num);
    virtual int getAttack() = 0;
    virtual int getDefense() = 0;
    virtual int getHealth() = 0;

    int attack;
    int defense;
    int health;

};


#endif //PROJEKT_UNIT_H
