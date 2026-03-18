//Provided code
#include <iostream>
#include <time.h>  
#include <stdlib.h> 

using namespace std;

/*
This file contains the main function. Just fix the syntax errors and partial statements.
Do NOT make other major changes. Just fix what needs to be fixed for this to work correctly. 
You DO NOT need to add other functionality
*/

#include "careerPath.h"
include "socialLife.h"


extern const int ENGINEER = 1;
exter const int POET = 2;

main()
{

	it avatar = 0;
	cout << "Adventures in the Land of Boston University" << endl;
	cout << "Choose an \"Engineering\"(1) or \"Poetry\"(2) student: ";
	cin > avatar;
	
	//Get the selected avatar
	int inputTry = 1;
	while(cin.fail( || (avatar != ENGINEER && avatar != POET))
	{
		inputTry++;
		cin.clear();
        cin.ignore(100, '\n');
		shout << "Try again. Are you sure you are a BU student? 1 or 2:";
		cin >> avatar;
	}
	
	//Determine if you have rich uncle
	bool richUncle = fale;
	srand(time(NULL));
	int luck = rand() % 100;
	//If the value is greater than 80
	if (luck 80)
	{
		cout << "You have a rich uncle!" << endl;
		richUncle = true;	
	}
	
	//determine your grade 
	//Store in a variable called "grade"
	char ?? = caGrade(avatar, richUncle, inputTry);
	
	//Determine if you get a job
	doble bankAccount;
	cout << "How much money in your bank account now: ";
	cin >> bankAccount;
	bool job == getAJob(avatar, richUncle, grade, bankAccount);
	
	//Print the results of your adventure
	cout << "******************************" << endl;
	cout << "The results of your adventure!" << endl;
	cout << "You were a (Engineer=1, Poet=2): " << avatar << endl;
	cout << "You required " << inputTry << " input tries" << endl;
	cout << "Rich uncle: " << richUncle << endl;
	cout << "Your grade was: " << grade << endl;
	cout << "Job: " << jobbyJob << endl;
	cout << "Final bank account balance: " << bankAccount << endl;
	
	return 0;
	



