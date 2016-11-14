
#include "Item.h"

// -------------------------------------------------------------------------------------

Item::Item(int const & row, int const & col)
    :item_row{row}, item_col{col}
{}


void Item::change_character()
//Character const & new_character)
{
//	character_ptr{} = new_character;	
}


bool Item::has_character()
{
//	return (character_ptr != nullptr);
    return true;
}

// --------------------------------------------------------------------------------------
// Item_Inc_Bombs
// --------------------------------------------------------------------------------------
void Item_Inc_Bombs::give_power_up(Character & character)
{
//	character.add_bomb(1);
}

void Item_Inc_Bombs::draw_graphics()
{
}


// --------------------------------------------------------------------------------------
// Item_Inc_Exp_Rad
// --------------------------------------------------------------------------------------
void Item_Inc_Exp_Rad::give_power_up(Character & character)
{
//	character.increase_exp_rad(2);
}

void Item_Inc_Exp_Rad::draw_graphics()
{
}
// --------------------------------------------------------------------------------------


// --------------------------------------------------------------------------------------

