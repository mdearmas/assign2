#include "Gameplay.h"

Gameplay::Gameplay(Gameboard& game)
{
  current = &game;
  previous = Gameboard(*current);
  first = Gameboard(*current);

  current_board = (*current).getBoard();
  previous_board = previous.getBoard();

  stable_repetitions = 0;
  oscillating_repetitions = 0;
  repeating_repetitions = 0;
  playtime = 0;
}

void Gameplay::play()
{
  int total_neighbors = 0;
  previous = *current;
  past_boards[playtime] = *current;
  previous_board = previous.getBoard();

  for(int h = 0; h < previous.getHorizontal(); ++h)
  {
    for(int v = 0; v < previous.getVertical(); ++v)
    {
      total_neighbors = checkHorizontal(h, v) + checkVertical(h, v) + checkLeftDiagonal(h, v) + checkRightDiagonal(h, v);
      if(total_neighbors == 3)
      {
        (*current).birth(h, v);
      }
      else if(total_neighbors >= 4 || total_neighbors <= 1)
      {
        (*current).death(h, v);
      }
      total_neighbors = 0;
    }
  }
  ++playtime;
}

int Gameplay::checkHorizontal(int h, int v)
{
  int neighbors = 0;

  if(v != 0)
  {
    if(previous_board[h][v - 1] == 'X')
    {
      ++neighbors;
    }
  }

  if(v != previous.getVertical()-1)
  {
    if(previous_board[h][v + 1] == 'X')
    {
      ++neighbors;
    }
  }

  return neighbors;
}

int Gameplay::checkVertical(int h, int v)
{
  int neighbors = 0;

  if(h != 0)
  {
    if(previous_board[h - 1][v] == 'X')
    {
      ++neighbors;
    }
  }

  if(h != previous.getHorizontal()-1)
  {
    if(previous_board[h + 1][v] == 'X')
    {
      ++neighbors;
    }
  }

  return neighbors;
}

int Gameplay::checkLeftDiagonal(int h, int v)
{
  int neighbors = 0;

  if(h != 0 && v != 0)
  {
    if(previous_board[h - 1][v - 1] == 'X')
    {
      ++neighbors;
    }
  }

  if(h != previous.getHorizontal()-1 && v != previous.getVertical()-1)
  {
    if(previous_board[h + 1][v + 1] == 'X')
    {
      ++neighbors;
    }
  }

  return neighbors;
}

int Gameplay::checkRightDiagonal(int h, int v)
{
  int neighbors = 0;

  if(h != 0 && v != previous.getVertical()-1)
  {
    if(previous_board[h - 1][v + 1] == 'X')
    {
      ++neighbors;
    }
  }

  if(h != previous.getHorizontal()-1 && v != 0)
  {
    if(previous_board[h + 1][v - 1] == 'X')
    {
      ++neighbors;
    }
  }

  return neighbors;
}

bool Gameplay::isStable()
{
  bool return_val = false;
  if((*current).compare(previous))
  {
    ++stable_repetitions;
  }
  if(stable_repetitions == 3)
  {
    return_val = true;
  }
  return return_val;
}

bool Gameplay::isOscillating()
{
  bool return_val = false;
  if((*current).compare(first))
  {
    ++oscillating_repetitions;
  }
  if(oscillating_repetitions == 3)
  {
    return_val = true;
  }
  return return_val;
}

bool Gameplay::isRepeating()
{
  bool return_val = false;
  for(int i = 0; i < playtime; ++i)
  {
    if((*current).compare(past_boards[i]))
    {
      ++repeating_repetitions;
    }
    if(repeating_repetitions == 30)
    {
      return_val = true;
    }
  }
  return return_val;
}
