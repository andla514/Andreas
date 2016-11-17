
#ifndef CHARACTER_H
#define CHARACTER_H
class Character;
#include "Bomb.h"
#include "Game.h"
#include <string>
#include <memory>
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
	void hurt_player();
	void smooth_move();
	void use_item(Item pickup);
	void make_bomb();
	void move_player();
	
	private:
	sf::Keyboard::Key  up;
	sf::Keyboard::Key down;
	sf::Keyboard::Key left;
	sf::Keyboard::Key right;
	sf::Keyboard::Key bomb;
	std::shared_ptr<Game> game_ptr{};
	int life{2};
	int bombs{1};
	int col{1};
	int row{1};
	int player_number{};
	//struct Bomb_settings{3, 5, 3};
	bool is_moving{false};
	bool is_immortal{false};
};

#endif