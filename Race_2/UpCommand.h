#pragma once
#include "Command.h"

class UpCommand : 
	public Command
{
public:
	UpCommand(Road* road);

	void Execute();

	~UpCommand();
};

