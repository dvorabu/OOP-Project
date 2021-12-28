#include "JumpingState.h"
#include "RightState.h"
#include "Player.h"
JumpingState::JumpingState()
{
}

std::unique_ptr<State> JumpingState::handleInput(sf::Vector2f input,int jumpCounter)
{
	if (jumpCounter < PLAYER_JUMP_HEIGHT)
		return NULL;
	if (input == DIRCTHION[Dirc::RIGHT])
		return std::make_unique<RightState>();
	if (input == DIRCTHION[Dirc::LEFT])
		return std::make_unique<LeftState>();
	else
		return NULL;
}

void JumpingState::enter(Player& player)
{
	player.getSprite().setTexture((ResourceManager::instance().getImage(Shape::PLAYER)));


}
