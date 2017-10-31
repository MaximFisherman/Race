#ifndef __LEFT_COMMAND_H__
#define __LEFT_COMMAND_H__

#include "Command.h"

class LeftCommand : 
	public Command 
{
public:
	LeftCommand(Road& road);

	void Execute();

	~LeftCommand();
};

#endif