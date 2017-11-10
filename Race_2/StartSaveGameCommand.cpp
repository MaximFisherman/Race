#include "stdafx.h"
#include "StartSaveGameCommand.h"


StartSaveGameCommand::StartSaveGameCommand(RoadCommand& _roadCommand) : Command(_roadCommand)
{
}

void StartSaveGameCommand::Execute()
{
	roadCommand.startSaveGame();
}

StartSaveGameCommand::~StartSaveGameCommand()
{
}
