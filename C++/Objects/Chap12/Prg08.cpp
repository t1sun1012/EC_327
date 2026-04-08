/**************************************************************
 * Modification of application file to show the actual use of * 
 * polymorphism with an array of poiners.                     *
 **************************************************************/

#include "student.h"

int main ( )
{
  // Declaration of an array of polymorphic variables (pointers)
  Person* ptr [4];

  // Instantiation of four objects in the heap memory
  ptr[0] = new Student ("Joe", 3.7);
  ptr[1] = new Student ("John", 3.9);
  ptr[2] = new Person ("Bruce");
  ptr[3] = new Person ("Sue");

  // Calling the virtual print function for each object
  for (int i = 0; i < 4; i++)
  {
    ptr[i] -> print ();
    cout << endl; 
  }

  // Deleting the objects in the heap
  for (int i = 0; i < 4; i++)
  {
    delete ptr [i];
  }
  return 0;
}

	