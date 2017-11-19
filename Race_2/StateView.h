#ifndef __STATE_VIEW_COMMAND_H__
#define __STATE_VIEW_COMMAND_H__

class StateView
{
public:
	StateView();

	virtual bool View() = 0;
	virtual bool Clear() = 0;

	virtual ~StateView();
};

#endif