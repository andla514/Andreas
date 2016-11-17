//
// Created 
//
#include "catch.hpp"
#include "Item.h"
#include "Character.h"


TEST_CASE("Testa Items")
{
    Item_Inc_Bombs inc_bomb{1,1};
    Item_Inc_Life inc_life{1,2};
    Item_Inc_Exp_Rad inc_rad{2,2};
    Item_Inc_Exp_Time inc_time{4,5};

    Character test_character{};

    inc_bomb.give_power_up(test_character);
    CHECK(test_character.bombs == 2);

    inc_life.give_power_up(test_character);
    CHECK(test_character.life == 3);

    inc_rad.give_power_up(test_character);
    CHECK(test_character.bomb_settings.radius == 4);

    inc_time.give_power_up(test_character);
    CHECK(test_character.bomb_settings.explosion_delay == 4);
    
}