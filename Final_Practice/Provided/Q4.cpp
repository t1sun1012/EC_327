#include <iostream>
using namespace std;

//DO NOT MODIFY
class Student
{
	public:

	virtual bool getStudied() = 0;
	
	protected:
		bool studied;
};

//DO NOT MODIFY
class MedStudent : public Student
{
	public:
	bool getStudied()
	{return true;}
};


//DO NOT MODIFY
class Slacker : public Student
{
	public:
	bool getStudied()
	{return false;}
};

//Add +, /, and * overloaded operators here.

//+ - Return a Slacker if either argument is a Slacker. MedStudent otherwise.
Student *operator+(Student &firstStudent, Student &secondStudent) {
	if ((dynamic_cast<Slacker *>(&firstStudent) != NULL) || (dynamic_cast<Slacker *>(&secondStudent) != NULL)) {
		return new Slacker();
	}
	else {
		return new MedStudent();
	}
}


// / - Return whatever the denominator is
Student *operator/(Student &firstStudent, Student &secondStudent) {
	if (dynamic_cast<Slacker *>(&secondStudent) != NULL) {
		return new Slacker();
	}
	else {
		return new MedStudent();
	}
}

// * - Return a Slacker if both arguments are Slackers. MedStudent otherwise.
Student *operator*(Student &firstStudent, Student &secondStudent) {
	if ((dynamic_cast<Slacker *>(&firstStudent) != NULL) && (dynamic_cast<Slacker *>(&secondStudent) != NULL)) {
		return new Slacker();
	}
	else {
		return new MedStudent();
	}
}

//HINT: Look at the title of the problem.





//ONLY REPLACE THE SIX LINES
//If you change other material to hardcode the cout statements you will get 0 for this question
int main()
{
	Slacker s;
	MedStudent m;
	
	Slacker *st; 
	Slacker *original;
	original = st;
	
	// Assign st to (s + m);
	st = dynamic_cast<Slacker *>(s+m);
	if(st == NULL)
		cout << "No Slackers added!" << endl;
	else
		cout << "Added at least one Slacker!" << endl;
	// Assign st to (m + m);
	st = dynamic_cast<Slacker *>(m+m);
	if(st == NULL)
		cout << "No Slackers added!" << endl;
	else
		cout << "Added at least one Slacker!" << endl;
	
	
	// Assign st to (m * s);
	st = dynamic_cast<Slacker *>(m*s);
	if (st == NULL)
		cout << "Multipied at least one MedStudent!" << endl;
	else
		cout << "No MedStudents multiplied!" << endl;	
	
	st = dynamic_cast<Slacker *>(s*s);
	// Assign st to (s * s);
	if (st == NULL)
		cout << "Multipied at least one MedStudent!" << endl;
	else
		cout << "No MedStudents multiplied!" << endl;
	
	
	// Assign st to (m / m);
	st = dynamic_cast<Slacker *>(m/m);
	if (st == NULL)
		cout << "MedStudent in the denominator!" << endl;
	else
		cout << "Slacker in the denominator" << endl;	


	// Assign st to (m / s);
	st = dynamic_cast<Slacker *>(m/s);
	if (st == NULL)
		cout << "MedStudent in the denominator!" << endl;
	else
		cout << "Slacker in the denominator" << endl;
	
	if(st == original)
	cout << "Nothing Changed!"<< endl;
	
  return 0;
}
