#ifndef __CHECK_FAIL_COMMAND_H__
#define __CHECK_FAIL_COMMAND_H__

#include "Command.h"

class CheckFailCommand :
	public Command
{
public:
	CheckFailCommand(Road& road, CAR_CONTROL _carControll);

	bool isFail(CAR_CONTROL carControll);
	void Execute();

	~CheckFailCommand();

private:
	CAR_CONTROL carControll;
};

#endif

