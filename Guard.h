#pragma once
#include <vector>
#include "ActiveObject.h"
#include "Utils.h"
#include "MoveStrategy.h"
#include "Shot.h"
class Factory;

class Guard : public ActiveObject
{
public:
	Guard(sf::Vector2f location,std::unique_ptr<MoveStrategy> m);
	virtual ~Guard() = default;
	void move(const sf::Time& deltaTime,sf::Vector2f playerLocation);
	void setMove(int direction);
	void createShot();
	void draw(sf::RenderWindow& window);
	void setIndex(int index);
	int getIndex();
	int getShotSize();
	sf::FloatRect getShotGlobal(int index);
protected:
	bool  m_isBoonked;
	std::unique_ptr<MoveStrategy> m_move;
	std::vector<std::unique_ptr<Shot>> m_shot;
	int m_index;

};