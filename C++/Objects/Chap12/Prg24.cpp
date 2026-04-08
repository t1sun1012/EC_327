/**************************************************************
 * The interface file for the Student class                   *
 **************************************************************/

#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"

class Student: virtual public Person  // Virtual inheritance
{
  protected:
    double gpa;  // Protected data member
  public:
    Student (string name, double gpa);
    ~Student ();
    void print ();
};

#endif



