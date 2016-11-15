#include "Explosion.h"

//-----------------CONSTRUCTOR--------------
Explosion::Explosion(int row, int col, int explosion_delay, bool has_item, std::shared_ptr<Game> our_game)
	: row{row}, col{col}, explosion_timer{Timer(explosion_delay)}, has_item{has_item}, my_game{our_game}
{}

//-----------------Destructor---------------
Explosion::~Explosion()
{
	if (has_item)
	{
		my_game->set_element(row, col, 2);
		make_item();
	}
	else
	{
		my_game->set_element(row, col, 0);
	}
}

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
		//Item temp_item = Item_Inc_Bomb(row, col);
	}
	else if (random_value >= 30 && random_value < 70)
	{
		//Item temp_item = Item_Inc_Rad(row, col);
	}
	else if (random_value >= 70 && random_value < 80)
	{
		//Item temp_item = Item_Inc_Life(row, col);
	}
	else if (random_value >= 80 && random_value < 100)
	{
		//Item temp_item = Item_Inc_Exp_Timer(row, col);
	}
	//my_game->add_item(temp_item);
	//my_game->set_element(row, col, 2);
}

/*
* void update()
* Checks the timer if its time to disperse
*/
void Explosion::update()
{
	if (explosion_timer.is_done())
		my_game->remove_explosion(row, col);
}
