
#ifndef EXPLOSION_H
#define EXPLOSION_H
#include "Game.h"
#include "Item.h"

class Explosion
{
    public:
    Explosion(int row, int col, bool has_item, std::shared_ptr<Game> our_game);
	~Explotion();
	
	void update();
	
	private:
	int row{};
	int col{};
	bool has_item{};
	std::shared_ptr<Game> my_game;
	
	void make_item();
};

#endif