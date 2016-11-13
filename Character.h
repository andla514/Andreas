
#ifndef CHARACTER_H
#define CHARACTER_H
#include "Game.h"
#include "Bomb.h"
#include <string>
#include <memory>
//#include "SFML/Graphics.hpp" //bara sålänge kontrollerna initializeras här

class Character
{
    public:
    Character();
	//Character(std::shared_ptr<Game>);
	
	//Character(shared_prt<Game> our_game, int player_number);
	int get_col();
	int get_row();
	//void set_ypos(int y);
	//void set_pos(int x);

	void move_player();
	
	private:
	//std::shared_ptr<Game> game_ptr{};
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
};

#endif