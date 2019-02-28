#include "Gameboard.h"
#include "Simulation.h"
#include "Gameplay.h"

int main(int argc, char **argv)
{
  srand(time(NULL));

  ifstream input_file;

  int h = 0;
  int v = 0;
  int generation_count = 0;

  double density;

  char answer;

  string filepath;

  Gameboard g;
  Simulation s;

  cout << "Would you like to input a map file or randomly generate a map? Enter 'M' for map file and 'R' for random. ";
  cin >> answer;

  if ( toupper(answer) == 'M' )
  {
    cout << "Please enter your file name: ";
    cin >> filepath;

    while(!g.fileFill(filepath))
    {
      cout << "An error has occurred. Try again: ";
      cin >> filepath;
    }
  }
  else if ( toupper(answer) != 'R' )
  {
    cout << "Incompatible response. The program will use the default 10 x 10 board with 50% population density." << endl;
    g.randomFill(0.50);
  }
  else
  {
    cout << "Enter the number of rows of the board: ";
    cin >> h;
    cout << "Enter the number of columns of the board: ";
    cin >> v;
    g.resize(h, v);
    cout << "Enter the population density of your world (a decimal between 0–10): ";
    cin >> density;
    g.randomFill(density);
  }

  Gameplay p(g);

  s.printGeneration(g, 0);

  do
  {
    ++generation_count;
    p.play();
    s.printGeneration(g, generation_count);
    s.next();
  } while(!g.isEmpty() && !p.isStable());

}
