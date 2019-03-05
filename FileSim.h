/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 2: Game of Life
  Purpose: This is the header file for the File class (child of Simulation). It overrides the runSim(), printGeneration(), and next() function to print to a specified file.
*/
#ifndef FILE_SIM_H_
#define FILE_SIM_H_

#include <fstream>
#include "Simulation.h"

class FileSim : public Simulation {
public:
  FileSim(); //default constructor
  FileSim(string file); //constructor

  void setFileName(string file); //sets filename to the passed parameter

  virtual void runSim(Gameboard& g, Gameplay& p, bool &b, int generation_count); //overwritten runSim function now includes code to open the output file as well as error checking for file output
  virtual void printGeneration(const Gameboard& g, int generation_count, ofstream& out); //overwritten printGeneration() function now includes an ofstream parameter so it can print to said ofstream
  virtual void next(ofstream& out); //overwritten next() function now prints to the passed ofstream parameter

private:
  string filename; //the name of the output file
  bool first_time; //used to ensure that the initial generation is printed to the file
};

#endif
