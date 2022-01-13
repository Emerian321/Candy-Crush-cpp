#include "point.h"
#include "rectangle.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <string>
#include <math.h>
#include <time.h>
#include <chrono>
#include <vector>
#include <iostream>
#include <random>
#include <array>

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
Animation Class

Allows Translations and rotations via Animationtype
--------------------------------------------------*/

class Animation {
 public:
  enum AnimationType {spin, bounce, spinAndBounce};
 private:
  const int animationTime = 60;
  const int bounceHeight = 200;
  Rectangle *rec;
  AnimationType animationType;
  int time{0};
  Point currentTranslation();
  double currentRotation();
 public:
  Animation(Rectangle *recToAnimate, AnimationType animationType);
  void draw();
  bool isComplete();
  Point Animation::currentTranslation();
  double Animation::currentRotation();
  bool Animation::isComplete() {
    return time>60;
  }
};