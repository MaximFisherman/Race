#ifndef __RIGHT_COMMAND_H__
#define __RIGHT_COMMAND_H__

#include "Command.h"

class RightCommand :
	public Command
{
public:
	RightCommand(Road& road);

	void Execute();

	~RightCommand();
};

#endif