#ifndef __UP_LEVEL_COMMAND_H__
#define __UP_LEVEL_COMMAND_H__

#include "Command.h"

class UpLevelCommand:
	public Command
{
public:
	UpLevelCommand(Road& road, int _difficult);

	void Execute();

	~UpLevelCommand();

private: 
	int difficult;
};

#endif
