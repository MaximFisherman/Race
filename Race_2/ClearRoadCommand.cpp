#include "stdafx.h"
#include "ClearRoadCommand.h"


ClearRoadCommand::ClearRoadCommand(Road* road) : Command(road)
{
}

void ClearRoadCommand::Execute()
{
	road->clearRoad();
}


ClearRoadCommand::~ClearRoadCommand()
{
}
