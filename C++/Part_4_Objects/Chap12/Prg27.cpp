/**************************************************************
 * The implementation file for the Professor class            *
 **************************************************************/

#include "professor.h"

// Constructor
Professor :: Professor (string nm, double sal)
: Person (nm), salary (sal)
{
}


// Destructor
Professor :: ~Professor ()
{
}


// Print member function
void Professor :: print ()
{
  cout << "Professor " << endl;
  cout << "Name: " << name << "  ";
  cout << "Salary: " << salary << endl << endl;
}

