#pragma once
#include <memory>
#include "Utils.h"
class Player;
class State
{
public:
	State();
	virtual ~State()=default;
	virtual std::unique_ptr<State>handleInput(sf::Vector2f input,int jumpCounter) = 0;
	virtual void enter(Player& player) = 0;
protected:
};
