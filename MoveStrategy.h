#pragma once
#include <SFML/Graphics.hpp>

class MoveStrategy
{
public:
	MoveStrategy();
	virtual ~MoveStrategy()=default;
	virtual void move(const sf::Time& deltaTim, sf::Sprite& sp, sf::Vector2f playerLocation) = 0;
	void setDirection(int direction);
protected:
	int m_direction = 0;

};
