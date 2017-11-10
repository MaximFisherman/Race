#pragma once
#include "Command.h"
class SaveGameCommand :
	public Command
{
public:
	SaveGameCommand(RoadCommand& _roadCommand, Statistic* _statistic);
	void Execute();
	~SaveGameCommand();

private:
	Statistic* statistic;
};

