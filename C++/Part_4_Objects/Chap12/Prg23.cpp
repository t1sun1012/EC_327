/**************************************************************
 * The implementation file for the Person class               *
 **************************************************************/

#include "person.h"

// Constructor
Person :: Person (string nm)
: name (nm)
{
}


// Destructor
Person :: ~Person ()
{
}


// Print member function
void Person :: print ()
{
  cout << "Person" << endl;
  cout << "Name: " << name << endl << endl;
}
