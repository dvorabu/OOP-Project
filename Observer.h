#pragma once
class Observer
{
public:
	Observer()=default;
	virtual~Observer()=default;
	virtual void UpdateColisionWithPesent(int presentIndex) = 0;
	virtual void UpdateColisionWithGurd(int gurdIndex,bool x) = 0;
	virtual void UpdateColisionWithDoor(bool x) = 0;
private:

};
