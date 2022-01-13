#include "canvas.h"
#include "const.h"
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <chrono>

Canvas::Canvas() {
  //plate initialisation
  for (int x = 0; x<gridSize; x++) {
    fruits.push_back({});
    for (int y = 0; y<gridSize; y++) {
      fruits[x].push_back(new Fruit{{56*x+25, 56*y+25}, COLORS[rand() % 6]});
    }
  }
  //neighbours detection  and attribution
  set_neighbours();
  //while the board still has 3 same color Fruit raws, destroy them
  while(destroyFruits()) {}
}

void Canvas::set_neighbours() {
  for (int x = 0; x<gridSize; x++)
    for (int y = 0; y<gridSize; y++)
      fruits[x][y]->setNeighbours(find_neighbours(x, y));
}

std::vector <Fruit *>Canvas::find_neighbours(int x, int y) {
  std::vector <Fruit *> neighbours;
  //for each possible cardinality, check if the new position is still in the board. If so, it's a neighbour.
  for (auto DIRECTION: DIRECTIONS) {
    if(0 <= x+DIRECTION[0] && x+DIRECTION[0] < gridSize && 0 <= y+DIRECTION[1] && y+DIRECTION[1] < gridSize){
      neighbours.push_back(fruits[x+DIRECTION[0]][y+DIRECTION[1]]);
    }
    else{
      //if the new position is out of board, we replace a fruit with a nullpointer.
      neighbours.push_back(nullptr);
    }
  }
  return neighbours;
}

bool Canvas::destroyFruits() {
  bool unstable=false;
  for (int x = 0; x<gridSize; x++) {
    for (int y = 0; y<gridSize; y++) {
      //for each cell, check if they are sharing color with two of their neighbours horizontally or vertically
      fruits[x][y]->detectLine();
    }
  }
  for (int x = 0; x<gridSize; x++) {
    for (auto f: fruits[x]) {
      if (f->isDestroyed()) {
        //if the fruit is marked as a Fruit to destroy
        f->setToCreate();
        //it is no longer
        unstable=true;
        auto fMatPos = f->getMatrixPos();
        while (fMatPos[1] > 0){ //while the fruit is not all the way up
          swapFruits(f, fruits[fMatPos[0]][fMatPos[1] - 1]); //he swaps with his upper neighbour
          fMatPos = f->getMatrixPos();
        }
        f->setFillColor(COLORS[rand() % 6]); //when he finally reach the top, the fruit gets assigned a new color
      }
    }
  }
  return unstable;
}

void Canvas::swapFruits(Fruit *fruit1, Fruit *fruit2) {
  std::vector <int> pos1 = fruit1->getMatrixPos();
  auto row1 = fruits[pos1[0]];
  std::vector <int> pos2 = fruit2->getMatrixPos();
  auto row2 = fruits[pos2[0]];
  fruits[pos1[0]][pos1[1]] = fruit2;
  fruits[pos2[0]][pos2[1]] = fruit1;
  fruit1->setScreenPos(pos2[0], pos2[1]);
  fruit2->setScreenPos(pos1[0], pos1[1]);
  set_neighbours();
}

void Canvas::draw() {
  for (auto &v: fruits)
    for (auto &f: v)
      f->draw();
}

void Canvas::mouseMove(Point mouseLoc) {
  for (auto &v: fruits)
    for (auto &f: v)
      f->mouseMove(mouseLoc);
}

void Canvas::mouseClick(Point mouseLoc) {
  for (auto v: fruits)
    for (auto f: v)
      if (f->mouseClick(mouseLoc)){
        toSwap.push_back(f);
        if (toSwap[0]->isNeighbour(toSwap[1])) {
          swapFruits(toSwap[0], toSwap[1]);
          if (!(destroyFruits())){
            swapFruits(toSwap[0], toSwap[1]);
          }
          while(destroyFruits());
          toSwap.clear();
        }
        if (toSwap.size() >= 2){
          toSwap.clear();
        }
      }
}

void Canvas::keyPressed(int keyCode) {
  switch (keyCode) {
    case 'q':
      exit(0);
  }
}