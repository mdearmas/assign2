/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 2: Game of Life
  Purpose: This file contains the out-of-class member functions of Simulation.
*/
#include "Simulation.h"

void Simulation::runSim(Gameboard& g, Gameplay& p, bool &b, int generation_count) //runs the simulation and outputs results. the bool parameter will be connected to the game_active bool in main.cpp to control the simulation loop
{
  p.play(); //plays the Game of Life
  this->printNextGeneration(g, generation_count); //overwrites the previous generation and prints the new generation
  this->next(); //preps for next output

  if(p.isStable() || p.isOscillating() || p.isRepeating()) //checks if the simulation has stabilized, formed an oscillator, or otherwise created a repeating pattern
  {
    this->pressEnterToContinue("it has stabilized");
    b = false;
  }
}

void Simulation::printGeneration(const Gameboard& g, int generation_count) //prints the 2d array associated with the passed Gameboard object
{
  int h = g.getHorizontal();
  int v = g.getVertical();
  char **a = g.getBoard();

  cout << "Generation " << generation_count << endl; //includes the generation number in the output
  for(int i = 0; i < h; ++i)
  {
    for(int j = 0; j < v; ++j)
    {
      cout << a[i][j];
    }
    cout << endl;
  }
}

void Simulation::printNextGeneration(const Gameboard& g, int generation_count) //rewinds the cursor to overwrite the previous generation, then prints the new generation
{
  int h = g.getHorizontal();
  int v = g.getVertical();
  char **a = g.getBoard();

  //this loop rewinds the cursor back the number of lines of the previous generation printing (Source: https://stackoverflow.com/questions/45134217/c-go-back-a-line)
  for(int i = 0; i <= h + 1; i++)
  {
    cout << "\033[F";
  }

  //the new generation is then printed over the previous one
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

void Simulation::next() //gets ready for next output. this mode pauses between generations.
{
  cout << endl;
  this_thread::sleep_for (chrono::seconds(1)); //Source: http://www.cplusplus.com/reference/thread/this_thread/sleep_for/ (because system("pause") wouldn't work on my MacOS)
}

void Simulation::pressEnterToContinue() //Source: https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1042856625&id=1043284385
{
  cin.clear();
  cout << "Press [ENTER] to continue. ";
  cin.ignore(1024, '\n');
}

void Simulation::pressEnterToContinue(string reason) //overloaded function to allow for a customized message.
{
  cin.clear();
  cout << "The simulation has stopped because " << reason << ". Please press [ENTER] to exit. " ;
  cin.ignore ( 1024, '\n' );
}
