//
// Created by kulik on 14. 11. 2020.
//

#ifndef PROJEKT_PLAYER_H
#define PROJEKT_PLAYER_H

#include <vector>
#include "Unit.h"
#include "Item.h"
#include "Monster.h"

using namespace std;

class Player : public Unit{
    vector<Item> inventory;
    int numberOfItems = 0;
public:
    int itembonus(string type);
    Player(int posX, int posY, int attack, int defense, int health, int number = 0, vector<Item> *inventory = new vector<Item>);
    int getAttack() override;
    int getDefense() override;
    int getHealth() override;
    bool drop(string name);
    bool pickup(Item item);
    char repr() override;
    string save();
    static Player* load(string object);
    string type() override{return "player";};
    bool fight(Monster monster);
    bool operator==(Player other);
};


#endif //PROJEKT_PLAYER_H
