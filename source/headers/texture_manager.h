#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

// this will load all game images and keep them in memory. Any object using graphics will get their image maps from this object.
// it will store textures in a <map> object, with the keys being const strings. Simple commands to load and get textures.

#include <map>
#include <SFML/Graphics.hpp>
#include <string>

class TextureManager
{
	private:
	std::map<const std::string, sf::Texture> texture_maps;
	
	
	public:
	void loadTexture(const std::string, const std::string);
	sf::Texture* getTexture(const std::string);
	
};

#endif