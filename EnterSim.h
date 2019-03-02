#ifndef ENTER_SIM_H_
#define ENTER_SIM_H_

#include "Simulation.h"

class EnterSim : public Simulation {
public:
  EnterSim():Simulation(){};
  virtual void next();
};

#endif
