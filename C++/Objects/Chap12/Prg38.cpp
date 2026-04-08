/**************************************************************
 * The implementation file for Student concrete class         *
 **************************************************************/

#include "student.h"

// Constructor
Student :: Student (string na, double gp)
:Person (na)
{
  gpa = gp;  // Assignment, not initialization
}


// PrintGPA member function
void Student :: printGPA ()
{
  cout << "GPA: " << fixed << setprecision (2) << gpa << endl;
}


// Print member function
void Student :: print ()
{
  Person :: print();
  printGPA ();
}

