#include "stdafx.h"
#include "SaveGameCommand.h"


SaveGameCommand::SaveGameCommand(RoadCommand& _roadCommand, Statistic* _statistic) : Command(_roadCommand)
{
	this->statistic = _statistic;
}

void SaveGameCommand::Execute()
{
	roadCommand.saveGame(statistic);
}


SaveGameCommand::~SaveGameCommand()
{
	delete statistic;
}
