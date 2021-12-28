#pragma once
#include "State.h"
#include "LeftState.h"
#include "Player.h"
class RightState :public State
{
public:
	RightState();
	~RightState() = default;
	virtual std::unique_ptr<State> handleInput(sf::Vector2f input, int jumpCounter)override;
	virtual void enter(Player& player)override;
private:

};