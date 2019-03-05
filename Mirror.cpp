/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 2: Game of Life
  Purpose: This file contains the out-of-class member functions of Mirror.
*/
#include "Gameplay.h"
#include "Mirror.h"

int Mirror::checkHorizontal(int h, int v) //changes the function to account for reflections
{
  int neighbors = 0;

  if(v == 0) //if the cell is in the left most column, check itself
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else //else, check the cell to the immediate left of the target cell
  {
    if(previous_board[h][v - 1] == 'X')
    {
      ++neighbors;
    }
  }

  if(v == previous.getVertical()-1) //if the cell is in the right most column, check itself
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else //else, check the cell to the immediate right
  {
    if(previous_board[h][v + 1] == 'X')
    {
      ++neighbors;
    }
  }

  return neighbors;
}

int Mirror::checkVertical(int h, int v) //changes the function to account for reflections
{
  int neighbors = 0;

  if(h == 0) //if the cell is in the top most row, check itself
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else //else, check the cell directly above
  {
    if(previous_board[h - 1][v] == 'X')
    {
      ++neighbors;
    }
  }

  if(h == previous.getHorizontal()-1) //if the cell is in the bottom most row, check itself
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else //else, check the cell directly below
  {
    if(previous_board[h + 1][v] == 'X')
    {
      ++neighbors;
    }
  }

  return neighbors;
}

int Mirror::checkLeftDiagonal(int h, int v) //changes the function to account for reflections
{
  int neighbors = 0;

  if(h == 0 && v == 0) //if the cell is the top left cell, then check itself
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else if(h == 0) //else, if the cell is in the top row, check the cell in the same row but one column to the left
  {
    if(previous_board[h][v - 1] == 'X')
    {
      ++neighbors;
    }
  }
  else if(v == 0) //else, if the cell is the the left most column, check the cell in the same column one row above
  {
    if(previous_board[h - 1][v] == 'X')
    {
      ++neighbors;
    }
  }
  else //else, check the cell one up and one to the left
  {
    if(previous_board[h - 1][v - 1] == 'X')
    {
      ++neighbors;
    }
  }

  if(h == previous.getHorizontal()-1 && v == previous.getVertical()-1) //if the cell is the bottom right one, check itself
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else if(h == previous.getHorizontal()-1) //else, if the cell is in the bottom row, check the cell in the same row but one column to the right
  {
    if(previous_board[h][v + 1] == 'X')
    {
      ++neighbors;
    }
  }
  else if(v == previous.getVertical()-1) //else, if the cell is in the right most column, check the cell in the same column but one row below
  {
    if(previous_board[h + 1][v] == 'X')
    {
      ++neighbors;
    }
  }
  else //else, check the cell one row down and one column to the right
  {
    if(previous_board[h + 1][v + 1] == 'X')
    {
      ++neighbors;
    }
  }

  return neighbors;
}

int Mirror::checkRightDiagonal(int h, int v) //changes the function to account for reflections
{
  int neighbors = 0;

  if(h == 0 && v == previous.getVertical()-1) //if the cell is the top right cell, check itself
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else if(h == 0) //else, if the cell is in the top row, check the same row but one cell to the right
  {
    if(previous_board[h][v + 1] == 'X')
    {
      ++neighbors;
    }
  }
  else if(v == previous.getVertical()-1) //else, if the cell is in the right most column, check the same column but one cell above
  {
    if(previous_board[h - 1][v] == 'X')
    {
      ++neighbors;
    }
  }
  else //else, check the cell one row up and one to the right
  {
    if(previous_board[h - 1][v + 1] == 'X')
    {
      ++neighbors;
    }
  }

  if(h == previous.getHorizontal()-1 && v == 0) //if the cell is the bottom left cell, check itself
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else if (h == previous.getHorizontal()-1) //else, if the cell is in the bottom row, check the same row but one cell to the left
  {
    if(previous_board[h][v - 1] == 'X')
    {
      ++neighbors;
    }
  }
  else if (v == 0) //else, if the cell is in the left most common, check the same column but one cell down
  {
    if(previous_board[h + 1][v] == 'X')
    {
      ++neighbors;
    }
  }
  else //else, check the cell one down and one to the left
  {
    if(previous_board[h + 1][v - 1] == 'X')
    {
      ++neighbors;
    }
  }

  return neighbors;
}
