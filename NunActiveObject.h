#pragma once
#include "Object.h"


class NunActiveObject : public Object {
public:
	NunActiveObject(sf::Vector2f location, int numOfImage) : Object(location, numOfImage) {}
	virtual ~NunActiveObject() = 0 {};
	virtual bool getDelete();
};