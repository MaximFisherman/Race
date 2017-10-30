#include "stdafx.h"
#include "LeftCommand.h"


LeftCommand::LeftCommand(Road* road) : Command(road)
{
}

void LeftCommand::Execute()
{
	road->turnLeft();
}


LeftCommand::~LeftCommand()
{
}
