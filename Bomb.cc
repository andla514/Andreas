#include "Bomb.h"
#include "Tile.h"
#include "Character.h"
#include "Explosion.h"
#include "Matrix_Map.h"
#include "Timer.h"
#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>

//-----------------CONSTRUCTOR--------------
Bomb::Bomb(int row, int col, Bomb_settings our_settings, std::shared_ptr<Matrix_Map> our_map,
	Character* my_creator)
	: row_pos{row}, col_pos{col},my_settings{our_settings.radius, our_settings.detonation_delay, our_settings.explosion_delay}, 
		detonation_timer{Timer(our_settings.detonation_delay)}, our_map{our_map}, my_creator{my_creator}
{}

/*
* void update()
* Checks if it's time to detonate
*/
void Bomb::update()
{
	if (detonation_timer.is_done())
		detonate();
}

/*
* void detonate()
* Calculate and creates explosions in the correct places
*/
void Bomb::detonate()
{
	spread_explosions ("right", my_settings.radius);
	spread_explosions ("left", my_settings.radius);
	spread_explosions ("up", my_settings.radius);
	spread_explosions ("down", my_settings.radius);
	get_creator().add_bomb(1);
	explode(row_pos, col_pos, false);
}

/*
* void explode (int row, int col, bool item_bool)
* Creates an Explosion object
*/
void Bomb::explode(int row, int col, bool item_bool)
{
	our_map->make_object(row, col, (std::make_unique<Explosion>(row, col, my_settings.explosion_delay,
										item_bool, our_map)));
}

/*
* void spread_explosions(string direction, int distance)
* Creates explosions in a given direction for a given distance.
* The function handles several exceptions that requires different solutions
*/
void Bomb::spread_explosions (std::string direction, int distance)
{
	int row{row_pos};
	int col{col_pos};
	
	while (distance > 1)
	{
		if (direction == "right")
			col ++;
		else if (direction == "left")
			col --;
		else if (direction == "up")
			row --;
		else if (direction == "down")
			row ++;
		else
			throw std::logic_error("Invalid direction");
			
		// Current place is a wall
		if (our_map->is_wall(row, col))
		{
			distance = 0;
		}
		// Current place is a box
		else if (our_map->is_box(row, col))
		{
			explode(row, col, true);
			distance = 0;
		}
		// Current place is a bomb
		else if (our_map->is_bomb(row, col))
		{
			if(!dynamic_cast<Bomb&>(our_map->get_reference(row, col)).detonation_timer.is_done())
			{
				//dynamic_cast<Bomb&>(our_map->get_reference(row, col)).detonation_timer = Timer{-1};
				dynamic_cast<Bomb&>(our_map->get_reference(row, col)).detonate();
			}
			distance --;
		}
		// Current place is an item
		/*else if (our_map->is_item(row, col))
		{
			explode(row, col, false);
			distance --;
		}*/
		// Current place is an explosion
		else if (our_map->is_explosion(row, col))
		{
			// The explotion with the longest remaining time on its timer, stays
			if (dynamic_cast<Explosion&>(our_map->get_reference(row, col)).time_left() <= 1000 * my_settings.explosion_delay)
			{
				dynamic_cast<Explosion&>(our_map->get_reference(row, col)).set_time_left(my_settings.explosion_delay);
				distance --;
			}
			else
			{
				distance --;
			}
		}
		// Current place is item or empty tile
		else 
		{
			explode(row, col, false);
			distance --;
		}
	}
}


/*
* Character& get_creator()
* Fetches a pointer to the creator of this bomb.
*/
Character& Bomb::get_creator()
{
	return *my_creator;
}