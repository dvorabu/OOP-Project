#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Utils.h"
#include "ResourceManager.h"
class Menu 
{
public:
	Menu (sf::Vector2f size,int numOfTexture);
	~Menu ()= default;

protected:
	sf::RectangleShape m_rec;
};
