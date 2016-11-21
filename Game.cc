#include "Bomb.h"
#include "Item.h"
#include "Explosion.h"
#include "Character.h"
#include "Matrix_Map.h"
#include <map>
#include <string>
#include <memory>
#include "SFML/Graphics.hpp"
#include <iostream>

//-----------------CONSTRUCTOR-------------------
Game::Game()
{}

//-----------------Physics-----------------------
void Game::update()
{
    for(auto it = bomb_list.begin(); it != bomb_list.end();)
    {
        if(it->second.get() == nullptr)
        {
            it = bomb_list.erase(it);
        }
        else
        {
            (it++)->second->update();
        }
    }
    /*
    for(auto it = item_list.begin(); it != item_list.end();)
    {
        if(it->second.get() == nullptr)
        {
            it = item_list.erase(it);
        }
        else
        {
            (it++)->second->update();
        }
    }*/
    for(auto it = explosion_list.begin(); it != explosion_list.end();)
    {
        if(it->second.get() == nullptr)
        {
            it = explosion_list.erase(it);
        }
        else
        {
            (it++)->second->update();
        }
    }
    for(auto it = character_list.begin(); it != character_list.end(); ++it)
    {
        it->second.update();
    }
}

//-----------------Graphics----------------------
void Game::draw_graphics(sf::RenderWindow & our_window)
{
    our_matrix.draw_graphics(our_window);
    /*
    for(auto it = item_list.begin(); it != item_list.end();)
    {
        if(it->second.get() == nullptr)
        {
            it = item_list.erase(it);
        }
        else
        {
            (it++)->second->draw_graphics(our_window);
        }
    }*/
    for(auto it = character_list.begin(); it != character_list.end(); ++it)
    {
        it->second.draw_graphics(our_window);
    }
}

//-----------------BOOLS-------------------------
bool Game::is_box(int row, int col) const
{
    return get_element(row, col) == 1;
}
bool Game::is_standing_on_item(int row, int col) const
{
    return get_element(row, col) == 2;
}
bool Game::is_bomb(int row, int col) const
{
    return get_element(row, col) == 3;
}
bool Game::is_standing_in_fire(int row, int col) const
{
    return get_element(row, col) == 4;
}
bool Game::is_wall(int row, int col) const
{
    return get_element(row, col) == 5;
}
bool Game::can_move_to(int row, int col) const
{
    int our_element = get_element(row, col);
    return our_element != 5 && our_element != 1 && our_element != 3;
}

//-----------------ADD_OBJECT--------------------
void Game::add_item(int row, int col, std::unique_ptr<Item> && new_item) noexcept
{
    item_list.insert(std::pair<std::string, std::unique_ptr<Item>>(std::to_string(row) + "," + std::to_string(col), std::move(new_item)));
    set_element(row, col, 2);
}
void Game::add_bomb(int row, int col, std::unique_ptr<Bomb> && new_bomb) noexcept
{
    bomb_list.insert(std::pair<std::string, std::unique_ptr<Bomb>>(std::to_string(row) + "," + std::to_string(col), std::move(new_bomb)));
    set_element(row, col, 3);
}
void Game::add_explosion(int row, int col, std::unique_ptr<Explosion> && new_explosion) noexcept
{
    explosion_list.insert(std::pair<std::string, std::unique_ptr<Explosion>>(std::to_string(row) + "," + std::to_string(col), std::move(new_explosion)));
    set_element(row, col, 4);
}
void Game::add_characters(int number_of_players, std::shared_ptr<Game> our_game) noexcept
{
    for(int i = 0; i < number_of_players; i++)
    {
        character_list.insert(std::pair<int, Character>(i + 1, Character{our_game, i + 1}));
    }
}

//-----------------REMOVE_OBJECT-----------------
void Game::remove_bomb(int row, int col) noexcept
{
    bomb_list.at(std::to_string(row) + "," + std::to_string(col)).reset();
    if(is_bomb(row, col))
    {
        set_element(row, col, 0);
    }
}
void Game::remove_explosion(int row, int col) noexcept
{
    explosion_list.at(std::to_string(row) + "," + std::to_string(col)).reset();
    if(is_standing_in_fire(row, col))
    {
        set_element(row, col, 0);
    }
}
void Game::remove_item(int row, int col) noexcept
{
    item_list.erase(std::to_string(row) + "," + std::to_string(col));
    if(is_standing_on_item(row, col))
    {
        set_element(row, col, 0);
    }
}

//-----------------GET_REFERENCE-----------------
Character & Game::get_character_reference(int player_number)
{
    if (character_list.find(player_number) == character_list.end())
    {
        throw std::logic_error("No character with this number");
    }
    return character_list.at(player_number);
}
Bomb & Game::get_bomb_reference(int row, int col)
{
    std::string our_key{std::to_string(row) + "," + std::to_string(col)};
    if (bomb_list.find(our_key) == bomb_list.end() || !bomb_list.at(our_key))
    {
        throw std::logic_error("No bomb at these coordinates");
    }
    return *bomb_list.at(our_key);
}
Item & Game::get_item_reference(int row, int col)
{
    std::string our_key{std::to_string(row) + "," + std::to_string(col)};
    if (item_list.find(our_key) == item_list.end() || !item_list.at(our_key))
    {
        throw std::logic_error("No item at these coordinates");
    }
    return *item_list.at(our_key);
}
Explosion & Game::get_explosion_reference(int row, int col)
{
    std::string our_key{std::to_string(row) + "," + std::to_string(col)};
    if (explosion_list.find(our_key) == explosion_list.end() || !explosion_list.at(our_key))
    {
        throw std::logic_error("No explosion at these coordinates");
    }
    return *explosion_list.at(our_key);
}

//-----------------GET/SET------------------
int Game::get_element(int row, int col)  const
{
    return our_matrix.get_element(row, col);
}
void Game::set_element(int row, int col, int new_value)
{
    our_matrix.set_element(row, col, new_value);
}
int Game::get_rows()  const noexcept
{
    return our_matrix.get_rows();
}
int Game::get_columns()  const noexcept
{
    return our_matrix.get_columns();
}