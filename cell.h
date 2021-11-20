#ifndef __CELL_H
#define __CELL_H

#include<vector>

#include "rectangle.h"
#include "point.h"

class Cell {
  Rectangle r;
  bool is_bomb = false;
  vector <Cell *> neighbors;
  int nearBomb = 0;
  Point center;
  bool revealed = false;
 public:
  // Constructor
  Cell(Point center, int w, int h);

  // Setters/Getters
  void setBomb() {
  is_bomb = true;
  }
  bool getBomb() {
  return is_bomb;
  }
  int getNearBomb () {
    return nearBomb;
  }
  void setNeighbors(vector <Cell *> found_neighbors) {
    neighbors = found_neighbors;
  }
  vector <Cell *> getNeighbors() {
    return neighbors;
  }

  // Objects methods
  void NearBombCount();
  void reveal();
  void endgame();

  // Methods that draw and handle events
  void draw();
  void mouseMove(Point mouseLoc);
  void mouseClick(Point mouseLoc);

};

#endif