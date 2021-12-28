#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
class Button
{
public:
	Button(std::string s, sf::Vector2f location,sf::Color color);
	~Button()=default;
	void draw(sf::RenderWindow& window);
	sf::FloatRect getGlobalBounds();

private:
	sf::Text m_text;
};
