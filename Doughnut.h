#ifndef DOUGHNUT_H
#define DOUGHNUT_H

#include <iostream>

#include "Gameboard.h"
#include "Gameplay.h"

using namespace std;

class Doughnut : public Gameplay {
public:
  Doughnut(Gameboard &game):Gameplay(game){}

  virtual int checkHorizontal(int h, int v);
  virtual int checkVertical(int h, int v);
  virtual int checkLeftDiagonal(int h, int v);
  virtual int checkRightDiagonal(int h, int v);

  int positive_modulo(int i, int n);
};

#endif
