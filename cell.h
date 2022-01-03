/*--------------------------------------------------

Cell class.

The Canvas class below will have cells as instance
vraiables and call the methods of Cell

--------------------------------------------------*/

#ifndef __CELL_H
#define __CELL_H

#include <vector>
#include <random>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

#include "rectangle.h"

class Cell {
  Rectangle r;
  std::vector <Cell *> neighbours;
  Point center;
  Fl_Color fillcolor;
  bool toDestroy = false;

 public:
  // Constructor
  Cell(Point center, int w, int h);

  // Setters/Getters
  std::vector <Cell *> getNeighbours() {
    return neighbours;
  }
  void setNeighbours(std::vector<Cell *> found_neighbours) {
    this->neighbours = found_neighbours;
  }

  void setToDestroy() {
    toDestroy = true;
  }

  // Objects methods
  void DetectLine(bool rec=true);

  // Methods that draw and handle events
  void draw();
  void mouseMove(Point mouseLoc);
  void mouseClick(Point mouseLoc);

};

#endif