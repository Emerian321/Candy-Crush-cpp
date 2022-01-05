#include "canvas.h"
#include "const.h"
#include <algorithm>
#include <stdio.h>
#include <iostream>

Canvas::Canvas() {
  for (int x = 0; x<gridSize; x++) {
    fruits.push_back({});
    for (int y = 0; y<gridSize; y++) {
      fruits[x].push_back({{56*x+25, 56*y+25}, COLORS[rand() % 6]});
    }
  }
  set_neighbours();
  for (int x = 0; x<gridSize; x++) {
    for (int y = 0; y<gridSize; y++) {
      fruits[x][y].detectLine(true);
    }
  }
}

void Canvas::set_neighbours() {
  for (int x = 0; x<gridSize; x++)
    for (int y = 0; y<gridSize; y++)
      fruits[x][y].setNeighbours(find_neighbours(x, y));
}

std::vector <Fruit *>Canvas::find_neighbours(int x, int y) {
  std::vector <Fruit *> neighbours;
  for (auto DIRECTION: DIRECTIONS) {
    if(0 <= x+DIRECTION[0] && x+DIRECTION[0] < gridSize && 0 <= y+DIRECTION[1] && y+DIRECTION[1] < gridSize){
      neighbours.push_back(&fruits[x+DIRECTION[0]][y+DIRECTION[1]]);
    }
    else{
      neighbours.push_back(nullptr);
    }
  }
  return neighbours;
}

void Canvas::draw() {
  for (auto &v: fruits)
    for (auto &f: v)
      f.draw();
}

void Canvas::mouseMove(Point mouseLoc) {
  for (auto &v: fruits)
    for (auto &f: v)
      f.mouseMove(mouseLoc);
}

void Canvas::mouseClick(Point mouseLoc) {
  for (auto &v: fruits)
    for (auto &f: v)
      if (f.mouseClick(mouseLoc)){
        ToSwap.push_back(f);
        if (ToSwap.size() == 2 
        && std::find(ToSwap[1].getNeighbours().begin(), ToSwap[1].getNeighbours().end(), &ToSwap[0]) != ToSwap[1].getNeighbours().end()){
  
        }
      for (auto &f: ToSwap) {
        f.setFrameColor(FL_BLACK);
      }
      ToSwap.clear();
      }
}

void Canvas::keyPressed(int keyCode) {
  switch (keyCode) {
    case 'q':
      exit(0);
  }
}