//
// Created by kulik on 14. 11. 2020.
//

#include "Monster.h"


char Monster::repr() {
    return 'M';
}

string Monster::save() {
    string res = "monster;" + to_string(getX()) + ";" +  to_string(getY());
     res +=  ";" + to_string(getAttack()) + ";" + to_string(getDefense()) + ";" + to_string(getHealth());
     return res + "\n";
}

Monster::Monster(int attack, int defence, int health, int posX, int posY) {
    setDefense(defence);setHealth(health);setAttack(attack); x = posX; y = posY;

}
Monster* Monster::load(string object) {
    string x = "";
    string y = "";
    string a = "" ; string d = ""; string h = "";
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
    while(object[pos] != ';'){
        y += object[pos];
        pos++;
    }
    pos++;
    while(object[pos] != ';'){
        a += object[pos];
        pos++;
    }
    pos++;
    while(object[pos] != ';'){
        d += object[pos];
        pos++;
    }
    pos++;
    while(pos < object.length()){
        h += object[pos];
        pos++;
    }

    return  new Monster(stoi(a), stoi(d), stoi(h), stoi(x), stoi(y));
}

bool Monster::operator==(Monster *other) {
    if(x == other->x && y == other->y){
        if(attack == other->attack && defense == other->defense && health == other->health){
            return true;
        }
    }
    return false;
}


