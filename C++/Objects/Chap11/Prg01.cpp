/**************************************************************
 * The program shows how we can let the class Student inherit *
 * from the class Person because a student is a person.       *
 **************************************************************/

#include <iostream>
#include <cassert>
#include <string>
using namespace std;


/**************************************************************
 * The class definition for the Person class                  *
 **************************************************************
class Person
{
  private:
    long identity;	
  public: 
    void setId (long identity);
    long getId( ) const;
};


/**************************************************************
 * The definition of setId function in the Person class       *
 **************************************************************/
void Person :: setId (long id)
{
  identity = id; 
  assert (identity >= 100000000 && identity <= 999999999) ; 
}



/**************************************************************
 * The definition of the getId function in the Person class   *
 **************************************************************/
long Person :: getId () const
{
  return identity;
}


/**************************************************************
 * The class definition for the Student class                 *
 **************************************************************/
class Student : public Person       
{
  private:
   double gpa;
  public: 
    void setGPA (double gpa);
    double getGPA () const;
};

/**************************************************************
 * The definition of setGPA function in Student class         *
 **************************************************************/
void Student :: setGPA (double gp)
{
  gpa = gp;
  assert (gpa >=0 && gpa <= 4.0);
}

/**************************************************************
 * The definition of getGPA function in Student class         *
 **************************************************************/
double Student :: getGPA() const
{
  return gpa;
}



/**************************************************************
 * The application function (main) that uses both classes     *
 **************************************************************/
int main ( )
{
  // Instantiation and use of a Person object
  Person person;
  person.setId (111111111L);
  cout << "Person Information: " << endl;
  cout << "Person's identity: " << person.getId ( );
  cout << endl << endl;

  // Instantiation and use of a Student object	
  Student student;
  student.setId (222222222L);
  student.setGPA (3.9);
  cout << "Student Information: " << endl;
  cout << "Student's identity: " << student.getId() << endl;
  cout << "Student's gpa: " << student.getGPA(); 
  return 0;
}

	