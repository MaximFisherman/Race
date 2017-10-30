#pragma once
#include "Command.h"

class DownCommand :
	public Command
{
public:
	DownCommand(Road* road);

	void Execute();

	~DownCommand();
};

