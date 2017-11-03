#include "stdafx.h"
#include "ClearRoadCommand.h"


ClearRoadCommand::ClearRoadCommand(RoadCommand& _roadCommand) : Command(_roadCommand)
{
}

void ClearRoadCommand::Execute()
{
	roadCommand.clearRoad();
}


ClearRoadCommand::~ClearRoadCommand()
{
}
