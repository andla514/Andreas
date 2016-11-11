
#ifndef GAME_H
#define GAME_H
#include "Matrix_Map.h"
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

    void draw_graphics();

    int get_element(int row, int col);
    void set_element(int row, int col, int new_value);
    int get_rows();
    int get_columns();

    // Bools
    bool is_standing_in_fire(int row, int col);
    bool is_standing_on_item(int row, int col);
    bool can_move_to(int row, int col);
    // Handle reference lists
    void add_item();
    void add_bomb();
    void add_explosion();
    void remove_bomb(int row, int col);
    void remove_explosion(int row, int col);

    // Data
    private:
    Matrix_Map our_matrix{};
    // Referenslista för Item
    // Referenslista för Bomb
    // Referenslista för Explosion
};

#endif