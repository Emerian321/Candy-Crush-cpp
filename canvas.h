/*--------------------------------------------------

Canvas class.

One instance of the canvas class is made by the
MainWindow class.

The fltk system via MainWindow calls:

draw 60 times a second
mouseMove whenever the mouse is moved
mouseClick whenever the mouse is clicked
keyPressed whenever a key is pressed

Any drawing code should be called ONLY in draw
or methods called by draw. If you try to draw
elsewhere it will probably crash.

--------------------------------------------------*/

#ifndef __CANVAS_H
#define __CANVAS_H

#include "fruit.h"
#include "const.h"
#include <stdio.h>
#include <iostream>
#include <vector>

class Canvas {
  std::vector< std::vector<Fruit *> > fruits;
  std::vector< Fruit *> toSwap;
 public:
  // Constructeur
  Canvas();

  // Complément Constructeur
  void set_neighbours();
  std::vector <Fruit *> find_neighbours(int x, int y);

  // Méthode objet
  bool destroyFruits();
  void swapFruits(Fruit *fruit1, Fruit *fruit2);
  // Draw
  void draw();

  // Gestion de la souris/clavier
  void mouseMove(Point mouseLoc);
  void mouseClick(Point mouseLoc);
  void keyPressed(int keyCode);
};

#endif