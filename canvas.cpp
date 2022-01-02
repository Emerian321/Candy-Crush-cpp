#include "canvas.h"
#include "const.h"


Canvas::Canvas() {
  for (int x = 0; x<gridSize; x++) {
    cells.push_back({});
    for (int y = 0; y<gridSize; y++)
      cells[x].push_back({{56*x+25, 56*y+25}, 45, 45});
  }
  set_neighbours();
}

void Canvas::set_neighbours() {
  for (int x = 0; x<gridSize; x++)
    for (int y = 0; y<gridSize; y++)
      cells[x][y].setNeighbours(find_neighbours(x, y));
}

std::vector <Cell *>Canvas::find_neighbours(int x, int y) {
  std::vector <Cell *> neighbours;
  for (int a = x-1; a < x+2; a++) {
    for (int b = y-1; b < y+2; b++) {
      if (a >= 0 and b >=0 and a < gridSize and b < gridSize and (a!=x or b!=y)) {
        neighbours.push_back(&cells[a][b]);
      }
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
      for (auto &c: v) c.mouseClick(mouseLoc);
}

void Canvas::keyPressed(int keyCode) {
  switch (keyCode) {
    case 'q':
      exit(0);
  }
}