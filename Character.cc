//#include <stdio.h>
#include <memory>
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Character.h"
#include "Bomb.h"
#include "Item.h"
#include "Timer.h"

#include <iostream> //Används ej? felsökning
//#include <utility>  //bara för move i testkonstruktorn

//-----------------CONSTRUCTOR--------------
Character::Character()
{
}

Character::Character(std::shared_ptr<Game> our_game, int player_number)
    : game_ptr{our_game}, player_number{player_number}
{
	set_keys(player_number);
}

void Character::set_keys(int player_number)
{
/*
move_dir: 
1 => up
2 => down
3 => left
4 => right
*/

    switch (player_number)
    {
    case 1:
	col = 1;
	row = 1;	
	xpos = col * 64;
	ypos = row * 64;
	up = sf::Keyboard::W;
	down = sf::Keyboard::S;
	left = sf::Keyboard::A;
	right = sf::Keyboard::D;
	bomb = sf::Keyboard::Tab;
	move_dir = 2;
	break;

    case 2:
	col = game_ptr->get_columns() - 2;
	row = game_ptr->get_rows() - 2;
	xpos = col * 64;
	ypos = row * 64;
	up = sf::Keyboard::Up;
	down = sf::Keyboard::Down;
	left = sf::Keyboard::Left;
	right = sf::Keyboard::Right;
	bomb = sf::Keyboard::RShift;
	move_dir = 1;
	break;

    case 3:
	col = game_ptr->get_columns() - 2;
	row = 1;
	xpos = col * 64;
	ypos = row * 64;
	up = sf::Keyboard::Numpad8;
	down = sf::Keyboard::Numpad5;
	left = sf::Keyboard::Numpad4;
	right = sf::Keyboard::Numpad6;
	bomb = sf::Keyboard::Add;
	move_dir = 2;
	break;

    case 4:
	col = 1;
	row = game_ptr->get_rows() - 2;
	xpos = col * 64;
	ypos = row * 64;
	up = sf::Keyboard::T;
	down = sf::Keyboard::G;
	left = sf::Keyboard::F;
	right = sf::Keyboard::H;
	bomb = sf::Keyboard::Space;
	move_dir = 1;
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
			game_ptr->set_element(row, col, 0);
		}
    }
}

void Character::draw_graphics(sf::RenderWindow &our_window)
{
    // TODO
	sf::CircleShape ball{32};
	ball.setFillColor(sf::Color::Blue);
	ball.setTextureRect(sf::IntRect{0, 0, 64, 64});
	ball.setPosition(xpos, ypos);
	our_window.draw(ball);
}

void Character::make_bomb()
{
    if (sf::Keyboard::isKeyPressed(bomb) )//&& bombs > 0 && !(is_immortal))
    {
		game_ptr->set_element(row, col, 3);
		Bomb_settings settings{2, 2, 1};
		game_ptr->add_bomb(row, col, std::make_unique<Bomb>(row, col, settings, game_ptr, player_number));
	//anropa bomb-construktor
    }
}

void Character::use_item(Item &pickup)
{
    //pickup.give_power_up(*this)
}

void Character::smooth_move()
{
	/*
	move_dir: 
	1 => up
	2 => down
	3 => left
	4 => right
	*/
	double time{my_timer.elapsed_time() / walk_time};
	int curr_step = step * time;

/*
	if(my_timer.is_done() && sf::Keyboard::isKeyPressed(last_key))
	{
		is_moving = true;
		my_timer.restart();
		xpos = 64 * col;
		ypos = 64 * row;
		step = 64;
	}
	*/
	if(my_timer.is_done())
	{
		is_moving = false;
		xpos = 64 * col;
		ypos = 64 * row;
		step = 64;
	}
	else if(move_dir == 1)
	{
		ypos -= curr_step;
	}
	else if(move_dir == 2)
	{
		ypos += curr_step;
	}
	else if(move_dir == 3)
	{
		xpos -= curr_step;
	}
	else if(move_dir == 4)
	{
		xpos += curr_step;
	}

	step -= curr_step;
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
	else if (col_inc == 0 && row_inc != 0 && game_ptr->can_move_to(row + row_inc, col))
    {
		std::cout << "fall 1";
		row += row_inc;
		is_moving = true;
		my_timer.restart();

    }
	else if (col_inc != 0 && row_inc == 0 && game_ptr->can_move_to(row, col + col_inc))
    {
		std::cout << "fall 2";
		col += col_inc;
		is_moving = true;
		my_timer.restart();

    }
    else if (game_ptr->can_move_to(row + row_inc, col) && !(game_ptr->can_move_to(row, col + col_inc)))
    {
		std::cout << "row_inc: " << row_inc << " col_inc: " << col_inc << " fall 3 \n";
		row += row_inc;
		is_moving = true;
		my_timer.restart();
    }
    else if (game_ptr->can_move_to(row, col + col_inc) && !(game_ptr->can_move_to(row + row_inc, col)))
    {
		std::cout << "fall 4";
		col += col_inc;
		is_moving = true;
		my_timer.restart();
    }
	else
	{
			is_moving = false;
	}
	/*
	move_dir: 
	1 => up
	2 => down
	3 => left
	4 => right
	*/


	if(col_inc > 0)
	{
		move_dir = 4;
		//last_key = sf::Keyboard::Key(right);
	}
	else if(col_inc < 0)
	{
		move_dir = 3;
		//last_key = sf::Keyboard::Key(left);
	}
	else if(row > 0)
	{
		move_dir = 2;
		//last_key = sf::Keyboard::Key(down);
		
	}
	else if(row < 0)
	{
		move_dir = 1;
		//last_key = sf::Keyboard::Key(up);
	}

}
