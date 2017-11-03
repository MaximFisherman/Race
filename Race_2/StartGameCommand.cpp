#include "stdafx.h"
#include "StartGameCommand.h"


StartGameCommand::StartGameCommand(RoadCommand& _roadCommand, int _sizeRoad) : Command(_roadCommand), sizeRoad(_sizeRoad)
{
	roadCommand.setSizeRoad(20, sizeRoad);
}

void StartGameCommand::Execute()
{
	
	roadCommand.initializationRoad();
}

StartGameCommand::~StartGameCommand()
{
}
