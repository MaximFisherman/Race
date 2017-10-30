#pragma once

const char SYMB_CAR = '^';
const char SYMB_ROAD = ' ';
const char SYMB_BLOCK = '#';
const int WIDTH_ROAD = 4;
const int HEIGHT_ROAD = 20;
const int BASE_SPEED = 400;
const int DIFFICULT = 7; // Affects the number of generated blocks.
const enum CAR_CONTROL { LEFT, RIGHT, UP, DOWN, NONE };