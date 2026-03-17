//Provided Code
#include <iostream>
#include <time.h>  
#include <stdlib.h> 

using namespace std;

#include "raceCalc.h"
#include "timeCalc.h"

/*
This file contains the main function. Just fix the syntax errors and partial statements.
Do NOT make other major changes. Just fix what needs to be fixed for this to work correctly. 
You DO NOT need to add other functionality
*/

extern const double MARATHON = 26.22;

int main()
{
	
	double bestTime;
	bool badWeather;
	bool trained;
	char units;
	int metrics;
	
	cout << "Time to go running!" << endl;
	cout << "Enter your best time ";
	cin >> bestTime;
	double originalBest = bestTime;
	
	cout << "Enter if you trained (1 or 0) ";
	cin >> trained;
	cout << "Enter if bad weather (1 or 0) ";
	cin >> badWeather;
	cout << "Enter if your time is in (h)ours or (m)inutes " ;
	cin >> units;
	cout << "Enter if your your want mph (0) or minutes per mile (1) " ;
	cin >> metrics;
	
	bool newBest = runAMarathon (bestTime, badWeather, trained);
	if (newBest)
		cout << "Your new best time is " << bestTime << endl;
	else
		cout << "No new best time" << endl;
	
	double split = calcSplit(bestTime, metrics, units);
	cout << split  << endl;
	
	
	//Print the results of your run
	cout << "******************************" << endl;
	cout << "Your orginal best time was " << originalBest << endl;
	cout << "Your new best time is " << bestTime << endl;
	if(trained)
		cout << "You trained" << endl;
	if (badWeather)
		cout << "There was bad weather";
	cout << "Your time calc was " << split;
	
	return 0;
}	



