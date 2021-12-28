#pragma once
#include <SFML/Graphics.hpp>
#include "MoveStrategy.h"
#include "Factory.h"
class MoveSmartStrategy :public MoveStrategy
{
public:
	MoveSmartStrategy();
	virtual ~MoveSmartStrategy()= default;
	virtual void move(const sf::Time& deltaTime, sf::Sprite& sp, sf::Vector2f playerLocation) override;
	sf::Vector2f Direction(int direction, sf::Vector2f position, const sf::Time& deltaTime);
private:
	static bool m_register;
};
bool MoveSmartStrategy::m_register = Factory::registerMove([]()->std::unique_ptr<MoveStrategy> { return std::make_unique<MoveSmartStrategy>(); });
