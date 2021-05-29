//
// Created by kulik on 27. 11. 2020.
//

#include "MapObject.h"
#include "Monster.h"
#include "Wall.h"
#include "Player.h"

void MapObject::move(string where) {
    if(where == "UP"){
        y--;
    }
    if(where == "DOWN"){
        y++;
    }
    if(where == "LEFT"){
        x--;
    }
    if(where == "RIGHT"){
        x++;
    }

}
