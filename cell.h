/*--------------------------------------------------

Cell class.

The Canvas class below will have cells as instance
vraiables and call the methods of Cell

--------------------------------------------------*/

#ifndef __CELL_H
#define __CELL_H

#include <vector>

#include "rectangle.h"

class Cell {
  Rectangle r;
  std::vector <Cell *> neighbours;
  Point center;
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

  // Objects methods

  // Methods that draw and handle events
  void draw();
  void mouseMove(Point mouseLoc);
  void mouseClick(Point mouseLoc);

};

#endif