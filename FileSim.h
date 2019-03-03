#ifndef FILE_SIM_H_
#define FILE_SIM_H_

#include <fstream>
#include "Simulation.h"

class FileSim : public Simulation {
public:
  FileSim();
  FileSim(string file);

  void setFileName(string file);

  virtual void runSim(Gameboard& g, Gameplay& p, bool &b, int generation_count);
  virtual void printGeneration(const Gameboard& g, int generation_count, ofstream& out);
  virtual void next(ofstream& out);

private:
  string filename;
  bool first_time;
};

#endif
