
#ifndef GAME_H
#define GAME_H
class Game;
#include "Bomb.h"
#include "Item.h"
#include "Explosion.h"
#include "Character.h"
#include "Matrix_Map.h"
#include <map>
#include <string>
#include <memory>
#include "SFML/Graphics.hpp"
/*
    0   :   Ground
    1   :   Box
    2   :   Item
    3   :   Bomb
    4   :   Explosion
    5   :   Wall
*/
class Game
{
    public:
    Game();

    void update();
    void draw_graphics(sf::RenderWindow &);

    int get_element(int row, int col) const;
    void set_element(int row, int col, int new_value);
    int get_rows() const noexcept;
    int get_columns() const noexcept;

    // Bools
    bool is_standing_in_fire(int row, int col) const;
    bool is_standing_on_item(int row, int col) const;
    bool can_move_to(int row, int col) const;
    bool is_wall(int row, int col) const;
    bool is_box(int row, int col) const;
    bool is_bomb(int row, int col) const;
    // Add object
    void add_item(int row, int col, std::unique_ptr<Item> && new_item) noexcept;
    void add_bomb(int row, int col, std::unique_ptr<Bomb> && new_bomb) noexcept;
    void add_explosion(int row, int col, std::unique_ptr<Explosion> && new_explosion) noexcept;
    void add_characters(int number_of_players, std::shared_ptr<Game> our_game) noexcept;
    // Remove object
    void remove_item(int row, int col) noexcept;
    void remove_bomb(int row, int col) noexcept;
    void remove_explosion(int row, int col) noexcept;
    // Get reference to object
    Character & get_character_reference(int player_number);
    Bomb & get_bomb_reference(int row, int col);
    Item & get_item_reference(int row, int col);
    Explosion & get_explosion_reference(int row, int col);

    // Data
    private:
    Matrix_Map our_matrix{};
    std::map<std::string, std::unique_ptr<Item>> item_list{};
    std::map<std::string, std::unique_ptr<Bomb>> bomb_list{};
    std::map<std::string, std::unique_ptr<Explosion>> explosion_list{};
    std::map<int, Character> character_list{};
};

#endif