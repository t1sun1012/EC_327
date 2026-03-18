//Provided code
#include <iostream>
using namespace std;

#include "jobSearch.h"
#include "interview.h"

/**
 * This main function is a testbench for the other functions.
 * EC327 Staff will have their own version. Use this to test your functions.
 * Please DO include file as well however with your submission. 
 * We will use this as a quick compilation test and to see what went wrong if you have issues.
 */
 
 
 int main()
 {
 
	cout << "Time to find a job!" << endl;
	cout << "How many jobs do you want (0-10): ";
	
	int jobCount;
	//No error checking here
	cin >> jobCount;
	
	
	int *interviewList = new int[jobCount];
	int interview;
	
	int jobNum;
	bool duplicateJob;
	for(int i=0; i<jobCount; i++)
	{
		cout << "Enter a job number (1-9): "; //ASSUME THAT ONLY 1-9 will be entered here by the user; no error checking needed
		cin >> jobNum;
		duplicateJob = isDuplicate(interviewList, jobNum, jobCount);
		if(!duplicateJob)
			addJob(interviewList, jobNum,i);
		else
			addJob(interviewList, 0, i);//no interview
	}
	
	bool itd;
	int *resultList = new int[jobCount];
	if(getResults(resultList, jobCount, "ResultInputFile.txt"))
	{
		for(int j=0; j<jobCount; j++)
		{
			cout << "Interview on day " << j << ": ";
			itd = interviewThatDay(interviewList, jobCount, interview);
			if (itd)
				cout << interviewDecode(interview) << " - ";
			else
				cout << "No Interview ";
				
			printResults(interview, resultList, j);
		}	
	}
	return 0;
 }
 
 
