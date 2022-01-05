#ifndef __VIRTUAL_H
#define __VIRTUAL_H

#include "point.h"

class Clickable {
  public:
    virtual bool contains(Point p) = 0;
    virtual bool mouseClick(Point p) = 0;

    virtual ~Clickable();
};

class Drawable {
  public:
    virtual void draw() = 0;

    virtual ~Drawable();
};

#endif