#include "Gameboard.h"

Gameboard::Gameboard()
{
  horizontal = 10;
  vertical = 10;
  board = new char*[horizontal];

  for(int i = 0; i < horizontal; ++i)
  {
    board[i] = new char[vertical];
  }

  for(int i = 0; i < horizontal; ++i)
  {
    for(int j = 0; j < vertical; ++j)
    {
      board[i][j] = '-';
    }
  }
}

Gameboard::Gameboard(int h, int v)
{
  horizontal = h;
  vertical = v;
  board = new char*[horizontal];

  for(int i = 0; i < horizontal; ++i)
  {
    board[i] = new char[vertical];
  }

  for(int i = 0; i < horizontal; ++i)
  {
    for(int j = 0; j < vertical; ++j)
    {
      board[i][j] = '-';
    }
  }
}

Gameboard::Gameboard(const Gameboard& copy)
{
  horizontal = copy.horizontal;
  vertical = copy.vertical;
  board = new char*[horizontal];

  for(int i = 0; i < horizontal; ++i)
  {
    board[i] = new char[vertical];
  }

  for(int i = 0; i < horizontal; ++i)
  {
    for(int j = 0; j < vertical; ++j)
    {
      board[i][j] = copy.board[i][j];
    }
  }
}

Gameboard::~Gameboard()
{
  for(int i = 0; i < horizontal; ++i)
  {
    delete[] board[i];
  }
  delete[] board;
}

void Gameboard::resize(int h, int v)
{
  for(int i = 0; i < horizontal; ++i)
  {
    delete[] board[i];
  }
  delete[] board;

  horizontal = h;
  vertical = v;
  board = new char*[horizontal];

  for(int i = 0; i < horizontal; ++i)
  {
    board[i] = new char[vertical];
  }

  for(int i = 0; i < horizontal; ++i)
  {
    for(int j = 0; j < vertical; ++j)
    {
      board[i][j] = '-';
    }
  }
}

void Gameboard::death(int h, int v)
{
  board[h][v] = '-';
}

void Gameboard::birth(int h, int v)
{
  board[h][v] = 'X';
}

void Gameboard::randomFill(double density)
{
  int r;
  for(int i = 0; i < horizontal; ++i)
  {
    for(int j = 0; j < vertical; ++j)
    {
      r = rand() % 100;
      if( r <= (density * 100) )
      {
        board[i][j] = 'X';
      }
    }
  }
}

bool Gameboard::fileFill(string filename)
{
  ifstream input_file;
  bool return_val = true;

  int index = 0;
  int line_count = 0;
  int h;
  int v;

  string line;

  input_file.open(filename);
  if(input_file.is_open())
  {
    input_file >> h;
    input_file.clear();
    input_file.ignore(1024, '\n');

    input_file >> v;
    if (h < 1 || v < 1 || input_file.fail())
    {
      return_val = false;
    }
    else
    {
      input_file.clear();
      input_file.seekg(0);
      resize(h, v);

      while ( getline(input_file, line) )
      {
        if(line_count < 2)
        {
          ++line_count;
        }
        else
        {
          for (int i = 0; i < vertical; ++i)
          {
            if(index >= horizontal)
            {
              return_val = false;
              break;
            }
            else if(line[i] != '-' && line[i] != 'X')
            {
              return_val = false;
            }
            else
            {
              board[index][i] = line[i];
            }
          }
          ++index;
        }
      }
    }
    input_file.close();
  }
  else
  {
    return_val = false;
  }

  return return_val;
}

bool Gameboard::compare(const Gameboard& g)
{
  bool return_val = true;
  char **board2 = g.getBoard();

  for(int i = 0; i < horizontal; ++i)
  {
    for(int j = 0; j < vertical; ++j)
    {
      if(board[i][j] != board2[i][j])
      {
        return_val = false;
      }
    }
  }
  return return_val;
}

bool Gameboard::isEmpty()
{
  bool return_val = true;

  for(int i = 0; i < horizontal; ++i)
  {
    for(int j = 0; j < vertical; ++j)
    {
      if(board[i][j] == 'X')
      {
        return_val = false;
      }
    }
  }
  return return_val;
}

Gameboard& Gameboard::operator=(const Gameboard &g)
{
  if(this != &g)
  {
    for(int i = 0; i < horizontal; ++i)
    {
      delete[] board[i];
    }
    delete[] board;

    horizontal = g.horizontal;
    vertical = g.vertical;
    board = new char*[horizontal];

    for(int i = 0; i < horizontal; ++i)
    {
      board[i] = new char[vertical];
    }

    for(int i = 0; i < horizontal; ++i)
    {
      for(int j = 0; j < vertical; ++j)
      {
        board[i][j] = g.board[i][j];
      }
    }
  }
}
