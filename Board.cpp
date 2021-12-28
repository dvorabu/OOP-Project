#include "Board.h"
#include "Leval.h"
#include "NewGame.h"
#include "Money.h"
#include "Wall.h"
#include "Leaves.h"
#include "Stop.h"

Board::Board() :m_rec(BOARD_SIZE), m_startLocation({0,225})
{
	m_rec.setPosition({ START_BOARD,START_BOARD + GAME_MENU_SIZE.y });
	m_rec.setFillColor(sf::Color(188, 93, 88));
}

bool Board::readFile(sf::RenderWindow& window, NewGame& ne,Leval& le)//קורא את הלוח מהקובץ ומעדכן נתונים
{	
	if (le.getLeval() > 1)
	{
		m_fileName.close();
		m_object.clear();
	}
	std::string fileName = "Board" + std::to_string(le.getLeval()) + ".txt";
	m_fileName.open(fileName);
	if (!m_fileName.is_open())
		m_fileName.exceptions(std::ios::failbit | std::ios::badbit);
	std::string line;
	std::getline(m_fileName, line);
	std::istringstream lineStream(line);
	lineStream >> m_numRows;
	lineStream >> m_numColls;
	m_object.resize(m_numRows);
	for (int i = 0; i < m_numRows; i++)
	{

		std::getline(m_fileName, line);
		for (int j = 0; j < line.size(); j++)
		{
			sf::Vector2f location = { float(m_startLocation.x + (j * IMAGE_SIZE)), float(m_startLocation.y + (i * IMAGE_SIZE)) };
			char x = (line[j]);
			switch (x)

			{
			case FLOORS:
				if(le.getLeval()==3)
				m_object[i].emplace_back(std::make_unique<Floor>(location, Shape::FLOOR1));
				else
				m_object[i].emplace_back(std::make_unique<Floor>(location, Shape::FLOOR));
				break;
			case STOP:
				if (le.getLeval() == 3)
					m_object[i].emplace_back(std::make_unique<Stop>(location, Shape::STOPP));
				else
					m_object[i].emplace_back(std::make_unique<Stop>(location, Shape::FLOOR));
				break;
			case LEAVE:
				m_object[i].emplace_back(std::make_unique<Leaves>(location, Shape::LEAVES));
				break;
			case DOOR:
				if (le.getLeval() == 3)
				m_object[i].emplace_back(std::make_unique<Door>(location, Shape::ENDLEVEL1));
				else
				m_object[i].emplace_back(std::make_unique<Door>(location, Shape::ENDLEVEL));
				break;
			case WALLS:
				m_object[i].emplace_back(std::make_unique<Wall>(location, Shape::WALL));
				break;
			case MONE:
				m_object[i].emplace_back(std::make_unique<Money>(location, Shape::MONEY));
				break;
				break;
			case PRESENT:
				le.createGift(location);
				break;
			case GUARDS:
				le.createGuard(location);
				break;
			defualt:
				break;
			}
		}
	}

	return true;
}

void Board::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_object.size(); i++)
		for (int j = 0; j < m_object[i].size(); j++)
			if (m_object[i][j]->getDelete())
				deleteFromMat(i, j);
	for (int i = 0; i < m_object.size(); i++)
		for(int j=0;j<m_object[i].size();j++)
		m_object[i][j]->draw(window);

}

void Board::deleteFromMat(int i, int j)
{
	m_object[i].erase(m_object[i].begin() + j);
}

std::unique_ptr<NunActiveObject>& Board::getNunActiveObject(int i,int j)
{

	if (i >= m_object.size() || j >= m_object[i].size())
		throw std::out_of_range(" ");
	
	return m_object[i][j];
}

int Board::getNumOfColls()
{
	return m_numColls;
}

int Board::getNumOfRows()
{
	return m_numRows;
}

int Board::getSizeOfRows(int index)
{
	return m_object[index].size();
}
