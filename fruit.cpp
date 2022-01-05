#include "fruit.h"
#include "const.h"

#include <stdio.h>
#include <iostream>
#include <random>

Fruit::Fruit(Point center, Fl_Color color): Rectangle(center, EDGE, EDGE, FL_BLACK, color) {}

void Fruit::mouseMove(Point mouseLoc) {
}


void Fruit::detectLine(bool rec) {
  for (int i = 0; i < 2; i++){
    if (neighbours[i] != nullptr && neighbours[i + 2] != nullptr){
      if (getFillColor() == neighbours[i]->getFillColor() && getFillColor() == neighbours[i + 2]->getFillColor()) {
        setFillColor(FL_BLACK);
        neighbours[i]->setFillColor(FL_BLACK);
        neighbours[i + 2]->setFillColor(FL_BLACK);
      }
    }
  }
} 


void Fruit::swapFruits(Fruit *otherFruit) {
  
}

bool Fruit::mouseClick(Point mouseLoc) {

}

