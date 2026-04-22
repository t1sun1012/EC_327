#include <iostream>
using namespace std;

class Student
{
	public: 
		
		//DO NOT CHANGE
		Student(bool s, int i, double g, int c)
		{
			studied = s;
			iq = i;
			gpa = g;
			classesTaken = c;
		}
		
		//Add two accessor methods here
   
		//MUST STAY PUBLIC
		double gpa;
		int classesTaken;
	
	private:
		
		//DO NOT MODIFY!!!
		void print()
		{
			cout << "Student studied = " << studied << endl;
			cout << "Student gpa = " << gpa << endl; 
			cout << "Student IQ = " << iq << endl; 
			cout << "Student classes taken = " << classesTaken << endl << endl; 			
		}
		
		//MUST STAY PRIVATE
		bool studied;
		int iq;
			
};


class Professor
{
	public: 
	
	//Add "addClass" function here
	//Parameter - Student
	/*
		If the willPass function returns true then the classesTaken 
		for the student should be incremented.
	*/
	
	//Add willPass function here
	//Parameter - Student
	//Return - bool
	/*
		If the student has studied or has an IQ of over 90 they should pass (return true)
	
		Else return false AND if gpa is less then 3 decrement the number of classes 
		they have taken.
	
	*/
};



//DO NOT CHANGE OTHER THAN TO UNCOMMENT THE CODE LISTED
int main()
{
  
  Professor p;
  
  Student s1(false, 100, 3.0, 0);
  Student s2(true, 100, 2.7, 0);
  Student s3(false, 87, 3.5, 1);
  Student s4(false, 80, 2.0, 1);
  
  //Uncomment when done
  /*
  p.addClass(s1);
  p.addClass(s2);
  p.addClass(s3);
  p.addClass(s4);
  */
  
  //Uncomment when done. YOU CANNOT MOVE the print function to public
  //How to give main access to print?
  /*
  s1.print();
  s2.print();
  s3.print();
  s4.print();
  */
  
  cout << "Q1 compiles" << endl;
  
  return 0;
  
}
