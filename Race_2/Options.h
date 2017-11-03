#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#include "Control.h"

class Options : 
	public Control
{
public:
	Options();
	void saveGame();
	void startSaveGame();
	void pause();
	~Options();
};

#endif