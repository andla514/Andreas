#include "Matrix_Map.h"
#include "Game.h"
#include "Item.h"
#include "Bomb.h"
#include "Explosion.h"
#include <iostream>
#include <memory>

//-----------------CONSTRUCTOR--------------
Game::Game()
{}
//-----------------Physics------------------
void Game::update() noexcept
{
    for(auto it = bomb_list.begin(); it != bomb_list.end(); ++it)
    {
        //it->second.update();
    }
    for(auto it = explosion_list.begin(); it != explosion_list.end(); ++it)
    {
        //it->second.update();
    }
    for(auto it = character_list.begin(); it != character_list.end(); ++it)
    {
        it->second.update();
    }
}
//-----------------Graphics-----------------
void Game::draw_graphics() const noexcept
{
    our_matrix.draw_graphics();
    // TODO
}
//-----------------BOOLS--------------------
bool Game::is_standing_in_fire(int row, int col) const noexcept
{
    return get_element(row, col) == 4;
}
bool Game::is_standing_on_item(int row, int col) const noexcept
{
    return get_element(row, col) == 2;
}
bool Game::can_move_to(int row, int col) const noexcept
{
    int our_element = get_element(row, col);
    return our_element != 5 && our_element != 1 && our_element != 3;
}
bool Game::is_wall(int row, int col) const noexcept
{
    return get_element(row, col) == 5;
}
bool Game::is_box(int row, int col) const noexcept
{
    return get_element(row, col) == 1;
}
bool Game::is_bomb(int row, int col) const noexcept
{
    return get_element(row, col) == 3;
}
//-----------------REFERENCE_LISTS----------
void Game::add_item(int row, int col, Item && new_item) noexcept
{
    item_list.insert(std::pair<std::string, Item*>(std::to_string(row) + "," + std::to_string(col), new Item(std::move(new_item))));
}
void Game::add_bomb(int row, int col, Bomb && new_bomb) noexcept
{
    bomb_list.insert(std::pair<std::string, Bomb>(std::to_string(row) + "," + std::to_string(col), std::move(new_bomb)));
}
void Game::add_explosion(int row, int col, Explosion && new_explosion) noexcept
{
    explosion_list.insert(std::pair<std::string, Explosion>(std::to_string(row) + "," + std::to_string(col), std::move(new_explosion)));
    std::cout << "Lägger till bomb på position: (" << row << "," << col << ")" << std::endl;
}
void Game::remove_bomb(int row, int col) noexcept
{
    bomb_list.erase(std::to_string(row) + "," + std::to_string(col));
}
void Game::remove_explosion(int row, int col) noexcept
{
    explosion_list.erase(std::to_string(row) + "," + std::to_string(col));
}
void Game::remove_item(int row, int col) noexcept
{
    item_list.erase(std::to_string(row) + "," + std::to_string(col));
}
void Game::add_characters(int number_of_players, std::shared_ptr<Game> our_game)
{
    for(int i = 0; i < number_of_players; i++)
    {
        character_list.insert(std::pair<int, Character>(i + 1, Character{our_game, i + 1}));
    }
}
Character & Game::get_character_reference(int player_number)
{
    return character_list.at(player_number);
}
Bomb & Game::get_bomb_reference(int row, int col)
{
    return bomb_list.at(std::to_string(row) + "," + std::to_string(col));
}
<<<<<<< HEAD
=======
Item & Game::get_item_reference(int row, int col)
{
    return *item_list.at(std::to_string(row) + "," + std::to_string(col));
}
>>>>>>> d24423e8c2042e9a8779755a7b64691ec9eba2d5
Explosion & Game::get_explosion_reference(int row, int col)
{
    return explosion_list.at(std::to_string(row) + "," + std::to_string(col));
}
//-----------------GET/SET------------------
int Game::get_element(int row, int col)  const noexcept
{
    return our_matrix.get_element(row, col);
}
void Game::set_element(int row, int col, int new_value) noexcept
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