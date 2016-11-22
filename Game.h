
#ifndef GAME_H
#define GAME_H
class Game;
#include "Character.h"
#include "Matrix_Map.h"
#include "Timer.h"
#include <map>
#include <memory>
#include "SFML/Graphics.hpp"

class Game
{
    public:
    Game();

    void update();
    void draw_graphics(sf::RenderWindow &);

    void add_characters(int number_of_players) noexcept;

    private:
    void generate_background();
    void initialize_graphics();
    
    // Data
    std::shared_ptr<Matrix_Map> our_matrix{};
    std::map<int, Character> character_list{};
    Timer bomb_changer{0.6, 3};
    Timer explosion_changer{1, 5};
    sf::Texture background;
    sf::Texture box;
    std::vector<sf::Texture> bombs{std::vector<sf::Texture>(3, sf::Texture{})};
    std::vector<sf::Texture> explosions{std::vector<sf::Texture>(5, sf::Texture{})};
};

#endif