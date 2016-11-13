//#include <stdio.h>
#include <memory>
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Character.h"
#include "Bomb.h"

#include <utility> //bara för move i testkonstruktorn

//-----------------CONSTRUCTOR--------------
Character::Character()
{}

/*
//Testkonstruktor
Character::Character(std::shared_prt<Game> our_game)
	:bombs{1}, xpos{1}, ypos{1}, our_game{std::move(our_game)}
    up{sf::Keyboard::W}, down{"sf::Keyboard::S"}, left{"sf::Keyboard::A"},
	right{"sf::Keyboard::D"}, place_bomb{"sf::Keyboard::Tab"}, bombs{1}, xpos{1}, ypos{1}, 
	our_game{std::move(our_game)}

	{}
*/

//Behöver operatoröverlagring på game (=)
/*
Character(std::shared_prt<Game> our_game, int player_number)
{
	switch(player_number)
	{
		case 1:
			up = "sf::Keyboard::W";
			down = "sf::Keyboard::S";
			left = "sf::Keyboard::A";
			right = "sf::Keyboard::D";
			place_bomb = "sf::Keyboard::Tab";
			game_ptr = our_game;
			bombs = 1;
			life = 2;
			xpos = 1;
			ypos = 1;
			break;
		case 2:
			up = 'sf::Keyboard::Up';
			down = 'sf::Keyboard::Down';
			left = 'sf::Keyboard::Left';
			right = 'sf::Keyboard::Right';
			place_bomb = "sf::Keyboard::RShift";
			game_ptr = our_game;
			bombs = 1;
			life = 2;
			xpos = our_game.get_columns() - 1;
			ypos = our_game.get_rows() - 1;
			break;
		case 3:
			up = "sf::Keyboard::Numpad8";
			down = "sf::Keyboard::Numpad5";
			left = "sf::Keyboard::Numpad4";
			right = "sf::Keyboard::Numpad6";
			place_bomb = "sf::Keyboard::Add";
			game_ptr = our_game;
			bombs = 1;
			life = 2;
			xpos = our_game.get_columns() - 1;
			ypos = our_game.get_rows() - 1;
		case 4:
			up = "sf::Keyboard::T";
			down = "sf::Keyboard::G";
			left = "sf::Keyboard::F";
			right = "sf::Keyboard::H";
			place_bomb = "sf::Keyboard::M";
			game_ptr = our_game;
			bombs = 1;
			life = 2;
			xpos = our_game.get_columns() - 1;
			ypos = our_game.get_rows() - 1;	
}
*/

//-----------------FUNCTION--------------
int Character::get_col()
{
	return col;
}
int Character::get_row()
{
	return row;
}

void Character::move_player()
{

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) )//&& game_ptr->can_move_to(col, row - 1))
	{
		row = row - 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) )//&& game_ptr->can_move_to(col, row + 1))
	{
		row = row + 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) )//&& game_ptr->can_move_to(col - 1, row))
	{
		col = col - 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) )//&& game_ptr->can_move_to(col + 1, row))
	{
		col = col + 1;
	}
}
