
#ifndef EXPLOSION_H
#define EXPLOSION_H
class Explosion;
#include "Game.h"
#include "Item.h"
#include "Timer.h"
#include <memory>

class Explosion
{
    public:
    Explosion(int row, int col, Timer explosion_timer, bool has_item, std::shared_ptr<Game> our_game);
	~Explosion();
	
	void update();
	
	private:
	int row{};
	int col{};
	bool has_item{};
	std::shared_ptr<Game> my_game;
	Timer explosion_timer;
	
	void make_item();
};

#endif