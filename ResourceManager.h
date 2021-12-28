#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Utils.h"

class ResourceManager
{
public:
	~ResourceManager()=default;
	static ResourceManager& instance();
	sf::Texture& getImage(int i);
	sf::Font& getFont();
	sf::Music& getMusic();
	sf::SoundBuffer& getSound();
	void setvec();
private:
	ResourceManager();
	ResourceManager(const ResourceManager&);
	std::vector<std::unique_ptr<sf::Texture>> m_textures;
	std::unique_ptr< sf::Font> m_font;
	std::unique_ptr< sf::Music> m_music;
	sf::SoundBuffer m_sound;
};