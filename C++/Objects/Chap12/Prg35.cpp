/**************************************************************
 * The interface file for Professor concrete class. This class*
 * inherits from two classes: Person and PrfType.             *
 **************************************************************/

#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "person.h"
#include "prftype.h"

class Professor : public Person, public PrfType
{	
  public: 
    Professor (string name, double salary);
    void printSalary();
    void print ();
};

