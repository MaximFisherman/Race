#include "stdafx.h"
#include "UpCommand.h"


UpCommand::UpCommand(Road* road) : Command(road)
{
}

void UpCommand::Execute()
{
	road->turnUp();
}


UpCommand::~UpCommand()
{
}
