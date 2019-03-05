/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 2: Game of Life
  Purpose: This is the header file for the Simulation class, which controls functions related to running the Game of Life simulation on the computer.
*/
#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <iostream> //allows access to input and output
#include <istream> //helps to clear stream (Source: https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1042856625&id=1043284385)
#include <thread> //needed for this_thread
#include <chrono> //needed for seconds

#include "Gameboard.h" //accesses Gameboard
#include "Gameplay.h" //access Gameplay

using namespace std;

class Simulation {
public:
  Simulation(){}; //default constructor (empty because there are no variables needed to be initialized)

  virtual void runSim(Gameboard& g, Gameplay& p, bool &b, int generation_count); //runs the simulation and outputs results
  virtual void printGeneration(const Gameboard& g, int generation_count); //prints the 2d array associated with the Gameboard
  virtual void next(); //gets ready for the next output (aka: pause mode)

  void printNextGeneration(const Gameboard& g, int generation_count); //rewinds the cursor to overwrite the previous generation
  void pressEnterToContinue(); //requires the user to press [ENTER] to continue
  void pressEnterToContinue(string reason); //overloaded to allow for a custom message
};

#endif
