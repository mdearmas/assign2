/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 2: Game of Life
  Purpose: This is the header file for the Gameboard class, which controls the 2d array that comprises the simulation grid.
*/
#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include <iostream> //allows acces to input and output
#include <fstream> //allows access to file reading
#include <cstdlib> //allows access to the c++ standard library (used to troubleshoot rand() function)
#include <time.h> //provides time() for random seeding

using namespace std; //allows access to std

class Gameboard {
public:
  Gameboard(); //default constructor
  Gameboard(int h, int v); //constructor
  Gameboard(const Gameboard& copy); //copy constructor

  ~Gameboard(); //destructor

  //accessor functions
  int getHorizontal() const { return horizontal; }
  int getVertical() const { return vertical; }
  char** getBoard() const { return board; }

  void resize(int h, int v); //resizes the 2d array
  void death(int h, int v); //fills a cell with a '-' to represent an empty or dead cell
  void birth(int h, int v); //fills a cell with a 'X' to represent a filled or alive cell

  void randomFill(double density); //randomly fills the 2d array with 'X's based on the passed parameter

  bool fileFill(string filename); //copies the map in the file of the same name as the parameter (returns a bool to keep track of a successful file access)
  bool compare(const Gameboard& g); //checks to see if the boards of two Gameboard objects are identical
  bool isEmpty(); //checks to see if the board has no 'X's

  Gameboard& operator=(const Gameboard &g); //redefines the assignment operator (Source: https://stackoverflow.com/questions/11347599/how-to-define-an-assignment-operator-outside-my-header-file-in-c)

private:
  int horizontal; //the number of rows
  int vertical; //the number of columns
  char **board; //a pointer to the first element of the 2d array that will serve as the simulation board
};

#endif
