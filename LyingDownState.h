#pragma once
#include "State.h"
class Player;
class Player;
class LyingDownState :public State
{
public:
	LyingDownState();
	~LyingDownState() = default;
	virtual std::unique_ptr<State> handleInput(sf::Vector2f input,int jumpCounter)override;
	virtual void enter(Player& player)override;
private:

};
