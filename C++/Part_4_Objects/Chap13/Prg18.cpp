/**************************************************************
 * The application file to test the Matrix class              *
 **************************************************************/

#include "matrix.h"
 
int main ()
{
  // Instantiation and filling matrix1 (2 by 3) 
  Matrix matrix1 (2, 3);
  matrix1.fill ();


  // Instantiation and filling matrix2 (2 by 3)	
  Matrix matrix2 (2, 3);
  matrix2.fill ();

  // Instantiation and filling matrix1 (3 by 4)	
  Matrix matrix3 (3, 4);
  matrix3.fill ();


  // Adding matrix 1 and 2 to get matrix4	
  Matrix matrix4 (2, 3);
  matrix4 = matrix1 + matrix2;

  // Subtracting matrix 2 from 1 to get matrix5		
  Matrix matrix5 (2, 3);
  matrix5 = matrix1 - matrix2;

  // Multiplying matrix 1 by 3 to get matrix6
  Matrix matrix6 (2, 4);
  matrix6 = matrix1 * matrix3;

  // Printing all six matrices
  cout << "matrix1: \n" << matrix1 << endl;
  cout << "matrix2: \n" << matrix2 << endl;
  cout << "matrix3: \n" << matrix3 << endl;
  cout << "matrix4 (matrix1 + matrix2): \n" << matrix4 << endl;
  cout << "matrix5 (matrix1 - matrix2): \n" << matrix5 << endl;
  cout << "matrix6 (matrix1 * matrix3): \n" << matrix6 << endl;
  return 0;
}

