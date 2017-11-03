#include "stdafx.h"
#include "UpLevelCommand.h"


UpLevelCommand::UpLevelCommand(RoadCommand& _roadCommand, int _difficult) : Command(_roadCommand),  difficult(_difficult)
{
}

void UpLevelCommand::Execute()
{
	roadCommand.setDifficult(difficult);
}


UpLevelCommand::~UpLevelCommand()
{
}
