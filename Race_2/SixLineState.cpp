#include "stdafx.h"
#include "SixLineState.h"


SixLineState::SixLineState(const Road& _road)
{
	this->road = &const_cast<Road&>(_road);
}

bool SixLineState::fourLineRoad()
{
	return false;
}

bool SixLineState::sixLineRoad()
{
	return true;
}

SixLineState::~SixLineState()
{
	delete road;
}
