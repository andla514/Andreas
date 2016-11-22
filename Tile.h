
#ifndef TILE_H
#define TILE_H
class Tile;

class Tile
{
    public:
    virtual ~Tile() = default;
    virtual void update() {};
};

class Wall: public Tile
{};

class Box: public Tile
{};

#endif
