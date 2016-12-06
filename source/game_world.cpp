#include <game_world.h>

void GameWorld::mapSwitch(LevelSelect level)
{
	// First, we need to vacate the current level so we can do the change:
	switch(current_level)
	{
		case Town:
		{
			town = current_map;
			town_objects = std::move(current_objects);
		} break;
		
		case Bar:
		{
			bar = current_map;
			bar_objects = std::move(current_objects);
		} break;
		
		case Rift:
		{
			rift = current_map;
			rift_objects = std::move(current_objects);
		} break;
	}
	
	// now we need to make the map we're switching to the current map for processing:
	switch(level)
	{
		case Town:
		{
			current_map = town;
			current_objects = std::move(town_objects);
			current_level = Town;
		} break;
		
		case Bar:
		{
			current_map = bar;
			current_objects = std::move(bar_objects);
			current_level = Bar;
		} break;
		
		case Rift:
		{
			current_map = rift;
			current_objects = std::move(rift_objects);
			current_level = Rift;
		} break;
	}
}

void GameWorld::setMapInfo(GameMap map, std::vector<unsigned int> objects, LevelSelect level)
{
	switch(level)
	{
		case Town:
		{
			town = map;
			town_objects = std::move(objects);
		} break;
		
		case Bar:
		{
			bar = map;
			bar_objects = std::move(objects);
		} break;
		
		case Rift:
		{
			rift = map;
			rift_objects = std::move(objects);
		} break;
	}
}