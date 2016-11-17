#include "Matrix_Map.h"
#include <iostream>
#include <windows.h>
#include "SFML/Graphics.hpp"

//-----------------CONSTRUCTOR--------------
Matrix_Map::Matrix_Map()
: max_rows{sizeof our_map / sizeof our_map[0]}, max_cols{sizeof our_map[0] / sizeof(int)}
{
    initialize_map();
}

void Matrix_Map::initialize_map() noexcept
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
void Matrix_Map::draw_graphics(sf::RenderWindow & our_window) const noexcept
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int r = 0; r < max_rows; r++)
    {
        for(int c = 0; c < max_cols; c++)
        {
            int element = get_element(r, c);
            int color_number;
            switch(element)
            {
                case 0:
                    color_number = 8;
                    break;
                case 1:
                    color_number = 6;
                    break;
                case 2:
                    color_number = 10;
                    break;
                case 3:
                    color_number = 12;
                    break;
                case 4:
                    color_number = 6;
                    break;
                case 5:
                    color_number = 13;
                    break;
                    // FÖR ATT TESTA
                case 6:
                    color_number = 7;
                    break;
            }
            SetConsoleTextAttribute(hConsole, color_number);
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

//-----------------GET/SET------------------
int Matrix_Map::get_element(int row, int col) const noexcept
{
    return our_map[row][col];
}
void Matrix_Map::set_element(int row, int col, int new_value) noexcept
{
    our_map[row][col] = new_value;
}
int Matrix_Map::get_rows() const noexcept
{
    return max_rows;
}
int Matrix_Map::get_columns() const noexcept
{
    return max_cols;
}