
#ifndef MATRIX_MAP_H
#define MATRIX_MAP_H
#include "SFML/Graphics.hpp"
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

    void draw_graphics(sf::RenderWindow &) const noexcept;

    int get_element(int row, int col) const noexcept;
    void set_element(int row, int col, int new_value) noexcept;
    int get_rows() const noexcept;
    int get_columns() const noexcept;

    private:
    void initialize_map() noexcept;
    // Data
    private:
    int max_rows;
    int max_cols;
    int our_map[19][25] = {{0}};
};

#endif