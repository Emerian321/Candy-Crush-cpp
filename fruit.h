#ifndef __FRUIT_H
#define __FRUIT_H


#include <random>

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

#include "rectangle.h"
#include "const.h"

class Fruit {
    Fl_Color color;
    Rectangle shape;
  public:
    // Constructor
    Fruit(Point center): color{COLORS[rand() % 6]}, shape(center, EDGE, EDGE, FL_BLACK, color) {};

    // Setter/Getter
    Fl_Color getColor() {
        return color;
    }

    void setColor(Fl_Color newColor){
        color = newColor;
        shape.setFillColor(newColor);
    }

    void draw() {
        shape.draw();
    }

    bool mouseClick(Point MouseLoc){
        if (shape.contains(MouseLoc)){
            shape.setFrameColor(FL_GREEN);
        }
        else{
            shape.setFrameColor(FL_BLACK);
        }
        return shape.contains(MouseLoc);
    }

    // Destructor
};

#endif 