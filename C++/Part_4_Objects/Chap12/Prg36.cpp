/**************************************************************
 * The interface file for TA concrete class. This class       *
 * inherits from tree classes: Person and StdType and PrfType.*
 **************************************************************/

#ifndef TA_H
#define TA_H
#include "person.h"
#include "stdtype.h"
#include "prftype.h"

class TA: public Person, public StdType, public PrfType
{
  public: 
    TA (string name, double gpa, double salary);
    void printGPA ();
    void printSalary();
    void print ();
};

#endif

