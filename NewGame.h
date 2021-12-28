#pragma once
#include "Utils.h"
#include "Leval.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "NewGame.h"
#include "StartMenu.h"
#include "GameMenu.h"
#include "Player.h"
#include "ResourceManager.h"
#include "Board.h"
class NewGame 
{
public:
	NewGame(sf::RenderWindow& window);
	~NewGame()=default;
	void run();
	void draw(sf::Clock clock);
	void createPlayer(sf::Vector2f location);
	void setPlayerDirc(sf::Vector2f dirc, sf::Time deltaTime);
	sf::Vector2f getPlayerDirc();
	sf::FloatRect getPlayerGlobalBounds();
	Player& getPlayer();

private:
	std::unique_ptr<Player> m_player;
	GameMenu m_gameMenu;
	sf::RenderWindow& m_window;
	sf::RenderWindow m_windowEndGame;
	int m_numOfLevel= START_LEVEL;
	sf::RectangleShape m_rin;
	sf::RectangleShape m_end;

};