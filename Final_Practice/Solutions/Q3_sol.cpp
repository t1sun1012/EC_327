#include <iostream>
#include<exception>
using namespace std;


class Student
{
	public: 
		
		virtual void setStudied(bool s)
		{ 
			studied = s; 
		}
   	
		double getStudied()
		{
			return studied;
		}
	
	protected:
		bool studied;
};



class StudiesException: public exception
{
	public:
		
		Student *sPtr;
		
		StudiesException(Student *s)
		{
			cout << this->what() << ": ";
			sPtr = s;
		}		
};

class Slacker: public Student
{
	public: 
	
		void setStudied(bool s)
		{	 
			throw StudiesException(this);
		}	
};


int main()
{
  
  Student *s = new Student();
  s->setStudied(true);
  cout << "Studied = " << s->getStudied() << endl;
  
  
  Student *slack = new Slacker();
  try
  {
	slack->setStudied(true);
  }
  catch (StudiesException e)
  {
	cout << "A " << typeid(*(e.sPtr)).name() << " does not study!" << endl;
  }
  
  cout << "Q3 compiles" << endl;
  
  return 0;
  
}
