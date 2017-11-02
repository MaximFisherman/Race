#include "stdafx.h"

#include "Control.h"
#include "UpCommand.h"
#include "DownCommand.h"
#include "LeftCommand.h"
#include "RightCommand.h"
#include "UpLevelCommand.h"
#include "ViewRoadCommand.h"
#include "CheckFailCommand.h"
#include "StartGameCommand.h"
#include "ClearRoadCommand.h"
#include "SetBloksOnRoadCommand.h"

Control::Control()
{
}

void Control::startGame(int sizeRoad)
{
	command = new StartGameCommand(road, sizeRoad);
	command->Execute();
}

void Control::UpLevel(int difficult)
{
	command = new UpLevelCommand(road, difficult);
	command->Execute();
}

void Control::setBlockOnRoad()
{
	command = new SetBloksOnRoadCommand(road);
	command->Execute();
}

void Control::clearRoad()
{
	command = new ClearRoadCommand(road);
	command->Execute();
}

void Control::viewRoad()
{
	command = new ViewRoadCommand(road);
	command->Execute();
}

void Control::turnRight()
{
	command = new RightCommand(road);
	command->Execute();
}

void Control::turnLeft()
{
	command = new LeftCommand(road);
	command->Execute();
}


void Control::turnUp()
{
	command = new UpCommand(road);
	command->Execute();
}

void Control::turnDown()
{
	command = new DownCommand(road);
	command->Execute();
}


bool Control::isFail(global::CAR_CONTROL carControll)
{
	CheckFailCommand checkFailCommand(road, carControll);
	return checkFailCommand.isFail(carControll);
}

Control::~Control()
{
}
