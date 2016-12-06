#include <tile.h>

Tile::Tile()
{
	size = 32;
}

void Tile::setType(TileType t)
{
	int x, y;
	switch(t)
	{
		case Floor:
		x=1; y=2;
		break;
		
		case Wall:
		x=1; y=0;
		break;
	}
	
	setTextureRect(sf::IntRect(x*size, y*size, size, size));
}