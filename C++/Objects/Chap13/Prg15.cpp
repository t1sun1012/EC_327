/**************************************************************
 * The application file date.cpp uses the Date objects.       *
 **************************************************************/

#include "date.h"

int main ( )
{

  // Create two dates and print them
  Date date1 (2, 8, 2014);
  Date date2 (10, 15, 1944);
  cout << "date1: " << date1;
  cout << "date2: " << date2;


  // Create two more dates, increment them, and print them
  Date date3 = date1;
  Date date4 = date2;
  date3++;
  date4++;
  cout << "date3: " << date3;
  cout << "date4: " << date4;

  // Add and subtract days to and from the previous dates
  date3 += 20;
  date4 -= 130;
  cout << "date3 after change: " << date3;
  cout << "date4 after change: " << date4;

  // Find the difference and print the number of days
  cout <<"Difference between date3 and date4: "; 
  cout << date3 - date4 << " days.";
  return 0;
}
	