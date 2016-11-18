#include "Bomb.h"
#include <iostream>
#include <memory>

//-----------------CONSTRUCTOR--------------
Bomb::Bomb(int row, int col, Bomb_settings our_settings, std::shared_ptr<Game> our_game,
	int my_creator)
	: row_pos{row}, col_pos{col},my_settings{our_settings.radius, our_settings.detonation_delay, our_settings.explosion_delay}, 
		detonation_timer{Timer(our_settings.detonation_delay)}, my_game{our_game}, my_creator{my_creator}
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
	my_game->remove_bomb(row_pos, col_pos);
}

/*
* void explode (int row, int col, bool item_bool)
* Creates a Explosion object
*/
void Bomb::explode(int row, int col, bool item_bool)
{
	my_game->set_element(row, col, 4);
	my_game->add_explosion(row, col, (std::make_unique<Explosion>(row, col, my_settings.explosion_delay,
										item_bool, my_game)));
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
	
	while (distance > 0)
	{
		// Current place is a wall
		if (my_game->is_wall(row, col))
		{
			distance = 0;
		}
		// Current place is a box
		else if (my_game->is_box(row, col))
		{
			explode(row, col, true);
			distance = 0;
		}
		// Current place is a bomb
		else if (my_game->is_bomb(row, col) && distance != my_settings.radius)
		{
			(my_game->get_bomb_reference(row, col)).detonate();
			my_game->remove_bomb(row, col);
			explode(row, col, false);
			distance --;
		}
		// Current place is an item
		else if (my_game->is_standing_on_item(row, col))
		{
			explode(row, col, false);
			my_game->remove_item(row, col);
			distance --;
		}
		// Current place is an explosion
		else if (my_game->is_standing_in_fire(row, col))
		{
			if ((my_game->get_explosion_reference(row, col)).time_left() <= 1000 * my_settings.explosion_delay)
			{
				bool temp = (my_game->get_explosion_reference(row, col)).get_was_box();
				my_game->remove_explosion(row, col);
				my_game->add_explosion(row, col, std::make_unique<Explosion>(Explosion(row, col, my_settings.explosion_delay,
									temp, my_game)));
				distance --;
			}
			else
				distance --;
		}	
		else 
		{
			explode(row, col, false);
			distance --;
		}
		
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
	}
}


/*
* Character& get_creator()
* Fetches a pointer to the creator of this bomb.
*/
Character& Bomb::get_creator()
{
	return my_game->get_character_reference(my_creator);
}