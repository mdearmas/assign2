#include "Controlpanel.h"

void Controlpanel::pressEnterToContinue()
{
  flushIStream(cin);
  cout << "Press [ENTER] to continue. ";
  cin.get();
}

void Controlpanel::pressEnterToContinue(string reason)
{
  flushIStream(cin);
  cout << "The simulation has stopped because " << reason << ". Please press [ENTER] to exit. " ;
  cin.get();
}

void Controlpanel::flushIStream(istream& in)
{
  in.ignore ( numeric_limits<streamsize>::max(), '\n' );
  in.clear();
}
