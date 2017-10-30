#pragma once
#include "Command.h"

class RightCommand :
	public Command
{
public:
	RightCommand(Road* road);

	void Execute();

	~RightCommand();
};

