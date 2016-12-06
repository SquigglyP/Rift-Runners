#include <game_map.h>
#include <iostream>

void GameMap::generateTest(int w, int h, sf::Texture& t)
{
	width = w; height = h; tile_size = 32;
	Tile tile;
	tile.setTexture(t);
	tile.setType(TileType::Floor);
	
	for(int x=0; x<width; x++)
	{
		for(int y=0; y<height; y++)
		{
			tile.setPosition(x*32, y*32);
			map.push_back(tile);
		}
	}
	
	int x(2), y(8);
	map[(x*width)+y].setType(TileType::Wall);
}

void GameMap::setTilemap(sf::Texture& t)
{
	for(int x=0; x<width; x++)
	{
		for(int y=0; y<height; y++)
		{
			map[(x*width)+y].setTexture(t);
		}
	}
}

void GameMap::draw(sf::RenderWindow& window)
{
	int i(0);
	sf::View view = window.getView();
	sf::Vector2i tl, br; // top left and bottom right of tile coord rectangle to draw
	bool something_to_draw = true;
	
	// let's make sure there's something to draw, first...
	if(view.getCenter().x + (view.getSize().x / 2) < 0)
		something_to_draw = false;
	if(view.getCenter().x - (view.getSize().x / 2) > width*tile_size)
		something_to_draw = false;
	if(view.getCenter().y + (view.getSize().y / 2) < 0)
		something_to_draw = false;
	if(view.getCenter().y - (view.getSize().y / 2) > height*tile_size)
		something_to_draw = false;
	
	if(view.getCenter().x - (view.getSize().x / 2) < 0)
		tl.x = 0;
	else
		tl.x = int((view.getCenter().x - (view.getSize().x / 2)) / tile_size);
	
	if(view.getCenter().y - (view.getSize().y / 2) < 0)
		tl.y = 0;
	else
		tl.y = int((view.getCenter().y - (view.getSize().y / 2)) / tile_size);
	
	if(view.getCenter().x + (view.getSize().x / 2) > (width-1)*tile_size)
		br.x = width-1;
	else
		br.x = int((view.getCenter().x + (view.getSize().x / 2)) / tile_size);
	
	if(view.getCenter().y + (view.getSize().x / 2) > (height-1)*tile_size)
		br.y = height-1;
	else
		br.y = int((view.getCenter().y + (view.getSize().y / 2)) / tile_size);
	
	if(something_to_draw)
	{
		for(int x = tl.x; x <= br.x; x++)
		{
			for(int y = tl.y; y <= br.y; y++)
			{
				window.draw(map[(x*width)+y]);
				i++;
			}
		}
	}
	
	std::cout << "drew " << i << " tiles." << std::endl;
}

void GameMap::setTile(int x, int y, Tile tile)
{
	map[(x*width)+y] = tile;
}