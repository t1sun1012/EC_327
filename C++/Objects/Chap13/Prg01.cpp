/**************************************************************
 * The interface file for the SmartPtr class                  *
 **************************************************************/

#ifndef SMARTPTR_H
#define SMARTPTR_H
#include <iostream>
using namespace std;

class Fraction;      // Forward declaration
class SmartPtr	
{		
  private:	
    Fraction* ptr;		
  public:	                                                                                                                          
    SmartPtr (Fraction* ptr);   	        
    ~SmartPtr ( );   	                        
    Fraction& operator* ( ) const;
    Fraction* operator->( ) const;
};
 	
#endif


