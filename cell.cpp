#include "cell.h"


Cell::Cell(Point center, int w, int h):
  r(center, w, h, FL_BLACK, FL_WHITE) {
    this->center = center;
  }

void Cell::NearBombCount() {
  for (auto n: neighbors) {
    if (n->getBomb()) {
      nearBomb++;
    }
  }
}

void Cell::reveal() {
  revealed = true;
  if (getNearBomb() == 0) {
      for (auto n: neighbors) {
    if (!n->getBomb() and !n->revealed)
      n->reveal();
      }
  }
}

void Cell::endgame() {
  revealed = true;
    for (auto n: neighbors) {
      if (!n->revealed)
        n->endgame();
    }
}

void Cell::draw() {
  r.draw();
  if (revealed) {
    if (is_bomb) {
    r.setFillColor(FL_RED);
    }
  }
}

void Cell::mouseMove(Point mouseLoc) {
  if (r.contains(mouseLoc)) {
    r.setFrameColor(FL_RED);
  } else {
    r.setFrameColor(FL_BLACK);
  }
}


void Cell::mouseClick(Point mouseLoc) {
  if (r.contains(mouseLoc))
    if (is_bomb)
    endgame();
    else
    reveal();
}
