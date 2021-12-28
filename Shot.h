#pragma once
#include "ActiveObject.h"
//#include "Factory.h"
class Shot :public ActiveObject
{
public:
	Shot(sf::Vector2f location);
	virtual ~Shot ()=default;
	void move(sf::Vector2f location, const sf::Time deltaTime);

private:
};
