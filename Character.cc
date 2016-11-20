//#include <stdio.h>
#include <memory>
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Character.h"
#include "Bomb.h"
#include "Item.h"

//#include <iostream> //Används ej?
//#include <utility>  //bara för move i testkonstruktorn

//-----------------CONSTRUCTOR--------------
Character::Character()
{
}

Character::Character(std::shared_ptr<Game> our_game, int player_number)
    : game_ptr{our_game}, player_number{player_number}
{
    switch (player_number)
    {
    case 1:
	col = 1;
	row = 1;
	up = sf::Keyboard::W;
	down = sf::Keyboard::S;
	left = sf::Keyboard::A;
	right = sf::Keyboard::D;
	bomb = sf::Keyboard::Tab;
	break;

    case 2:
	col = our_game->get_columns() - 2;
	row = our_game->get_rows() - 2;
	up = sf::Keyboard::Up;
	down = sf::Keyboard::Down;
	left = sf::Keyboard::Left;
	right = sf::Keyboard::Right;
	bomb = sf::Keyboard::Tab;
	break;

    case 3:
	col = our_game->get_columns() - 2;
	row = 1;
	up = sf::Keyboard::Numpad8;
	down = sf::Keyboard::Numpad5;
	left = sf::Keyboard::Numpad4;
	right = sf::Keyboard::Numpad6;
	bomb = sf::Keyboard::Tab;
	break;

    case 4:
	col = 1;
	row = our_game->get_rows() - 2;
	up = sf::Keyboard::T;
	down = sf::Keyboard::G;
	left = sf::Keyboard::F;
	bomb = sf::Keyboard::Tab;
	break;
    }
}

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
    if (life > 0)
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

		make_bomb();

		if (game_ptr->is_standing_on_item(row, col))
		{
	    	use_item(game_ptr->get_item_reference(row, col));
			game_ptr->remove_item(row, col);
		}
    }
}

void Character::draw_graphics(sf::RenderWindow & our_window)
{
	sf::CircleShape ball{32};
	ball.setFillColor(sf::Color::Blue);
	ball.setTextureRect(sf::IntRect{0, 0, 64, 64});
	ball.setPosition(col * 64, row * 64);
	our_window.draw(ball);
}

void Character::make_bomb()
{
    if (sf::Keyboard::isKeyPressed(bomb) )//&& bombs > 0 && !(is_immortal))
    {
		Bomb_settings settings{2, 2, 1};
		game_ptr->add_bomb(row, col, std::make_unique<Bomb>(row, col, settings, game_ptr, player_number));
	//anropa bomb-construktor
    }
}

void Character::use_item(Item & pickup)
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
    int col_inc{0};
	int row_inc{0};

    if (sf::Keyboard::isKeyPressed(up))
    {
		row_inc -= 1;
    }
    if (sf::Keyboard::isKeyPressed(down))
    {
		row_inc += 1;
    }
    if (sf::Keyboard::isKeyPressed(left))
    {
		col_inc -= 1;
    }
    if (sf::Keyboard::isKeyPressed(right))
    {
		col_inc += 1;
    }

    if (col_inc == 0 && row_inc == 0)
    {
		is_moving = false;
    }
    else if((col_inc == 0 || row_inc == 0) && game_ptr->can_move_to(row + row_inc, col + col_inc))
    {
		row += row_inc;
		col += col_inc;
		is_moving = true;
    } else if(game_ptr->can_move_to(row + row_inc, col))
	{
		row += row_inc;
		is_moving = true;
	} else if(game_ptr->can_move_to(row, col + col_inc))
	{
		col += col_inc;
		is_moving = true;
	}

}
