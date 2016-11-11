#include "Game.h"
#include "catch.hpp"
#include <iostream>

TEST_CASE("Set and get")
{
    Game our_game;
    CHECK(our_game.get_element(0, 0) == 5);
    our_game.set_element(0, 0, 1);
    CHECK(our_game.get_element(0, 0) == 1);
    CHECK(our_game.get_rows() == 19);
    CHECK(our_game.get_columns() == 25);

    our_game.draw_graphics();
}