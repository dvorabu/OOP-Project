#pragma once
#include<string>
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
class Command
{
public:
	Command();
	virtual ~Command()=default;
	virtual void execute() = 0;

private:
	sf::Text m_text;
};
