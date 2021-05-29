//
// Created by kulik on 8. 12. 2020.
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

TEST(TestItem, TestOperatorTrue) {
    Item *item = new Item("testItem", 10, 10, 10, 5, 10);
    ASSERT_TRUE(item->operator==(*item));
}

TEST(TestItem, TestOperatorFalse) {
    Item *item1 = new Item("testItem1", 10, 10, 10, 5, 10);
    Item *item2 = new Item("testItem2", 10, 10, 10, 5, 10);
    ASSERT_FALSE(item1->operator==(*item2));
}
TEST(TestItem, TestSave) {
    string res = "item;Health;10;10;10;10;50\n";
    Item *item1 = new Item("Health", 10, 10, 10, 10, 50);
    ASSERT_EQ(res, item1->save());
}
TEST(TestItem, TestOperatorF) {
    Item *item2 = new Item("testItem2", 10, 10, 10, 5, 10);
    ASSERT_TRUE(item2->repr() == '*');
    ASSERT_FALSE(item2->repr() == 'o');
}


// AAA  - Aarange act assert

// ToDo test  potom load skusit na tom stringu co vyprodukuje save
