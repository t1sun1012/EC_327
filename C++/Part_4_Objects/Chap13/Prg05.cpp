/**************************************************************
 * The implementation file for Array class                    *
 **************************************************************/

#include "array.h"

// Constructor (allocating memory in the heap)
Array :: Array (int s)
:size (s)
{
  ptr = new double [size];
}
 
 // Destructor (freeing memory in the heap) 
Array :: ~Array( )
{
  delete [ ] ptr;
} 

// Accessor subscript
double& Array :: operator[ ] (int index) const
{ 
  if (index < 0 || index >= size)
  {
    cout << "Index is out of range. Program terminates.";
    assert (false);
  }
  return ptr [index];
}

// Mutator subscript  
double& Array :: operator[ ] (int index)
{
  if (index < 0 || index >= size)
  {
    cout << "Index is out of range. Program terminates.";
    assert (false);
  }
  return ptr [index];
}

   