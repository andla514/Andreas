
#ifndef EXPLOSION_H
#define EXPLOSION_H
class Explosion;
#include "Tile.h"
#include "Matrix_Map.h"
#include "Item.h"
#include "Timer.h"
#include <memory>
#include <stdlib.h>

class Explosion: public Tile
{
    public:
    Explosion(int row_pos, int col_pos, int explosion_delay, bool was_box, std::shared_ptr<Matrix_Map> our_map);
	~Explosion() override = default;
	
	void update() override;
	int time_left();
	bool get_was_box() const; 
	void set_time_left(double time_left);

	private:
	int row{};
	int col{};
	Timer explosion_timer;
	bool was_box{};
	std::shared_ptr<Matrix_Map> our_map{nullptr};
	
	
	void make_item();
};

#endif