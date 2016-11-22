
#ifndef ITEM_H
#define ITEM_H
#include "Tile.h"
#include "SFML/Graphics.hpp"
class Item;
class Item_Inc_Bombs;
class Item_Inc_Exp_Rad;
class Item_Inc_Exp_Time;
class Item_Inc_Life;
// #include "Game.h"
#include "Character.h"
#include <iostream>





class Item: public Tile
{
public:
    virtual Item(int const & row, int const & col) = 0;
    virtual ~Item() = default;
    virtual void give_power_up(Character & character) = 0;    
    virtual void draw_graphics(sf::RenderTexture &) = 0;
    
    int item_row{};
    int item_col{};
    
    sf::Texture powerup_Texture;
    sf::Sprite powerup_Sprite;
};



class Item_Inc_Bombs:public Item
{
public:
    Item_Inc_Bombs(int const & row, int const & col) override;
    ~Item_Inc_Bombs()
    {
        std::cout << "Förstör item!" << std::endl;
    }
    void give_power_up(Character & character) override;
    void draw_graphics(sf::RenderTexture &) override;
};


class Item_Inc_Exp_Rad:public Item
{
public:
    Item_Inc_Exp_Rad(int const & row, int const & col) override;
    ~Item_Inc_Exp_Rad() = default;
    void give_power_up(Character & character) override;	    
    void draw_graphics(sf::RenderTexture &) override; 
};


class Item_Inc_Life:public Item
{
public:
    Item_Inc_Life(int const & row, int const & col) override;
    ~Item_Inc_Life() = default;
    void give_power_up(Character & character) override;    
    void draw_graphics(sf::RenderTexture &) override;
};

class Item_Inc_Exp_Time:public Item
{
public:
    Item_Inc_Exp_Time(int const & row, int const & col) override;
    ~Item_Inc_Exp_Time() = default; 
    void give_power_up(Character & character) override;
    void draw_graphics(sf::RenderTexture &) override;
};

#endif