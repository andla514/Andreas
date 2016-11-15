#include "Explosion.h"

//-----------------CONSTRUCTOR--------------
Explosion::Explosion(int row, int col, int explosion_delay, bool has_item, Game* our_game)
	: row{row}, col{col},explosion_timer{Timer(2)}, has_item{has_item}, my_game{my_game}
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
	
	if (random_value >= 0 && random_value < 100)
	{
		//Item temp_item = item1(row, col);
	}
	//my_game->add_item(temp_item);
	//my_game->set_element(row, col, 2);
}

void Explosion::update()
{
	if (explosion_timer.is_done())
		my_game->remove_explosion(row, col);
}
