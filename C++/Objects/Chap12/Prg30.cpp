/**************************************************************
 * The application to test all four classes (Person, Student, *
 * Professor, and TA).                                        *
 **************************************************************/

#include "ta.h"

int main ( )
{
  // Testing Person class
  Person person ("John");
  person.print ();


  // Testing Student class	
  Student student ("Anne", 3.9);
  student.print ();


  // Testing Professor class	
  Professor professor ("Lucie", 78000);
  professor.print ();

  // Testing TA class	
  TA ta ("George", 3.2, 20000);
  ta.print ();
  return 0;
}

