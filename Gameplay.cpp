/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 2: Game of Life
  Purpose: This file includes all the out-of-class member functions for the Gameplay class.
*/
#include "Gameplay.h"

Gameplay::Gameplay() //default constructor
{
  Gameboard g; //generates a default Gameboard
  current = &g; //sets current to the address of the gameboard

  previous = Gameboard(*current); //copies current to previous
  first = Gameboard(*current); //copies current to first

  current_board = (*current).getBoard(); //stores the array associated with current to the current_board variable
  previous_board = previous.getBoard(); //stores the array associated with previous to the previous_board variable

  stable_repetitions = 0; //initializes the stable_repetitions variable to 0
  oscillating_repetitions = 0; //initializes the oscillating_repetitions variable to 0
  repeating_repetitions = 0; //initializes the repeating_repetitions variable to 0
  playtime = 0; //initializes the playtime variable to 0
}

Gameplay::Gameplay(Gameboard& game) //constructor
{
  current = &game; //sets current to the address of the passed Gameboard parameter
  previous = Gameboard(*current); //copies current to previous
  first = Gameboard(*current); //copies current to first

  current_board = (*current).getBoard(); //stores the array associated with current to the current_board variable
  previous_board = previous.getBoard(); //stores the array associated with previous to the previous_board variable

  stable_repetitions = 0; //initializes the stable_repetitions variable to 0
  oscillating_repetitions = 0; //initializes the oscillating_repetitions variable to 0
  repeating_repetitions = 0; //initializes the repeating_repetitions variable to 0
  playtime = 0; //initializes the playtime variable to 0
}

void Gameplay::play() //takes the current board, compares it to its neighbors, and updates the board
{
  int total_neighbors = 0; //initializes the number of neighbors to 0
  previous = *current; //stores the most current Gameboard object to previous
  past_boards[playtime] = *current; //stores the current board to the past_boards array
  previous_board = previous.getBoard(); //access the board stored in the previous variable

  for(int h = 0; h < previous.getHorizontal(); ++h) //iterating along the rows
  {
    for(int v = 0; v < previous.getVertical(); ++v) //iterating along the columns
    {
      total_neighbors = checkHorizontal(h, v) + checkVertical(h, v) + checkLeftDiagonal(h, v) + checkRightDiagonal(h, v); //totals the number of neighbors surrounding a single cell
      if(total_neighbors == 3) //if the number of neighbors = 3, then the cell is filled
      {
        (*current).birth(h, v);
      }
      else if(total_neighbors >= 4 || total_neighbors <= 1) //if the number of neighbors is greater than or equal to 4 or less than or equal to 1, the cell is emptied
      {
        (*current).death(h, v);
      }
      total_neighbors = 0; //resets the number of neighbors to 0
    }
  }
  ++playtime; //increments the number of times the board has been played
}

int Gameplay::checkHorizontal(int h, int v) //checks the cells directly left and right of the target cell
{
  int neighbors = 0;

  if(v != 0) //so long as the cell is not on the left most column
  {
    if(previous_board[h][v - 1] == 'X') //if the cell is occupied, add a neighbor
    {
      ++neighbors;
    }
  }

  if(v != previous.getVertical()-1) //so long as the cell is not on the right most column
  {
    if(previous_board[h][v + 1] == 'X') //if the cell is occupied, add a neighbor
    {
      ++neighbors;
    }
  }

  return neighbors;
}

int Gameplay::checkVertical(int h, int v)
{
  int neighbors = 0;

  if(h != 0) //so long as the cell is not on the top most row
  {
    if(previous_board[h - 1][v] == 'X') //if the cell is occupied, add a neighbor
    {
      ++neighbors;
    }
  }

  if(h != previous.getHorizontal()-1) //so long as the cell is not on the bottom most row
  {
    if(previous_board[h + 1][v] == 'X') //if the cell is occupied, add a neighbor
    {
      ++neighbors;
    }
  }

  return neighbors;
}

int Gameplay::checkLeftDiagonal(int h, int v)
{
  int neighbors = 0;

  if(h != 0 && v != 0) //so long as the cell is not on the left most column or top most row
  {
    if(previous_board[h - 1][v - 1] == 'X') //if the cell is occupied, add a neighbor
    {
      ++neighbors;
    }
  }

  if(h != previous.getHorizontal()-1 && v != previous.getVertical()-1) //so long as the cell is not on the right most column or the bottom most row
  {
    if(previous_board[h + 1][v + 1] == 'X') //if the cell is occupied, add a neighbor
    {
      ++neighbors;
    }
  }

  return neighbors;
}

int Gameplay::checkRightDiagonal(int h, int v)
{
  int neighbors = 0;

  if(h != 0 && v != previous.getVertical()-1) //so long as the cell is not on the right most column or top most row
  {
    if(previous_board[h - 1][v + 1] == 'X') //if the cell is occupied, add a neighbor
    {
      ++neighbors;
    }
  }

  if(h != previous.getHorizontal()-1 && v != 0) //so long as the cell is not on the left most column or bottom most row
  {
    if(previous_board[h + 1][v - 1] == 'X') //if the cell is occupied, add a neighbor
    {
      ++neighbors;
    }
  }

  return neighbors;
}

bool Gameplay::isStable() //checks if the gameboard has stabilized (aka: no changes are occuring)
{
  bool return_val = false;
  if((*current).compare(previous)) //if the current board looks exactly the same as the previous board
  {
    ++stable_repetitions; //increments the number of times the board has been stable
  }
  if(stable_repetitions == 3) //once the simulation has been stable through three generations, return true
  {
    return_val = true;
  }
  return return_val;
}

bool Gameplay::isOscillating() //checks if the gameboard is an oscillator circling back to its original iteration; helps shorter period oscillators terminate earlier than via the isRepeating() function
{
  bool return_val = false;
  if((*current).compare(first)) //if the current board looks exactly the same as the first board
  {
    ++oscillating_repetitions; //increments the number of times the board has returned to its initial state
  }
  if(oscillating_repetitions == 3) //once the simulation has oscillated through three times, return true
  {
    return_val = true;
  }
  return return_val;
}

bool Gameplay::isRepeating() //a failsafe that catches all other stable conditions, such as a pattern that eventually stabilizes into an oscillator
{
  bool return_val = false;
  for(int i = 0; i < playtime; ++i) //iterates through the number of times play() has been invoked
  {
    if((*current).compare(past_boards[i])) //if the current board equals any previous board
    {
      ++repeating_repetitions; //increments the number of times repetitions have been seen
    }
    if(repeating_repetitions == 30) //once 30 repetitions have been seen, return true (30 is an arbitrary value)
    {
      return_val = true;
    }
  }
  return return_val;
}
