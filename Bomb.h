#ifndef BOMB_H
#define BOMB_H
class Bomb;
#include "Game.h"
#include "Character.h"
#include "Game.h"
#include "Character.h"
#include "Explosion.h"
#include "Timer.h"
#include <memory>
#include <string>
#include <stdexcept>
struct Bomb_settings
{
	int radius;
	int detonation_delay;
	int explosion_delay;
};

class Bomb
{
    public:
	// Constructor/destructor
    Bomb(int row, int col, Bomb_settings our_settings, std::shared_ptr<Game> ourgame,
	int my_creator);
	~Bomb() = default;
	
	void update();
	void detonate();
	
	
	private:
	int row_pos{};
	int col_pos{};
	Bomb_settings my_settings;
	Timer detonation_timer;
	std::shared_ptr<Game> my_game{nullptr};
	int my_creator{};
	
	// Private functions
	void spread_explosions(std::string direction, int distance);
	//Character& get_creator();	
};



#endif