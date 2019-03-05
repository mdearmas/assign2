/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 2: Game of Life
  Purpose: This file, main.cpp, contains the main function for Assignment 2. The resulting program will first ask what mode the user wants to run their game in,
  (defaulting to a 10x!0 board with 0.5 population density in case of erroneous input). If file input is selected, the user will be prompted to enter the name of
  their file; if random is selected, the user will be prompted to enter the number of rows and columns and the population density. Then, the user will be asked
  what mode they would like (defaulting to Classic if erroneous input). Finally, the user will be prompeted with a choice regarding how their output will
  be formatted (defaulting to Pauses if erroneous input).
*/
#include "Gameboard.h"
#include "Simulation.h"
#include "EnterSim.h"
#include "FileSim.h"
#include "Gameplay.h"
#include "Doughnut.h"
#include "Mirror.h"

int main(int argc, char **argv)
{
  srand(time(NULL)); //seeding at startup for random generation

  ifstream input_file; //for the map file

  int h = 0; //the number of rows, as input by the user (h for horizontal)
  int v = 0; //the number of columns, as input by the user (v for vertical)
  int generation_count = 0; //the number of generations

  double density; //the population density, as input by the user

  char answer; //a variable that will store console input regarding first board generation mode (mapfile or random) and then game mode (Classic, Doughnut, or Mirror)
  char output_mode; //a variable that will store console input regarding the output mode of the game

  string input_filepath; //will store the name of the input map file
  string output_filepath; //will store the name of the output file, should that option be chosen

  bool game_active = true; //a boolean that keeps the simulation looping

  Gameboard g; //the cell grid of the game

  Simulation s; //an object to access the Simulation class functions (pause mode)
  EnterSim se; //an object to access the EnterSim class functions (child of Simulation, press ENTER mode)
  FileSim sf; //an object to access the FileSim class functions (child of Simulation, file output mode)

  //choose how the gameboard is created
  cout << "Would you like to input a map file or randomly generate a map? Enter 'M' for map file and 'R' for random. ";
  cin >> answer;

  //flushes the input stream
  cin.clear();
  cin.ignore(1024, '\n');

  if ( toupper(answer) == 'M' ) //mapfile input
  {
    cout << "Please enter your file name: ";
    cin >> input_filepath;

    //loop to ensure a viable file has been entered
    while(!g.fileFill(input_filepath))
    {
      //flushes the input stream
      cin.clear();
      cin.ignore(1024, '\n');
      cout << "An error has occurred; either the file does not exist, or the file is not in the correct format. Try again: ";
      cin >> input_filepath;
    }
  }
  else if ( toupper(answer) != 'R' ) //if the input is not a valid response
  {
    cout << "Incompatible response. The program will use the default 10 x 10 board with 50% population density." << endl;
    g.randomFill(0.50);
  }
  else //if toupper(answer) == 'R'
  {
    cout << "Enter the number of rows of the board: ";
    cin >> h;

    //loop to ensure a valid number of rows
    while (cin.fail() || h < 1)
    {
      //flushes the input stream
      cin.clear();
      cin.ignore(1024, '\n');

      cout << "Not a valid number of rows. Try again: ";
      cin >> h;
    }

    //flushes the input stream
    cin.clear();
    cin.ignore(1024, '\n');

    cout << "Enter the number of columns of the board: ";
    cin >> v;

    //loop to ensure a valid number of columns
    while (cin.fail() || v < 1)
    {
      //flushes the input stream
      cin.clear();
      cin.ignore(1024, '\n');
      cout << "Not a valid number of columns. Try again: ";
      cin >> v;
    }

    //flushes the input stream
    cin.clear();
    cin.ignore(1024, '\n');

    //resizes the gameboard to the desired specifications
    g.resize(h, v);

    cout << "Enter the population density of your world (a decimal between 0–1): ";
    cin >> density;

    //loop to ensure a valid population density
    while (cin.fail() || density > 1 || density < 0)
    {
      cin.clear();
      cin.ignore(1024, '\n');
      cout << "Not a valid population density. Try again: ";
      cin >> density;
    }
    g.randomFill(density); //randomly fills the gameboard according to the input density
  }

  //flushes the input stream
  cin.clear();
  cin.ignore(1024, '\n');

  //choose the game mode
  cout << "What game mode would you like? Press 'C' for classic, 'D' for doughnut, or 'M' for mirror: ";
  cin >> answer;

  //outputs to the console what mode has been selected for the user's benefit
  if ( toupper(answer) == 'D' ) //doughnut mode
  {
    cout << "Doughnut mode has been selected. " << endl;
  }
  else if ( toupper(answer) == 'M') //mirror mode
  {
    cout << "Mirror mode has been selected. " << endl;
  }
  else if ( toupper(answer) != 'C' ) //default in case an invalid choice has been input
  {
    cout << "Incompatible response. The program will default to classic mode." << endl;
  }
  else //classic mode
  {
    cout << "Classic mode has been selected. " << endl;
  }

  //Game mode object initialization (since the gameboard is required to create these objects)
  Gameplay p(g); //default (classic)
  Doughnut pd(g); //doughnot mode
  Mirror pm(g); //mirror mode

  //flushes the input stream
  cin.clear();
  cin.ignore(1024, '\n');

  //choose the output mode
  cout << "How would you like your output? Press 'P' for a pause between generations, 'E' for an ENTER key press to trigger generations, or 'F' for an output file containing the results: ";
  cin >> output_mode;
  if ( toupper(output_mode) == 'E' ) //Press Enter mode
  {
    cout << "Keypress mode has been selected. " << endl;

    //print initial generation
    se.printGeneration(g, generation_count);
    ++generation_count;
    cin.ignore(1024, '\n');
    se.next();

    while(game_active) //simulation loop
    {
      if (g.isEmpty()) //exits loop if board is empty
      {
        se.pressEnterToContinue("it is empty");
        game_active = false;
      }
      else if ( toupper(answer) == 'D' ) //runs Doughnut mode
      {
        se.runSim(g, pd, game_active, generation_count);
      }
      else if( toupper(answer) == 'M' ) //runs Mirror mode
      {
        se.runSim(g, pm, game_active, generation_count);
      }
      else //runs Classic mode
      {
        se.runSim(g, p, game_active, generation_count);
      }
      ++generation_count; //increments the number of generations with every successive loop
    }
  }
  else if ( toupper(output_mode) == 'F') //File Output mode
  {
    cout << "File output mode has been selected. Please enter the name of your output file: ";
    cin >> output_filepath;
    sf.setFileName(output_filepath);

    //flushes the input stream
    cin.clear();
    cin.ignore(1024, '\n');

    while(game_active) //simulation loop
    {
      if (g.isEmpty()) //exits loop if board is empty
      {
        sf.pressEnterToContinue("it is empty");
        game_active = false;
      }
      else if ( toupper(answer) == 'D' ) //Doughnut mode
      {
        sf.runSim(g, pd, game_active, generation_count);
      }
      else if( toupper(answer) == 'M' ) //Mirror mode
      {
        sf.runSim(g, pm, game_active, generation_count);
      }
      else //Classic mode
      {
        sf.runSim(g, p, game_active, generation_count);
      }
      ++generation_count; //increments the number of generations with every successive loop
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

    //print initial generation
    s.printGeneration(g, generation_count);
    ++generation_count;
    cin.ignore(1024, '\n');
    s.next();

    while(game_active) //exits loop if board is empty
    {
      if (g.isEmpty())
      {
        s.pressEnterToContinue("it is empty");
        game_active = false;
      }
      else if ( toupper(answer) == 'D' ) //Doughnut mode
      {
        s.runSim(g, pd, game_active, generation_count);
      }
      else if( toupper(answer) == 'M' ) //Mirror mode
      {
        s.runSim(g, pm, game_active, generation_count);
      }
      else //Classic mode
      {
        s.runSim(g, p, game_active, generation_count);
      }
      ++generation_count; //increments the number of generations with every successive loop
    }
  }
  return 0;
}
