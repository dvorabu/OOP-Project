#include "HelpCommand.h"

HelpCommand::HelpCommand(sf::RenderWindow& window):m_rec(WINDOW_SIZE),m_window(window),m_button(BUTTON_SIZE)
{
	m_rec.setPosition(DEFULT_POSITOION);
	m_button.setPosition(START_WINDOW+1000, START_WINDOW+700);
	m_button.setFillColor(sf::Color::White);
	m_rec.setTexture(&(ResourceManager::instance().getImage(Shape::HELP)));
	m_text.setString("continue");
	m_text.setCharacterSize(30);
	m_text.setFont(ResourceManager::instance().getFont());
	m_text.setColor(sf::Color::Black);
	m_text.setPosition(START_WINDOW + 1040, START_WINDOW + 720);
}

void HelpCommand::execute()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.draw(m_rec);
		m_window.draw(m_button);
		m_window.draw(m_text);
		m_window.display();
		if (continuation())
			return;
	}

	
}

bool HelpCommand::continuation()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::MouseButtonPressed:
			if (m_button.getGlobalBounds().contains(m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
				return true;
			break;

		}
	}
}
