#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

class Object {
public:
	Object(sf::Vector2f location, int numOfImage);
	virtual ~Object() = 0 {};
	void draw(sf::RenderWindow& window);
	sf::FloatRect objectGlobalBounds();
	sf::Vector2f objectGlobal();

protected:

	sf::Vector2f m_location;
	sf::Sprite m_sprite;
};