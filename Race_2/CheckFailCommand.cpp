#include "stdafx.h"
#include "CheckFailCommand.h"


CheckFailCommand::CheckFailCommand(Road& road, CAR_CONTROL _carControll) : Command(road), carControll(_carControll)
{
}

bool CheckFailCommand::isFail(CAR_CONTROL carControll)
{
	return road.isFail(carControll);
}

void CheckFailCommand::Execute()
{
}


CheckFailCommand::~CheckFailCommand()
{
}
