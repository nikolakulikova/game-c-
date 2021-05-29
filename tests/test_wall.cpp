

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

TEST(TestWall, TestOperator) {
    Wall *w = new Wall(15, 15);
    ASSERT_TRUE(w->operator==(*w));
}

TEST(TestWall, TestOperatorTrue) {
    Wall *w1 = new Wall(10, 10);
    Wall *w2 = new Wall(10, 10);
    ASSERT_TRUE(w1->operator==(*w2));
}
TEST(TestWall, TestSave) {
    string res = "wall;0;0\n";
    Wall *w = new Wall(0,0);
    ASSERT_EQ(res, w->save());
}
TEST(TestWall, TestSaveFalse) {
    string res = "p;0;0\n";
    Wall *w = new Wall(0,5);
    ASSERT_FALSE(res ==  w->save());
}
TEST(TestWall, TestRepr) {
    Wall *w = new Wall(2,0);
    ASSERT_TRUE(w->repr() == '#');
    ASSERT_FALSE(w->repr() == 'X');
}


// AAA  - Aarange act assert

// ToDo test  potom load skusit na tom stringu co vyprodukuje save


