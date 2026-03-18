//Provided code
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

//interviewDecode
//Fix the function
//Only fix the function header and the one line commented
string interviewDecode(const int interview_value)
{
  string interview = "";
  int target = interview_value; //make sure the value is not greater than 9
  switch(target)
  {
    case 0:  return interview = "No Interview";  
    case 1:  return interview = "Microsoft";
	case 2:  return interview = "Intel";  
    case 3:  return interview = "Samsung"; 
	case 4:  return interview = "Facebook";  
    case 5:  return interview = "Google";
	case 6:  return interview = "Apple";  
    case 7:  return interview = "Uber"; 
	case 8:  return interview = "Qualcomm";  
    case 9:  return interview = "AMD";	
    default:
      cout << "Error" << endl;
	  return interview;
  }
  cout << "No switch!" << endl;
  return interview; // (Should never get this far)
}

//Fix this function
bool interviewThatDay(int *const interviewList, const int jobCount, int& interview)
{
	for (int i =0; i< jobCount; i++)//fix the question marks
	{
		if (interviewList[i] != -1) //check if the interview list at the given index is NOT equal to -1
		{
			//set the interview value to the value at the index location
			//Add one line
			interview = interviewList[i];
			
			//clear this interview by setting the value at the index location to -1
			//Add one line
			interviewList[i] = -1;
			
			return true;
		}
	}
	return false;
}
