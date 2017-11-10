#ifndef __START_SAVE_GAME_COMMAND_H__
#define __START_SAVE_GAME_COMMAND_H__

#include "Command.h"

class StartSaveGameCommand : 
	public Command
{
public:
	StartSaveGameCommand(RoadCommand& _roadCommand);
	void Execute();
	~StartSaveGameCommand();
};

#endif