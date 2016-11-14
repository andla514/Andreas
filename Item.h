
#ifndef ITEM_H
#define ITEM_H

class Item;
class Item_Inc_Bombs;
class Item_Inc_Exp_Rad;


class Item
{
public:
    Item(int const & row, int const & col);
    virtual ~Item() = default;
    void change_character();         //Character &current_character);
    bool has_character();
    virtual void give_power_up() = 0;
    
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


class Item_3:public Item
{
public:
    using Item::Item;
    ~Item_3() = default;
    
    void draw_graphics() override;
};

class Item_4:public Item
{
public:
    using Item::Item;
    ~Item_4() = default;
    
    void draw_graphics() override;
};

#endif
