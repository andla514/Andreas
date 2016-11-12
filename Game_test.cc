#include "Game.h"
#include "catch.hpp"
#include <iostream>
#include "Item.h"

TEST_CASE("Set and get (Game)")
{
    Game our_game;
    CHECK(our_game.get_element(0, 0) == 5);
    our_game.set_element(0, 0, 1);
    CHECK(our_game.get_element(0, 0) == 1);
    CHECK(our_game.get_rows() == 19);
    CHECK(our_game.get_columns() == 25);

    our_game.draw_graphics();
}
TEST_CASE("Add and remove item")
{
    Game our_game;
    Item first_item;
    our_game.add_item(1, 2, first_item);
    //Item gotten_item = our_game.get_item_at(1, 2);
}