#include "Gift.h"

void Gift::setPosition(sf::Vector2f location)
{
	m_sprite.setPosition(location);
}

void Gift::setIndex(int index)
{
	m_index = index;
}

int Gift::getIndex()
{
	return m_index;
}
