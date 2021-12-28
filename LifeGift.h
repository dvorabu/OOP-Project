#pragma once
#include <vector>
#include "Gift.h"
#include "Factory.h"
//class Factory;

class LifeGift : public Gift {
public:
	LifeGift(sf::Vector2f location = DEFULT_POSITOION) : Gift(location, Shape::LIFEGIFT) {}
	virtual ~LifeGift() = default;
private:
	static bool m_registerit;

};
inline bool LifeGift::m_registerit = Factory::registerit(2, []() -> std::unique_ptr<Gift> { return std::make_unique<LifeGift>(); });