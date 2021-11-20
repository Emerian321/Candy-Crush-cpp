#include<vector>

#include "canvas.h"
#include "cell.h"

const int gridSize = 10;

Canvas::Canvas() {
  for (int x = 0; x<gridSize; x++) {
    cells.push_back({});
    for (int y = 0; y<gridSize; y++)
      cells[x].push_back({{50*x+25, 50*y+25}, 40, 40});
  }
  set_bombs();
  set_neighbors();
  set_nearBombs();
}

void Canvas::set_bombs() {
  for (int a = 0; a < gridSize*gridSize/8; a++) {
    int i = rand() % 10;
    int j = rand() % 10;
    while (cells[i][j].getBomb()) {
      i = rand() % 10;
      j = rand() % 10;
    }
    cells[i][j].setBomb();
  }
}

void Canvas::set_neighbors() {
  for (int x = 0; x<gridSize; x++)
    for (int y = 0; y<gridSize; y++)
      cells[x][y].setNeighbors(find_neighbors(x, y));
}

vector <Cell *>Canvas::find_neighbors(int x, int y) {
  vector <Cell *> neighbors;
  for (int a = x-1; a < x+2; a++) {
    for (int b = y-1; b < y+2; b++) {
      if (a >= 0 and b >=0 and a < gridSize and b < gridSize and (a!=x or b!=y)) {
        neighbors.push_back(&cells[a][b]);
      }
    }
  }
  return neighbors;
}

void Canvas::set_nearBombs() {
  for (int x = 0; x<gridSize; x++)
    for (int y = 0; y<gridSize; y++)
      cells[x][y].NearBombCount();
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
      for (auto &c: v) c.mouseClick(mouseLoc);
}

void Canvas::keyPressed(int keyCode) {
  switch (keyCode) {
    case 'q':
      exit(0);
  }
}