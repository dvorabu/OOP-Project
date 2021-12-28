#pragma once
#include <SFML/Graphics.hpp>
#include "MoveStrategy.h"
#include "Factory.h"
#include "utils.h"
class MoveRandomStrategy:public MoveStrategy
{
public:
	MoveRandomStrategy();
	virtual ~MoveRandomStrategy()=default;
	virtual void move(const sf::Time& deltaTime, sf::Sprite& sp, sf::Vector2f playerLocation) override;
private:
	static bool m_register;
	int m_numSteps = 0;
};
bool MoveRandomStrategy::m_register = Factory::registerMove([]()->std::unique_ptr<MoveStrategy> { return std::make_unique<MoveRandomStrategy>(); });
