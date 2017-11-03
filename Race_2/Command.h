#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "RoadCommand.h" 

class Command
{
protected:
	Command(RoadCommand& road);
	RoadCommand& roadCommand;
public:
	virtual ~Command();
	virtual void Execute() = 0;
};

#endif
