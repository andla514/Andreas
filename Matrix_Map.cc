#include "Matrix_Map.h"
#include <iostream>

//-----------------CONSTRUCTOR--------------
Matrix_Map::Matrix_Map()
: max_rows{sizeof our_map / sizeof our_map[0]}, max_cols{sizeof our_map[0] / sizeof(int)}
{
    initialize_map();
}

void Matrix_Map::initialize_map()
{
    for(int r = 0; r < max_rows; r++)
    {
        for(int c = 0; c < max_cols; c++)
        {
            if(r == 0 || c == 0  || r == max_rows - 1 || c == max_cols - 1)
            {
                set_element(r, c, 5);
            }
            else if(r % 2 == 0 && c % 2 == 0)
            {
                set_element(r, c, 5);
            }
            else if(rand() % 100 + 1 < 70)
            {
                set_element(r, c, 1);
            }
        }
    }
    // Player 1 spawn
    set_element(1, 1, 0);
    set_element(1, 2, 0);
    set_element(2, 1, 0);

    // Player 2 spawn
    set_element(1, max_cols - 2, 0);
    set_element(1, max_cols - 3, 0);
    set_element(2, max_cols - 2, 0);

    // Player 3 spawn
    set_element(max_rows - 2, max_cols - 2, 0);
    set_element(max_rows - 2, max_cols - 3, 0);
    set_element(max_rows - 3, max_cols - 2, 0);

    // Player 4 spawn
    set_element(max_rows - 2, 1, 0);
    set_element(max_rows - 2, 2, 0);
    set_element(max_rows - 3, 1, 0);
}
//-----------------Graphics-----------------
void Matrix_Map::draw_graphics()
{
    for(int r = 0; r < max_rows; r++)
    {
        for(int c = 0; c < max_cols; c++)
        {
            std::cout << get_element(r, c) << " ";
        }
        std::cout << std::endl;
    }
}

//-----------------GET/SET------------------
int Matrix_Map::get_element(int row, int col)
{
    return our_map[row][col];
}
void Matrix_Map::set_element(int row, int col, int new_value)
{
    our_map[row][col] = new_value;
}
int Matrix_Map::get_rows()
{
    return max_rows;
}
int Matrix_Map::get_columns()
{
    return max_cols;
}