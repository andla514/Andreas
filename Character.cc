//#include <stdio.h>
#include <memory>
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Character.h"
#include "Bomb.h"

#include <iostream> //Används ej?
#include <utility>  //bara för move i testkonstruktorn

//-----------------CONSTRUCTOR--------------
Character::Character()
{
}

/*
//Testkonstruktor
Character::Character(std::shared_prt<Game> our_game)
	: game_ptr{std::move(our_game)}, col{1}, row{1}, player_number{1}
{
}
*/	
	//: bombs{1}, col{1}, row{1}, life{2}, game_ptr{std::move(our_game)}, player_number{1}
	//{}


/*
Character(std::shared_prt<Game> our_game, int player_number)
    : bombs{1}, col{1}, row{1}, life{2}, game_ptr{std::move(our_game)}, player_number{player_number}
{
}
*/

//-----------------FUNCTION--------------
int Character::get_col() const
{
    return col;
}
int Character::get_row() const
{
    return row;
}

void Character::add_bomb(int number)
{
    bombs += number;
}

void Character::increase_exp_rad(int number)
{
    //Bomb_settings.radius += number;
}

void Character::increase_exp_time(int number)
{
    //bomb_settings.explosion_delay += number;
}

void Character::update()
{
    if (is_moving)
    {
	smooth_move();
    }
    else
    {
	move_player();
    }

    if (game_ptr->is_standing_in_fire(row, col) && !(is_immortal))
    {
	hurt_player();
	is_immortal = true;
    }
    else if (!(game_ptr->is_standing_in_fire(row, col)))
	{
	    is_immortal = false;
	}

    lay_bomb();

    if (game_ptr->is_standing_on_item(row, col))
    {
	use_item(game_ptr->get_item_at(row, col));
    }
}

void Character::lay_bomb()
{
    switch (player_number)
    {
    case 1:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && bombs > 0 && !(is_immortal))
		{
		    //anropa bomb-construktor
		}
    case 2:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && bombs > 0 && !(is_immortal))
		{
		    //anropa bomb-construktor
		}
    case 3:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) && bombs > 0 && !(is_immortal))
		{
		    //anropa bomb-construktor
		}
    case 4:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && bombs > 0 && !(is_immortal))
		{
		    //anropa bomb-construktor
		}
    }
}

void Character::use_item(Item pickup)
{
    //pickup.give_power_up(*this)
}

void Character::smooth_move()
{
	is_moving = false;
}

void Character::hurt_player()
{
    life -= 1;
}


void Character::move_player()
{
	int curr_col{col};
	int curr_row{row};

	switch (player_number)
    {
    case 1:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && game_ptr->can_move_to(col, row - 1))
		{
			row = row - 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && game_ptr->can_move_to(col, row + 1))
		{
			row = row + 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && game_ptr->can_move_to(col - 1, row))
		{
			col = col - 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && game_ptr->can_move_to(col + 1, row))
		{
			col = col + 1;
		}
	case 2:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && game_ptr->can_move_to(col, row - 1))
		{
			row = row - 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && game_ptr->can_move_to(col, row + 1))
		{
			row = row + 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && game_ptr->can_move_to(col - 1, row))
		{
			col = col - 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && game_ptr->can_move_to(col + 1, row))
		{
			col = col + 1;
		}
	case 3:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8) && game_ptr->can_move_to(col, row - 1))
		{
			row = row - 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5) && game_ptr->can_move_to(col, row + 1))
		{
			row = row + 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4) && game_ptr->can_move_to(col - 1, row))
		{
			col = col - 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6) && game_ptr->can_move_to(col + 1, row))
		{
			col = col + 1;
		}
	case 4:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && game_ptr->can_move_to(col, row - 1))
		{
			row = row - 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && game_ptr->can_move_to(col, row + 1))
		{
			row = row + 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && game_ptr->can_move_to(col - 1, row))
		{
			col = col - 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && game_ptr->can_move_to(col + 1, row))
		{
			col = col + 1;
		}
	}

	if(curr_col == col && curr_row == row)
	{
		is_moving = false;
	}
	else 
	{
		is_moving = true;
	}
}
