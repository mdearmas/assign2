#include "Simulation.h"

Simulation::Simulation()
{
  mode = "Basic";
}

void Simulation::printGeneration(const Gameboard& g)
{
  int h = g.getHorizontal();
  int v = g.getVertical();
  char **a = g.getBoard();

  for(int i = 0; i < h; ++i)
  {
    for(int j = 0; j < v; ++j)
    {
      cout << a[i][j];
    }
    cout << endl;
  }
}

void Simulation::next()
{
  cout << endl;
}
