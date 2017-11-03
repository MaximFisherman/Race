#ifndef __STATE_H__
#define __STATE_H__

class State
{
public:
	State();
	virtual bool View() = 0;
	virtual bool Clear() = 0;
	~State();
};

#endif