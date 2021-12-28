#include "LeftState.h"
#include "Player.h"
#include "ProtectionState.h"
#include "RightState.h"
#include "LyingDownState.h"
#include "JumpingState.h"
LeftState::LeftState()
{
}

std::unique_ptr<State> LeftState::handleInput(sf::Vector2f input,int jumpCounter)
{
	if (input == DIRCTHION[Dirc::RIGHT])
		return std::make_unique<RightState>();
	if (input == DIRCTHION[Dirc::DOWN])
		return std::make_unique<LyingDownState>();
	if (input == DIRCTHION[Dirc::UP])
		return std::make_unique<JumpingState>();
	else
		return NULL;
}

void LeftState::enter(Player& player)
{
	player.getSprite().setTexture((ResourceManager::instance().getImage(Shape::PLAYER)));

	player.setProtection(false);
	player.getSprite().setRotation(1);
	player.setFall(true);
	player.getSprite().setScale(1,1);
	player.setDirc(DIRCTHION[(Dirc::LEFT)]);
}
