#include "fruit.h"
#include "const.h"

#include <stdio.h>
#include <iostream>
#include <random>

Fruit::Fruit(Point center, Fl_Color color): Rectangle(center, EDGE, EDGE, FL_BLACK, color) {}

void Fruit::mouseMove(Point mouseLoc) {
}

bool Fruit::detectLine(bool rec) {
  bool lineFound = false;
  for (int i = 0; i < 2; i++){
    if (neighbours[i] != nullptr && neighbours[i + 2] != nullptr){
      if (getFillColor() == neighbours[i]->getFillColor() && getFillColor() == neighbours[i + 2]->getFillColor()) {
        this->setToDestroy();
        this->setFillColor(FL_BLACK);
        neighbours[i]->setToDestroy();
        neighbours[i]->setFillColor(FL_BLACK);
        neighbours[i + 2]->setToDestroy();
        neighbours[i + 2]->setFillColor(FL_BLACK);
        lineFound = true;
      }
    }
  }
  return lineFound;
}

bool Fruit::isNeighbour(Fruit *fruit) {
  for (auto c: neighbours)
    if (c == fruit) return true;
  return false;
}

bool Fruit::mouseClick(Point mouseLoc) {
  if (contains(mouseLoc)) {
    setFrameColor(FL_GREEN);
  }
  else {
    setFrameColor(FL_BLACK);
  }
  return contains(mouseLoc);
}

