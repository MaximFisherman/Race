#include "stdafx.h"
#include "CloseState.h"


CloseState::CloseState(const Statistic& _statistic)
{
	statistic = &const_cast<Statistic&>(_statistic);
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
	
}
