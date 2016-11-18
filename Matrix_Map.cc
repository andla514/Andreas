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

void Matrix_Map::load_permanent_textures()
{
    for(int i = 0; i <= 4; i++ )
    {
            if(!explosions[i].loadFromFile("Textures/Flame/Flame_F0" + std::to_string(i) + ".png"))
            {
                throw std::logic_error("Can't load explosion texture");
            }
    }
    for(int i = 0; i <= 2; i++)
    {
            if(!bombs[i].loadFromFile("Textures/Bomb/Bomb_f0" + std::to_string(i + 1) + ".png"))
            {
                throw std::logic_error("Can't load bomb texture");
            }
    }
    if(!box.loadFromFile("Textures/Blocks/ExplodableBlock.png"))
    {
        throw std::logic_error("Can't load box texture");
    }
}

void Matrix_Map::initialize_map() noexcept
{
    // CREATE BACKGROUND
    sf::Texture wall_texture, ground_texture;
    if(!wall_texture.loadFromFile("Textures/Blocks/SolidBlock.png"))
    {
        throw std::logic_error("Can't load wall texture");
    }
    if(!ground_texture.loadFromFile("Textures/Blocks/BackgroundTile.png"))
    {
        throw std::logic_error("Can't load ground texture");
    }
    sf::Sprite wall{wall_texture};
    sf::Sprite ground{ground_texture};

    sf::RenderTexture temp_texture;
    temp_texture.create(max_cols * 64, max_rows * 64);
    ///////////////////////////////////////////////////

    load_permanent_textures();

    std::cout << "Max rows: " << max_rows << std::endl;
    for(int r = 0; r < max_rows; r++)
    {
        for(int c = 0; c < max_cols; c++)
        {
            ground.setPosition(64 * c, 64 * r);
            temp_texture.draw(ground);
            if((r == 0 || c == 0  || r == max_rows - 1 || c == max_cols - 1)
                || (r % 2 == 0 && c % 2 == 0))
            {
                set_element(r, c, 5);
                wall.setPosition(64 * c, 64 * r);
                temp_texture.draw(wall);
            }
            else if(rand() % 100 + 1 < 70)
            {
                set_element(r, c, 1);
            }
        }
    }

    set_element(5, 4, 3);
    set_element(6, 3, 4);
    temp_texture.display();
    //temp_texture.getTexture().copyToImage().saveToFile("test.png");
    background = temp_texture.getTexture();


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

void Matrix_Map::update()
{
    if(sprite_changer.is_done())
    {
        sprite_changer.restart();
        if(++current_explosion >= 5)
        {
            current_explosion = 0;
        }
        if(++current_bomb >= 3)
        {
            current_bomb = 0;
        }
    }
}
//-----------------Graphics-----------------
void Matrix_Map::draw_graphics(sf::RenderWindow & our_window) const noexcept
{
    our_window.draw(sf::Sprite{background});
    sf::Sprite explosion_sprite{explosions[current_explosion]};
    sf::Sprite bomb_sprite{bombs[current_bomb]};
    sf::Sprite box_sprite{box};
    std::cout << "Test2" << std::endl;
    
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
                    box_sprite.setPosition(64 * c, 64 * r);
                    our_window.draw(box_sprite);
                    color_number = 6;
                    break;
                case 2:
                    color_number = 10;
                    break;
                case 3:
                    color_number = 12;
                    bomb_sprite.setPosition(64 * c + 9, 64 * r + 9);
                    our_window.draw(bomb_sprite);
                    break;
                case 4:
                    color_number = 6;
                    explosion_sprite.setPosition(64 * c + 9, 64 * r + 9);
                    our_window.draw(explosion_sprite);
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
            //std::cout << element << " ";
        }
        //std::cout << std::endl;
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