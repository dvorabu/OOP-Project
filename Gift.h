#pragma once
#include <vector>
#include "NunActiveObject.h"

class Gift : public NunActiveObject {
public:
	Gift(sf::Vector2f location, int numOfImage) : NunActiveObject(location, numOfImage) {}
	virtual ~Gift() = 0 {};
	void setPosition(sf::Vector2f location);
	void setIndex(int index);
	int getIndex();
protected:
	int m_index;
};