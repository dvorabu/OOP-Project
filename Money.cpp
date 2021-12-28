#include "Money.h"

Money::Money(sf::Vector2f location, int numOfImage) : NunActiveObject(location, numOfImage)
{
}

Money::~Money()
{
	m_sound.setBuffer(ResourceManager::instance().getSound());
	m_sound.setVolume(100.f);
	m_sound.play();
}

void Money::setDelete()
{

	m_delete = true;
}

bool Money::getDelete()
{
	return m_delete;
}
