#include "stdafx.h"
#include "DownCommand.h"


DownCommand::DownCommand(RoadCommand& _roadCommand) : Command(_roadCommand)
{
}

void DownCommand::Execute()
{
	roadCommand.turnDown();
}


DownCommand::~DownCommand()
{
}
