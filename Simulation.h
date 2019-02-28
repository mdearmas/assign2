#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <iostream>
#include <fstream>

#include "Gameboard.h"

using namespace std;

class Simulation {
public:
  Simulation();
  virtual void printGeneration(const Gameboard& g);
  virtual void next();
private:
  string mode;
};

#endif
