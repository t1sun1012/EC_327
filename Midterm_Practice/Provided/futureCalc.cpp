//Provided Code
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


//Fix this function
//futureScore
//calculate the gpa plus 1/3 the external info sum
//perform arithmetic on that value to ensure to return a value between 0 and 9
?? futureScore(const ??, const ??)
{
	int score;
	score = ??//fix
	return score;
}


//futureDecode
//fix this function
//Only fix the function header and the four lines commented
?? futureDecode(??)
{
  string future = "";
  //??(??)
  {
    case 0:  return future = "No Future";  
    case 1:  return future = "Live With Parents";
	case 2:  return future = "Perpetual College Student";  
    case 3:  return future = "Intern"; 
	//case ??:  return ?? = "Technician";  
    case 5:  return future = "Junior Engineer";
	case 6:  return future = "Senior Engineer";  
    case 7:  return future = "CEO"; 
	case 8:  return future = "President";  
    case 9:  return future = "Emperor of the World";	
    //?? - add the correct syntax here for the default behavior
      cout << "Error" << endl;
	  return future;
  }
  cout << "No switch!" << endl;
  //return ??; // (Should never get this far)
}


