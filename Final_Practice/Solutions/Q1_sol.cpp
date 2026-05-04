#include <iostream>
using namespace std;

class Student
{
	public: 
		
		Student(bool s, int i, double g, int c)
		{
			studied = s;
			iq = i;
			gpa = g;
			classesTaken = c;
		}
		
		bool getStudied()
		{ 
			return studied; 
		}
		
		int getIQ()
		{
			return iq;
		}
   
		friend int main();
	
		double gpa;
		int classesTaken;
	
	private:
		
		void print()
		{
			cout << "Student studied = " << studied << endl;
			cout << "Student gpa = " << gpa << endl; 
			cout << "Student IQ = " << iq << endl; 
			cout << "Student classes taken = " << classesTaken << endl << endl; 			
		}
		
		bool studied;
		int iq;
			
};


class Professor
{
	public: 
	
	void addClass(Student &s)
	{ 
		if(willPass(s))
			s.classesTaken++;
	}
	
	bool willPass(Student &s)
	{
		if (s.getStudied() || s.getIQ() > 90)
		{
			return true;
		}
		else
		{
			if(s.gpa < 3)
				s.classesTaken--;
			return false;
		}
			
	}
};




int main()
{
  
  Professor p;
  
  Student s1(false, 100, 3.0, 0);
  Student s2(true, 100, 2.7, 0);
  Student s3(false, 87, 3.5, 1);
  Student s4(false, 80, 2.0, 1);
  
  p.addClass(s1);
  p.addClass(s2);
  p.addClass(s3);
  p.addClass(s4);
  
  s1.print();
  s2.print();
  s3.print();
  s4.print();

  cout << "Q1 compiles" << endl;
  
  return 0;
  
}
