#pragma once
#include "State.h"
class ProtectionState :public State
{
public:
	ProtectionState();
   ~ProtectionState()=default;
   virtual std::unique_ptr<State> handleInput(sf::Vector2f input,int jumpCounter)override;
   virtual void enter(Player& player)override;
private:
	sf::Clock m_clock;
};