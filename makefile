FLAGS=-lfltk  -Wall -std=c++17

all: main

main: main.cpp rectangle.h rectangle.cpp cell.h cell.cpp canvas.h canvas.cpp
	g++ main.cpp rectangle.h rectangle.cpp cell.h cell.cpp canvas.h canvas.cpp -o main $(FLAGS)