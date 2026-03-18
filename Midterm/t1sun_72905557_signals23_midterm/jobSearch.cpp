#include <iostream>
#include <fstream>
using namespace std;


//Fix this function
//Just fix the one line
bool isDuplicate(const int *const interviewList, const int jobNum, const int jobCount)
{
	for (int k=0; k<jobCount; k++)
		{
			//case for a duplicate entry
			if(interviewList[k] == jobNum)//just fix this line the rest of the body is fine
			{
				cout << "Duplicate job!" << endl;
				return true;
			}
		}
	return false;
}

//Fix this function
//Just fix the one line
void addJob(int *const interviewList, const int jobNum, const int i)
{
	cout << "Adding job " << jobNum << " on day " << i << endl;//leave this line
	//add one line here; this should add the jobNum to the interviewList at the specified location i 
	interviewList[i] = jobNum;
	return;
}

//Fix this function
//Only fix the 3 lines
bool getResults(int *const resultList, const int jobCount, const char* file)
{
	ifstream input;	
	input.open(file);//fix this line

	int i = 0;
	while(i< jobCount)//fix this line
	{		
		input >> resultList[i];//fix this line; should fill the results array	
		i++;
	}
	
	input.close();
	return true;
}

//Fix this function
//Just fix the 2 lines
void printResults(const int interview, const int *const resultList, const int j)
{
	if(resultList[j] != 0 && interview != 0)//check if you have a result value (non zero) AND the interview is not zero
			cout << "Got the job!" << endl;
	else if (interview == 0)//check if the interview value is zero
			cout << "N/A" << endl;
	else
		cout << "Didn't get the job" << endl;
	return;
}








