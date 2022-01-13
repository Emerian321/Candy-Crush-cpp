#include "fruit.h"
#include "const.h"

#include <stdio.h>
#include <iostream>
#include <random>

Fruit::Fruit(Point center, Fl_Color color): Rectangle(center, EDGE, EDGE, FL_BLACK, color) {}

void Fruit::mouseMove(Point mouseLoc) {
}

bool Fruit::detectLine() {
  //Check if the cell is in the middle of a 3 same color fruit combination.
  //Fruit combinations can only be vertical or horizontal.
  bool lineFound = false;
  for (int i = 0; i < 2; i++){
    //if the Fruit is between two other fruits
    if (neighbours[i] != nullptr && neighbours[i + 2] != nullptr){
      //check if their color match
      if (getFillColor() == neighbours[i]->getFillColor() && getFillColor() == neighbours[i + 2]->getFillColor()) {
        this->setToDestroy();
        neighbours[i]->setToDestroy();
        neighbours[i + 2]->setToDestroy();
        lineFound = true;
      }
    }
  }
  return lineFound;
}

bool Fruit::isNeighbour(Fruit *fruit) {
  //check if two fruits are neighbours
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

