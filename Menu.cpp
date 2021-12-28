
#include "Menu.h"

Menu::Menu(sf::Vector2f size, int numOfTexture):m_rec(size)
{
	m_rec.setPosition({ START_BOARD,START_BOARD });
	m_rec.setFillColor(sf::Color::White);
	m_rec.setTexture(&(ResourceManager::instance().getImage(numOfTexture)));
}
