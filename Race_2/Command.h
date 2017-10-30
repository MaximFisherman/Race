#pragma once
#include "Road.h" 
class Command
{
protected:
	Command(Road* road);
	Road* road;
public:
	virtual ~Command();
	virtual void Execute() = 0;
};

