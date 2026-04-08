/**************************************************************
 * The implementation file for the TA class                   *
 **************************************************************/

#include "ta.h"

// Constructor
TA :: TA (string nm, double gp, double sal)
: Person (nm), Student (nm, gp), Professor (nm, sal)
{ 
}


// Destructor
TA :: ~TA ()
{
}


// Print member function
void TA :: print ()
{
  cout << "Teaching Assistance: " << endl;
  cout << "Name: " << name << "  ";
  cout << "GPA: " << gpa << "  ";
  cout << "Salary: " << salary << endl << endl;
}