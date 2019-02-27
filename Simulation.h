#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <iostream>
#include <fstream>

#include "Gameboard.h"

using namespace std;

class Simulation {
public:
  Simulation();
  virtual void printGeneration(const Gameboard& g, int generation_count);
  virtual void next();
private:
  bool active;
};

#endif
