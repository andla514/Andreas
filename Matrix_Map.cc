#include "Matrix_Map.h"
#include "Tile.h"
#include "Item.h"
#include "Bomb.h"
#include "Explosion.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <ctime>
#include <memory>

//-----------------CONSTRUCTOR-------------------
Matrix_Map::Matrix_Map()
: max_rows{sizeof our_map / sizeof our_map[0]}, max_cols{sizeof our_map[0] / sizeof(int)}
{
    initialize_map();
}

//-----------------GET/SET-----------------------
Tile & Matrix_Map::get_reference(int row, int col)
{
    if(our_map[row][col].get() == nullptr)
    {
        throw std::logic_error("There is no object at that position!");
    }
    return *our_map[row][col];
}
int Matrix_Map::get_rows() const noexcept
{
    return max_rows;
}
int Matrix_Map::get_columns() const noexcept
{
    return max_cols;
}
//-----------------BOOLS-------------------------
bool Matrix_Map::is_box(int row, int col) const
{
    return dynamic_cast<Box*>(our_map[row][col].get());
}
bool Matrix_Map::is_item(int row, int col) const
{
    return dynamic_cast<Item*>(our_map[row][col].get());
}
bool Matrix_Map::is_bomb(int row, int col) const
{
    return dynamic_cast<Bomb*>(our_map[row][col].get());
}
bool Matrix_Map::is_explosion(int row, int col) const
{
    return dynamic_cast<Explosion*>(our_map[row][col].get());
}
bool Matrix_Map::is_wall(int row, int col) const
{
    return dynamic_cast<Wall*>(our_map[row][col].get());
}
bool Matrix_Map::is_null(int row, int col) const
{
    return our_map[row][col].get() == nullptr;
}
bool Matrix_Map::can_move_to(int row, int col) const
{
    return !is_bomb(row, col) && !is_wall(row, col) && !is_box(row, col);
}
//-----------------ADD/REMOVE_OBJECT-------------
void Matrix_Map::make_object(int row, int col, std::unique_ptr<Tile> && new_object)
{
    our_map[row][col] = std::move(new_object);
}
void Matrix_Map::remove_object(int row, int col)
{
    our_map[row][col].reset();
}

//-----------------INITIALIZATION----------------
void Matrix_Map::initialize_map() noexcept
{
    srand(time(NULL));

    for(int r = 0; r < max_rows; r++)
    {
        for(int c = 0; c < max_cols; c++)
        {
            // Make Wall-tile
            if((r == 0 || c == 0  || r == max_rows - 1 || c == max_cols - 1)
                || (r % 2 == 0 && c % 2 == 0))
            {
                make_object(r, c, std::make_unique<Wall>());
            }
            // Make Box-tile
            else if(rand() % 100 + 1 < 70)
            {
                make_object(r, c, std::make_unique<Box>());
            }
        }
    }

    //  Clear Player 1 spawn
    make_object(1, 1, std::unique_ptr<Tile>());
    make_object(1, 2, std::unique_ptr<Tile>());
    make_object(2, 1, std::unique_ptr<Tile>());

    // Clear Player 2 spawn
    make_object(1, max_cols - 2, std::unique_ptr<Tile>());
    make_object(1, max_cols - 3, std::unique_ptr<Tile>());
    make_object(2, max_cols - 2, std::unique_ptr<Tile>());

    // Clear Player 3 spawn
    make_object(max_rows - 2, max_cols - 2, std::unique_ptr<Tile>());
    make_object(max_rows - 2, max_cols - 3, std::unique_ptr<Tile>());
    make_object(max_rows - 3, max_cols - 2, std::unique_ptr<Tile>());

    // Clear Player 4 spawn
    make_object(max_rows - 2, 1, std::unique_ptr<Tile>());
    make_object(max_rows - 2, 2, std::unique_ptr<Tile>());
    make_object(max_rows - 3, 1, std::unique_ptr<Tile>());
    
}