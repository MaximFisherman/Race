#include "stdafx.h"
#include "StartGameCommand.h"


StartGameCommand::StartGameCommand(Road& road, int _sizeRoad) : Command(road), sizeRoad(_sizeRoad)
{
	road.setSizeRoad(20, sizeRoad);
}

void StartGameCommand::Execute()
{
	
	road.initializationRoad();
}

StartGameCommand::~StartGameCommand()
{
}
