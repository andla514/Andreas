
#ifndef EXPLOSION_H
#define EXPLOSION_H
class Explotion;
#include "Game.h"
#include "Item.h"
#include "Timer.h"

class Explosion
{
    public:
    Explosion(int row, int col, Timer explotion_timer, bool has_item, std::shared_ptr<Game> our_game);
	~Explotion();
	
	void update();
	
	private:
	int row{};
	int col{};
	bool has_item{};
	std::shared_ptr<Game> my_game;
	*Timer explotion_timer;
	
	void make_item();
};

#endif