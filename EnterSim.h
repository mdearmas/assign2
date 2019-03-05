/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 2: Game of Life
  Purpose: This is the header file for the EnterSim class (child of Simulation). It overrides the next() function so that the simulation will only proceed when the user presses [ENTER].
*/
#ifndef ENTER_SIM_H_
#define ENTER_SIM_H_

#include "Simulation.h"

class EnterSim : public Simulation {
public:
  EnterSim():Simulation(){}; //default constructor
  virtual void next(); //overwritten next() function to employ pressEnterToContinue()
};

#endif
