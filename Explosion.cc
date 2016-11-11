#include "Game.h"
#include "Explosion.h"

//-----------------CONSTRUCTOR--------------
Explosion::Explosion(int row, int col, bool has_item, std::shared_ptr<Game> our_game)
	: row{row}, col{col}, has_item{has_item}, my_game{my_game}
{}

//-----------------Destructor---------------
Explotion::~Explotion()
{
	if (has_item)
	{
		my_game.set_element(row, col, 2);
		make_item(row,col);
	}
	else
	{
		my_game.set_element(row, col, 0);
	}
	my_game.remove_explotion_at(row, col);
}

//-----------------Functions----------------
void Explotion::make_item()
{
	int random_value {rand() % 100};
	
	if (random value >= 0 && random_value < 100)
	{
		Item temp_item = item1(row, col);
	}
	my_game.add_item(temp_item);
}

void Explotion::update()
{}
