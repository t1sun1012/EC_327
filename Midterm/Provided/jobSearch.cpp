#include <iostream>
#include <fstream>
using namespace std;


//Fix this function
//Just fix the one line
?? isDuplicate(??)
{
	for (int k=0; k<jobCount; k++)
		{
			//case for a duplicate entry
			if(??)//just fix this line the rest of the body is fine
			{
				cout << "Duplicate job!" << endl;
				return true;
			}
		}
	return false;
}

//Fix this function
//Just fix the one line
?? addJob(??)
{
	cout << "Adding job " << jobNum << " on day " << i << endl;//leave this line
	//add one line here; this should add the jobNum to the interviewList at the specified location i 
	return;
}

//Fix this function
//Only fix the 3 lines
?? getResults(??)
{
	ifstream input;	
	input.open(??);//fix this line

	int i = 0;
	while(i<??)//fix this line
	{		
		input >> ??;//fix this line; should fill the results array	
		i++;
	}
	
	input.close();
	return true;
}

//Fix this function
//Just fix the 2 lines
?? printResults(??)
{
	if(??)//check if you have a result value (non zero) AND the interview is not zero
			cout << "Got the job!" << endl;
	else if (??)//check if the interview value is zero
			cout << "N/A" << endl;
	else
		cout << "Didn't get the job" << endl;
	return;
}








