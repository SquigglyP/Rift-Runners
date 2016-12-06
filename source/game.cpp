#include <game.h>

Game::Game()
{
	title = "Rift Runners";
	
	setVideoMode(sf::VideoMode(1280, 720), false);
	view.reset(sf::FloatRect(0,0,640, 360));
	view.setViewport(sf::FloatRect(0,0,1,1));
	
	GameMap town;
	GameMap bar;
	
	// Will need to load the maps for the town and bar so I can begin the game...
	//town.loadMap("town.map"); // load the saved town map?
	//bar.loadMap("bar.map"); // load the saved bar map?
}

void Game::setVideoMode(sf::VideoMode vidmode, bool b)
{
	window.close();
	fullscreen = b;
	if(fullscreen)
		window.create(vidmode, title, sf::Style::Fullscreen);
	else
		window.create(vidmode, title);
}

void Game::input()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
		{
			window.close();
			running = false;
		}
	
		// check if keyboard key is pressed, and if so, switch on that key
		else if(event.type == sf::Event::KeyPressed)
		{
			switch(event.key.code) // note that all of this is going to change eventually. I was just testing this functionality.
			{
				case sf::Keyboard::Key::F1:
				setVideoMode(sf::VideoMode(1280, 720), false);
				break;
				
				case sf::Keyboard::Key::F2:
				setVideoMode(sf::VideoMode(640,360), false);
				break;
				
				case sf::Keyboard::Key::F3:
				setVideoMode(sf::VideoMode(1280, 720), true);
				break;
				
				case sf::Keyboard::Key::F4:
				setVideoMode(sf::VideoMode(1920, 1080), true);
				break;
				
				case sf::Keyboard::Key::Escape:
				{
					window.close();
					running = false;
				} break;
				
				// testing movement of view
				
				case sf::Keyboard::Key::W:
				view.move(sf::Vector2f(0, -8));
				break;
				
				case sf::Keyboard::Key::S:
				view.move(sf::Vector2f(0, 8));
				break;
				
				case sf::Keyboard::Key::A:
				view.move(sf::Vector2f(-8, 0));
				break;
				
				case sf::Keyboard::Key::D:
				view.move(sf::Vector2f(8, 0));
				break;
				
			}
		}
	
	}
}

void Game::draw()
{
	window.clear();
	window.setView(view);
	
	// begin to draw the game stuff
	map.draw(window);
	window.draw(sprite);
	window.setView(window.getDefaultView());
	// Anything that needs to be 'unzoomed', like debug info or shit like that will be drawn below this line in the 'normal' view, on top of the rest of the game:
	
	window.display();
}

void Game::run() // the game loop
{
	running = true;
	
	//testing here:
	TM.loadTexture("images/player.png", "player");
	TM.loadTexture("images/32x32_test_tiles.png", "tilemap");
	sprite.setTexture(*TM.getTexture("player"));
	map.generateTest(100,100, *TM.getTexture("tilemap"));
	
	 while (running)
    {
		
		
		draw();
		input();
		//update();
		
	}
}

