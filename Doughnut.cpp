#include "Gameplay.h"
#include "Doughnut.h"


int Doughnut::checkHorizontal(int h, int v)
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

int Doughnut::checkVertical(int h, int v)
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

int Doughnut::checkLeftDiagonal(int h, int v)
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

int Doughnut::checkRightDiagonal(int h, int v)
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

int Doughnut::positive_modulo(int i, int n)
{
  return (n + (i % n)) % n;
}
