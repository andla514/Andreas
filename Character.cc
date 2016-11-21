#include <memory>
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Character.h"
#include "Bomb.h"
#include "Item.h"
#include "Timer.h"
#include <stdexcept>
//#include <stdio.h>

//-----------------CONSTRUCTOR--------------
Character::Character()
{
}

Character::Character(std::shared_ptr<Game> our_game, int player_number)
    : game_ptr{our_game}, player_number{player_number}
{
	init_character(player_number);
}

void Character::init_character(int player_number)
{
/*
move_dir: 
1 => up
2 => down
3 => left
4 => right
*/
	load_textures(player_number);
    switch (player_number)
    {
    case 1:
	col = 1;
	row = 1;	
	xpos = col * step;
	ypos = row * step;
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
	xpos = col * step;
	ypos = row * step;
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
	xpos = col * step;
	ypos = row * step;
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
	xpos = col * step;
	ypos = row * step;
	up = sf::Keyboard::T;
	down = sf::Keyboard::G;
	left = sf::Keyboard::F;
	right = sf::Keyboard::H;
	bomb = sf::Keyboard::Space;
	move_dir = 1;
	break;
    }
}

//-----------------Get/Change--------------
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
void Character::add_life(int number)
{
	life += number;
}

void Character::increase_exp_rad(int number)
{
    //bomb_setting.radius += number;
}

void Character::increase_exp_time(int number)
{
    //bomb_setting.explosion_delay += number;
}

void Character::hurt_player()
{
    life -= 1;
}

int Character::index_cal(double percent, bool moving)
{
	if(!moving)
		return 0;
	else if(percent < 0 || percent > 1)
		throw std::logic_error("Percent is not in index");
	else if(percent <= 0.143)
		return 1;
	else if(percent < 0.286)
		return 2;
	else if(percent <= 0.429)
		return 3;
	else if(percent <= 0.571)
		return 4;
	else if(percent <= 0.714)
		return 5;
	else if(percent <= 0.857)
		return 6;
	else
		return 7;
}

