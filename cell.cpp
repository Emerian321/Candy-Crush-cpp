#include "cell.h"

Cell::Cell(Point center, int w, int h):
  r(center, w, h, FL_BLACK, FL_WHITE), center(center) {
  }

void Cell::draw() {
  r.draw();
}

void Cell::mouseMove(Point mouseLoc) {
  if (r.contains(mouseLoc)) {
    r.setFrameColor(FL_RED);
  } else {
    r.setFrameColor(FL_BLACK);
  }
}

void Cell::DetectLine(bool rec=true) {
  if (fillcolor == neighbours[0]->fillcolor and fillcolor == neighbours[2]->fillcolor) {
    setToDestroy();
    neighbours[0]->setToDestroy();
    neighbours[2]->setToDestroy();
  }

  if (fillcolor == neighbours[1]->fillcolor and fillcolor == neighbours[3]->fillcolor) {
    setToDestroy();
    neighbours[1]->setToDestroy();
    neighbours[3]->setToDestroy();
  }

  if (rec) {
      for (auto &neighour: neighbours) {
        neighour->DetectLine(rec=false);
      }
  }

}

void Cell::mouseClick(Point mouseLoc) {
}