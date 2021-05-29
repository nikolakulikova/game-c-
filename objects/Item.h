//
// Created by kulik on 20. 11. 2020.
//
#include <iostream>
#include "MapObject.h"

#ifndef PROJEKT_ITEM_H
#define PROJEKT_ITEM_H
using namespace std;

class Item : public MapObject{
public:
    string name;
    int health_i;
    int defense_i;
    int attack_i;
    bool operator==(Item item1);
    char repr() override;
    string save();
    Item(string name, int posX, int posY, int a, int d, int h);
    static Item* load(string object);
    string type() override{return "item";};
};


#endif //PROJEKT_ITEM_H
