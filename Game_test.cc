#include "Game.h"
#include "Bomb.h"
#include "catch.hpp"
#include <iostream>
#include "Item.h"
#include <memory>

TEST_CASE("Set and get (Game)")
{
    Game our_game;
    CHECK(our_game.get_element(0, 0) == 5);
    our_game.set_element(0, 0, 1);
    CHECK(our_game.get_element(0, 0) == 1);
    CHECK(our_game.get_rows() == 19);
    CHECK(our_game.get_columns() == 25);
    //our_game.draw_graphics();
}
TEST_CASE("Add and remove item")
{
    Game our_game;
    our_game.add_item(1, 1, std::make_unique<Item_Inc_Bombs>(1, 1));
    our_game.add_item(1, 2, std::make_unique<Item_Inc_Exp_Rad>(1, 2));
    our_game.add_item(1, 3, std::make_unique<Item_Inc_Life>(1, 3));
    our_game.add_item(1, 4, std::make_unique<Item_Inc_Exp_Time>(1, 4));

    CHECK(dynamic_cast<Item_Inc_Bombs*>(&our_game.get_item_reference(1, 1)));
    CHECK(dynamic_cast<Item_Inc_Exp_Rad*>(&our_game.get_item_reference(1, 2)));
    CHECK(dynamic_cast<Item_Inc_Life*>(&our_game.get_item_reference(1, 3)));
    CHECK(dynamic_cast<Item_Inc_Exp_Time*>(&our_game.get_item_reference(1, 4)));
}
/*
TEST_CASE("Add and remove bomb")
{
    Game our_game;
    our_game.update();
    our_game.remove_bomb(1, 1);
    our_game.add_bomb(1, 1, Bomb{3});
    our_game.update();
    CHECK(our_game.get_bomb_reference(1,1).number == 3);
    our_game.update();
}*/
TEST_CASE("Bools (Game)")
{
    Game our_game;
    // With element being 0 = Ground
    our_game.set_element(0, 0, 0);
    CHECK_FALSE(our_game.is_standing_in_fire(0, 0));
    CHECK_FALSE(our_game.is_standing_on_item(0, 0));
    CHECK(our_game.can_move_to(0, 0));
    CHECK_FALSE(our_game.is_wall(0, 0));
    CHECK_FALSE(our_game.is_box(0, 0));

    // With element being 1 = Box
    our_game.set_element(0, 0, 1);
    CHECK_FALSE(our_game.is_standing_in_fire(0, 0));
    CHECK_FALSE(our_game.is_standing_on_item(0, 0));
    CHECK_FALSE(our_game.can_move_to(0, 0));
    CHECK_FALSE(our_game.is_wall(0, 0));
    CHECK(our_game.is_box(0, 0));

    // With element being 2 = Item
    our_game.set_element(0, 0, 2);
    CHECK_FALSE(our_game.is_standing_in_fire(0, 0));
    CHECK(our_game.is_standing_on_item(0, 0));
    CHECK(our_game.can_move_to(0, 0));
    CHECK_FALSE(our_game.is_wall(0, 0));
    CHECK_FALSE(our_game.is_box(0, 0));

    // With element being 3 = Bomb
    our_game.set_element(0, 0, 3);
    CHECK_FALSE(our_game.is_standing_in_fire(0, 0));
    CHECK_FALSE(our_game.is_standing_on_item(0, 0));
    CHECK_FALSE(our_game.can_move_to(0, 0));
    CHECK_FALSE(our_game.is_wall(0, 0));
    CHECK_FALSE(our_game.is_box(0, 0));

    // With element being 4 = Explosion
    our_game.set_element(0, 0, 4);
    CHECK(our_game.is_standing_in_fire(0, 0));
    CHECK_FALSE(our_game.is_standing_on_item(0, 0));
    CHECK(our_game.can_move_to(0, 0));
    CHECK_FALSE(our_game.is_wall(0, 0));
    CHECK_FALSE(our_game.is_box(0, 0));

    // With element being 5 = Wall
    our_game.set_element(0, 0, 5);
    CHECK_FALSE(our_game.is_standing_in_fire(0, 0));
    CHECK_FALSE(our_game.is_standing_on_item(0, 0));
    CHECK_FALSE(our_game.can_move_to(0, 0));
    CHECK(our_game.is_wall(0, 0));
    CHECK_FALSE(our_game.is_box(0, 0));
}