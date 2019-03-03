/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 2: Game of Life
  Purpose: This is the header file for the Gameplay class, which manages the standard Game of Life's rules and processes (including checking for neighbors and populating the succeeding generation.)
*/

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include <iostream>

#include "Gameboard.h" //allows us access to the Gameboard class

using namespace std;

class Gameplay {
public:
  Gameplay(); //default constructor
  Gameplay(Gameboard& game); //constructor
  virtual ~Gameplay() {}; //destructor

  void death(int h, int v); //empties a cell, aka: fills the cell with '-'
  void birth(int h, int v); //fills a cell with 'X'

  void play(); //runs through all the cells on a board, checks for neighbors, and adjusts the current board accordingly

  virtual int checkHorizontal(int h, int v); //checks the cells directly left and right of the target cell
  virtual int checkVertical(int h, int v); //checks the cells directly above and below the target cell
  virtual int checkLeftDiagonal(int h, int v);
  virtual int checkRightDiagonal(int h, int v);

  bool isStable(); //checks if the gameboard has stabilized (aka: no changes are occuring)
  bool isOscillating(); //checks if the gameboard is an oscillator circling back to its original iteration
  bool isRepeating(); //a failsafe that catches all other stable conditions, such as a pattern that eventually stabilizes into an oscillator

protected:
  Gameboard* current; //the address of the current game board in play
  Gameboard previous; //a copy of the gameboard before changes have occurred
  Gameboard first; //the inital state of the gameboard, makes it easier to track oscillators

  Gameboard past_boards[1200]; //enough to accomodate the r-pentomino

  char **current_board; //stores the board object of current
  char **previous_board; //stores the board object of previous

  int stable_repetitions; //number of times a repetition is detected via isStable()
  int oscillating_repetitions; //number of times a repetition is detected via isOscillating()
  int repeating_repetitions; //number of times a repetition is detected via isRepeating() [yes I know this is super redundant but I had already created a naming convention pattern and I had to stick to it]
  int playtime; //number ot times play() has been called
};

#endif
