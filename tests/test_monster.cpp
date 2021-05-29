

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

TEST(TestMonster, TestOperator) {
    Monster *monster = new Monster(10, 10, 20, 5,5);
    ASSERT_TRUE(monster==monster);
}

TEST(TestMonster, TestOperatorFalse) {
    Monster *monster1 = new Monster(10, 10, 20, 5,5);
    Monster *monster2 = new Monster(10, 10, 30, 5,5);
    ASSERT_FALSE(monster1==monster2);
}
TEST(TestMonster, TestSave) {
    string res = "monster;5;5;10;10;50\n";
    Monster *monster = new Monster(10, 10, 50, 5,5);
    ASSERT_EQ(res, monster->save());
}
TEST(TestMonster, TestRepr) {
    Monster *monster = new Monster(10, 10, 50, 5,5);
    ASSERT_TRUE(monster->repr() == 'M');
    ASSERT_FALSE(monster->repr() == 'N');
}


// AAA  - Aarange act assert

// ToDo test  potom load skusit na tom stringu co vyprodukuje save
