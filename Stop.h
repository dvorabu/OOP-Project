#pragma once
#include "NunActiveObject.h"
class Stop : public NunActiveObject {
public:
	Stop(sf::Vector2f location, int numOfImage) : NunActiveObject(location, numOfImage) {}
	virtual ~Stop() = default;
};