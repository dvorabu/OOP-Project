#pragma once
#include "Utils.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "ResourceManager.h"
#include "Guard.h"
#include "Board.h"
#include "Gift.h"
#include "Factory.h"
#include "CollisionHandling.h"
//class Observer;

class NewGame;
class Leval :public Observer
{
public:
	Leval(int numOfLevel/*,Player *player*/);
	~Leval() = default;
	bool run(NewGame& no, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window, NewGame& ne);
	void handelEvent(sf::RenderWindow& window, NewGame& ne);
	void move(NewGame& ne);
	void setEndLevel();
	sf::Vector2f keyToDirection(sf::Keyboard::Key key);
	int getLeval();
	void createGift(sf::Vector2f location);
	void createGuard(sf::Vector2f location);
	void createGuardShot();
	void handelCollision(NewGame& ne);
	bool handelPlayerCollision(NewGame& ne);
	void handelShotCollision(NewGame& ne);
	virtual void UpdateColisionWithPesent(int presentIndex) override;
	virtual void UpdateColisionWithGurd(int gurdIndex, bool x)override;
	virtual void UpdateColisionWithDoor(bool x)override;

protected:
	std::vector<std::unique_ptr<Guard>> m_guards;
	std::vector<std::unique_ptr<Gift>> m_gift;
	int m_numLeval;
	sf::View m_view;
	sf::Sprite m_rec;
	Board m_board;
	sf::Clock m_clock;
	sf::Clock m_clockShot;
	sf::Vector2f m_direchtion;
	sf::Vector2f m_prevDirechtion;
	bool m_endLevel;
	bool m_playeIsLose=false;

};