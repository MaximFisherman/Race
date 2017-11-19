#include "stdafx.h"
#include "OpenState.h"


OpenState::OpenState(const Statistic& _statistic)
{
	this->statistic = &const_cast<Statistic&>(_statistic);
}

bool OpenState::View()
{
	return true;
}

bool OpenState::Clear()
{
	return false;
}

OpenState::~OpenState()
{
	delete statistic;
}
