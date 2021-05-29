//
// Created by kulik on 27. 11. 2020.
//

#include "Map.h"
#include "../objects/Wall.h"

bool Map::isEndchar(char ch){
    switch (ch){
        case '\n':
        case '\r':
        case '\t':
        case '\b':
        case '\v':
        case '\0':
            return true;
        default:
            return false;
    }
}

string Map::trim(string line){
    string res;
    int i = 0;
    while(i < line.length() && !isEndchar(line.at(i))){
        res += line.at(i);
        i++;
    }
    return res;
}
bool Map::read(const string &file) {
    ifstream inFile;
    inFile.open(file);
    string line;
    if (!inFile) {
        return false;
    }
    while (!inFile.eof()) {
        MapObject *object;
        line = "";
        getline(inFile, line);
        line = trim(line);
        object  = Map::loadObject(line);
        privateMap[object->y][object->x] = *object;
    }
    inFile.close();
    return true;
}


MapObject* Map::loadObject(string object) {
    int pos = 0;
    string who = "";
    MapObject *res;
    while(object[pos] != ';'){
        who += object[pos];
        pos++;
    }
    if(who == "monster"){
        res = Monster::load(object);
    }
    else if(who == "item"){
        res = Item::load(object);

    }
    else if(who == "player"){
        res = Player::load(object);
    }
    else if(who == "wall"){
        res = Wall::load(object);
    }
    return res;
}

bool Map::save(const string &file) {
    fstream outFile;
    if (outFile.fail()) {
        return false;
    }
    outFile.open(file, fstream::out);
    for(int i = 0; i < mapSizeY; i++) {
        for (int j = 0; j < mapSizeX; j++) {
            string line = "";
            line = privateMap[i][j].save();
            outFile << line;
        }
    }
    outFile.flush();
    outFile.close();
    return true;
}

void Map::move(string where) {
    int x = player->getX();
    int y = player->getY();
    int newx = x;
    int newy = y;
    int choice = 0;
    if(where == "UP"){
        choice = whatsThere(x, y - 1);
        newy--;
    }
    if(where == "DOWN"){
        choice = whatsThere(x, y + 1);
        newy++;
    }
    if(where == "LEFT"){
        choice = whatsThere(x - 1, y);
        newx--;
    }
    if(where == "RIGHT"){
        choice = whatsThere(x + 1, y);
        newx++;
    }
    switch(choice){
        case 0:
            return;
        case 1: {
            string answer = "";
            cout << "Do you want to fight or not? YES / NO";
            cin >> answer;
            if (answer == "YES") {
                player->fight(*dynamic_cast<Monster *>(&privateMap[newy][newx]));
            }
            return;
        }

        case 2:{
            string answer = "";
            cout << "Do you want to pick up item or not? YES / NO";
            cin >> answer;
            if(answer == "YES"){
                string item = "";
                cout << "Do you want to drop something? Write name of item OR NO";
                cin >> item;
                if(item == "NO"){
                    player->pickup(*dynamic_cast< Item*>(&privateMap[newy][newx]));
                    return;
                }
                player->drop(item);
                player->pickup(*dynamic_cast< Item*>(&privateMap[newy][newx]));

            }
            return;

        }
        case 3:
            player->move(where);

    }

}

int Map::whatsThere(int x, int y) {
    if(privateMap[y][x].isWall()){
        return 0;
    }
    if(privateMap[y][x].type() == "monster"){
        return 1;
    }
    if(privateMap[y][x].type() == "item"){
        return 2;
    }

    return 3;
}

bool Map::maps_same_by_chars(Map other) {
    for(int column = 0; column < mapSizeY; column++){
        for(int row = 0; row < mapSizeX; row++) {
            if(privateMap[column][row].repr() != other.privateMap[column][row].repr()){

                return false;
            }
        }
    }
    return true;
}
bool Map::maps_same_by_operator(Map other) {
    for(int column = 0; column < mapSizeY; column++){
        for(int row = 0; row < mapSizeX; row++) {
            if(privateMap[column][row].operator==(&other.privateMap[column][row])){
                continue;
            } else{
                return false;
            }
        }
    }
    return true;
}
Map::Map() {
    privateMap = new MapObject*[mapSizeY];
    for(int i = 0; i < mapSizeY; i++){
        privateMap[i] = new MapObject[mapSizeX];
    }
}