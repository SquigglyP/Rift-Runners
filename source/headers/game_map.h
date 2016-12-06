#ifndef GAME_MAP_H
#define GAME_MAP_H

// will store a vector of sf::Sprites. for now. I might change this later.

#include <SFML/Graphics.hpp>
#include <tile.h>
#include <vector>


class GameMap
{
	private:
	int tile_size;
	sf::Texture* p_texture; // the tileset texture, recieved upon creation
	std::vector<Tile> map; // 1D vector will be filled using width * height and will use a forumla like [(x*width)+y] to access the x,y coordinates.
	
	int width, height;
	
	public:
	void generateTest(int, int, sf::Texture&);
	void setTilemap(sf::Texture&);
	void draw(sf::RenderWindow&);
	void setTile(int, int, Tile);
	
	
};

#endif