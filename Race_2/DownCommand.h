#ifndef __DOWN_COMMAND_H__
#define __DOWN_COMMAND_H__

#include "Command.h"

class DownCommand :
	public Command
{
public:
	DownCommand(RoadCommand& _roadCommand);

	void Execute();

	~DownCommand();
};

#endif