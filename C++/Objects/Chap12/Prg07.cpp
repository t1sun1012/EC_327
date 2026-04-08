/*************************************************************
 * The application file to test Person and Student classes   *
 *************************************************************/

#include "Student.h"

int main ( )
{
  // Creation of ptr as polymorphic variable
  Person* ptr;

  // Instantiation of Person object in the heap
  ptr = new Person ("Lucie");
  cout << "Person Information";	
  ptr -> print();
  cout << endl;
  delete ptr;

  // Instantiation of Student object in the heap
  ptr = new Student ("John", 3.9);
  cout << "Student Information";	
  ptr -> print();
  cout << endl;
  delete ptr;
  return 0;
}	


