
#include "Item.h"

#include "Game.h"
#include "Character.h"
#include "Bomb.h"


// --------------------------------------------------------------------------------------
// Item
// --------------------------------------------------------------------------------------
Item::Item(int const & row, int const & col)
    :item_row{row}, item_col{col}
{}


// --------------------------------------------------------------------------------------
// Item_Inc_Bombs
// --------------------------------------------------------------------------------------

void Item_Inc_Bombs::give_power_up(Character & character)
{
	character.add_bomb(1);
}

void Item_Inc_Bombs::draw_graphics()
{}


// --------------------------------------------------------------------------------------
// Item_Inc_Exp_Rad
// --------------------------------------------------------------------------------------

void Item_Inc_Exp_Rad::give_power_up(Character & character)
{
	character.increase_exp_rad(2);
}

void Item_Inc_Exp_Rad::draw_graphics()
{}


// --------------------------------------------------------------------------------------
// Item_Inc_Life
// --------------------------------------------------------------------------------------

void Item_Inc_Life::give_power_up(Character & character)
{
	character.add_life(1);
}

void Item_Inc_Life::draw_graphics()
{}

// --------------------------------------------------------------------------------------
// Item_Inc_Exp_Time
// --------------------------------------------------------------------------------------

void Item_Inc_Exp_Time::give_power_up(Character & character)
{
    character.increase_exp_time(1);
}

void Item_Inc_Exp_Time::draw_graphics()
{}