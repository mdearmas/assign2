/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 2: Game of Life
  Purpose: This file contains all the out-of-class member functions for the Gameboard class.
*/
#include "Gameboard.h"

Gameboard::Gameboard() //default constructor
{
  horizontal = 10; //default sets the number of columns to 10
  vertical = 10; //default sets the number of columns to 10
  board = new char*[horizontal]; //sets board to a dynamic array (of size equal to horizontal) of char pointers

  for(int i = 0; i < horizontal; ++i) //fills each element of the above array with another array of vertical length
  {
    board[i] = new char[vertical];
  }

  for(int i = 0; i < horizontal; ++i) //fills the array with '-' (AKA: it's empty upon initilization)
  {
    for(int j = 0; j < vertical; ++j)
    {
      board[i][j] = '-';
    }
  }
}

Gameboard::Gameboard(int h, int v)
{
  horizontal = h; //sets the number of rows to the first passed integer parameter
  vertical = v; //sets the number of columns to the second passed integer parameter
  board = new char*[horizontal]; //sets board to a dynamic array (of size equal to horizontal) of char pointers

  for(int i = 0; i < horizontal; ++i) //fills each element of the above array with another array of vertical length
  {
    board[i] = new char[vertical];
  }

  for(int i = 0; i < horizontal; ++i) //fills the array with '-' (AKA: it's empty upon initilization)
  {
    for(int j = 0; j < vertical; ++j)
    {
      board[i][j] = '-';
    }
  }
}

Gameboard::Gameboard(const Gameboard& copy) //copy constructor
{
  horizontal = copy.horizontal; //sets this.horizontal to the horizontal of the passed Gameboard
  vertical = copy.vertical; //sets this.vertical to the vertical of the passed Gameboard
  board = new char*[horizontal]; //sets board to a dynamic array (of size equal to horizontal) of char pointers

  for(int i = 0; i < horizontal; ++i) //fills the array with '-' (AKA: it's empty upon initilization)
  {
    board[i] = new char[vertical];
  }

  for(int i = 0; i < horizontal; ++i) //iterates through the arrays and copies the elements of the passed object to this object
  {
    for(int j = 0; j < vertical; ++j)
    {
      board[i][j] = copy.board[i][j];
    }
  }
}

Gameboard::~Gameboard() //destructor
{
  for(int i = 0; i < horizontal; ++i)
  {
    delete[] board[i];
  }
  delete[] board;
}

void Gameboard::resize(int h, int v) //resizes the 2d array
{
  //first deletes the existing array
  for(int i = 0; i < horizontal; ++i)
  {
    delete[] board[i];
  }
  delete[] board;

  //sets the variables to the new values and dynamically creates a new char* array
  horizontal = h;
  vertical = v;
  board = new char*[horizontal];

  for(int i = 0; i < horizontal; ++i) //fills new array with arrays
  {
    board[i] = new char[vertical];
  }

  for(int i = 0; i < horizontal; ++i) //fills new array with empty cells
  {
    for(int j = 0; j < vertical; ++j)
    {
      board[i][j] = '-';
    }
  }
}

void Gameboard::death(int h, int v) //fills the cell at the location indicated by the parameters with '-'
{
  board[h][v] = '-';
}

void Gameboard::birth(int h, int v) //fills the cell at the location indicated by the parameters with 'X'
{
  board[h][v] = 'X';
}

void Gameboard::randomFill(double density) //randomly fills cells of the 2d array with 'X's
{
  int r;

  //nested loops to iterate through the game board
  for(int i = 0; i < horizontal; ++i)
  {
    for(int j = 0; j < vertical; ++j)
    {
      r = rand() % 100; //randomly generates a number between 0-100
      if( r <= (density * 100) ) //density is input as a double between 0 and 1, so it must be multiplied by 100
      {
        board[i][j] = 'X';
      }
    }
  }
}

bool Gameboard::fileFill(string filename) //copies the map in the file of the same name as the parameter (returns a bool to keep track of a successful file access)
{
  ifstream input_file; //the input file stream
  bool return_val = true; //this bool value is used to track whether or not the function was successful in accessing and copying the file

  int index = 0; //used to keep track of the line number of the file in order to map it to the row index of the gameboard array
  int line_count = 0;
  int h;
  int v;

  string line;

  input_file.open(filename); //opens the file of the same name as the passed parameter
  if(input_file.is_open()) //checks to see if the file was successfully opened
  {
    input_file >> h;

    //flushes the input stream
    input_file.clear();
    input_file.ignore(1024, '\n');

    input_file >> v;

    if (h < 1 || v < 1 || input_file.fail()) //checks to see if the number of rows and columns are valid; if not, the function returns false
    {
      return_val = false;
    }
    else
    {
      //clears the input stream and resets the cursor
      input_file.clear();
      input_file.seekg(0);

      resize(h, v); //resizes the array to fit the dimensions included in the file

      while ( getline(input_file, line) )
      {
        if(line_count < 2) //skips the first two lines of the file, since they contain the dimension and not the map
        {
          ++line_count;
        }
        else
        {
          for (int i = 0; i < vertical; ++i) //interates through the columns in a single row
          {
            if(index >= horizontal) //if there are more lines in the file than there are rows in the array
            {
              return_val = false;
              break;
            }
            else if(line[i] != '-' && line[i] != 'X') //checks to see if the map contains invalid characters
            {
              return_val = false;
            }
            else //copies the line character to the board
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
  else //if the file was not able to be opened
  {
    return_val = false;
  }

  return return_val;
}

bool Gameboard::compare(const Gameboard& g) //checks to see if the boards of two Gameboard objects are identical
{
  bool return_val = true;
  char **board2 = g.getBoard(); //stores the board of the passed Gameboard g for easy access

  //loop iterates through both arrays; if at any point, the array elements are not equal, the boolean swtiches to false
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

bool Gameboard::isEmpty() //checks to see if the board has no 'X's
{
  bool return_val = true;

  //if the array at any point contains a 'X', then the boolean switches to true
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

Gameboard& Gameboard::operator=(const Gameboard &g) //redefines the assignment operator
{
  if(this != &g) //prevents self assignment
  {
    for(int i = 0; i < horizontal; ++i) //deletes the existing array
    {
      delete[] board[i];
    }
    delete[] board;

    //sets this objects variables to the values of the passed Gameboard
    horizontal = g.horizontal;
    vertical = g.vertical;
    board = new char*[horizontal];

    //creates a new 2d array for the board
    for(int i = 0; i < horizontal; ++i)
    {
      board[i] = new char[vertical];
    }

    //copies the contents of the passed Gameboard to this board
    for(int i = 0; i < horizontal; ++i)
    {
      for(int j = 0; j < vertical; ++j)
      {
        board[i][j] = g.board[i][j];
      }
    }
  }
}
