#pragma once
#include <SFML/Graphics.hpp>

class AssetManager
{
public:
	AssetManager();

	static sf::Texture& GetTexture(std::string const& filename);
private:
	std::map<std::string, sf::Texture> m_Textures;
	static AssetManager* sInstance;
};
