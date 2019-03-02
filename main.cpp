#include "Gameboard.h"
#include "Simulation.h"
#include "Gameplay.h"
#include "Doughnut.h"
#include "Mirror.h"

int main(int argc, char **argv)
{
  srand(time(NULL));

  ifstream input_file;

  int h = 0;
  int v = 0;
  int generation_count = 0;
  int quit;

  double density;

  char answer;

  string filepath;

  bool game_active = true;

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
  Doughnut pd(g);
  Mirror pm(g);

  cout << "What game mode would you like? Press 'C' for classic, 'D' for doughnut, or 'M' for mirror: ";
  cin >> answer;

  if ( toupper(answer) == 'D' )
  {
    cout << "Doughnut mode has been selected. " << endl;
    cout << endl;
  }
  else if ( toupper(answer) == 'M')
  {
    cout << "Mirror mode has been selected. " << endl;
    cout << endl;
  }
  else if ( toupper(answer) != 'C' )
  {
    cout << "Incompatible response. The program will default to classic mode." << endl;
  }

  s.printGeneration(g, generation_count);
  ++generation_count;
  cin.ignore();
  s.next();

  while(game_active)
  {
    if (g.isEmpty())
    {
      s.pressEnterToContinue("it is empty");
      game_active = false;
    }
    else if ( toupper(answer) == 'D' )
    {
      pd.play();
      s.printNextGeneration(g, generation_count);
      s.next();

      if(pd.isStable() || pd.isOscillating())
      {
        s.pressEnterToContinue("it has stabilized");
        game_active = false;
      }
    }
    else if( toupper(answer) == 'M' )
    {
      pm.play();
      s.printNextGeneration(g, generation_count);
      s.next();

      if(pm.isStable() || pm.isOscillating())
      {
        s.pressEnterToContinue("it has stabilized");
        game_active = false;
      }
    }
    else
    {
      p.play();
      s.printNextGeneration(g, generation_count);
      s.next();

      if(p.isStable() || p.isOscillating())
      {
        s.pressEnterToContinue("it has stabilized");
        game_active = false;
      }
    }
    ++generation_count;
  }

}
