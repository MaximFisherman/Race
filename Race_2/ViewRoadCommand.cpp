#include "stdafx.h"
#include "ViewRoadCommand.h"


ViewRoadCommand::ViewRoadCommand(RoadCommand& _roadCommand) : Command(_roadCommand)
{
}

void ViewRoadCommand::Execute()
{
	roadCommand.viewRoad();
}


ViewRoadCommand::~ViewRoadCommand()
{
}
