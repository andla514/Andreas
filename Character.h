
#ifndef CHARACTER_H
#define CHARACTER_H
#include "Bomb.h"
#include "Game.h"
#include <string>
#include <memory>
//#include "SFML/Graphics.hpp" //bara sålänge kontrollerna initializeras här

class Character
{
    public:
    Character();
	~Character() = default;
	Character(std::shared_ptr<Game>);
	
	//Character(shared_prt<Game> our_game, int player_number);
	void add_bomb(int number);
	int get_col() const;
	int get_row() const;
	void increase_exp_rad(int number);
	void update();
	void hurt_player();
	void smooth_move();
	void use_item(Item pickup);
	void lay_bomb();
	//void set_ypos(int y);
	//void set_pos(int x);

	//void move_player();
	
	private:
	std::shared_ptr<Game> game_ptr{};
	/*
	std::string up{};//sf::Keyboard::W};
	std::string down{};//sf::Keyboard::S};
	std::string left{};//sf::Keyboard::A};
	std::string right{};//sf::Keyboard::D};
	std::string place_bomb{};
	*/
	int life{};
	int bombs{};
	int col{};
	int row{};
	struct Bomb_settings{3, 5, 3};
	bool is_moving{false};
	bool is_immortal{false};
};

#endif