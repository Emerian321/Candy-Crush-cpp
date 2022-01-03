FLAGS=-lfltk  -Wall -std=c++17

all: main

main: main.cpp rectangle.h rectangle.cpp cell.h cell.cpp canvas.h canvas.cpp fruit.h const.h
	g++ main.cpp rectangle.h rectangle.cpp cell.h cell.cpp canvas.h canvas.cpp fruit.h const.h -o main $(FLAGS)