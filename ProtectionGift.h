#pragma once
#include <vector>
#include "Gift.h"
#include "Factory.h"

class ProtectionGift : public Gift {
public:
	ProtectionGift(sf::Vector2f location = DEFULT_POSITOION) : Gift(location, Shape::PROTECTIONGIFT) {}
	virtual ~ProtectionGift() = default;
private:
	static bool m_registerit;
};
inline bool ProtectionGift::m_registerit = Factory::registerit(1, []() -> std::unique_ptr<Gift> { return std::make_unique<ProtectionGift>(); });