/**************************************************************
 * The interface file for an Array class                      *
 **************************************************************/

#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cassert>
using namespace std;
                                                                               
class Array 
{
  private:
    double* ptr;
    int size;
  public: 
    Array (int size);  // Constructor 
    ~Array( );  // Destructor
    double& operator[ ] (int index) const; // Accessor  
    double& operator[ ] (int index) ;  // Mutator     
};

#endif

