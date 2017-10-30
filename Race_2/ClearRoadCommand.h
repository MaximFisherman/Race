#pragma once
#include "Command.h"

class ClearRoadCommand :
	public Command
{
public:
	ClearRoadCommand(Road* road);

	void Execute();

	~ClearRoadCommand();
};

