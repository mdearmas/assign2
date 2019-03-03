#include "FileSim.h"

FileSim::FileSim()
{
  filename = "";
}

FileSim::FileSim(string file)
{
  filename = file;
}

void FileSim::setFileName(string file)
{
  filename = file;
}

void FileSim::runSim(Gameboard& g, Gameplay& p, bool &b, int generation_count)
{
  ofstream ouput_file(filename, ios::out | ios::app);

  if(ouput_file.is_open())
  {
    p.play();
    this->printGeneration(g, generation_count, ouput_file);
    this->next(ouput_file);

    if(p.isStable() || p.isOscillating())
    {
      this->pressEnterToContinue("it has stabilized");
      b = false;
    }
  }
  else
  {
    cout << "File was not able to be accessed. " << endl;
    b = false;
  }
}

void FileSim::printGeneration(const Gameboard& g, int generation_count, ofstream& out)
{
  int h = g.getHorizontal();
  int v = g.getVertical();
  char **a = g.getBoard();

  out << "Generation " << generation_count << endl;
  for(int i = 0; i < h; ++i)
  {
    for(int j = 0; j < v; ++j)
    {
      out << a[i][j];
    }
    out << endl;
  }
}

void FileSim::next(ofstream& out)
{
  out << endl;
}
