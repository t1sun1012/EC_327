/**************************************************************
 * The implementation file for the Smallest class             *
 **************************************************************/

#include "smallest.h"

// Constructor
Smallest :: Smallest ( )
{
  current = numeric_limits <int> :: max();
}

// Overloaded function call operator	                                                                                                                                     
int Smallest :: operator() (int next) 
{
  if (next < current)
  {	
    current  =  next;
  }
  return current; 
}	