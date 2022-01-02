/*--------------------------------------------------
Constants header file
--------------------------------------------------*/

#ifndef __CONST_H
#define __CONST_H

#include <vector>
#include <FL/Fl.H>

const int DIRECTIONS[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

//canvas.cpp
const int gridSize = 9;

//cell.cpp
const std::vector <Fl_Color> colors = {FL_RED, FL_BLUE, FL_MAGENTA, FL_GREEN, FL_YELLOW};

//main.cpp
const int windowWidth = 500;
const int windowHeight = 500;
const double refreshPerSecond = 60;

#endif
