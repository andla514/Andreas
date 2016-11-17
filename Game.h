
#ifndef GAME_H
#define GAME_H
class Game;
#include <map>
#include "Bomb.h"
#include "Item.h"
#include "Character.h"
#include <string>
#include "Explosion.h"
#include "Matrix_Map.h"
#include <memory>
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

    void update() noexcept;
    void draw_graphics() const noexcept;

    int get_element(int row, int col) const noexcept;
    void set_element(int row, int col, int new_value) noexcept;
    int get_rows() const noexcept;
    int get_columns() const noexcept;

    // Bools
    bool is_standing_in_fire(int row, int col) const noexcept;
    bool is_standing_on_item(int row, int col) const noexcept;
    bool can_move_to(int row, int col) const noexcept;
    bool is_wall(int row, int col) const noexcept;
    bool is_box(int row, int col) const noexcept;
    // Handle reference lists
    void add_item(int row, int col, Item new_item) noexcept;
    void add_bomb(int row, int col, Bomb new_bomb) noexcept;
    void add_explosion(int row, int col, Explosion new_explosion) noexcept;
    Item get_item_at(int row, int col);
    void remove_bomb(int row, int col) noexcept;
    void remove_explosion(int row, int col) noexcept;
    void add_characters(int number_of_players, std::shared_ptr<Game> our_game);
    Character & get_character_reference(int player_number);

    // Data
    private:
    Matrix_Map our_matrix{};
    std::map<std::string, Item> item_list{};
    std::map<std::string, Bomb> bomb_list{};
    std::map<std::string, Explosion> explosion_list{};
    std::map<int, Character> character_list{};
};

#endif