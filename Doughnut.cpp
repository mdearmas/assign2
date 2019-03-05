/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 1: C++ Review
  Purpose: This file contains the out-of-member class functions for Doughnut.
*/
#include "Gameplay.h" //allows access to Gameplay class
#include "Doughnut.h" //allows access to Doughnut.h

int Doughnut::checkHorizontal(int h, int v) //changes the function to utilize the modulo operator to wrap around the array
{
  int neighbors = 0;

  if(previous_board[h][positive_modulo((v - 1), (*current).getVertical())] == 'X')
  {
    ++neighbors;
  }

  if(previous_board[h][positive_modulo((v + 1), (*current).getVertical())] == 'X')
  {
    ++neighbors;
  }

  return neighbors;
}

int Doughnut::checkVertical(int h, int v) //changes the function to utilize the modulo operator to wrap around the array
{
  int neighbors = 0;

  if(previous_board[positive_modulo((h - 1), (*current).getHorizontal())][v] == 'X')
  {
    ++neighbors;
  }

  if(previous_board[positive_modulo((h + 1), (*current).getHorizontal())][v] == 'X')
  {
    ++neighbors;
  }

  return neighbors;
}

int Doughnut::checkLeftDiagonal(int h, int v) //changes the function to utilize the modulo operator to wrap around the array
{
  int neighbors = 0;

  if(previous_board[positive_modulo((h - 1), (*current).getHorizontal())][positive_modulo((v - 1), (*current).getVertical())] == 'X')
  {
    ++neighbors;
  }

  if(previous_board[positive_modulo((h + 1), (*current).getHorizontal())][positive_modulo((v + 1), (*current).getVertical())] == 'X')
  {
    ++neighbors;
  }

  return neighbors;
}

int Doughnut::checkRightDiagonal(int h, int v) //changes the function to utilize the modulo operator to wrap around the array
{
  int neighbors = 0;

  if(previous_board[positive_modulo((h - 1), (*current).getHorizontal())][positive_modulo((v + 1), (*current).getVertical())] == 'X')
  {
    ++neighbors;
  }

  if(previous_board[positive_modulo((h + 1), (*current).getHorizontal())][positive_modulo((v - 1), (*current).getVertical())] == 'X')
  {
    ++neighbors;
  }

  return neighbors;
}

int Doughnut::positive_modulo(int i, int n) //adapts the C++ modulo operator to always produce a positive number(Source: https://stackoverflow.com/questions/14997165/fastest-way-to-get-a-positive-modulo-in-c-c )
{
  return (n + (i % n)) % n;
}
