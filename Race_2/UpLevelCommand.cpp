#include "stdafx.h"
#include "UpLevelCommand.h"


UpLevelCommand::UpLevelCommand(Road& road, int _difficult) : Command(road),  difficult(_difficult)
{
}

void UpLevelCommand::Execute()
{
	road.setDifficult(difficult);
}


UpLevelCommand::~UpLevelCommand()
{
}
