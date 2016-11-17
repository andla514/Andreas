#include "Bomb.h"
#include <iostream>

//-----------------CONSTRUCTOR--------------
Bomb::Bomb(int row, int col, Bomb_settings our_settings, std::shared_ptr<Game> our_game,
	int my_creator)
	: row_pos{row}, col_pos{col},my_settings{our_settings.radius, our_settings.detonation_delay, our_settings.explosion_delay}, 
		detonation_timer{Timer(our_settings.detonation_delay)}, my_game{our_game}, my_creator{my_creator}
{}


void Bomb::update()
{
	if (detonation_timer.is_done())
		detonate();
}

// Calculate and creates explosions in the correct places
void Bomb::detonate()
{
	spread_explosions ("right", my_settings.radius);
	spread_explosions ("left", my_settings.radius);
	spread_explosions ("up", my_settings.radius);
	spread_explosions ("down", my_settings.radius);
	get_creator().add_bomb(1);
}

void Bomb::spread_explosions (std::string direction, int distance)
{
	int row{row_pos};
	int col{col_pos};
	
	while (distance > 0)
	{
		if (my_game->is_wall(row, col))
		{
			distance = 0;
		}
		else if (my_game->is_box(row, col))
		{
			my_game->set_element(row, col, 4);
			my_game->add_explosion(row, col, Explosion(row, col, my_settings.explosion_delay,
									true, my_game));
			distance = 0;
			std::cout << "Explosion" << row << col;   // Felsök
		}
/*		else if (my_game->is_bomb(row,col))
		{
			my_game->get_bomb_reference->detonate();
			my_game->remove_bomb(row, col);
			my_game->add_explosion(row, col, Explosion(row, col, my_settings.explosion_delay,
									false, my_game));
			distance --;
		}
		*/
		else if (my_game->is_standing_on_item(row, col))
		{
			my_game->set_element(row, col, 4);
			//my_game->remove_item(row, col);
			my_game->add_explosion(row, col, Explosion(row, col, my_settings.explosion_delay,
									false, my_game));
			distance --;
			std::cout << "Explosion" << row << col;   // Felsök
		}
		//Lägg till fall då en explosion överlappar en annan.
		else 
		{
			my_game->set_element(row, col, 4);
			my_game->add_explosion(row, col, Explosion(row, col, my_settings.explosion_delay,
									false, my_game));
			distance --;
			std::cout << "Explosion" << row << col;   // Felsök
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