#pragma once
#include "Menu.h"
#include "Leval.h"
class GameMenu : public Menu
{
public:
	GameMenu();
	~GameMenu()= default;
	void draw(sf::RenderWindow& window,sf::Clock clock,int life,int score, int level);
	void setInformation(sf::Clock clock, int life, int score,int level);
	void setView(sf::RenderWindow& window);

private:
	sf::View m_view;
	sf::Text m_lifeText;
	sf::Text m_scoreText;
	sf::Text m_levalText;
	sf::Text m_clockText;
	sf::Clock m_clock;
};
