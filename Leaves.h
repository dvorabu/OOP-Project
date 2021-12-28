#pragma once
#include "NunActiveObject.h"
class Leaves : public NunActiveObject {
public:
	Leaves(sf::Vector2f location, int numOfImage) : NunActiveObject(location, numOfImage) {}
	virtual ~Leaves() = default;
};