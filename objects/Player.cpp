//
// Created by kulik on 14. 11. 2020.
//

#include "Player.h"

int Player::itembonus(string type){
    int res = 0;
    for(int i = 0; i < inventory.size(); i++){
        if(type == "health"){
            res += inventory[i].health_i;
        }
        else if(type == "defense"){
            res += inventory[i].defense_i;
        }
        else if(type == "attack"){
            res += inventory[i].attack_i;
        }

    }
    return res;
}
int Player::getAttack() {
    int a = attack;
    a += itembonus("attack");
    return a;
}

int Player::getDefense(){
    int d = defense;
    d += itembonus("defense");
    return d;
}
int Player::getHealth(){
    int h = health;
    h += itembonus("health");
    return h;
}

bool Player::drop(string name) {
    for(int i = 0; i < inventory.size(); i++){
        if(inventory[i].name == name){
            inventory.erase(inventory.begin() + i);
            return true;
        }
    }
    return false;
}

bool Player::pickup(Item item) {
    if(&item == nullptr)
        return false;
    if(numberOfItems < 10){
        item.x = 0;
        item.y = 0;
        inventory.push_back(item);
        numberOfItems++;
        return true;
    }
    return false;
}

Player::Player(int posX, int posY, int attack, int defense, int health, int number, vector<Item> *inventory) {
    x = posX; y = posY, numberOfItems = number; this->inventory = *inventory;
    setAttack(attack);setHealth(health);setDefense(defense);

}
char Player::repr() {return 'H';}

string Player::save() {
    string res = "player;";
    res += to_string(getX()) + ";" + to_string(getY()) ;
    res +=  ";" + to_string(attack) + ";" + to_string(getDefense()) +  ";" + to_string(getHealth());
    if(numberOfItems > 0){
        res += ";" + to_string(numberOfItems)  + ";[" ;
    }
    else{
        res += ";" + to_string(numberOfItems);
    }
    for(int i = 0; i < numberOfItems; i++){
        res += "{" + inventory[i].save().substr(0,inventory[i].save().find('\n')) + "}";
    }
    if(numberOfItems > 0){
        res += "]";
    }
    return res+ "\n";
}


Player* Player::load(string object) {
    string x, y, a, d, h = "";
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
    if(object.find('[' , pos) != -1 ){
        while(object[pos] != ';'){
            h += object[pos];
            pos++;
        }
        pos++;
        string n= "";
        while(object[pos] != '['){
            n += object[pos];
            pos++;
        }
        vector<Item> inventor ;
        pos++;
        while(object.find('}', pos) != 0){
            int end = object.find('}', pos);
            inventor.push_back(*Item::load(object.substr(pos, end - pos)));
            pos += end + 1;
        }

        return new Player(stoi(x), stoi(y), stoi(a), stoi(d), stoi(h), stoi(n), &inventor);
    }
    while(object[pos] != ';'){
        h += object[pos];
        pos++;
    }
    pos++;
    string n = "";
    while(pos < object.length()){
        n += object[pos];
        pos++;
    }


    return new Player(stoi(x), stoi(y), stoi(a), stoi(d), stoi(h),stoi(n));
}

bool Player::fight(Monster monster) {
    while(attack > 0 || monster.attack > 0 || defense > 0 || monster.defense > 0 || health > 0 || monster.health > 0){
        if(attack > monster.attack){
            monster.attack -= attack;
        }
        else if(attack < monster.attack){
            attack -= monster.attack;
        }
        if(defense > monster.defense){
            monster.defense -= defense;
        }
        else if(defense < monster.defense){
             defense -= monster.defense;
        }
        if(health > monster.health){
            monster.health -= health;
        }
        else if(health < monster.health){
            health -= monster.health;
        }

    }
    if( health > monster.health ){
        return true;
    }
    return false;
}

bool Player::operator==(Player other) {
    if(x == other.x && y == other.y){
        if(attack == other.attack && defense == other.defense && health == other.health){
            for(auto& x:inventory){
                bool flag = false;
                for(auto& y:other.inventory){
                    if(x == y){
                        flag = true;
                    }
                }
                if(!flag){
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}



