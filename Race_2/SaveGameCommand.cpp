#include "stdafx.h"
#include "SaveGameCommand.h"


SaveGameCommand::SaveGameCommand(RoadCommand& _roadCommand, Statistic* _statistic) : Command(_roadCommand)
{
	this->statistic = _statistic;
}

bool SaveGameCommand::isFailSave()
{
	return roadCommand.saveGame(statistic);
}

void SaveGameCommand::Execute()
{
	
}

SaveGameCommand::~SaveGameCommand()
{
	delete statistic;
}
