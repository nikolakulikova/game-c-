

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

TEST(TestPlayer, TestOperator) {
    Player *player = new Player(15, 15, 20, 5,5,0);
    ASSERT_TRUE(player->operator==(*player));
}

TEST(TestPlayer, TestOperatorTrue) {
    Player *player1 = new Player(10, 10, 20, 5,5);
    Player *player2 = new Player(10, 10, 20, 5,5);
    ASSERT_TRUE(player1->operator==(*player2));
}
TEST(TestPlayer, TestSave) {
    string res = "player;15;15;10;5;10;0\n";
    Player *player = new Player(15, 15, 10, 5,10,0);
    ASSERT_EQ(res, player->save());
}
TEST(TestPlayer, TestSaveFalse) {
    string res = "player;15;15;10;5;10;0;[{item;Health;20;20;10;10;50}]\n";
    Player *player = new Player(15, 15, 10, 5,10,0);
    ASSERT_FALSE(res ==  player->save());
}
TEST(TestPlayer, TestRepr) {
    Player *player = new Player(10, 10, 50, 5,5);
    ASSERT_TRUE(player->repr() == 'H');
    ASSERT_FALSE(player->repr() == 'L');
}


// AAA  - Aarange act assert

// ToDo test  potom load skusit na tom stringu co vyprodukuje save


