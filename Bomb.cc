#include "Bomb.h"
#include "Game.h"
#include "Explosion.h"
#include "Item.h"

//-----------------CONSTRUCTOR--------------
Bomb::Bomb(int row, int col, Bomb_settings our_settings, std::shared_ptr<Game> our_game,
	std::shared_ptr<Character> my_creator)
	: row-pos{row}, col-pos{col}, my_settings{our_settings}, my_game{our_game}, 
	my_creator{my_creator}, detonation_timer{Timer(my_settings.detonation_timer)}
{}


void Bomb::update()
{
	if (detonation_timer.is_done())
		detonate();
}

// Calculate and creates explotions in the correct places
void Bomb::detonate()
{
	spread_explotions (right, radius);
	spread_explotions (left, radius);
	spread_explotions (up, radius);
	spread_explotions (down, radius);
}

void Bomb::spread_explotions (std::string direction, int distance)
{
	int row{row_pos};
	int col{col_pos};
	
	while (distance > 0)
	{
		if (my_game.is_wall(row, col))
		{
			distance = 0;
		}
		else if (my_game.is_box(row,col))
		{
			box_spawn(row, col);
			distance = 0;
		}
		else 
		{
			my_game.set_element(row, col, 4);
			Explotion(row, col, Timer(my_settings.explotion_delay()), false, my_game)
			distance--;
		}
		
		if (direction = "right")
			col ++;
		else if (direction = "left")
			col --;
		else if (direction = "up")
			row --;
		else if (direction = "down")
			row ++;
		else
			throw logic_error("Invalid direction");
	}
}

void Bomb::box_spawn(int row, int col)
{
	int random_value {rand() % 100}
	if (random_value < 30)
		Explotion(row, col, Timer(my_settings.explotion_delay()), true, my_game)
	else
		Explotion(row, col, Timer(my_settings.explotion_delay()), false, my_game)
}
	