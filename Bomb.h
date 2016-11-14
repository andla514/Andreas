#ifndef BOMB_H
#define BOMB_H
class Bomb;
#include "Game.h"
#include "Explosion.h"
#include "Item.h"
#include "Timer.h"

class Bomb
{
    public:
    Bomb(int row, int col, Bomb_settings our_settings, std::shared_ptr<Game> ourgame,
	std::shared_ptr<Character> my_creator);
	~Bomb() = default;
	
	struct Bomb_settings;
	
	void update();
	void detonate();
	
	
	private:
	int row_pos{};
	int col_pos{};
	Bomb_settings my_settings{};
	std::shared_ptr<Game> my_game{};
	std::shared_ptr<Character> my_creator{};
	*Timer detonation_timer;
	
	void spread_explotions(std::string direction, int distance);
	void box_spawn(int row, int col);
	
};

struct Bomb_settings
{
	int radius;
	int detonation_delay;
	int explotion_delay;
};

#endif