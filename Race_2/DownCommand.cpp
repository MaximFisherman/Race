#include "stdafx.h"
#include "DownCommand.h"


DownCommand::DownCommand(Road* road) : Command(road)
{
}

void DownCommand::Execute()
{
	road->turnDown();
}


DownCommand::~DownCommand()
{
}
