#include "Explosion.h"
#include <iostream>
#include <memory>

//-----------------CONSTRUCTOR--------------
Explosion::Explosion(int row_pos, int col_pos, int explosion_delay, bool was_box, std::shared_ptr<Matrix_Map> our_map)
	: row{row_pos}, col{col_pos}, explosion_timer{Timer(explosion_delay)}, was_box{was_box}, our_map{our_map}
{}


//-----------------Functions----------------

/*
*	void make_item()
*	Randomly selects which item to create and adds it in Game's item list.
*/
void Explosion::make_item()
{
	int random_value {rand() % 100};
	if (random_value >= 0 && random_value < 30)
	{
		our_map->make_object(row, col, std::make_unique<Item_Inc_Bombs>(row, col));
	}
	else if (random_value >= 30 && random_value < 70)
	{
		our_map->make_object(row, col, std::make_unique<Item_Inc_Exp_Rad>(row, col));
	}
	else if (random_value >= 70 && random_value < 80)
	{
		our_map->make_object(row, col, std::make_unique<Item_Inc_Life>(row, col));
	}
	else if (random_value >= 80 && random_value < 100)
	{
		our_map->make_object(row, col, std::make_unique<Item_Inc_Exp_Time>(row, col));
	}
}

/*
* void update()
* Checks the timer if its time to disperse
*/
void Explosion::update()
{
	if (explosion_timer.is_done())
	{
		int random_value {rand() % 100};
		if (was_box && random_value <= 60)
		{
			make_item();
		}
		else
		{
			our_map->remove_object(row, col);
		}
	}
}

/*
* int time_left()
* Returns the time left on explosion_timer
*/
int Explosion::time_left()
{
	return explosion_timer.time_left();
}

void Explosion::set_time_left(double time_left)
{
	explosion_timer = Timer{time_left};
}

/*
* bool get_was_box()
* Returns vas_box
*/
bool Explosion::get_was_box() const
{
	return was_box;
}