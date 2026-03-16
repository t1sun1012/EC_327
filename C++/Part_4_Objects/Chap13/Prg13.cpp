/**************************************************************
 * The interface file date.h defining the class Date          *
 **************************************************************/

#ifndef  DATE_H
#define  DATE_H
#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
using namespace std;

class Date
{
  private: 
  // Instance Data Members
  int month;
  int day;
  int year;

  // Static Data Members and member functions
  static const int startWeekDay;
  static const int startYear;
  static const int daysInMonths [ ];
  static const string daysOfWeek [ ];
  static const string monthsOfYear [ ];	
  static bool isLeap (int year);

  // Private helper function		
  bool isValid () const;
  string findWeekDay ( );
  int findTotalDays( ) const;
  void plusReset ( );
  void minusReset ( );
  public:

  // Constructors and destructor
  Date (int month, int day, int year);
  Date ( );
  ~Date ( );

  // Member operator functions
  Date& operator++( ); 
  Date& operator--( ); 
  Date operator++ (int); 
  Date operator--(int); 
  Date& operator+= (int days); 
  Date& operator-= (int days); 
  bool operator== (const Date& right ) const;
  bool operator!= (const Date& right ) const;
  Date& operator= (const Date& right );

  // Friend operator functions
  friend int operator- (const Date& date1, const Date& date2); 
  friend ostream& operator<<(ostream& output, const Date& date);
};

#endif
