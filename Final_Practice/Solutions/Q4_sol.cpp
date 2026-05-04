#include <iostream>
using namespace std;


class Student
{
	public:

	virtual bool getStudied() = 0;
	
	protected:
		bool studied;
};

class MedStudent : public Student
{
	public:
	bool getStudied()
	{return true;}
};


class Slacker : public Student
{
	public:
	bool getStudied()
	{return false;}
};


Student *operator+(Student &firstStudent, Student &secondStudent)
{

	if((dynamic_cast<Slacker *>(&firstStudent) != NULL) || (dynamic_cast<Slacker *>(&secondStudent) != NULL)) 
		return new Slacker();
	else
		return new MedStudent();

}

Student *operator/(Student &firstStudent, Student &secondStudent)
{

	if((dynamic_cast<Slacker *>(&secondStudent) != NULL)) 
		return new Slacker();
	else
		return new MedStudent();


}

Student *operator*(Student &firstStudent, Student &secondStudent)
{
	if((dynamic_cast<Slacker *>(&firstStudent) != NULL) && (dynamic_cast<Slacker *>(&secondStudent) != NULL)) 
		return new Slacker();
	else
		return new MedStudent();

}


int main()
{
	Slacker s;
	MedStudent m;
	
	Slacker *st; 
	Slacker *original;
	original = st;
	
	st = dynamic_cast<Slacker *>(s + m);
	if(st == NULL)
		cout << "No Slackers added!" << endl;
	else
		cout << "Added at least one Slacker!" << endl;
	st = dynamic_cast<Slacker *>(m + m);
	if(st == NULL)
		cout << "No Slackers added!" << endl;
	else
		cout << "Added at least one Slacker!" << endl;
	
	
	st = dynamic_cast<Slacker *>(m * s);
	if (st == NULL)
		cout << "Multipied at least one MedStudent!" << endl;
	else
		cout << "No MedStudents multiplied!" << endl;	
	st = dynamic_cast<Slacker *>(s * s);
	if (st == NULL)
		cout << "Multipied at least one MedStudent!" << endl;
	else
		cout << "No MedStudents multiplied!" << endl;
	
	
	st = dynamic_cast<Slacker *>(m / m);
	if (st == NULL)
		cout << "MedStudent in the denominator!" << endl;
	else
		cout << "Slacker in the denominator" << endl;	
	st = dynamic_cast<Slacker *>(m / s);
	if (st == NULL)
		cout << "MedStudent in the denominator!" << endl;
	else
		cout << "Slacker in the denominator" << endl;
	
	if(st == original)
	cout << "Nothing Changed!"<< endl;
	
  return 0;
}
