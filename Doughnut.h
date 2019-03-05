/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 2: Game of Life
  Purpose: This is the header file for the Doughnut class (child of Gameplay).  This overrides the check functions to adapt to Doughnut mode.
*/
#ifndef DOUGHNUT_H
#define DOUGHNUT_H

#include <iostream> //allows us access to input/output

#include "Gameboard.h" //allows us access to Gameboard
#include "Gameplay.h" //allows us access to the parent Gameplay class

using namespace std; //allows us access to std

class Doughnut : public Gameplay {
public:
  Doughnut():Gameplay(){} //default constructor
  Doughnut(Gameboard &game):Gameplay(game){} //constructor

  virtual int checkHorizontal(int h, int v); //overrides Gameplay::checkHorizontal to adapt to Doughnut mode
  virtual int checkVertical(int h, int v); //overrides Gameplay::checkVertical to adapt to Doughnut mode
  virtual int checkLeftDiagonal(int h, int v); //overrides Gameplay::checkLeftDiagonal to adapt to Doughnut mode
  virtual int checkRightDiagonal(int h, int v); //overrides Gameplay::checkRightDiagonal to adapt to Doughnut mode

  int positive_modulo(int i, int n); //adapts the C++ modulo operator to always produce a positive number
};

#endif
