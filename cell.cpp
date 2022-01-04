#include "cell.h"
#include "const.h"
#include <stdio.h>
#include <iostream>

Cell::Cell(Point center):
  r(center, EDGE, EDGE), center{center}, fruit{new Fruit(center)} {
  }

void Cell::draw() {
  fruit->draw();
}

void Cell::mouseMove(Point mouseLoc) {
  if (r.contains(mouseLoc)) {
    r.setFrameColor(FL_RED);
  } else {
    r.setFrameColor(FL_BLACK);
  }
}

void Cell::DetectLine(bool rec) {
  for (int i = 0; i < 2; i++){
    if (neighbours[i] != nullptr && neighbours[i + 2] != nullptr){
      if (fruit->getColor() == neighbours[i]->fruit->getColor() && fruit->getColor() == neighbours[i + 2]->fruit->getColor()) {
        fruit->setColor(FL_BLACK);
        neighbours[i]->fruit->setColor(FL_BLACK);
        neighbours[i + 2]->fruit->setColor(FL_BLACK);
      }
    }
  }
} 

bool Cell::mouseClick(Point mouseLoc) {
  return fruit->mouseClick(mouseLoc);
}

