/**************************************************************
 * The implementation file date.cpp defining the instance     *
 * member functions and helper functions for the Date class   *
 **************************************************************/

#include "date.h"

// Parameter constructor
Date :: Date (int m, int d, int y )
: month (m), day (d), year (y)
{
  if (!isValid ())
  {
    cout << "Date is not valid; program terminates!" << endl;
    assert (false);
  }
} 


// Default constructor
Date :: Date ()
: month (1), day(1), year(1900)
{
}


// Destructor
Date :: ~Date ()
{
}


// Pre-increment operator
Date&  Date :: operator++() 
{
  day++;
  plusReset ();
  return *this;
}


// Pre-decrement operator
Date&  Date :: operator--( ) 
{
  day--;
  minusReset ();
  return *this;
}


// Post-increment operator
Date Date :: operator++ (int) 
{
  Date temp (month, day, year);
  ++(*this);
  return temp;
}


// Post-decrement operator
Date Date :: operator--(int) 
{
  Date temp (month, day, year);
  --(*this);
  return temp;
}


// Compound addition operator
Date&  Date :: operator+= (int days) 
{
  for (int i = 1; i <= days; i++)
  {
    ++(*this); 
  }		
  return *this;
}


// Compound subtraction operator
Date&  Date :: operator-= (int days) 
{
  for (int i = days; i >= 1; i--)
  {
    --(*this); 
  }	
  return *this;
}


//Operator ==
bool Date :: operator== (const Date& right ) const
{
  bool fact1 = (month == right.month);
  bool fact2 = (day == right.day);
  bool fact3 = (year == right.year);
  return (fact1 && fact2 && fact3);
}


// Operator !=
bool Date :: operator!= (const Date& right ) const 
{
  return !(*this == right);
}


// Assignment operator
Date& Date :: operator= (const Date& right ) 
{
  if (*this != right)   // Check for self-assignment
  {
    month = right.month;
    day = right.day;
   year = right.year;
  }
  return *this;
}


// Subtraction operator (friend function)
int operator-(const Date& date1, const Date& date2) 
{
  return (date1.findTotalDays() - date2.findTotalDays());
}



// Output operator (friend function)
ostream& operator<< (ostream& output , const Date& date)
{
  cout << Date :: daysOfWeek [(date.findTotalDays()
                   + Date :: startWeekDay)% 7] << "   ";
  cout << Date :: monthsOfYear [date.month] << " ";
  cout << date.day << " ";
  cout << date.year << endl;
}



// Private function for validation
bool Date :: isValid () const
{
  bool validMonth = (month >= 1) && (month <=12);
  bool validYear = (year >= startYear);
  bool validDay = (day >= 1) && (day <= (Date::
                   daysInMonths[month]
                   + (isLeap (year) && month == 2)));	
  return (validMonth && validYear && validDay);
}	


// Private function for resetting after increment
void Date :: plusReset ()
{
  bool extraDay = (isLeap (year) && month == 2);
  if (day > daysInMonths[month] + extraDay)
  {
    day = 1;
    month++;
  }
  if (month > 12)
  {
    month = 1;
    year++;
  }
}


// Private function for resetting after decrement
void Date :: minusReset ()
{
  if (day < 1)
  {
    month--;	
    if (month < 1)
    {
      month = 12;
      year--;
    }
    bool extraDay = isLeap (year) && (month == 2);
    day = daysInMonths[month] + extraDay ;	
  } 
}


// Private function to find total days
int Date :: findTotalDays() const
{
  int totalDays = 0;
  int currentYear = startYear;
  while (year > currentYear)
  {
    totalDays += 365 + isLeap(currentYear);
    currentYear++;
  }
  int currentMonth = 1;
  while (month > currentMonth)
  {
    totalDays += daysInMonths [currentMonth];
    if (currentMonth == 2)  
    {
      totalDays += isLeap(year);
    }
    currentMonth++;
  }
  totalDays += day - 1;
  return totalDays;
}


// Initialization of static data members
const int Date :: startWeekDay = 1;
const int Date :: startYear = 1900;

const int Date :: daysInMonths [ ] = {0, 31, 28, 31, 30, 31,
                                      30, 31, 31, 30, 31, 30,
                                      31};

const string Date :: daysOfWeek [ ]= {"Sun", "Mon","Tue",
                                      "Wed", "Thr", "Fri"
                                      "Sat"};

const string Date :: monthsOfYear [ ] = {"", "Jan", "Feb",
                                         "Mar", "Apr","May", 
                                         "Jun", "Jul", "Aug",
                                         "Sep", "Oct", "Nov"
                                         "Dec"};

	
// Definition of static member function
bool Date :: isLeap (int year) 
{
  return (year % 400 == 00) || 
         ((year % 4 == 0)&& (year % 100 != 0));
}


