#pragma once
#include "Command.h"

class SetBloksOnRoadCommand : 
	public Command
{
public:
	SetBloksOnRoadCommand(Road* road);

	void Execute();

	~SetBloksOnRoadCommand();
};

