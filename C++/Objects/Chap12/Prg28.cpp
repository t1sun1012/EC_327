/**************************************************************
 * The interface file for the TA class                        *
 **************************************************************/

#ifndef TA_H
#define TA_H
#include "student.h"
#include "professor.h"

class TA: public Professor, public Student // Double inheritance
{
  public:
    TA (string name, double gpa, double sal);
    ~TA ();
    void print ();
};

#endif