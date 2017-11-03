#include "stdafx.h"
#include "LeftCommand.h"


LeftCommand::LeftCommand(RoadCommand& _roadCommand) : Command(_roadCommand)
{
}

void LeftCommand::Execute()
{
	roadCommand.turnLeft();
}


LeftCommand::~LeftCommand()
{
}
