#pragma once
#include <Vector>
#include "ActiveObject.h"
#include "Utils.h"
#include <iostream>
#include "State.h"
#include "Factory.h"
#include "Subject.h"
#include "Observer.h"
#include <memory>
class Player : public Subject,public ActiveObject {
public:
	Player(sf::Vector2f location);
	virtual ~Player() = default;
	void RegisterObserver(Observer* pObserver)override;
	void RemoveObserver(Observer* pObserver)override;
	void NotifyObservers(int index)override;
	virtual void NotifyObserversPlayer(int index, bool x) override;
	virtual void NotifyObserversDoor(bool x) override;
	void handleInput(sf::Vector2f input,sf::Time deltaTime);
	void setDirc(sf::Vector2f dirc);
	void setLife(int x);
	void move();
	void deleteShot(int index);
	sf::Sprite& getSprite();
	void draw(sf::RenderWindow& window);
	int getLife();
	int getScore();
	int getShotSize();
	sf::Vector2f getDirc();
	void setState(std::unique_ptr<State> state);
	void enterState();
	void setScore(int points);
	void setFall(bool x);
	void createShot();
	sf::FloatRect getShotGlobal(int index);
	Shot& getShot(int index);
	void setProtection(bool x);
	bool getProtection();
	void setShot(bool x);
	bool getEnd();
	void setEnd(bool x);
private:

	std::unique_ptr<State> m_state;
	std::vector<Observer*>m_observer;

	int m_life;
	int m_scour;
	sf::Vector2f m_dirchtion;
	sf::Vector2f m_prevPosition;
	sf::Clock m_clock;
	sf::Clock m_clockShot;
	int m_jumpCounter = 0;
	bool m_isFall=false;
	bool m_isShot=false;
	bool m_isProtection=false;
	bool m_isEnd=false;
	std::vector<std::unique_ptr<Shot>> m_shot;
};