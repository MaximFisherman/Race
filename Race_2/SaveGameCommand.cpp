#include "stdafx.h"
#include "SaveGameCommand.h"


SaveGameCommand::SaveGameCommand(RoadCommand& _roadCommand, const Statistic* _statistic) : Command(_roadCommand)
{
	this->statistic = const_cast<Statistic*>(_statistic);
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
