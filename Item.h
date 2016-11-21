
#ifndef ITEM_H
#define ITEM_H
class Item;
class Item_Inc_Bombs;
class Item_Inc_Exp_Rad;
class Item_Inc_Exp_Time;
class Item_Inc_Life;
#include "Tile.h"
#include "Character.h"
#include <iostream>
#include "SFML/Graphics.hpp"



class Item: public Tile
{
public:
    Item(int const & row, int const & col);
    virtual void give_power_up(Character & character) = 0;    
    
    int item_row{};
    int item_col{};
    
};



class Item_Inc_Bombs:public Item
{
public:
    using Item::Item;
    ~Item_Inc_Bombs() override = default;
    void give_power_up(Character & character) override;
    void draw_graphics(sf::RenderWindow &) override;
};


class Item_Inc_Exp_Rad:public Item
{
public:
    using Item::Item;
    ~Item_Inc_Exp_Rad() override = default;
    void give_power_up(Character & character) override;	    
    void draw_graphics(sf::RenderWindow &) override; 
};


class Item_Inc_Life:public Item
{
public:
    using Item::Item;
    ~Item_Inc_Life() override = default;
    void give_power_up(Character & character) override;    
    void draw_graphics(sf::RenderWindow &) override;
};

class Item_Inc_Exp_Time:public Item
{
public:
    using Item::Item;
    ~Item_Inc_Exp_Time() override = default; 
    void give_power_up(Character & character) override;
    void draw_graphics(sf::RenderWindow &) override;
};

#endif
