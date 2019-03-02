#ifndef MIRROR_H_
#define MIRROR_H_

#include <iostream>

#include "Gameboard.h"
#include "Gameplay.h"

using namespace std;

class Mirror : public Gameplay {
public:
  Mirror(Gameboard &game):Gameplay(game){}

  virtual int checkHorizontal(int h, int v);
  virtual int checkVertical(int h, int v);
  virtual int checkLeftDiagonal(int h, int v);
  virtual int checkRightDiagonal(int h, int v);
};

#endif
