#include "LyingDownState.h"
#include "LeftState.h"
#include "RightState.h"
#include "Player.h"
#include "Utils.h"

LyingDownState::LyingDownState()
{
}

std::unique_ptr<State> LyingDownState::handleInput(sf::Vector2f input, int jumpCounter)
{
	if (input == DIRCTHION[Dirc::RIGHT])
		return std::make_unique<RightState>();
	if (input == DIRCTHION[Dirc::LEFT] )
		return std::make_unique<LeftState>();
	else
		return NULL;
}

void LyingDownState::enter(Player& player)
{
	player.getSprite().setTexture((ResourceManager::instance().getImage(Shape::PLAYER)));
	player.getSprite().rotate(90);
}
