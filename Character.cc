#include "Game.h"
#include "Character.h"
#include "Bomb.h"
#include <stdio.h>
#include "SFML/Graphics.hpp"

//-----------------CONSTRUCTOR--------------
Character::Character()
{}

Character(shared_prt<Game> our_game, int player_number)
{
	switch(player_number)
	{
		case 1:
			up = "sf::Keyboard::W";
			down = "sf::Keyboard::S";
			left = "sf::Keyboard::A";
			right = "sf::Keyboard::D";
			xpos = 1;
			ypos = 1;
			break;
		case 2:
			up = '8';
			down = '5';
			left = '4';
			right = '6';
			xpos = our_game.get_columns() - 1;
			ypos = our_game.get_rows() - 1;
			break;
		case 3:
			up = "sf::Keyboard::Numpad8";
			down = "sf::Keyboard::Numpad5";
			left = "sf::Keyboard::Numpad4";
			right = "sf::Keyboard::Numpad6";
			xpos = our_game.get_columns() - 1;
			ypos = our_game.get_rows() - 1;
	
	
}

void Character::move_player()
{
	
	
	
	
	
}
