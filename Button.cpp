#include "Button.h"

Button::Button(std::string s, sf::Vector2f location, sf::Color color)
{
	m_text.setString(s);
	m_text.setCharacterSize(60);
	m_text.setPosition(location);
	m_text.setFont(ResourceManager::instance().getFont());
	m_text.setColor(color);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_text);

}

sf::FloatRect Button::getGlobalBounds()
{
	return m_text.getGlobalBounds();
}
