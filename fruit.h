/*--------------------------------------------------

Fruit class.

The Canvas class below will have Fruits as instance
vraiables and call the methods of Fruit

--------------------------------------------------*/

#ifndef __FRUIT_H
#define __FRUIT_H

#include <vector>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

#include "rectangle.h"

class Fruit: public Rectangle {
  Fl_Color color;
  std::vector <Fruit *> neighbours;
  bool destroy = false;

 public:
  // Constructor
  Fruit(Point center, Fl_Color color);

  // Setters/Getters
  std::vector <Fruit *> getNeighbours() {
    return neighbours;
  }
  void setNeighbours(std::vector<Fruit *> found_neighbours) {
    this->neighbours = found_neighbours;
  }

  std::vector <int> getMatrixPos(){
    std::vector <int> pos;
    pos.push_back((getCenter().x - 25) / 56);
    pos.push_back((getCenter().y - 25) / 56);
    return pos;
  }

  void setToDestroy() {
    destroy = true;
  }

  // Objects methods
  void detectLine(bool rec);
  void swapFruits(Fruit *otherFruit);

  // Methods that draw and handle events
  void mouseMove(Point mouseLoc);
  bool mouseClick(Point mouseLoc);

};

#endif
