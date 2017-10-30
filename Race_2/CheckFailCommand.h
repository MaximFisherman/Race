#pragma once
#include "Command.h"

class CheckFailCommand :
	public Command
{
private:
	CAR_CONTROL carControll;
public:
	CheckFailCommand(Road* road, CAR_CONTROL _carControll);

	bool isFail(CAR_CONTROL carControll);
	void Execute();

	~CheckFailCommand();
};

