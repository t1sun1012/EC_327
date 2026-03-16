/**************************************************************
 * The implementation file for the class Course               *
 **************************************************************/

#include "course.h"

// Constructor
Course :: Course (string nm, int ut)
: name (nm), units (ut)
{
  roster = new CourseRoster;
}
 

// Destructor
Course :: ~Course ()
{
}


// Definition of getName function
string Course :: getName() const
{
  return name;
}


// Definition of addStudent function
void Course :: addStudent (string name)
{
  roster -> addStudent (name);
}


// Definition of getRoster function
CourseRoster* Course :: getRoster () const
{
  return roster;
}

 
// Definition of print function
void Course :: print () const
{
  cout << "Course Name: " << name << endl;
  cout << "Number of Units: " << units << endl;
  roster -> print (); 
}


