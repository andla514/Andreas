
#ifndef CHARACTER_H
#define CHARACTER_H
#include "Bomb.h"
#include "Game.h"
#include <string>
#include <memory>

//bara sålänge kontrollerna initializeras här
//#include "SFML/Graphics.hpp"

class Character
{
    public:
    Character();
	~Character() = default;
	Character(std::shared_ptr<Game>);
	//Character(std::shared_prt<Game> our_game, int player_number);
	
	void add_bomb(int number);
	int get_col() const;
	int get_row() const;
	void increase_exp_rad(int number);
	void increase_exp_time(int number);
	void update();
	void hurt_player();
	void smooth_move();
	void use_item(Item pickup);
	void lay_bomb();
	void move_player();
	
	private:
	std::shared_ptr<Game> game_ptr{};
	int life{2};
	int bombs{1};
	int col{};
	int row{};
	int player_number{};
	//struct Bomb_settings{3, 5, 3};
	bool is_moving{false};
	bool is_immortal{false};
};

#endif