
#ifndef CHARACTER_H
#define CHARACTER_H
#include "Game.h"
#include "Bomb.h"
#include <string>

class Character
{
    public:
    Character();
	Character(shared_prt<Game> our_game, int player_number);
	get_pos();
	
	
	void move_player();
	
	private:
	
	std::string up{};
	std::string down{};
	std::string left{};
	std::string right{};
	int xpos{};
	int ypos{};
};

#endif