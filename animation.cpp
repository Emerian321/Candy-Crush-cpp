#include "point.h"
#include "rectangle.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <math.h>

/*--------------------------------------------------
Translation Class
--------------------------------------------------*/
struct Translation {
  Translation(Point p) {
    fl_push_matrix();
    fl_translate(p.x, p.y);
  }
  ~Translation() {
    fl_pop_matrix();
  }
};

/*--------------------------------------------------
Rotation Class
--------------------------------------------------*/

struct Rotation {
  Rotation(Point center, double angle) {
    fl_push_matrix();
    fl_translate(center.x, center.y);
    fl_rotate(angle);
    fl_translate(-1*center.x, -1*center.y);
  }
  ~Rotation() {
    fl_pop_matrix();
  }
};

/*--------------------------------------------------

Cell class declaration (implementations later)

The Canvas class below will have cells as instance
vraiables and call the methods of Cell
--------------------------------------------------*/

class Animation;

class Cell {
  Rectangle r;
  Animation *animation;
 public:
  // Constructor
  Cell(Point center, int w, int h);

  // Methods that draw and handle events
  void drawWithoutAnimate();
  void draw();
  void mouseMove(Point /* mouseLoc */) {};
  void mouseClick(Point mouseLoc);
  Point getCenter() {
    return r.getCenter();
  }
};

/*--------------------------------------------------

Animation Class
--------------------------------------------------*/

class Animation {
 public:
  enum AnimationType {spin, bounce, spinAndBounce};
 private:
  const int animationTime = 60;
  const int bounceHeight = 200;
  Cell *c;
  AnimationType animationType;
  int time{0};
  Point currentTranslation();
  double currentRotation();
 public:
  Animation(Cell *cellToAnimate, AnimationType animationType)
      : c{cellToAnimate}, animationType{animationType} {}
  void draw();
  bool isComplete();
};

void Animation::draw() {
  ++time;
  Translation t3{currentTranslation()};
  Rotation r{c->getCenter(), currentRotation()};
  c->drawWithoutAnimate();
}

Point Animation::currentTranslation() {
  if (animationType==bounce || animationType == spinAndBounce)
    return {0, static_cast<int>(-1*bounceHeight*sin(3.1415*time/animationTime))};
  else
    return {0, 0};
}
double Animation::currentRotation() {
  if (animationType==spin || animationType == spinAndBounce)
    return time*360.0/animationTime;
  else
    return 0;
}

bool Animation::isComplete() {
  return time>60;
}