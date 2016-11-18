#include "Explosion.h"
#include <iostream>
#include <memory>

//-----------------CONSTRUCTOR--------------
Explosion::Explosion(int row, int col, int explosion_delay, bool was_box, std::shared_ptr<Game> our_game)
	: row{row}, col{col}, explosion_timer{Timer(explosion_delay)}, was_box{was_box}, my_game{our_game}
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
		//my_game->add_item(make_unique<Item>(Item_Inc_Bomb(row, col));
	}
	else if (random_value >= 30 && random_value < 70)
	{
		//my_game->add_item(make_unique<Item>(Item_Inc_Rad(row, col));
	}
	else if (random_value >= 70 && random_value < 80)
	{
		//my_game->add_item(make_unique<Item>(Item_Inc_Life(row, col)));
	}
	else if (random_value >= 80 && random_value < 100)
	{
		//my_game->add_item(make_unique>Item>(Item_Inc_Exp_Timer(row, col));
	}
	
	my_game->set_element(row, col, 2);
	std::cout << "Lägger ett item";
}

/*
* void update()
* Checks the timer if its time to disperse
*/
void Explosion::update()
{
	if (explosion_timer.is_done())
	{
		my_game->remove_explosion(row, col);
	
		int random_value {rand() % 100};
	
		if (was_box && random_value <= 30)
		{
			my_game->set_element(row, col, 2);
			make_item();
		}
		else
		{
			my_game->set_element(row, col, 0);
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