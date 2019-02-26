#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h> //provides time() for random seeding

using namespace std;

class Gameboard {
public:
  Gameboard();
  Gameboard(int h, int v);
  Gameboard(const Gameboard& copy);

  ~Gameboard();

  int getHorizontal() const { return horizontal; }
  int getVertical() const { return vertical; }
  char** getBoard() const { return board; }


  void resize(int h, int v);
  void randomFill(double density);

  bool fileFill(string filename);
  bool compare(const Gameboard& g1, const Gameboard& g2);

private:
  int horizontal;
  int vertical;
  char **board;
};

#endif
