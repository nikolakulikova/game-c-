//
// Created by kulik on 30. 11. 2020.
//

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

#include "../objects/Item.h"
#include "../objects/MapObject.h"
#include "../objects/Player.h"
#include "../objects/Monster.h"
#include "../objects/Wall.h"
#include "../objects/Unit.h"
#include "../map/Map.h"

using namespace ::testing;

TEST(TestMap, TestTrim) {
    Map *map = new Map();
    string line = "TestString\n";
    ASSERT_EQ("TestString", map->trim(line));
}
TEST(TestMap, TestByChars) {
    Map *map1 = new Map();
    Map *map2 = new Map();
    map1->read("first.txt");
    map2->read("first.txt");
    ASSERT_TRUE(map1->maps_same_by_chars(*map2));
}
TEST(TestMap, TestSame) {
    Map *map1 = new Map();
    Map *map2 = new Map();
    map1->read("first.txt");
    map2->read("first.txt");
    ASSERT_TRUE(map1->maps_same_by_operator(*map2));
}
// ToDo ked bude hotovy operator == tak vieme spravit test ze ci sa mapa rovna sama sebe
//  a potom to vieme vyuzit aj pri tom save a load
