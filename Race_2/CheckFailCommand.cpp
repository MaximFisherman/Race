#include "stdafx.h"
#include "CheckFailCommand.h"


CheckFailCommand::CheckFailCommand(RoadCommand& _roadCommand, global::CAR_CONTROL _carControll) : Command(_roadCommand), carControll(_carControll)
{
}

bool CheckFailCommand::isFail(global::CAR_CONTROL carControll)
{
	return roadCommand.isFail(carControll);
}

void CheckFailCommand::Execute()
{
}


CheckFailCommand::~CheckFailCommand()
{
}
