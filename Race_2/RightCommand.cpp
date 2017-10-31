#include "stdafx.h"
#include "RightCommand.h"


RightCommand::RightCommand(Road& road) : Command(road)
{
}

void RightCommand::Execute()
{
	road.turnRight();
}


RightCommand::~RightCommand()
{
}
