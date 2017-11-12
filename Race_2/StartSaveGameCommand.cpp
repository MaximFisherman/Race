#include "stdafx.h"
#include "StartSaveGameCommand.h"


StartSaveGameCommand::StartSaveGameCommand(RoadCommand& _roadCommand) : Command(_roadCommand)
{
}

bool StartSaveGameCommand::isFailStartSaveGame()
{
	return roadCommand.startSaveGame();;
}

void StartSaveGameCommand::Execute()
{
	
}

StartSaveGameCommand::~StartSaveGameCommand()
{
}
