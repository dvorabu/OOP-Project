#pragma once
#include "NunActiveObject.h"
class Door : public NunActiveObject {
public:
	Door(sf::Vector2f location, int numOfImage) : NunActiveObject(location, numOfImage) {}
	virtual ~Door() = default;
};