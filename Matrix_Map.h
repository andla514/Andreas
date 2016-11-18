
#ifndef MATRIX_MAP_H
#define MATRIX_MAP_H
#include "SFML/Graphics.hpp"
#include "Timer.h"
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

    void update();
    void draw_graphics(sf::RenderWindow &) const noexcept;

    int get_element(int row, int col) const noexcept;
    void set_element(int row, int col, int new_value) noexcept;
    int get_rows() const noexcept;
    int get_columns() const noexcept;

    private:
    void initialize_map() noexcept;
    void load_permanent_textures();
    // Data
    private:
    int max_rows;
    int max_cols;
    int our_map[15][21] = {{0}};
    Timer sprite_changer{0.2};
    sf::Texture background;
    sf::Texture box;
    std::vector<sf::Texture> bombs{std::vector<sf::Texture>(3, sf::Texture{})};
    std::vector<sf::Texture> explosions{std::vector<sf::Texture>(5, sf::Texture{})};
    int current_explosion{0};
    int current_bomb{0};
};

#endif