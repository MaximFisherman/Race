#include "stdafx.h"
#include "FourLineState.h"


FourLineState::FourLineState(const Road& _road)
{
	this->road = &const_cast<Road&>(_road);
}

bool FourLineState::fourLineRoad()
{
	return true;
}

bool FourLineState::sixLineRoad()
{
	return false;
}

FourLineState::~FourLineState()
{
	delete road;
}
