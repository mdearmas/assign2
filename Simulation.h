#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <iostream>
#include <istream>
#include <thread>
#include <chrono>

#include "Gameboard.h"
#include "Gameplay.h"

using namespace std;

class Simulation {
public:
  virtual void printGeneration(const Gameboard& g, int generation_count);
  virtual void printNextGeneration(const Gameboard& g, int generation_count);
  virtual void next();

  void pressEnterToContinue();
  void pressEnterToContinue(string reason);

  void runSim(Gameboard& g, Gameplay& p, bool &b, int generation_count);
};

#endif
