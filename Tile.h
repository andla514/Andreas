
#ifndef TILE_H
#define TILE_H
class Tile;
#include "SFML/Graphics.hpp"

class Tile
{
    public:
    virtual ~Tile() = default;
    virtual void update() {};
    virtual void draw_graphics(sf::RenderWindow &) {};
};

class Wall: public Tile
{};

class Box: public Tile
{};

#endif
