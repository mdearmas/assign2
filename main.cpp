#include "Gameboard.h"
#include "Simulation.h"
#include "EnterSim.h"
#include "FileSim.h"
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
  char output_mode;

  string input_filepath;
  string output_filepath;

  bool game_active = true;

  Gameboard g;

  Simulation s;
  EnterSim se;
  FileSim sf;

  cout << "Would you like to input a map file or randomly generate a map? Enter 'M' for map file and 'R' for random. ";
  cin >> answer;

  if ( toupper(answer) == 'M' )
  {
    cout << "Please enter your file name: ";
    cin >> input_filepath;

    while(!g.fileFill(input_filepath))
    {
      cout << "An error has occurred; either the file does not exist, or the file is not in the correct format. Try again: ";
      cin >> input_filepath;
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
    while (cin.fail() || h < 1)
    {
      cin.clear();
      cin.ignore(1024, '\n');
      cout << "Not a valid number of rows. Try again: ";
      cin >> h;
    }

    cout << "Enter the number of columns of the board: ";
    cin >> v;
    while (cin.fail() || v < 1)
    {
      cin.clear();
      cin.ignore(1024, '\n');
      cout << "Not a valid number of columns. Try again: ";
      cin.clear();
      cin >> v;
    }

    g.resize(h, v);

    cout << "Enter the population density of your world (a decimal between 0–1): ";
    cin >> density;
    while (cin.fail() || density > 1 || density < 0)
    {
      cin.clear();
      cin.ignore(1024, '\n');
      cout << "Not a population density. Try again: ";
      cin >> density;
    }
    g.randomFill(density);
  }

  cout << "What game mode would you like? Press 'C' for classic, 'D' for doughnut, or 'M' for mirror: ";
  cin >> answer;
  if ( toupper(answer) == 'D' )
  {
    cout << "Doughnut mode has been selected. " << endl;
  }
  else if ( toupper(answer) == 'M')
  {
    cout << "Mirror mode has been selected. " << endl;
  }
  else if ( toupper(answer) != 'C' )
  {
    cout << "Incompatible response. The program will default to classic mode." << endl;
  }
  else
  {
    cout << "Classic mode has been selected. " << endl;
  }

  Gameplay p(g);
  Doughnut pd(g);
  Mirror pm(g);

  cout << "How would you like your output? Press 'P' for a pause between generations, 'E' for an ENTER key press to trigger generations, or 'F' for an output file containing the results: ";
  cin >> output_mode;
  if ( toupper(output_mode) == 'E' )
  {
    cout << "Keypress mode has been selected. " << endl;
    se.printGeneration(g, generation_count);
    ++generation_count;
    cin.ignore(1024, '\n');
    se.next();

    while(game_active)
    {
      if (g.isEmpty())
      {
        se.pressEnterToContinue("it is empty");
        game_active = false;
      }
      else if ( toupper(answer) == 'D' )
      {
        se.runSim(g, pd, game_active, generation_count);
      }
      else if( toupper(answer) == 'M' )
      {
        se.runSim(g, pm, game_active, generation_count);
      }
      else
      {
        se.runSim(g, p, game_active, generation_count);
      }
      ++generation_count;
    }
  }
  else if ( toupper(output_mode) == 'F')
  {
    cout << "File output mode has been selected. Please enter the name of your output file: ";
    cin >> output_filepath;
    sf.setFileName(output_filepath);

    cin.ignore(1024, '\n');

    while(game_active)
    {
      if (g.isEmpty())
      {
        sf.pressEnterToContinue("it is empty");
        game_active = false;
      }
      else if ( toupper(answer) == 'D' )
      {
        sf.runSim(g, pd, game_active, generation_count);
      }
      else if( toupper(answer) == 'M' )
      {
        sf.runSim(g, pm, game_active, generation_count);
      }
      else
      {
        sf.runSim(g, p, game_active, generation_count);
      }
      ++generation_count;
    }
  }
  else
  {
    if( toupper(output_mode) != 'P' )
    {
      cout << "Incompatible response. The program will default to pause mode." << endl;
    }
    else
    {
      cout << "Pause mode has been selected. " << endl;
    }

    s.printGeneration(g, generation_count);
    ++generation_count;
    cin.ignore(1024, '\n');
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
        s.runSim(g, pd, game_active, generation_count);
      }
      else if( toupper(answer) == 'M' )
      {
        s.runSim(g, pm, game_active, generation_count);
      }
      else
      {
        s.runSim(g, p, game_active, generation_count);
      }
      ++generation_count;
    }
  }
}
