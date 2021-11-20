#ifndef __CANVAS_H
#define __CANVAS_H

#include <vector>

#include "point.h"
#include "cell.h"

class Canvas {
  vector< vector<Cell> > cells;
 public:
  // Constructeur
  Canvas();

  // Complément Constructeur
  void set_bombs();
  void set_neighbors();
  vector <Cell *>find_neighbors(int x, int y);
    void set_nearBombs();
  // Draw
  void draw();

  // Gestion de la souris/clavier
  void mouseMove(Point mouseLoc);
  void mouseClick(Point mouseLoc);
  void keyPressed(int keyCode);
};

#endif