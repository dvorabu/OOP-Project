#pragma once
#include "Gift.h"
#include "Guard.h"
#include "Shot.h"
typedef std::vector<std::vector<std::unique_ptr<Gift>(*)()>>mymat;
typedef std::unique_ptr<MoveStrategy>(*moveFunc)();

class Factory
{
public:
	Factory()=default;
	~Factory()=default;
	static std::unique_ptr<Gift> create(int numOfLeval);
	static bool registerit(int i,std::unique_ptr<Gift>(*f)());
	static bool registerMove(moveFunc mf);
	static std::unique_ptr<Guard> createGuard(sf::Vector2f location);
	static std::unique_ptr<Shot> createShot(sf::Vector2f location);
private:
	static mymat& getMat()
	{
		static mymat m_mat(MAX_NUM_OF_LEVAL);
		return m_mat;
	}
	static std::vector<moveFunc>& getMoveVec()
	{
		static std::vector<moveFunc> m_moveVec;

		return m_moveVec;
	}

};
