//
// Created by kulik on 14. 11. 2020.
//

#ifndef PROJEKT_MONSTER_H
#define PROJEKT_MONSTER_H


#include "Unit.h"

class Monster: public Unit{
public:
    int getAttack()override{return attack;};
    int getDefense() override{return defense;};
    int getHealth() override{return health;};
    Monster(int attack, int defense, int health, int x, int y);
    char repr() override ;
    string save() override ;
    static Monster* load(string object);
    bool operator==(Monster *other)  ;
    string type() override{return "monster";};
};


#endif //PROJEKT_MONSTER_H
