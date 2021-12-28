#include "Guard.h"
#include "Factory.h"

Guard::Guard(sf::Vector2f location,std::unique_ptr<MoveStrategy> m) :ActiveObject(location, Shape::GUARD), m_move(std::move(m))
{

}

void Guard::move(const sf::Time& deltaTime, sf::Vector2f playerLocation)
{

	m_move->move(deltaTime,m_sprite, playerLocation);
	for (int i = 0; i < m_shot.size(); i++)
		m_shot[i]->move(DIRCTHION[Dirc::LEFT], deltaTime);

}

void Guard::setMove(int direction)
{

	m_move->setDirection(direction);
}

void Guard::createShot()
{
	m_shot.emplace_back(Factory::createShot(m_sprite.getPosition()));

}

void Guard::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_shot.size(); i++)
		m_shot[i]->draw(window);
	window.draw(m_sprite);
}

void Guard::setIndex(int index)
{
	m_index = index;
}

int Guard::getIndex()
{
	return m_index;
}

int Guard::getShotSize()
{
	return m_shot.size();
}

sf::FloatRect Guard::getShotGlobal(int index)
{
	return m_shot[index]->objectGlobalBounds();
}
