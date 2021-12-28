#include "Factory.h"


std::unique_ptr<Gift> Factory::create(int numOfLeval)
{
	auto i = rand() % numOfLeval;
	auto p=getMat()[i][rand() % getMat()[i].size()]();
	if (p == nullptr)
			return nullptr;
			return p;
}



bool Factory::registerit(int i, std::unique_ptr<Gift>(*f)())
{
	
	getMat()[i].emplace_back(f);
	return true;
}

bool Factory::registerMove(moveFunc mf)
{

		getMoveVec().emplace_back(mf);
		return true;

}

std::unique_ptr<Guard> Factory::createGuard(sf::Vector2f location)
{
	return std::make_unique<Guard>(location,getMoveVec()[(rand() % getMoveVec().size())]());
}

std::unique_ptr<Shot> Factory::createShot(sf::Vector2f location)
{
	return std::make_unique<Shot>(location);
}
