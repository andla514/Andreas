
#ifndef MATRIX_MAP_H
#define MATRIX_MAP_H
#include "SFML/Graphics.hpp"
#include "Timer.h"
#include "Tile.h"
#include <memory>
/*
    0   :   Ground
    1   :   Box
    2   :   Item
    3   :   Bomb
    4   :   Explosion
    5   :   Wall
*/
class Matrix_Map
{
    public:
    Matrix_Map();

    Tile & get_reference(int row, int col);
    int get_rows() const noexcept;
    int get_columns() const noexcept;
    // Bools
    bool is_explosion(int row, int col) const;
    bool is_item(int row, int col) const;
    bool is_wall(int row, int col) const;
    bool is_box(int row, int col) const;
    bool is_bomb(int row, int col) const;
    bool is_null(int row, int col) const;
    bool can_move_to(int row, int col) const;

    // Add/remove object
    void make_object(int row, int col, std::unique_ptr<Tile> && new_object);
    void remove_object(int row, int col);

    private:
    void initialize_map() noexcept;
    // Data
    private:
    int max_rows;
    int max_cols;
    std::unique_ptr<Tile> our_map[15][21] = {{0}};
};

#endif