#ifndef __CHECK_FAIL_COMMAND_H__
#define __CHECK_FAIL_COMMAND_H__

#include "Command.h"

class CheckFailCommand :
	public Command
{
public:
	CheckFailCommand(RoadCommand& _roadCommand, global::CAR_CONTROL _carControll);

	bool isFail(global::CAR_CONTROL carControll);
	void Execute();

	~CheckFailCommand();

private:
	global::CAR_CONTROL carControll;
};

#endif

