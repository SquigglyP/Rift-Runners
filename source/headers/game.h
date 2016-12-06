#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <texture_manager.h>
#include <game_map.h>

class Game
{
	private:
	sf::RenderWindow window;
	sf::View view;
	bool running;
	bool fullscreen;
	 std::string title;
	
	//testing shit below here
	
	sf::Sprite sprite;
	
	TextureManager TM;
	GameMap map;
	
	public:
	Game();
	//void init();
	void run();
	void setVideoMode(sf::VideoMode, bool);
	
	void draw();
	void update();
	void input();
	
	
};

#endif