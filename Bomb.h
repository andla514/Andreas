#ifndef BOMB_H
#define BOMB_H
class Bomb;
struct Bomb_settings
{
	int radius;
	int detonation_delay;
	int explosion_delay;
};
#include "Game.h"
#include "Tile.h"
#include "Character.h"
#include "Explosion.h"
#include "Matrix_Map.h"
#include "Timer.h"
#include <memory>
#include <string>
#include <stdexcept>

class Bomb: public Tile
{
    public:
	// Constructor/destructor
    Bomb(int row, int col, Bomb_settings our_settings, std::shared_ptr<Matrix_Map> our_map,
	Character* my_creator);
	~Bomb() override = default;
	
	void update() override;
	void detonate();
	
	private:
	int row_pos{};
	int col_pos{};
	Bomb_settings my_settings;
	Timer detonation_timer;
	std::shared_ptr<Matrix_Map> our_map{nullptr};
	Character* my_creator;
	
	// Private functions
	void explode(int row, int col, bool item_bool);
	void spread_explosions(std::string direction, int distance);
	Character& get_creator();	
};



#endif