#ifndef __SAVE_GAME_COMMAND_H__
#define __SAVE_GAME_COMMAND_H__

#include "Command.h"
class SaveGameCommand :
	public Command
{
public:
	SaveGameCommand(RoadCommand& _roadCommand, const Statistic* _statistic);
	
	bool isFailSave();
	void Execute();

	~SaveGameCommand();

private:
	Statistic* statistic;
};

#endif