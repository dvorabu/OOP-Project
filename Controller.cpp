#include "Controller.h"
#include "HelpCommand.h"

Controller::Controller() :m_window(WINDOW__DEFULT_SIZE, "Trolls"), m_endGame(WINDOW_SIZE)
{
	m_window.setFramerateLimit(8);
	m_endGame.setPosition({ START_BOARD,START_BOARD });
	m_endGame.setFillColor(sf::Color::Red);
}

void Controller::run()
{
	StartMenu s;
	s.add("New Game", std::make_unique <StartCommand>((*this)));
	s.add("help", std::make_unique <HelpCommand>((m_window)));
	while (m_window.isOpen())
	{
		m_window.clear();
		s.activate(m_window);
		m_window.display();
	}
}

void Controller::makeNewGame()
{
	m_newGame = std::make_unique<NewGame>(m_window);
	m_newGame->createPlayer(PLAYER_LOCATION);
	m_newGame->run();
		return;
}

void Controller::draw()
{
	m_window.clear();
	m_startMenu.drow(m_window);
}
