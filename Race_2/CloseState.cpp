#include "stdafx.h"
#include "CloseState.h"


CloseState::CloseState(Statistic* _statistic) : statistic(_statistic)
{

}

bool CloseState::View()
{
	return false;
}

bool CloseState::Clear()
{
	return true;
}

CloseState::~CloseState()
{
	delete statistic;
}
