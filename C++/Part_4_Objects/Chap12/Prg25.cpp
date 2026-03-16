/*************************************************************
 * The implementation file for the Student                   *
 *************************************************************/

#include "Student.h"

// Constructor
Student :: Student (string name, double gp)
: Person (name),  gpa (gp)
{
  assert (gpa <= 4.0);
}


// Destructor
Student :: ~Student()
{
}


// Print member function uses a protected data member (name)
void Student :: print () 
{
  cout << "Student " << endl;
  cout << "Name: " << name << "  ";
  cout << "GPA: " << gpa << endl << endl;
}