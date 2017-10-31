#include "stdafx.h"
#include "ViewRoadCommand.h"


ViewRoadCommand::ViewRoadCommand(Road& road) : Command(road)
{
}

void ViewRoadCommand::Execute()
{
	road.viewRoad();
}


ViewRoadCommand::~ViewRoadCommand()
{
}
