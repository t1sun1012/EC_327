//Provided code
/**
 * This function determines a various measure of your speed.
 It needs to return a double value that represents either Miles Per Hour or
 Minutes Per Mile.
 It requires
 1. Metric - 0 for MPH, 1 for Minutes Per Mile - this is what it needs to calculate
 2. Units - h = time in hours, m = time in minutes - there are the units fo the time provided
 
MPH = MARATHON distance divided by time in hours.
Minutes Per Mile = time in minutes divided by MARATHON distance

 */

#include "timeCalc.h"
 
extern const double MARATHON;

//Put calcSplit function here as described in timeCalc.h
?? calcSplit(??)
{
	//mph
	if (metric == ??)
	{
		cout << "MPH: ";
		if(units == ??)
		{
			return (MARATHON/??);
		}
		
		if (units == ??)
		{
			return (MARATHON/(??/60.0));
		}
		
	}	
	
	//minutes per mile
	if (metric == ??)
	{
		cout << "Minutes Per Mile: ";
		if(units == ??)
		{
			return ((??*60.0)/MARATHON);
		}
		
		if (units == ??)
		{
			return (??/MARATHON);
		}
		
	}	
	
	return 0;
}




