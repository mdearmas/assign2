/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 2: Game of Life
  Purpose: This contains the out-of-class member functions for FileSim.
*/
#include "FileSim.h"

FileSim::FileSim() //default constructor
{
  filename = "default.txt";
  first_time = true; //first_time initialized to true
}

FileSim::FileSim(string file) //constructor
{
  filename = file; //sets the file name to the passed parameter
  first_time = true; //first_time initialized to true
}

void FileSim::setFileName(string file) //resets filename to the passed parameter
{
  filename = file;
}

void FileSim::runSim(Gameboard& g, Gameplay& p, bool &b, int generation_count) //overwritten runSim function now includes code to open the output file as well as error checking for file output
{
  ofstream ouput_file(filename, ios::out | ios::app); //opens the output file that shares the name of the filename variable

  if(ouput_file.is_open()) //checks to see if the output file has been successfully opened
  {
    if(first_time) //ensures the initial generation is printed, then switches first_time to false
    {
      this->printGeneration(g, generation_count, ouput_file);
      this->next(ouput_file);
      first_time = false;
    }
    else //if it's not the initial generation, play() runs before things are printed to the file
    {
      p.play();
      this->printGeneration(g, generation_count, ouput_file);
      this->next(ouput_file);
    }

    if(p.isStable() || p.isOscillating() || p.isRepeating()) //checks if the simulation has stabilized, formed an oscillator, or otherwise created a repeating pattern
    {
      this->pressEnterToContinue("it has stabilized");
      b = false;
    }
  }
  else //if the file is not able to be opened, an error message is printed to the console
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

  //now this section prints to the passed ofstream& parameter instead of the console
  //also the function no longer moves the cursor to overwrite the existing board
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

void FileSim::next(ofstream& out) //now this function will print an empty line to the file to separate generations
{
  out << endl;
}
