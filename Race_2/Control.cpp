#include "stdafx.h"

#include "Control.h"
#include "UpCommand.h"
#include "DownCommand.h"
#include "LeftCommand.h"
#include "RightCommand.h"
#include "UpLevelCommand.h"
#include "ViewRoadCommand.h"
#include "SaveGameCommand.h"
#include "CheckFailCommand.h"
#include "StartGameCommand.h"
#include "ClearRoadCommand.h"
#include "StartSaveGameCommand.h"
#include "SetBloksOnRoadCommand.h"

Control::Control()
{
	
}

void Control::startGame(int sizeRoad)
{
	command = new StartGameCommand(roadCommand, sizeRoad);
	command->Execute();
}

void Control::UpLevel(int difficult)
{
	command = new UpLevelCommand(roadCommand, difficult);
	command->Execute();
}

void Control::setBlockOnRoad()
{
	command = new SetBloksOnRoadCommand(roadCommand);
	command->Execute();
}

void Control::clearRoad()
{
	command = new ClearRoadCommand(roadCommand);
	command->Execute();
}

void Control::viewRoad()
{
	command = new ViewRoadCommand(roadCommand);
	command->Execute();
}

void Control::turnRight()
{
	command = new RightCommand(roadCommand);
	command->Execute();
}

void Control::turnLeft()
{
	command = new LeftCommand(roadCommand);
	command->Execute();
}


void Control::turnUp()
{
	command = new UpCommand(roadCommand);
	command->Execute();
}

void Control::turnDown()
{
	command = new DownCommand(roadCommand);
	command->Execute();
}


bool Control::isFail(global::CAR_CONTROL carControll)
{
	CheckFailCommand checkFailCommand(roadCommand, carControll);
	return checkFailCommand.isFail(carControll);
}

bool Control::saveGame(const Statistic* statistic)
{
	SaveGameCommand saveGameCommand(roadCommand, statistic);
	return saveGameCommand.isFailSave();
}

bool Control::startSaveGame()
{
	StartSaveGameCommand startSaveGameCommand(roadCommand);
	return startSaveGameCommand.isFailStartSaveGame();
}

Control::~Control()
{
	delete command;
}
