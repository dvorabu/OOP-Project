#pragma once
#include "Menu.h"
#include "NewGame.h"
#include "Command.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
class StartMenu :public Menu
{
public:
	StartMenu ();
	~StartMenu() =default;
	void add(std::string name, std::unique_ptr<Command> c);
	void activate(sf::RenderWindow& window);
	void drow(sf::RenderWindow& window);
	int getOptionFromUser(sf::RenderWindow& window);
	bool performAction(int index, sf::RenderWindow& window);
private:
	typedef std::pair<std::string, std::unique_ptr<Command>> option;
	std::vector<option> m_options;
	std::vector<std::unique_ptr<Button>> m_button;

};