//-----------------Update/Graphics--------------
void Character::update()
{
    if (life > 0)
    {
		if ((my_timer.is_done() && sf::Keyboard::isKeyPressed(last_key)) || !is_moving)
		{
			move_player();
		}
		else //if(is_moving)
		{
			smooth_move();
		}
		/*
		else
		{
			move_player();
		}
		*/
			
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

void Character::load_textures(int player_number)
{
	//Skriv en switch som ändrar spelarfärg beroende på nummer
	switch (player_number)
	{
		case 1:
			for(int i = 0; i <= 7; i++)
			{
					if(!back[i].loadFromFile("Textures/Bomberman/Back/Bman_B_f0" + std::to_string(i) + ".png"))
					{
						throw std::logic_error("Can't load chacaters back texture");
					}
					if(!front[i].loadFromFile("Textures/Bomberman/Front/Bman_F_f0" + std::to_string(i) + ".png"))
					{
						throw std::logic_error("Can't load chacaters front texture");
					}
					if(!side_right[i].loadFromFile("Textures/Bomberman/Right/Bman_F_f0" + std::to_string(i) + ".png"))
					{
						throw std::logic_error("Can't load chacaters right texture");
					}
					if(!side_left[i].loadFromFile("Textures/Bomberman/Left/Bman_F_f0" + std::to_string(i) + ".png"))
					{
						throw std::logic_error("Can't load chacaters left texture");
					}
			}
			break;
		case 2:
			for(int i = 0; i <= 7; i++)
			{
					if(!back[i].loadFromFile("Textures/Bomberman/Back/Bman_B_f0" + std::to_string(i) + ".png"))
					{
						throw std::logic_error("Can't load chacaters back texture");
					}
					if(!front[i].loadFromFile("Textures/Bomberman/Front/Bman_F_f0" + std::to_string(i) + ".png"))
					{
						throw std::logic_error("Can't load chacaters front texture");
					}
					if(!side_right[i].loadFromFile("Textures/Bomberman/Right/Bman_F_f0" + std::to_string(i) + ".png"))
					{
						throw std::logic_error("Can't load chacaters right texture");
					}
					if(!side_left[i].loadFromFile("Textures/Bomberman/Left/Bman_F_f0" + std::to_string(i) + ".png"))
					{
						throw std::logic_error("Can't load chacaters left texture");
					}
			}
			break;
		case 3:
			for(int i = 0; i <= 7; i++)
			{
					if(!back[i].loadFromFile("Textures/Bomberman/Back/Bman_B_f0" + std::to_string(i) + ".png"))
					{
						throw std::logic_error("Can't load chacaters back texture");
					}
					if(!front[i].loadFromFile("Textures/Bomberman/Front/Bman_F_f0" + std::to_string(i) + ".png"))
					{
						throw std::logic_error("Can't load chacaters front texture");
					}
					if(!side_right[i].loadFromFile("Textures/Bomberman/Right/Bman_F_f0" + std::to_string(i) + ".png"))
					{
						throw std::logic_error("Can't load chacaters right texture");
					}
					if(!side_left[i].loadFromFile("Textures/Bomberman/Left/Bman_F_f0" + std::to_string(i) + ".png"))
					{
						throw std::logic_error("Can't load chacaters left texture");
					}
			}
			break;
		case 4:
			for(int i = 0; i <= 7; i++)
   			{
            	if(!back[i].loadFromFile("Textures/Bomberman/Back/Bman_B_f0" + std::to_string(i) + ".png"))
            	{
                	throw std::logic_error("Can't load chacaters back texture");
            	}
				if(!front[i].loadFromFile("Textures/Bomberman/Front/Bman_F_f0" + std::to_string(i) + ".png"))
            	{
                	throw std::logic_error("Can't load chacaters front texture");
            	}
				if(!side_right[i].loadFromFile("Textures/Bomberman/Right/Bman_F_f0" + std::to_string(i) + ".png"))
            	{
                	throw std::logic_error("Can't load chacaters right texture");
            	}
				if(!side_left[i].loadFromFile("Textures/Bomberman/Left/Bman_F_f0" + std::to_string(i) + ".png"))
            	{
                	throw std::logic_error("Can't load chacaters left texture");
            	}
    		}
			break;
	}
}

void Character::draw_graphics(sf::RenderWindow &our_window)
{
	if(life > 0)
	{
	sf::Sprite charcter_sprite;
	int index{index_cal(my_timer.completion(), is_moving)};
	switch(move_dir)
	{
	case 1:
		charcter_sprite.setTexture(back[index]);
		break;
	case 2:
		charcter_sprite.setTexture(front[index]);
		break;
	case 3:
		charcter_sprite.setTexture(side_left[index]);
		break;
	case 4:
		charcter_sprite.setTexture(side_right[index]);
		break;
	}

	charcter_sprite.setPosition(xpos, ypos - step);
	our_window.draw(charcter_sprite);
	}

}

//-----------------Make/Use--------------
void Character::make_bomb()
{
    if (sf::Keyboard::isKeyPressed(bomb) && bombs > 0 && !(is_immortal) && !(game_ptr->is_bomb(row, col)))
    {
		//Bomb_settings bomb_setting{2, 2, 1};
		game_ptr->add_bomb(row, col, std::make_unique<Bomb>(row, col, bomb_setting, game_ptr, player_number));
		bombs -= 1;
    }
}

void Character::use_item(Item &pickup)
{
    //pickup.give_power_up(*this)
}

//-----------------Movement--------------
void Character::smooth_move()
{
	/*
	move_dir: 
	1 => up
	2 => down
	3 => left
	4 => right
	*/

	/*
	if(my_timer.is_done() && sf::Keyboard::isKeyPressed(last_key))
	{
		my_timer.restart();
		move_player();
	}
	*/

	double vel{step/walk_time};
	double progress = my_timer.elapsed_time() * vel;
	xpos = step * col;
	ypos = step * row;

	if(my_timer.is_done())
	{
		is_moving = false;
	}
	else if(move_dir == 1)
	{
		ypos = ypos + step - progress;
	}
	else if(move_dir == 2)
	{
		ypos = ypos - step + progress;

	}
	else if(move_dir == 3)
	{
		xpos =  xpos + step - progress; 
	}
	else if(move_dir == 4)
	{
		xpos = xpos - step + progress;
	}
}

void Character::move_player()
{
    int col_inc{0};
    int row_inc{0};
	int curr_col{col};
	int curr_row{row};

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
		row += row_inc;
		is_moving = true;
		my_timer.restart();

    }
	else if (col_inc != 0 && row_inc == 0 && game_ptr->can_move_to(row, col + col_inc))
    {
		col += col_inc;
		is_moving = true;
		my_timer.restart();

    }
    else if (game_ptr->can_move_to(row + row_inc, col) && row_inc != 0)
    {
		row += row_inc;
		is_moving = true;
		my_timer.restart();
    }
    else if (game_ptr->can_move_to(row, col + col_inc) && col_inc != 0)
    {
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

	if(col > curr_col)
	{
		move_dir = 4;
		last_key = sf::Keyboard::Key(right);
	}
	else if(col < curr_col)
	{
		move_dir = 3;
		last_key = sf::Keyboard::Key(left);
	}
	else if(row > curr_row)
	{
		move_dir = 2;
		last_key = sf::Keyboard::Key(down);
		
	}
	else if(row < curr_row)
	{
		move_dir = 1;
		last_key = sf::Keyboard::Key(up);
	}
}
