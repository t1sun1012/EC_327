/*************************************************************
 * The implementation file for the Student class             * 
 *************************************************************/

#include "Student.h"

// Definition of Constructor for Student class
Student :: Student (string nm, double gp)
: Person (nm), gpa (gp)
{
}


// Definition of virtual print function for Student class
void Student :: print () const
{
  Person :: print ();
  cout << "GPA: " << gpa << endl;
}

