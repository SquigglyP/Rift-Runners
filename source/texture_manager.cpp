#include <texture_manager.h>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

void TextureManager::loadTexture(const std::string filename, const std::string key)
{
	sf::Texture texture;
	texture.loadFromFile(filename);
	texture_maps[key] = texture;
}

sf::Texture* TextureManager::getTexture(const std::string key)
{
	return &texture_maps[key];
}