#pragma once
#include "Command.h"

class LeftCommand : 
	public Command 
{
public:
	LeftCommand(Road* road);

	void Execute();

	~LeftCommand();
};

