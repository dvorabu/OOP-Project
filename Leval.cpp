#include "Leval.h"
#include "Controller.h"
#include "Door.h"
#include "Money.h"
Leval::Leval(int numOfLevel/*, Player* player*/) :m_numLeval(numOfLevel), m_view(sf::FloatRect(START_BOARD, START_BOARD + GAME_MENU_SIZE.y, BOARD_SIZE.x, BOARD_SIZE.y))
,m_endLevel(false)/*, m_rec(BOARD_SIZE)*/
{
    ResourceManager::instance().getImage(m_numLeval).setRepeated(true);
    m_rec.setTexture((ResourceManager::instance().getImage(m_numLeval)));
    m_rec.setTextureRect({ 0, 0,6000, 2700 });

	m_view.setViewport({ 0.f, 0.25f, 1.f, 0.75f });
	m_rec.setPosition({ START_BOARD-200,START_BOARD + GAME_MENU_SIZE.y });

    ResourceManager::instance().getMusic().stop();
    ResourceManager::instance().getMusic().setLoop(55.0f);
    ResourceManager::instance().getMusic().play();
    ResourceManager::instance().getMusic().setVolume(55.f);

}

bool Leval::run(NewGame& no, sf::RenderWindow& window)
{
    no.getPlayer().getSprite().setPosition(PLAYER_LOCATION);
    no.getPlayer().RegisterObserver(this);
    m_board.readFile(window, no,*this);
    while (!m_endLevel&&!m_playeIsLose)
    {
        handelCollision(no);
         if(m_numLeval>1)
         createGuardShot();
        window.clear();
        draw(window, no); 
        window.display();
        handelEvent(window,no);
    }
    no.getPlayer().RemoveObserver(this);
    if (m_endLevel)
        return true;
    return false;
}

void Leval::draw(sf::RenderWindow& window, NewGame& ne)
{

	window.setView(m_view);
	window.draw(m_rec);
    for (int i = 0; i < m_guards.size(); i++)
        m_guards[i]->draw(window);
    for (int i = 0; i < m_gift.size(); i++) 
        m_gift[i]->draw(window);

       
    m_board.draw(window);
    ne.draw(m_clock);
}

void Leval::handelEvent(sf::RenderWindow& window, NewGame& ne)
{
    m_prevDirechtion = m_direchtion;
    if (auto event = sf::Event{}; window.waitEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            m_direchtion= keyToDirection((event.key.code));
            if (event.key.code == sf::Keyboard::Space)
                 ne.getPlayer().createShot();
            move(ne);
            break;
        }
    }
}

void Leval::move(NewGame& ne)
{

    const auto deltaTime = m_clock.restart();
    const auto speedPerSecond = 100.f;
    ne.setPlayerDirc(m_direchtion, deltaTime);
    for (int i = 0; i < m_guards.size(); i++)
        m_guards[i]->move(deltaTime,ne.getPlayerDirc());
    if (m_direchtion == DIRCTHION[Dirc::UP]|| m_direchtion == DIRCTHION[Dirc::DOWN])
        m_direchtion = m_prevDirechtion;
        if (handelPlayerCollision(ne))
        return;
    m_view.move(m_direchtion * speedPerSecond * deltaTime.asSeconds());
  
}

void Leval::setEndLevel()
{
    m_endLevel = !m_endLevel;
}

sf::Vector2f Leval::keyToDirection(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Left:
        return DIRCTHION[Dirc::LEFT];
    case sf::Keyboard::Right:
        return DIRCTHION[Dirc::RIGHT];
    case sf::Keyboard::Up:
        return DIRCTHION[Dirc::UP];
    case sf::Keyboard::Down:
        return DIRCTHION[Dirc::DOWN];
    default:
        return DIRCTHION[Dirc::DEFAULT];
    }   
    
}

int Leval::getLeval()
{
    return m_numLeval;
}

void Leval::createGift(sf::Vector2f location)
{
    m_gift.emplace_back(Factory::create(m_numLeval));
    m_gift[m_gift.size() - 1]->setPosition(location);
    m_gift[m_gift.size() - 1]->setIndex(m_gift.size() - 1);
}

void Leval::createGuard(sf::Vector2f location)
{

        m_guards.emplace_back(Factory::createGuard(location));
        m_guards[m_guards.size()-1]->setIndex(m_guards.size() - 1);
}

void Leval::createGuardShot()
{
    if (m_clockShot.getElapsedTime().asSeconds() >= 8.0f)
    {
        if (m_guards.size() == 0)
            return;
        m_guards[rand() % m_guards.size()]->createShot();
        m_clockShot.restart();
    }
}

void Leval::handelCollision(NewGame& ne)
{
    for (int i = 0; i < m_guards.size(); i++)
        if (m_guards[i]->objectGlobalBounds().intersects(ne.getPlayer().objectGlobalBounds()))
        {
            processCollision(ne.getPlayer(), *m_guards[i]);
        }
    int index = 0;
    while (index<m_guards.size())
    {
        for (int i = 0; i < m_board.getNumOfRows(); i++)
            for (int j = 0; j < m_board.getSizeOfRows(i); j++)
                if (m_board.getNunActiveObject(i, j)->objectGlobalBounds().contains(m_guards[index]->objectGlobal()))
            {
                processCollision(*m_guards[index], *m_board.getNunActiveObject(i, j));
            }
        index++;
    }
    for(int i=0;i<m_gift.size();i++)
        if (m_gift[i]->objectGlobalBounds().intersects(ne.getPlayerGlobalBounds()))
        {
            processCollision(ne.getPlayer(), *m_gift[i]);
        }
    handelShotCollision(ne);          
}

bool Leval::handelPlayerCollision(NewGame& ne)
{
    ne.getPlayer().setEnd(false);
    for (int i = 0; i < m_board.getNumOfRows(); i++)
        for (int j = 0; j < m_board.getSizeOfRows(i); j++)
            if (m_board.getNunActiveObject(i, j)->objectGlobalBounds().intersects(ne.getPlayer().objectGlobalBounds()))
            {
                processCollision(ne.getPlayer(), *m_board.getNunActiveObject(i, j));
            }
    return ne.getPlayer().getEnd();
}

void Leval::handelShotCollision(NewGame& ne)
{
    for (int i = 0; i < m_guards.size(); i++)
    for (int j = 0; j < ne.getPlayer().getShotSize(); j++)
        if (m_guards[i]->objectGlobalBounds().intersects(ne.getPlayer().getShotGlobal(j)))
        {
            m_guards.erase(m_guards.begin() + i);
            ne.getPlayer().deleteShot(j);
        }
    for (int i = 0; i < m_guards.size(); i++)
        for (int j = 0; j < m_guards[i]->getShotSize(); j++)
            if (m_guards[i]->getShotGlobal(j).intersects(ne.getPlayer().objectGlobalBounds()))
            {
                if (!ne.getPlayer().getProtection())
                {
                    ne.getPlayer().setLife(-1);
                    m_playeIsLose = true;
                }
              
            }

}

void Leval::UpdateColisionWithPesent(int presentIndex)
{
    m_gift.erase(m_gift.begin() + presentIndex);
    for (int i = 0; i < m_gift.size(); i++)
        m_gift[i]->setIndex(i);
}

void Leval::UpdateColisionWithGurd(int gurdIndex, bool x)
{
    m_guards.erase(m_guards.begin() + gurdIndex);
    for (int i = 0; i < m_guards.size(); i++)
        m_guards[i]->setIndex(i);
    m_playeIsLose = x;
}

void Leval::UpdateColisionWithDoor(bool x)
{
    m_endLevel = x;
}
