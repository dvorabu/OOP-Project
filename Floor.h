#pragma once
//#include <Vector>
#include "NunActiveObject.h"
class Floor : public NunActiveObject {
public:
	Floor(sf::Vector2f location, int numOfImage) : NunActiveObject(location, numOfImage) {}
	virtual ~Floor() = default;
};