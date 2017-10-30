#pragma once
#include "Command.h"

class ViewRoadCommand : 
	public Command 
{
public:
	ViewRoadCommand(Road* road);

	void Execute();

	~ViewRoadCommand();
};

