#include "stdafx.h"
#include "SetBloksOnRoadCommand.h"


SetBloksOnRoadCommand::SetBloksOnRoadCommand(Road* road) : Command(road)
{
}


void SetBloksOnRoadCommand::Execute()
{
	road->setBlockOppositeLine();
	road->setBlockRoadLine();
}

SetBloksOnRoadCommand::~SetBloksOnRoadCommand()
{
}
