#include "Gameplay.h"

Gameplay::Gameplay()
{
  current = Gameboard();
  previous = Gameboard(current);
  previous2 = Gameboard(current);

  current_board = current.getBoard();
  previous_board = previous.getBoard();
}

Gameplay::Gameplay(const Gameboard& game)
{
  current = Gameboard(game);
  previous = Gameboard(current);
  previous2 = Gameboard(current);

  current_board = current.getBoard();
  previous_board = previous.getBoard();
}

void Gameplay::death(int h, int v)
{
  current_board[h][v] = '-';
}

void Gameplay::birth(int h, int v)
{
  current_board[h][v] = 'X';
}

void Gameplay::play()
{
  int total_neighbors = 0;
  previous2 = previous;
  previous = current;
  previous_board = previous.getBoard();

  for(int h = 0; h < previous.getHorizontal(); ++h)
  {
    for(int v = 0; v < previous.getVertical(); ++v)
    {
      total_neighbors = checkHorizontal(h, v) + checkVertical(h, v) + checkLeftDiagonal(h, v) + checkRightDiagonal(h, v);
      if(total_neighbors = 3)
      {
        birth(h, v);
      }
      else if(total_neighbors >= 4 || total_neighbors <= 1)
      {
        death(h, v);
      }
    }
  }
}

int Gameplay::checkHorizontal(int h, int v)
{
  int neighbors;

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
  int neighbors;

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
  int neighbors;

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
  int neighbors;

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
  return (current.compare(previous));
}

bool Gameplay::isOscillating()
{
  return (current.compare(previous2));
}
