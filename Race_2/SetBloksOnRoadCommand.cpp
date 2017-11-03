#include "stdafx.h"
#include "SetBloksOnRoadCommand.h"


SetBloksOnRoadCommand::SetBloksOnRoadCommand(RoadCommand& _roadCommand) : Command(_roadCommand)
{
}


void SetBloksOnRoadCommand::Execute()
{
	roadCommand.setBlockOppositeLine();
	roadCommand.setBlockRoadLine();
}

SetBloksOnRoadCommand::~SetBloksOnRoadCommand()
{
}
