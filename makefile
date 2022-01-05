FLAGS=-lfltk  -Wall -std=c++17

all: main

main: main.cpp rectangle.h rectangle.cpp fruit.h fruit.cpp canvas.h canvas.cpp const.h virtual.h
	g++ main.cpp rectangle.h rectangle.cpp fruit.h fruit.cpp canvas.h canvas.cpp const.h virtual.h -o main $(FLAGS)