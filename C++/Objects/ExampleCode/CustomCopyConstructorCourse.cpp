#include <iostream>
#include "Course1.h"
using namespace std;

int main()
{
  
  Course course1("C++");
  Course course2(course1);
  
  course1.addStudent("Bart Simpson");
  course2.addStudent("Homer Simpson");
  
  cout << "Students in course1: " << course1.getStudents()[0] << endl;
  cout << "Students in course2: " << course2.getStudents()[0] << endl;

  return 0;
}
