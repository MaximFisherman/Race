#ifndef __RIGHT_COMMAND_H__
#define __RIGHT_COMMAND_H__

#include "Command.h"

class RightCommand :
	public Command
{
public:
	RightCommand(RoadCommand& _roadCommand);

	void Execute();

	~RightCommand();
};

#endif