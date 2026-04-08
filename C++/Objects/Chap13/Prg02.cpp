/*************************************************************
 * The implementation file for the SmartPtr class            *
 *************************************************************/

#include "smartptr.h"

// Constructor
SmartPtr :: SmartPtr (Fraction*  p)
: ptr (p)  
{
}	

// Destructor		
SmartPtr :: ~SmartPtr ( )
{
  delete ptr;
}

// Overloading of indirection operator 
Fraction& SmartPtr :: operator* ( ) const
{
  return *ptr;
}

// Overloading of the arrow operator 
Fraction* SmartPtr :: operator-> ( ) const
{
  return ptr;
}


