#pragma once

//#include <Vector>
#include "Object.h"
#include "Utils.h"
#include <iostream>


class ActiveObject : public Object {
public:
	
	ActiveObject(sf::Vector2f location, int numOfImage): Object(location, numOfImage) {}
	virtual ~ActiveObject()  = default;
	
protected:
};