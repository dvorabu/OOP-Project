#pragma once
#include <vector>
#include "Gift.h"
#include "Factory.h"
//class Factory;

class ShotGift : public Gift {
public:
	ShotGift(sf::Vector2f location = DEFULT_POSITOION) : Gift(location, Shape::SHOTGIFT) {}
	virtual ~ShotGift() = default;
private:
	static bool m_registerit;

};
inline bool ShotGift::m_registerit = Factory::registerit(1, []() -> std::unique_ptr<Gift> { return std::make_unique<ShotGift>(); });