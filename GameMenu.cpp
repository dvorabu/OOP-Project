#include "GameMenu.h"
#include "ResourceManager.h"

GameMenu::GameMenu() :Menu(GAME_MENU_SIZE, Shape::BACKGROUND2), m_view(sf::FloatRect(START_BOARD, START_BOARD, GAME_MENU_SIZE.x, GAME_MENU_SIZE.y))
{
	m_clock.restart();
	m_view.setViewport({ 0.f, 0.f, 1.f, 0.25f });

	m_levalText.setCharacterSize(40);
	m_levalText.setPosition({ 220, 20 });
	m_levalText.setFont(ResourceManager::instance().getFont());
	m_levalText.setColor(sf::Color::Black);

	m_clockText.setCharacterSize(40);
	m_clockText.setPosition({ 450, 20 });
	m_clockText.setFont(ResourceManager::instance().getFont());
	m_clockText.setColor(sf::Color::Black);


	m_lifeText.setCharacterSize(40);
	m_lifeText.setPosition({ 680, 20 });
	m_lifeText.setFont(ResourceManager::instance().getFont());
	m_lifeText.setColor(sf::Color::Black);


	m_scoreText.setCharacterSize(40);
	m_scoreText.setPosition({ 910, 20 });
	m_scoreText.setFont(ResourceManager::instance().getFont());
	m_scoreText.setColor(sf::Color::Black);
}

void GameMenu::draw(sf::RenderWindow& window, sf::Clock clock, int life, int score, int level)
{
	if (level > 2)
	{
		m_lifeText.setColor(sf::Color::White);
		m_scoreText.setColor(sf::Color::White);
		m_clockText.setColor(sf::Color::White);

	}
	m_rec.setTexture(&ResourceManager::instance().getImage(level));
	setInformation(clock,life,score, level);
	window.setView(m_view);
	window.draw(m_rec);
	window.draw(m_levalText);
	window.draw(m_clockText);
	window.draw(m_lifeText);
	window.draw(m_scoreText);
}

void GameMenu::setInformation(sf::Clock clock, int life, int score, int level)
{
	m_lifeText.setString("life:\n " + std::to_string(life));
	m_scoreText.setString("score: \n" + std::to_string(score));
	m_levalText.setString("level: \n" + std::to_string(level));
	m_clockText.setString("time: \n"+std::to_string(int(m_clock.getElapsedTime().asSeconds())));
}


void GameMenu::setView(sf::RenderWindow& window)
{
	m_view = sf::View(sf::FloatRect(0, 0, WINDOW_SIZE.x, WINDOW_SIZE.y));
	m_view.setViewport({ 0.f, 0.f,1.f,1.f });
	window.setView(m_view);
}
