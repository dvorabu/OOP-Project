#pragma once
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "ResourceManager.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <exception>
#include "NunActiveObject.h"
#include "ActiveObject.h"
#include "Floor.h"
#include "Door.h"
class NewGame;
class Leval;
class Board
{
public:
	Board();
	~Board() = default;
	bool readFile( sf::RenderWindow& window, NewGame& ne,Leval& le);
	void draw(sf::RenderWindow& window);
	void deleteFromMat(int i, int j);
	std::unique_ptr<NunActiveObject>& getNunActiveObject(int i,int j);
	int getNumOfColls();
	int getNumOfRows();
	int getSizeOfRows(int index);
protected:

	sf::RectangleShape m_rec;
	std::vector<std::vector<std::unique_ptr<NunActiveObject>>> m_object;
	std::ifstream m_fileName;
	int m_numColls;
	int m_numRows;
	sf::Vector2f m_startLocation;
};