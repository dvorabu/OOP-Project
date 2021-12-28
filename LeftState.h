#pragma once
#include "State.h"
class Player;
class LeftState :public State
{
public:
	LeftState();
	~LeftState() = default;
	virtual std::unique_ptr<State> handleInput(sf::Vector2f input, int jumpCounter)override;
	virtual void enter(Player& player)override;
private:

};
