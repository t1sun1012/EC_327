#include <iostream>

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

//Add StudiesException here. Extend the "exception" class
//See exam document for details
//Include this line in the contructor: cout << this->what() << ": "; 
class StudiesException : public exception {
	public:
		Student *sPtr;

		StudiesException(Student* Ptr){
			sPtr = Ptr;
			cout << this->what() << ": ";
		}

};



//Add Slacker class here
//All it needs in one public method - void setStudied(bool s)
//This function should throw the appropriate exception
class Slacker : public Student {
	void setStudied(bool s) override {
		throw StudiesException(this);
	}
};


int main()
{
  
  Student *s = new Student();
  s->setStudied(true);
  cout << "Studied = " << s->getStudied() << endl;
  
  // Uncomment and fix once the Slacker class and StudiesException is created
  Student *slack = new Slacker();
 
  try {
	slack->setStudied(true);
  }
  
  //Catch exception and respond with this
  catch (StudiesException& e){
	cout << "A " << typeid(*(e.sPtr)).name() << " does not study!" << endl;
  }
  
  
  cout << "Q3 compiles" << endl;
  
  return 0;
  
}
