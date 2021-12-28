#pragma once
#include <Vector>
#include "NunActiveObject.h"
class Money : public NunActiveObject {
public:
	Money(sf::Vector2f location, int numOfImage);
	virtual ~Money();
	void setDelete();
	virtual bool getDelete()override;
private:
	bool m_delete=false;
	sf::Sound m_sound;
};