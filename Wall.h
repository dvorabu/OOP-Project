#pragma once
#include "NunActiveObject.h"
class Wall : public NunActiveObject {
public:
	Wall(sf::Vector2f location, int numOfImage) : NunActiveObject(location, numOfImage) {}
	virtual ~Wall() = default;
};