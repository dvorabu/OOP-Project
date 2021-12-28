#pragma once
#include "Command.h"
class Controller;

class StartCommand :public Command
{
public:
	StartCommand(Controller& co);
	~StartCommand() = default;
	virtual void execute()override;
private:

	Controller& m_co;
};