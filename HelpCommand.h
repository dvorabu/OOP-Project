#pragma once
#include <SFML/Graphics.hpp>
#include "Command.h"
#include "Utils.h"
class Controller;

class HelpCommand :public Command
{
public:
	HelpCommand(sf::RenderWindow& window);
	~HelpCommand() = default;
	virtual void execute()override;
private:
	sf::RectangleShape m_rec;
	sf::Text m_text;
	sf::RectangleShape m_button;
	sf::RenderWindow& m_window;
	bool continuation();
};