#include "stdafx.h"
#include "CalculateState.h"


CalculateState::CalculateState(const Statistic& _statistic)
{
	statistic = _statistic;
}

bool CalculateState::View()
{
	return true;
}

bool CalculateState::Clear()
{
	return false;
}

CalculateState::~CalculateState()
{
}
