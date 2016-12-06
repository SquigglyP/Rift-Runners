#ifndef GAME_WORLD_H
#define GAME_WORLD_H

// GameWorld object will store all of the data for the world of the game, including the maps and a list of entity id's that exist on those maps.
// It will require methods to keep track of entities in the maps, as well as remove them and destroy them and also a method to get the list for processing.
// This will make it much easier and faster to run through the entities doing updates, since we'll know exactly which entities we need to worry about.

#include <game_map.h>
#include <vector>

enum LevelSelect // outside the class so the systems can access it.
	{
		Town,
		Bar,
		Rift
	};

class GameWorld
{
	private:
	// The map and objects that currently need to be processed:
	GameMap current_map;
	std::vector<unsigned int> current_objects;
	
	// The hub town map:
	GameMap town;
	std::vector<unsigned int> town_objects;
	
	// The rift world we are visiting: (may allow player to go back to town, which is why this is necessary)
	GameMap rift;
	std::vector<unsigned int> rift_objects;
	
	// The bar scene, which is essentially the main menu of the game:
	GameMap bar;
	std::vector<unsigned int> bar_objects;
	
	LevelSelect current_level; // keeps track of current level we're on. May need another to designate a new Rift level, not a previous one.
	
	public:
	void mapSwitch(LevelSelect); // switch between maps.
	std::vector<unsigned int>* getCurrentEntities(){return &current_objects;}; // get pointer to vector of current objects (maybe only need to do this one time?)
	GameMap* getCurrentMap(){return &current_map;}; // get pointer to current map (maybe only need to do this one time?)
	
	void setMapInfo(GameMap, std::vector<unsigned int>, LevelSelect); // hand over a map and list of entities to replace a level with another one
	
	void createNewRiftMap(); // begines the process of generating a new level for the rift world.
	
};

#endif