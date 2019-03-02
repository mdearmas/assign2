#include "Gameplay.h"
#include "Mirror.h"

int Mirror::checkHorizontal(int h, int v)
{
  int neighbors = 0;

  if(v == 0)
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else
  {
    if(previous_board[h][v - 1] == 'X')
    {
      ++neighbors;
    }
  }

  if(v == previous.getVertical()-1)
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else
  {
    if(previous_board[h][v + 1] == 'X')
    {
      ++neighbors;
    }
  }

  return neighbors;
}

int Mirror::checkVertical(int h, int v)
{
  int neighbors = 0;

  if(h == 0)
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else
  {
    if(previous_board[h - 1][v] == 'X')
    {
      ++neighbors;
    }
  }

  if(h == previous.getHorizontal()-1)
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else
  {
    if(previous_board[h + 1][v] == 'X')
    {
      ++neighbors;
    }
  }

  return neighbors;
}

int Mirror::checkLeftDiagonal(int h, int v)
{
  int neighbors = 0;

  if(h == 0 && v == 0)
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else if(h == 0)
  {
    if(previous_board[h][v - 1] == 'X')
    {
      ++neighbors;
    }
  }
  else if(v == 0)
  {
    if(previous_board[h - 1][v] == 'X')
    {
      ++neighbors;
    }
  }
  else
  {
    if(previous_board[h - 1][v - 1] == 'X')
    {
      ++neighbors;
    }
  }

  if(h == previous.getHorizontal()-1 && v == previous.getVertical()-1)
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else if(h == previous.getHorizontal()-1)
  {
    if(previous_board[h][v + 1] == 'X')
    {
      ++neighbors;
    }
  }
  else if(v == previous.getVertical()-1)
  {
    if(previous_board[h + 1][v] == 'X')
    {
      ++neighbors;
    }
  }
  else
  {
    if(previous_board[h + 1][v + 1] == 'X')
    {
      ++neighbors;
    }
  }

  return neighbors;
}

int Mirror::checkRightDiagonal(int h, int v)
{
  int neighbors = 0;

  if(h == 0 && v == previous.getVertical()-1)
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else if(h == 0)
  {
    if(previous_board[h][v + 1] == 'X')
    {
      ++neighbors;
    }
  }
  else if(v == previous.getVertical()-1)
  {
    if(previous_board[h - 1][v] == 'X')
    {
      ++neighbors;
    }
  }
  else
  {
    if(previous_board[h - 1][v + 1] == 'X')
    {
      ++neighbors;
    }
  }

  if(h == previous.getHorizontal()-1 && v == 0)
  {
    if(previous_board[h][v] == 'X')
    {
      ++neighbors;
    }
  }
  else if (h == previous.getHorizontal()-1)
  {
    if(previous_board[h][v - 1] == 'X')
    {
      ++neighbors;
    }
  }
  else if (v == 0)
  {
    if(previous_board[h + 1][v] == 'X')
    {
      ++neighbors;
    }
  }
  else
  {
    if(previous_board[h + 1][v - 1] == 'X')
    {
      ++neighbors;
    }
  }

  return neighbors;
}
