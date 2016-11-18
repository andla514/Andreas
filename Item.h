
#ifndef ITEM_H
#define ITEM_H
class Item;
class Item_Inc_Bombs;
class Item_Inc_Exp_Rad;
class Item_Inc_Exp_Time;
class Item_Inc_Life;
// #include "Game.h"
#include "Character.h"



class Item
{
public:
    Item(int const & row, int const & col);
    virtual ~Item() = default;
    // virtual void give_power_up(Character & character) = 0;    
    virtual void draw_graphics() = 0;
    
    int item_row{};
    int item_col{};
    
};



class Item_Inc_Bombs:public Item
{
public:
    using Item::Item;
    ~Item_Inc_Bombs() = default;
    void give_power_up(Character & character) override;
    void draw_graphics() override;
};


class Item_Inc_Exp_Rad:public Item
{
public:
    using Item::Item;
    ~Item_Inc_Exp_Rad() = default;
    void give_power_up(Character & character) override;	    
    void draw_graphics() override; 
};


class Item_Inc_Life:public Item
{
public:
    using Item::Item;
    ~Item_Inc_Life() = default;
    void give_power_up(Character & character) override;    
    void draw_graphics() override;
};

class Item_Inc_Exp_Time:public Item
{
public:
    using Item::Item;
    ~Item_Inc_Exp_Time() = default; 
    void give_power_up(Character & character) override;
    void draw_graphics() override;
};

#endif
