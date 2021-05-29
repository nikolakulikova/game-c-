//
// Created by kulik on 27. 11. 2020.
//

#ifndef PROJEKT_MAP_H
#define PROJEKT_MAP_H

#include <fstream>
#include <bits/unique_ptr.h>
#include "../objects/MapObject.h"
#include "../objects/Player.h"
#include "../objects/Monster.h"
#include "../objects/Item.h"

class Map {
private:
    Player *player;
    int whatsThere(int x, int y);
public:
    int mapSizeX = 20;
    int mapSizeY = 20;
    Map();
    MapObject* loadObject(string object);
    bool read(const string &file);
    bool isEndchar(char ch);
    string trim(string line);
    bool save(const string &file);
    void move(string where);
    bool operator==(Map other);
    bool maps_same_by_chars(Map other);
    bool maps_same_by_operator(Map other);

public:
     MapObject **privateMap ;

};







#endif //PROJEKT_MAP_H
