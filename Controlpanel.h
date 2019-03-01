#ifndef CONTROLPANEL_H_
#define CONTROLPANEL_H_

#include <ios>
#include <iostream>
#include <istream>
#include <limits>

#include "Gameboard.h"
#include "Simulation.h"
#include "Gameplay.h"
#include "Doughnut.h"

using namespace std;

class Controlpanel
{
public:
  void pressEnterToContinue();
  void pressEnterToContinue(string reason);
  void flushIStream(istream& in);
};

#endif
