/**************************************************************
 * The interface file for the Professor class                 *
 **************************************************************/

#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "person.h"

class Professor: virtual public Person  // Virtual inheritance
{
  protected:
    double salary;  // Protected data member
  public:
    Professor (string name, double salary);
    ~Professor ();
    void print ();
};

#endif

