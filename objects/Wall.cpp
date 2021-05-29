//
// Created by kulik on 27. 11. 2020.
//

#include "Wall.h"

char Wall::repr() {
    return '#';
}

string Wall::save() {
    string res = "wall;" + to_string(getX()) + ";" + to_string(getY());
    return res + "\n";
}
Wall::Wall(int posX, int posY) {
    x = posX; y = posY;
}
Wall* Wall::load(string object) {
    string x , y = "";
    int pos = 0;
    while(object[pos] != ';'){
        pos++;
    }
    pos++;
    while(object[pos] != ';'){
        x += object[pos];
        pos++;
    }
    pos++;
    while(pos < object.length()){
        y += object[pos];
        pos++;
    }
    return new Wall(stoi(x), stoi(y));
}

bool Wall::operator==(Wall other) {
    if(x == other.x && y == other.y){
        return true;
    }
    return false;
}


