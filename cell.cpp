#include "cell.h"
#include "const.h"
#include <random>

Cell::Cell(Point center, int w, int h):
  r(center, w, h, FL_BLACK, FL_WHITE), center(center) {
  newFillColor();
  }

void Cell::draw() {
  r.draw();
}

void Cell::mouseMove(Point mouseLoc) {
  if (r.contains(mouseLoc)) {
    r.setFrameColor(FL_RED);
  } else {
    r.setFrameColor(FL_BLACK);
  }
}

void Cell::newFillColor(){
  this->fillcolor = colors[rand() % 5];
  this->r.setFillColor(this->fillcolor);
}

void Cell::mouseClick(Point mouseLoc) {
}
