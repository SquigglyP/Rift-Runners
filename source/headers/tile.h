#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <string>

enum TileType
{
	Floor,
	Wall,
};

class Tile : public sf::Sprite
{
	private:
	TileType type;
	int size;
	
	
	public:
	Tile();
	TileType getType(){return type;};
	void setType(TileType);
	
	
};

#endif