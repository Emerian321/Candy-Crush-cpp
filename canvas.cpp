#include "canvas.h"
#include "const.h"
#include <algorithm>
#include <stdio.h>
#include <iostream>

Canvas::Canvas() {
  for (int x = 0; x<gridSize; x++) {
    cells.push_back({});
    for (int y = 0; y<gridSize; y++) {
      cells[x].push_back({{56*x+25, 56*y+25}});
    }
  }
  set_neighbours();
  for (int x = 0; x<gridSize; x++) {
    for (int y = 0; y<gridSize; y++) {
      cells[x][y].DetectLine(true);
    }
  }
}

void Canvas::set_neighbours() {
  for (int x = 0; x<gridSize; x++)
    for (int y = 0; y<gridSize; y++)
      cells[x][y].setNeighbours(find_neighbours(x, y));
}

std::vector <Cell *>Canvas::find_neighbours(int x, int y) {
  std::vector <Cell *> neighbours;
  for (auto DIRECTION: DIRECTIONS) {
    if(0 <= x+DIRECTION[0] && x+DIRECTION[0] < gridSize && 0 <= y+DIRECTION[1] && y+DIRECTION[1] < gridSize){
      neighbours.push_back(&cells[x+DIRECTION[0]][y+DIRECTION[1]]);
    }
    else{
      neighbours.push_back(nullptr);
    }
  }
  return neighbours;
}

void Canvas::draw() {
  for (auto &v: cells)
    for (auto &c: v)
      c.draw();
}

void Canvas::mouseMove(Point mouseLoc) {
  for (auto &v: cells)
    for (auto &c: v)
      c.mouseMove(mouseLoc);
}

void Canvas::mouseClick(Point mouseLoc) {
  for (auto &v: cells)
    for (auto &c: v)
      if (c.mouseClick(mouseLoc)){
        toSwapCells.push_back(c);
        if (toSwapCells.size() == 2 
        && std::find(toSwapCells[1].getNeighbours().begin(), toSwapCells[1].getNeighbours().end(), &toSwapCells[0]) != toSwapCells[1].getNeighbours().end()){
          int y = toSwapCells[0].getMatrixPos()[0];
          int x = toSwapCells[0].getMatrixPos()[1];
          int yp = toSwapCells[1].getMatrixPos()[0];
          int xp = toSwapCells[1].getMatrixPos()[1];
          std::swap(cells[y][x], cells[yp][xp]);
          toSwapCells.clear();
        }
      }
}

void Canvas::keyPressed(int keyCode) {
  switch (keyCode) {
    case 'q':
      exit(0);
  }
}