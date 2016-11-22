#include "Matrix_Map.h"
#include "Character.h"
#include "Game.h"
#include <map>
#include <string>
#include <memory>
#include "SFML/Graphics.hpp"
#include <iostream>

//-----------------CONSTRUCTOR-------------------
Game::Game()
{
    our_matrix = std::make_shared<Matrix_Map>();
    initialize_graphics();
}

//-----------------Physics-----------------------
void Game::update()
{
    for(int r = 0; r < our_matrix->get_rows(); r++)
    {
        for(int c = 0; c < our_matrix->get_columns(); c++)
        {
            if(!our_matrix->is_null(r, c))
            {
                our_matrix->get_reference(r, c).update();
            }
        }
    }
    for(auto it = character_list.begin(); it != character_list.end(); ++it)
    {
        it->second.update();
    }
}

//-----------------Graphics----------------------
void Game::draw_graphics(sf::RenderWindow & our_window)
{
    // Draws standard background
    our_window.draw(sf::Sprite{background});
    // Creates the sprites needed
    sf::Sprite explosion_sprite{explosions[explosion_changer.fraction_of_completion()]};
    sf::Sprite bomb_sprite{bombs[bomb_changer.fraction_of_completion()]};
    sf::Sprite box_sprite{box};
    
    for(int r = 0; r < our_matrix->get_rows(); r++)
    {
        for(int c = 0; c < our_matrix->get_columns(); c++)
        {
            if(our_matrix->is_box(r, c))
            {
                box_sprite.setPosition(64 * c, 64 * r);
                our_window.draw(box_sprite);
            }
            else if(our_matrix->is_bomb(r, c))
            {
                bomb_sprite.setPosition(64 * c + 9, 64 * r + 9);
                our_window.draw(bomb_sprite);
            }
            else if(our_matrix->is_explosion(r, c))
            {
                explosion_sprite.setPosition(64 * c + 9, 64 * r + 9);
                our_window.draw(explosion_sprite);
            }
            else if(our_matrix->is_item(r, c))
            {
                our_matrix->get_reference(r, c).draw_graphics(our_window);
            }
        }
    }
    for(auto it = character_list.begin(); it != character_list.end(); ++it)
    {
        it->second.draw_graphics(our_window);
    }
}

void Game::add_characters(int number_of_players) noexcept
{
    for(int i = 0; i < number_of_players; i++)
    {
        character_list.insert(std::pair<int, Character>(i + 1, Character{our_matrix, i + 1}));
    }
}

void Game::initialize_graphics()
{
    generate_background();
    // Loading permanent Textures
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

void Game::generate_background()
{
    // Create background
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
    temp_texture.create(our_matrix->get_columns() * 64, our_matrix->get_rows() * 64);
    ///////////////////////////////////////////////////

    for(int r = 0; r < our_matrix->get_rows(); r++)
    {
        for(int c = 0; c < our_matrix->get_columns(); c++)
        {
            if(our_matrix->is_wall(r, c))
            {
                wall.setPosition(64 * c, 64 * r);
                temp_texture.draw(wall);
            }
            else
            {
                ground.setPosition(64 * c, 64 * r);
                temp_texture.draw(ground);
            }
        }
    }
    // Save background texture
    temp_texture.display();
    background = temp_texture.getTexture();
}