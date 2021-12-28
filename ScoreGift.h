#pragma once
#include <vector>
#include "Gift.h"
#include "Factory.h"
#include "Utils.h"
class ScoreGift : public Gift {
public:
	ScoreGift(sf::Vector2f location=DEFULT_POSITOION) : Gift(location ,Shape::SCOREGIFT) {}
	virtual ~ScoreGift() = default;
private:
	static bool m_registerit;

};
inline bool ScoreGift::m_registerit = Factory::registerit(0, []() -> std::unique_ptr<Gift> { return std::make_unique<ScoreGift>(); });