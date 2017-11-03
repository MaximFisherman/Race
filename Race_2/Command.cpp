#include "stdafx.h"
#include "Command.h"


Command::Command(RoadCommand& _roadCommand) : roadCommand(_roadCommand)
{
}


Command::~Command()
{
}