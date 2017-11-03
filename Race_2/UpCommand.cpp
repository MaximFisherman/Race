#include "stdafx.h"
#include "UpCommand.h"


UpCommand::UpCommand(RoadCommand& _roadCommand) : Command(_roadCommand)
{
}

void UpCommand::Execute()
{
	roadCommand.turnUp();
}


UpCommand::~UpCommand()
{
}
