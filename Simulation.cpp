#include "Simulation.h"

void Simulation::printGeneration(const Gameboard& g, int generation_count)
{
  int h = g.getHorizontal();
  int v = g.getVertical();
  char **a = g.getBoard();

  cout << "Generation " << generation_count << endl;
  for(int i = 0; i < h; ++i)
  {
    for(int j = 0; j < v; ++j)
    {
      cout << a[i][j];
    }
    cout << endl;
  }
}

void Simulation::printNextGeneration(const Gameboard& g, int generation_count)
{
  int h = g.getHorizontal();
  int v = g.getVertical();
  char **a = g.getBoard();

 for(int i = 0; i <= h + 1; i++)
  {
    cout << "\033[F";
  }

  cout << "Generation " << generation_count << endl;
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
  this_thread::sleep_for (chrono::seconds(1));
}

void Simulation::pressEnterToContinue()
{
  cin.clear();
  cout << "Press [ENTER] to continue. ";
  cin.ignore(1024, '\n');
}

void Simulation::pressEnterToContinue(string reason)
{
  cin.clear();
  cout << "The simulation has stopped because " << reason << ". Please press [ENTER] to exit. " ;
  cin.ignore ( 1024, '\n' );
}
