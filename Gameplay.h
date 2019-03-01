#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include <iostream>

#include "Gameboard.h"

using namespace std;

class Gameplay {
public:
  Gameplay(Gameboard& game);
  virtual ~Gameplay() {};

  void death(int h, int v);
  void birth(int h, int v);

  void play();

  virtual int checkHorizontal(int h, int v);
  virtual int checkVertical(int h, int v);
  virtual int checkLeftDiagonal(int h, int v);
  virtual int checkRightDiagonal(int h, int v);

  bool isStable();
  bool isOscillating();

protected:
  Gameboard* current;
  Gameboard previous;
  Gameboard first;

  char **current_board;
  char **previous_board;

  int stable_repetitions;
  int oscillating_repetitions;
};

#endif
