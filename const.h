/*--------------------------------------------------
Constants header file
--------------------------------------------------*/

#ifndef __CONST_H
#define __CONST_H

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <vector>

const int DIRECTIONS[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; //Haut Droite Bas Gauche

//cell.cpp
const int EDGE = 45;

//fruit.cpp
const Fl_Color COLORS[6] = {FL_RED, FL_DARK_RED, FL_YELLOW, FL_GREEN, FL_BLUE, FL_MAGENTA};

//canvas.cpp
const int gridSize = 9;

//cell.cpp
const std::vector <Fl_Color> colors = {FL_RED, FL_BLUE, FL_MAGENTA, FL_GREEN, FL_YELLOW};

//main.cpp
const int windowWidth = 500;
const int windowHeight = 500;
const double refreshPerSecond = 60;

#endif
