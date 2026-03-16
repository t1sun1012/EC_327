/**************************************************************
 * The interface file for the Matrix class                    *
 **************************************************************/

#ifndef  MATRIX_H
#define MATRIX_H
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

// Definition of class Matrix
class Matrix
{
  private:
    int row;
    int col;
    int** mat;

  public:
    Matrix ();   // Default constructor
    Matrix (int row, int col);   // Parameter constructor
    ~Matrix ();    // Destructor   
    Matrix (const Matrix& origin);    // Copy constructor
    Matrix& operator= (const Matrix& right ); // Assignment 
    void fill ();
 
   // Four friend overloaded operators
   friend const Matrix operator+ (const Matrix& lef, 
                                  const Matrix& rgt);
   friend const Matrix operator- (const Matrix& lef, 
                                  const Matrix& rgt);
   friend const Matrix operator* (const Matrix& lef, 
                                  const Matrix& rgt);	
   friend ostream& operator << (ostream& input, 
                                const Matrix& mat);
};

#endif

