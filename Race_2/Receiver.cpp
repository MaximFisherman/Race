#include "stdafx.h"

#include "Receiver.h"
#include "UpCommand.h"
#include "DownCommand.h"
#include "LeftCommand.h"
#include "RightCommand.h"
#include "ViewRoadCommand.h"
#include "CheckFailCommand.h"
#include "ClearRoadCommand.h"
#include "SetBloksOnRoadCommand.h"

Receiver::Receiver()
{
}

void Receiver::setBlockOnRoad()
{
	command = new SetBloksOnRoadCommand(&road);
	command->Execute();
}

void Receiver::clearRoad()
{
	command = new ClearRoadCommand(&road);
	command->Execute();
}

void Receiver::viewRoad()
{
	command = new ViewRoadCommand(&road);
	command->Execute();
}

void Receiver::turnRight()
{
	command = new RightCommand(&road);
	command->Execute();
}

void Receiver::turnLeft()
{
	command = new LeftCommand(&road);
	command->Execute();
}

void Receiver::turnUp()
{
	command = new UpCommand(&road);
	command->Execute();
}

void Receiver::turnDown()
{
	command = new DownCommand(&road);
	command->Execute();
}


bool Receiver::isFail(CAR_CONTROL carControll)
{
	CheckFailCommand checkFailCommand(&road, carControll);
	return checkFailCommand.isFail(carControll);
}

Receiver::~Receiver()
{
}
