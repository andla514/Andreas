
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
	sf::Texture Powerup_Texture;
	if(!Powerup_Texture.loadFromFile(("Textures/Powerups/BombPowerup.png"))
	{
		throw std::logic_error("Can't load Item texture");
	}
	
	sf::Sprite Powerup_Sprite;
	if(!Powerup_Sprite.setTexture(Powerup_Texture))
	{
		throw std::logic_error("Can't convert Powerup_Texture to Powerup_Sprite");
	}
	
}


// --------------------------------------------------------------------------------------
// Item_Inc_Bombs
// --------------------------------------------------------------------------------------

void Item_Inc_Bombs::give_power_up(Character & character)
{
	character.add_bomb(1);
}

void Item_Inc_Bombs::draw_graphics(sf::RenderWindow &)
{
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

void Item_Inc_Exp_Rad::give_power_up(Character & character)
{
	character.increase_exp_rad(2);
}

void Item_Inc_Exp_Rad::draw_graphics(sf::RenderWindow & our_window)
{
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

void Item_Inc_Life::give_power_up(Character & character)
{
	character.add_life(1);
}

void Item_Inc_Life::draw_graphics(sf::RenderWindow &)
{
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

void Item_Inc_Exp_Time::give_power_up(Character & character)
{
    character.increase_exp_time(1);
}

void Item_Inc_Exp_Time::draw_graphics(sf::RenderWindow &)
{
	/*
	sf::Sprite Increase_Explosion_Duration_Time;
	if(!Increase_Explosion_Duration_Time.loadFromFile("Textures/Powerups/BombTimePowerup" + ".png"))
		{
		throw std::logic_error("Can't load Item 'Increase Explosion Duration Time' texture");
		}
	*/
}