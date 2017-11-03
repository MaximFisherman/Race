#ifndef __UP_COMMAND_H__
#define __UP_COMMAND_H__

#include "Command.h"

class UpCommand : 
	public Command
{
public:
	UpCommand(RoadCommand& _roadCommand);

	void Execute();

	~UpCommand();
};

#endif