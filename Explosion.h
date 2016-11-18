
#ifndef EXPLOSION_H
#define EXPLOSION_H
class Explosion;
#include "Game.h"
#include "Item.h"
#include "Timer.h"
#include <memory>
#include <stdlib.h>

class Explosion
{
    public:
    Explosion(int row_pos, int col_pos, int explosion_delay, bool was_box, std::shared_ptr<Game> our_game);
	~Explosion()= default;
	
	void update();
	int time_left();
	bool get_was_box() const; 

	private:
	int row{};
	int col{};
	Timer explosion_timer;
	bool was_box{};
	std::shared_ptr<Game> my_game{nullptr};
	
	
	void make_item();
};

#endif