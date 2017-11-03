#include "stdafx.h"
#include "RightCommand.h"


RightCommand::RightCommand(RoadCommand& _roadCommand) : Command(_roadCommand)
{
}

void RightCommand::Execute()
{
	roadCommand.turnRight();
}


RightCommand::~RightCommand()
{
}
