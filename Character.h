#ifndef CHARACTER_H
#define CHARACTER_H
class Character;
#include "Bomb.h"
#include "Matrix_Map.h"
#include "Item.h"
#include <string>
#include <memory>
#include <vector>
#include "Timer.h"
#include "SFML/Graphics.hpp"

class Character
{
    public:
    Character();
	~Character() = default;
	Character(std::shared_ptr<Matrix_Map> our_map, int player_number);
	
	void add_bomb(int number);
	int get_col() const;
	int get_row() const;
	void increase_exp_rad(int number);
	void increase_exp_time(int number);
	void update();
	void draw_graphics(sf::RenderWindow &);
	void hurt_player();
	void smooth_move();
	void use_item(Item & pickup);
	void make_bomb();
	void move_player();
	void load_textures(int player_number);
	
	private:
	void init_character(int player_number);
	int index_cal(double percent, bool moving);
	sf::Keyboard::Key up;
	sf::Keyboard::Key down;
	sf::Keyboard::Key left;
	sf::Keyboard::Key right;
	sf::Keyboard::Key bomb;
	sf::Keyboard::Key last_key;
	std::vector<sf::Texture> back{std::vector<sf::Texture>(8, sf::Texture{})};
    std::vector<sf::Texture> front{std::vector<sf::Texture>(8, sf::Texture{})};
	std::vector<sf::Texture> side_left{std::vector<sf::Texture>(8, sf::Texture{})};
    std::vector<sf::Texture> side_right{std::vector<sf::Texture>(8, sf::Texture{})};
	int move_dir{1};
	std::shared_ptr<Matrix_Map> our_map{};
	int life{2};
	int bombs{2};
	int col{1};
	int row{1};
	int xpos{};
	int ypos{}; 
	int const step{64};
	double walk_time {0.15};
	Timer my_timer{walk_time, 7}; 
	int player_number{};
	Bomb_settings bomb_setting{2, 2, 1};

	bool is_moving{false};
	bool is_immortal{false};
};

#endif