//
// Created by kulik on 20. 11. 2020.
//

#include "Item.h"

bool Item::operator==(Item item1) {
    if(item1.name  == name){
        return true;
    }
    return false;
}

char Item::repr() {
    return '*';
}

string Item::save() {
    string res = "item;" + name + ";" +  to_string(getX()) + ";" + to_string(getY());
    res += ";" + to_string(attack_i) + ";" + to_string(defense_i) + ";" + to_string(health_i);
    return res + "\n";

}


Item* Item::load(string object) {
    string x, y, a, d, h, name = "";
    int pos = 0;
    while(object[pos] != ';'){
        pos++;
    }
    pos++;
    while(object[pos] != ';'){
        name += object[pos];
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

    return new Item(name, stoi(x), stoi(y), stoi(a), stoi(d), stoi(h));
}

Item::Item(string Name, int posX, int posY, int a, int d, int h) {
    name = Name;
    x = posX;
    y = posY;
    attack_i = a;
    defense_i = d;
    health_i = h;
}
