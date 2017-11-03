#ifndef __START_GAME_COMMAND_H__
#define __START_GAME_COMMAND_H__

#include "Command.h"

class StartGameCommand : 
	public Command
{
public:
	StartGameCommand(RoadCommand& _roadCommand, int _sizeRoad);

	void Execute();

	~StartGameCommand();
private: 
	int sizeRoad;
};

#endif