/**************************************************************
 * The application file to test the Array class               *
 **************************************************************/

#include "array.h"

int main ( )
{
  // Instantiation of array object with three elements
  Array arr (3);

  // Storing values using mutator operator [ ]	
  arr[0] = 22.31;
  arr[1] = 78.61;
  arr[2] = 65.22;

  // Retrieving values using accessor operator [ ]		
  for (int i = 0; i < 3; i++)
  {
    cout << "Value of arr [" << i <<"]: " << arr[i] << endl;
  }
  return 0;
}


