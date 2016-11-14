#include "Explosion.h"

//-----------------CONSTRUCTOR--------------
Explosion::Explosion(int row, int col, Timer explotion_timer, bool has_item, std::shared_ptr<Game> our_game)
	: row{row}, col{col}, explosion_timer{explosion_timer}, has_item{has_item}, my_game{my_game}
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
void Explosion::make_item()
{
	int random_value {rand() % 100};
	
	if (random_value >= 0 && random_value < 100)
	{
		//Item temp_item = item1(row, col);
	}
	//my_game->add_item(temp_item);
}

void Explosion::update()
{
	if (explosion_timer.is_done())
		my_game->remove_explosion(row, col);
}
