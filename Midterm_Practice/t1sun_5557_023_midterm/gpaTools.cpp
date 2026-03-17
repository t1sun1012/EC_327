#include <iostream>
#include <fstream>
using namespace std;


//Fix this function
void addGPA(const double classGpa, const int i, double * gpaList)
{
	
	//set the element in the list at the index provided to gpa
	//??[i] = gpa;
	gpaList[i] = classGpa;
	return;	
}

//Fix this function
void determineGPA(const double *const gpaList, const int classCount, double &ave)
{
	double gpaTotal = 0;
	for (int j=0; j<classCount; j++)//figure out the loop action-after-each-iteration
	{
		cout << "Course #" << j+1 << " = " << gpaList[j] << endl;
		//increment the total by the current element in the list
		//gpaTotal += ??;
		gpaTotal += gpaList[j];
	}
	//determin the total divided by how may elements thre are
	//ave = ??;
	ave = gpaTotal / classCount;
	return;
}

//Fix this function
double * addNewClass(const double *const gpaList, const double addedGPA, int& classCount)
{
	//create the array with a size big enough for the old elements plus the new one
	//double *returnList = ??;
	double *returnList = new double[classCount + 1];
	for(int i=0; i<classCount; i++)//determine the loop continuation condition
		//returnList[i] = ??;//copy the orginal elements into the new element
		returnList[i] = gpaList[i];
	//returnList[size] = ??;//add the new gpa
	returnList[classCount] = addedGPA;


	//?? add a line here that is going to modify a variable to take into account the new size of the array 
	classCount++;
	return returnList;
}

//Fix this function
int readExternalInfo(const char * inputFile)
{
	ifstream input;	
	input.open(inputFile);
	int sum = 0;
	int temp;
	//Pick the right while statement
	/*
	while(input.eof())
	while(!eof())
	while(!input.eof())
	while(!input)
	*/
	while(!input.eof())
	{
		input >> temp;
		//add temp to a growing sum value
		sum += temp;
		//??;
	}
	//Pick the right statement
	/*
	input.close();
	input.exit();
	close.input();
	*/
	input.close();
	return sum;
}











