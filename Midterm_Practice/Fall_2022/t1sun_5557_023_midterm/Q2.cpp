//Provided Code
#include <iostream>
using namespace std;

#include "gpaTools.h"
#include "futureCalc.h"

/**
 * This main function is a testbench for the other functions.
 * EC327 Staff will have their own version. Use this to test your functions.
 * Please DO include file as well however with your submission. 
 * We will use this as a quick compilation test and to see what went wrong if you have issues.
 */
 
 
 int main()
 {
	
	cout << "Let's get some basic grade info!" << endl;
	cout << "How many classes are you going to take? ";
	
	int classCount;
	cin >> classCount;
	
	double *gpaList = new double[classCount];
	double classGpa;
	for (int i=0; i<classCount; i++)
	{
		cout << "Enter a class GPA: " ;
		cin >> classGpa;
		addGPA(classGpa, i, gpaList);
	}
	
	double ave;
	cout << "Recorded GPA" << endl;
	determineGPA(gpaList, classCount, ave);
	cout << "Overall GPA is : " << ave << endl;
	
	char addClass = 'y';
	while(addClass == 'y')
	{
	cout << "Do you want to add a class? (y/n) ";
	cin >> addClass;
		if (addClass == 'y')
		{
			double addedGPA;
			cout << "Class GPA: ";
			cin >> addedGPA;
			double *tempGPA = addNewClass(gpaList, addedGPA, classCount);
			delete [] gpaList;
			gpaList = tempGPA;
			cout << "Recorded GPA" << endl;
			determineGPA(gpaList, classCount, ave);
			cout << "Overall GPA is : " << ave << endl;
		}
	}
	
	char externalInfo;
	int sum = 0;
	cout << "Do you have external info? (y/n) ";
	cin >> externalInfo;
	if (externalInfo == 'y')
	{
		sum = readExternalInfo("ExternalInfo.txt");
		cout << "External Info = " << sum << endl;
	}

	
	cout << "Time to plan your future!" << endl;
	
	int score = futureScore(ave, sum);
	cout << "Future Score = " << score << endl;
	
	cout << futureDecode(score);
	
	return 0;
 }
 
 
