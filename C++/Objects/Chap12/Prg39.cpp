/**************************************************************
 * The implementation file for Professor concrete class       *
 **************************************************************/

#include "professor.h"

// Constructor
Professor :: Professor (string nm, double sal)
: Person (nm)
{
  salary = sal;   // Assignment, not initialization
}


// PrintSalary member function
void Professor :: printSalary ()
{
  cout << "Salary: ";
  cout << fixed << setprecision (2) << salary << endl;
}


// General print function
void Professor :: print ()
{
  Person :: print();
  printSalary();
}


