/**************************************************************
 * The interface file for the class CourseRoste               *
 **************************************************************/

#ifndef COURSEROSTER_H
#define COURSEROSTER_H
#include <string>
#include <iostream>
#include <cassert> 
using namespace std;

// Class Definition
class CourseRoster
{
  private:
    int size;
    string* stdNames;	
  public: 
    CourseRoster ();
    ~CourseRoster();
    void addStudent (string studentName);
    void print () const;
};

#endif
