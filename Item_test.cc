//
// Created 
//
#include "catch.hpp"
#include "Item.h"
#include "Character.h"
#include "Character.h"


TEST_CASE("Testa Items")
{
    Item_Inc_Bombs 		inc_bomb{1,1};
    Item_Inc_Life 		inc_life{1,2};
    Item_Inc_Exp_Rad 	inc_rad{2,2};
    Item_Inc_Exp_Time 	inc_time{4,5};

    Character test_character{};
    inc_bomb.give_power_up(test_character);
    inc_life.give_power_up(test_character);
    inc_rad.give_power_up(test_character);
	inc_time.give_power_up(test_character);
	
	CHECK(inc_bomb.item_row == 1);
	CHECK(inc_bomb.item_col == 1);
	CHECK(inc_life.item_row == 1);
	CHECK(inc_life.item_row == 2);
	CHECK(inc_rad.item_row == 1);
	CHECK(inc_rad.item_col == 1);
	CHECK(inc_time.item_row == 1);
	CHECK(inc_time.item_col == 1);
	   
}