/**************************************************************
 * The application file to test the SmartPtr class            *
 **************************************************************/

#include "smartptr.h"
#include "fraction.h"

int main ( )
{
  // Creating a smart Pointer object 
  SmartPtr sp = new Fraction (2, 5);               

  // Accessing the member through the * operator
  cout << "Fraction: " << endl;
  (*sp).print ();
  cout << endl;

  // Accessing the member through -> operator
  cout << "Fraction: " << endl;
  sp -> print ();
  cout << endl;
  return 0;
}

	