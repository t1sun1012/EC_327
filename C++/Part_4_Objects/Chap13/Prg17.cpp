/**************************************************************
 * The implementation file for the Matrix class               *
 **************************************************************/

#include "matrix.h"

// Default constructor
Matrix :: Matrix ()
: row (0), col (0)
{
  mat = 0;
}


// Parameter constructor
Matrix :: Matrix (int r, int c)
:row (r), col (c)
{
  mat = new int* [row];
  for (int r = 0; r < row; r++)
  {
    mat [r] = new int [col];
  }
}


// Destructor
Matrix :: ~Matrix ()
{
  for (int r = 0; r < row; r++)
  {
    delete [ ] mat [r];
  }
  delete [ ] mat;
}


// Copy constructor
Matrix :: Matrix (const Matrix& origin)
{
  mat = new int* [origin.row];
  for (int r = 0; r < origin.row; r++)
  {
    mat [r] = new int [origin.col];
  }

  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < col; c++)
    {
       mat [r][c] = origin.mat [r][c];
    }
  }
}


// Assignment operator
Matrix& Matrix :: operator= (const Matrix& right)
{
  row = right.row;
  col = right.col;
  mat = new int* [row];
  for (int r = 0; r < row; r++)
  {
    mat [r] = new int [col];
  }
  for (int r = 0; r < right.row; r++)
  {
    for (int c = 0; c < right.col; c++)
    {
      mat [r][c] = right.mat [r][c];
    }
  }
  return *this;
} 


// Overloading the addition operator		
const Matrix operator+ (const Matrix& left, const Matrix& right)
{
  if (left.row != right.row || left.col != right.col)
  {
    cout << "Matrices are not compatible for addition!" << endl;
    assert (false);
  }
  Matrix result (left.row, right.col);
  for (int r = 0; r < left.row ; r++)
  {
    for (int c = 0; c < right.col; c++)
    {
      result.mat [r] [c] = left.mat [r] [c] + right.mat [r] [c];
    }
  }
  return result;
}


// Overloading the subtraction operator		
const Matrix operator- (const Matrix& left, const Matrix& right)
{
  if (left.row != right.row || left.col != right.col)
  {
    cout << "Matrices are not compatible for subtraction!";
    cout << endl;
    assert (false);
  }
  Matrix result (left.row, right.col);
  for (int r = 0; r < left.row ; r++)
  {
    for (int c = 0; c < right.col; c++)
    {
      result.mat [r][c] = left.mat [r][c] - right.mat [r][c];
    }
  }
  return result;
}



// Overloading the multiplication operator		
const Matrix operator* (const Matrix& left, const Matrix& right)
{
  if (left.col != right.row)
  {
    cout << "Matrices are not compatible for multiplication!";
    cout << endl;
    assert (false);
  }
  Matrix result (left.row, right.col);
  int common = left.col;
  for (int r = 0; r < result.row ; r++)
  {
    for (int c = 0; c < result.col; c++)
    {
      result.mat [r][c] = 0;
      for (int k = 0; k < common; k++)
      {
        result.mat[r][c] += (left.mat) [r][k]*(right.mat)[k][c];
      }
    }
  }
  return result;
}

	
// Overloading the insertion operator		
ostream& operator<< (ostream& output, const Matrix& left)
{
  for (int r = 0; r < left.row; r++)
  {
    for (int c = 0; c < left.col; c++)
    {
      cout << fixed << setw (5) << (left.mat) [r][c] << " ";
    }
    cout << endl;
  }
  return output;
  }

	 
// The fill member function to fill the value of a matrix
void Matrix :: fill () 
{
  for (int r = 0; r < row ; r++)
  {
    cout << "Enter " << col << " values for row "; 
    cout << r << " separated by space(s): " ;
    for (int c = 0; c < col; c++)
    {
      cin >> mat[r][c]; 
    }
  }
  cout << endl;
}

