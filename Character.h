
#ifndef CHARACTER_H
#define CHARACTER_H
class Character;
#include "Bomb.h"
#include "Game.h"
#include "Item.h"
#include <string>
#include <memory>
#include "Timer.h"
#include "SFML/Graphics.hpp"

class Character
{
    public:
    Character();
	~Character() = default;
	Character(std::shared_ptr<Game> our_game, int player_number);
	
	void add_bomb(int number);
	int get_col() const;
	int get_row() const;
	void increase_exp_rad(int number);
	void increase_exp_time(int number);
	void update();
	void draw_graphics(sf::RenderWindow &);
	void hurt_player();
	void smooth_move();
	void use_item(Item & pickup);
	void make_bomb();
	void move_player();
	
	private:
	void set_keys(int player_number);
	sf::Keyboard::Key  up;
	sf::Keyboard::Key down;
	sf::Keyboard::Key left;
	sf::Keyboard::Key right;
	sf::Keyboard::Key bomb;
	std::shared_ptr<Game> game_ptr{};
	int move_dir{};
	int life{2};
	int bombs{1};
	int col{1};
	int row{1};
	int xpos{1};
	int ypos{1};
	int step{64};
	double walk_time {0.3};
	Timer my_timer{walk_time}; 
	int player_number{};
	//struct Bomb_settings{3, 5, 3};
	bool is_moving{false};
	bool is_immortal{false};
};

#endif