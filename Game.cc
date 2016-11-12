#include "Matrix_Map.h"
#include "Game.h"
#include "Item.h"
#include <iostream>

//-----------------CONSTRUCTOR--------------
Game::Game()
{}
//-----------------Graphics-----------------
void Game::draw_graphics()
{
    our_matrix.draw_graphics();
    // TODO
}
//-----------------BOOLS--------------------
bool Game::is_standing_in_fire(int row, int col)
{
    return get_element(row, col) == 4;
}
bool Game::is_standing_on_item(int row, int col)
{
    return get_element(row, col) == 2;
}
bool Game::can_move_to(int row, int col)
{
    int our_element = get_element(row, col);
    return our_element != 5 && our_element != 1 && our_element != 3;
}
bool Game::is_wall(int row, int col)
{
    return get_element(row, col) == 5;
}
bool Game::is_box(int row, int col)
{
    return get_element(row, col) == 1;
}
//-----------------REFERENCE_LISTS----------
void Game::add_item(int row, int col, Item new_item)
{
    item_list.insert(std::pair<std::string, Item>(row + "" + col, new_item));
}
void Game::add_bomb()
{
    // TODO
}
void Game::add_explosion()
{
    // TODO
}
void Game::remove_bomb(int, int)
{
    // TODO
}
void Game::remove_explosion(int, int)
{
    // TODO
}
Item Game::get_item_at(int row, int col)
{
    std::string our_key = row + "" + col;
    if(item_list.find(our_key) != item_list.end())
    {
        throw std::out_of_range("Item doesn't exist!");
    }
    Item our_item = item_list.at(our_key);
    item_list.erase(our_key);
    return our_item;
}
//-----------------GET/SET------------------
int Game::get_element(int row, int col)
{
    return our_matrix.get_element(row, col);
}
void Game::set_element(int row, int col, int new_value)
{
    our_matrix.set_element(row, col, new_value);
}
int Game::get_rows()
{
    return our_matrix.get_rows();
}
int Game::get_columns()
{
    return our_matrix.get_columns();
}