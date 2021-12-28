#pragma once
#include "Observer.h"
class Subject
{
public:
	Subject()=default;
	virtual~Subject()=default;
	virtual void RegisterObserver(Observer* pObserver) = 0;

	virtual void RemoveObserver(Observer* pObserver) = 0;

	virtual void NotifyObservers(int index) = 0;
	virtual void NotifyObserversPlayer(int index,bool x) = 0;
	virtual void NotifyObserversDoor(bool x) = 0;

private:

};