#include "Simulation.h"

Simulation::Simulation()
{
  active = true;
}

void Simulation::printGeneration(const Gameboard& g, int generation_count)
{
  int h = g.getHorizontal();
  int v = g.getVertical();
  char **a = g.getBoard();

  cout << "Generation " << generation_count << endl;
  cout << endl;

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
