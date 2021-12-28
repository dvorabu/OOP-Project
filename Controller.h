#pragma once
#include "NewGame.h"
#include "StartCommand.h"
#include <vector> 
class Controller
{
public:
	Controller();
	~Controller()=default;
	void run();
	void  makeNewGame();
	void draw();
private:
	StartMenu m_startMenu;
	sf::RenderWindow m_window;
	std::unique_ptr <NewGame> m_newGame;
	sf::RectangleShape m_endGame;
};
