#include "stdafx.h"
#include "CheckFailCommand.h"


CheckFailCommand::CheckFailCommand(Road& road, global::CAR_CONTROL _carControll) : Command(road), carControll(_carControll)
{
}

bool CheckFailCommand::isFail(global::CAR_CONTROL carControll)
{
	return road.isFail(carControll);
}

void CheckFailCommand::Execute()
{
}


CheckFailCommand::~CheckFailCommand()
{
}
