//Provided Code
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


//Fix this function
//futureScore
//calculate the gpa plus 1/3 the external info sum
//perform arithmetic on that value to ensure to return a value between 0 and 9
int futureScore(const double ave, const int sum)
{
	int score;
	score = ave + (1/3 * sum);//fix

  // todo ensure 0 and 9
	return score;
}


//futureDecode
//fix this function
//Only fix the function header and the four lines commented
string futureDecode(int score)
{
  string future = "";
  //??(??)
  switch (score)
  {
    case 0:  return future = "No Future";  break;
    case 1:  return future = "Live With Parents"; break;
	  case 2:  return future = "Perpetual College Student";  break;
    case 3:  return future = "Intern"; break;
	  //case ??:  return ?? = "Technician";  
    case 4: return future = "Technician"; break;
    case 5:  return future = "Junior Engineer";break;
	  case 6:  return future = "Senior Engineer";  break;
    case 7:  return future = "CEO"; break;
	  case 8:  return future = "President";  break;
    case 9:  return future = "Emperor of the World";	break;
    //?? - add the correct syntax here for the default behavior
    default:
      cout << "Error" << endl;break;
	  return future;
  }
  cout << "No switch!" << endl;
  return future = "Error";
  //return ??; // (Should never get this far)
}


