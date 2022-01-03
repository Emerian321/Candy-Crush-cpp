#include "cell.h"
#include "const.h"

Cell::Cell(Point center):
  r(center, EDGE, EDGE), center{center}, fruit{center} {
  }

void Cell::draw() {
  fruit.draw();
}

void Cell::mouseMove(Point mouseLoc) {
  if (r.contains(mouseLoc)) {
    r.setFrameColor(FL_RED);
  } else {
    r.setFrameColor(FL_BLACK);
  }
}

void Cell::DetectLine() {
  if (fruit.getColor() == neighbours[0]->fruit.getColor() and fruit.getColor() == neighbours[2]->fruit.getColor()) {
    setToDestroy();
    neighbours[0]->setToDestroy();
    neighbours[2]->setToDestroy();
  }

  if (fruit.getColor() == neighbours[1]->fruit.getColor() and fruit.getColor() == neighbours[3]->fruit.getColor()) {
    setToDestroy();
    neighbours[1]->setToDestroy();
    neighbours[3]->setToDestroy();
  }

  if (true) {
      for (auto &neighour: neighbours) {
        neighour->DetectLine();
      }
  }
}

void Cell::mouseClick(Point mouseLoc) {
}
