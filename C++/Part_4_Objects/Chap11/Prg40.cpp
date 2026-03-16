/**************************************************************
 * The interface file for the class Registrar                 *
 **************************************************************/

#ifndef REGISTRAR_H
#define REGISTRAR_H
#include "course.h"
#include "student.h"


// Class Definition
class Registrar
{
  public: 
    Registrar ();
    ~Registrar(); 
    void enroll (Student student, Course course);
};
#endif