#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "RoadCommand.h" 

class Command
{
protected:
	RoadCommand& roadCommand;
public:
	Command(RoadCommand& road);
	virtual ~Command();
	virtual void Execute() = 0;
};

#endif
