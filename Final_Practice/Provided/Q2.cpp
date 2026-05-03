#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
	public: 
		
		Student()
		{
			studied = false;
			iq = 200;
			gpa = 4.0;
			classesTaken = 100;
		}
		

		double getGPA()
		{
			return gpa;
		}
		
		double getIQ()
		{
			return iq;
		}
		
		bool getStudied()
		{
			return studied;
		}
		
		double getClassesTaken()
		{
			return classesTaken;
		}	
		
		virtual void setStudied(bool s)
		{
			studied = s;
		}
		
		
	protected:
		double gpa;
		double classesTaken;
		bool studied;
		double iq;
			
};


//Add Slacker class here
class Slacker : public Student {
	public:
		Slacker() {
			studied = false;
			iq = iq / 2.0;
			gpa = gpa / 5.0;
			classesTaken = classesTaken / 4.0;
		}

		void setStudied(bool s) override {
			studied = false;
		}
};


//DO NOT CHANGE
void printStudent(Student *s)
{
	cout << "Student studied = " << s->getStudied() << endl;
	cout << "Student gpa = " << std::setprecision(5) << s->getGPA() << endl; 
	cout << "Student IQ = " << s->getIQ() << endl; 
	cout << "Student classes taken = " << s->getClassesTaken() << endl << endl;
}


//DO NOT CHANGE ANY LINES IN MAIN! Just uncomment code.
int main()
{ 
  Student *s = new Student();
  s->setStudied(true);
  printStudent(s);
  
  
  Student *slack = new Slacker();
  slack->setStudied(true);
  printStudent(slack);
  
  
  cout << "Q2 compiles" << endl;
  
  return 0;
}
