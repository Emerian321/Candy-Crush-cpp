#include "canvas.h"
#include "const.h"
#include <algorithm>
#include <stdio.h>
#include <iostream>

Canvas::Canvas() {
  for (int x = 0; x<gridSize; x++) {
    fruits.push_back({});
    for (int y = 0; y<gridSize; y++) {
      fruits[x].push_back(new Fruit{{56*x+25, 56*y+25}, COLORS[rand() % 6]});
    }
  }
  set_neighbours();
  destroyFruits();
}

void Canvas::set_neighbours() {
  for (int x = 0; x<gridSize; x++)
    for (int y = 0; y<gridSize; y++)
      fruits[x][y]->setNeighbours(find_neighbours(x, y));
}

std::vector <Fruit *>Canvas::find_neighbours(int x, int y) {
  std::vector <Fruit *> neighbours;
  for (auto DIRECTION: DIRECTIONS) {
    if(0 <= x+DIRECTION[0] && x+DIRECTION[0] < gridSize && 0 <= y+DIRECTION[1] && y+DIRECTION[1] < gridSize){
      neighbours.push_back(fruits[x+DIRECTION[0]][y+DIRECTION[1]]);
    }
    else{
      neighbours.push_back(nullptr);
    }
  }
  return neighbours;
}

bool Canvas::destroyFruits() {
  bool unstable=false;
  for (int x = 0; x<gridSize; x++) {
    for (int y = 0; y<gridSize; y++) {
      fruits[x][y]->detectLine(true);
    }
  }
  for (int x = 0; x<gridSize; x++) {
    for (auto f: fruits[x]) {
      if (f->isDestroyed()) {
        unstable=true;
      }
    }
  }
  return unstable;
}

void Canvas::swapFruits(Fruit *fruit1, Fruit *fruit2) {
  std::vector <int> pos1 = fruit1->getMatrixPos();
  fruits[pos1[0]][pos1[1]] = fruit2;
  fruit2->setScreenPos(pos1[0], pos1[1]);

  std::vector <int> pos2 = fruit2->getMatrixPos();
  fruits[pos2[0]][pos2[1]] = fruit1;
  fruit2->setScreenPos(pos2[0], pos2[1]);
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
        if (toSwap.size() == 2 && toSwap[0]->isNeighbour(toSwap[1])) {
          swapFruits(toSwap[0], toSwap[1]);
          for (auto s: toSwap) s->setFrameColor(FL_BLACK);
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