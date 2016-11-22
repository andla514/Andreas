
#include "Item.h"

#include "Game.h"
#include "Character.h"
#include "Bomb.h"


// --------------------------------------------------------------------------------------
// Item
// --------------------------------------------------------------------------------------
Item::Item(int const & row, int const & col)
    :item_row{row}, item_col{col}
{
	
}


// --------------------------------------------------------------------------------------
// Item_Inc_Bombs
// --------------------------------------------------------------------------------------

Item_Inc_Bombs::Item_Inc_Bombs(int const & row, int const & col)
	:item_row{row}, item_col{col}
{
	if(!powerup_Texture.loadFromFile("Textures/Powerups/BombPowerup.png"))
	{
		throw std::logic_error("Can't load Item texture");
	}
	
	powerup_Sprite.setTexture(powerup_Texture);	
}
void Item_Inc_Bombs::give_power_up(Character & character)
{
	character.add_bomb(1);
}

void Item_Inc_Bombs::draw_graphics(sf::RenderTexture & our_window)
{
	//sf::Sprite to_draw{powerup_Texture};
	powerup_Sprite.setPosition(64 * item_col + 16, 64 * item_row + 16);
	our_window.draw(powerup_Sprite);
	/*
	sf::Texture Increase_Number_of_Maximum_Bombs_Texture; 
	sf::Sprite Increase_Number_of_Maximum_Bombs_Sprite;
	if(!Increase_Number_of_Maximum_Bombs.loadFromFile("Textures/Powerups/BombPowerup.png"))
		{
		throw std::logic_error("Can't load Item 'Increase Explosion Radius' texture");
		}
	*/
}


// --------------------------------------------------------------------------------------
// Item_Inc_Exp_Rad
// --------------------------------------------------------------------------------------

Item_Inc_Exp_Rad::Item_Inc_Exp_Rad(int const & row, int const & col)
	:item_row{row}, item_col{col}
{
	if(!powerup_Texture.loadFromFile("Textures/Powerups/FlamePowerup.png"))
	{
		throw std::logic_error("Can't load Item texture");
	}
	
	powerup_Sprite.setTexture(powerup_Texture);	
}

void Item_Inc_Exp_Rad::give_power_up(Character & character)
{
	character.increase_exp_rad(2);
}

void Item_Inc_Exp_Rad::draw_graphics(sf::RenderTexture & our_window)
{
	powerup_Sprite.setPosition(64 * item_col + 16, 64 * item_row + 16);
	our_window.draw(powerup_Sprite);
	/*
	sf::Sprite Increase_Explosion_Radius;
	if(!Increase_Explosion_Radius.loadFromFile("Textures/Powerups/FlamePowerup" + ".png"))
		{
		throw std::logic_error("Can't load Item 'Increase Explosion Radius' texture");
		}
	*/
}


// --------------------------------------------------------------------------------------
// Item_Inc_Life
// --------------------------------------------------------------------------------------

Item_Inc_Life::Item_Inc_Life(int const & row, int const & col)
	:item_row{row}, item_col{col}
{
	if(!powerup_Texture.loadFromFile("Textures/Powerups/LifePowerup.png"))
	{
		throw std::logic_error("Can't load Item texture");
	}
	
	powerup_Sprite.setTexture(powerup_Texture);	
}

void Item_Inc_Life::give_power_up(Character & character)
{
	//character.add_life(1);
}

void Item_Inc_Life::draw_graphics(sf::RenderTexture &)
{
	powerup_Sprite.setPosition(64 * item_col + 16, 64 * item_row + 16);
	our_window.draw(powerup_Sprite);
	/*
	sf::Sprite Increase_Life;
	if(!Increase_Life.loadFromFile("Textures/Powerups/LifePowerup" + ".png"))
		{
		throw std::logic_error("Can't load Item 'Increase Life' texture");
		}
	*/
}

// --------------------------------------------------------------------------------------
// Item_Inc_Exp_Time
// --------------------------------------------------------------------------------------

Item_Inc_Exp_Time::Item_Inc_Exp_Time(int const & row, int const & col)
	:item_row{row}, item_col{col}
{
	if(!powerup_Texture.loadFromFile("Textures/Powerups/BombTimePowerup.png"))
	{
		throw std::logic_error("Can't load Item texture");
	}
	
	powerup_Sprite.setTexture(powerup_Texture);	
}


void Item_Inc_Exp_Time::give_power_up(Character & character)
{
    character.increase_exp_time(1);
}

void Item_Inc_Exp_Time::draw_graphics(sf::RenderTexture &)
{
	powerup_Sprite.setPosition(64 * item_col + 16, 64 * item_row + 16);
	our_window.draw(powerup_Sprite);
	/*
	sf::Sprite Increase_Explosion_Duration_Time;
	if(!Increase_Explosion_Duration_Time.loadFromFile("Textures/Powerups/BombTimePowerup" + ".png"))
		{
		throw std::logic_error("Can't load Item 'Increase Explosion Duration Time' texture");
		}
	*/
}