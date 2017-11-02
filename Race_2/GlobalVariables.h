#ifndef __GLOBAL_VARIABLES_H__
#define __GLOBAL_VARIABLES_H__

namespace global {
	const char SYMB_CAR = '^';
	const char SYMB_ROAD = ' ';
	const char SYMB_BLOCK = '#';
	const int BASE_SPEED = 400;
	const int INCREASE_SPEED = 10;
	const double KILOMETR_PER_SECOND = 0.000277778;
	const int CONVERT_TIME = 60;
	const int LEVEL_ONE = 1;
	const int SIX_WAY_ROAD = 6;
	const int FOUR_WAY_ROAD = 4;
	const int DIFFICULT_LEVEL_ONE = 7;
	const int DIFFICULT_LEVEL_TWO = 6;
	const int DIFFICULT_LEVEL_THREE = 5;
	const int DIFFICULT_LEVEL_FOUR = 4;
	const int LEVEL_TWO = 2;
	const int LEVEL_THREE = 5;
	const int LEVEL_FOUR = 10;
	const enum CAR_CONTROL { LEFT, RIGHT, UP, DOWN, NONE };
}

#endif