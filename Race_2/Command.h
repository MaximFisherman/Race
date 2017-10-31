#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "Road.h" 

class Command
{
protected:
	Command(Road& road);
	Road& road;
public:
	virtual ~Command();
	virtual void Execute() = 0;
};

#endif
