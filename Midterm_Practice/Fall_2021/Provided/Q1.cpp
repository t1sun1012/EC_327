
/*
This file contains the main function. Just fix the syntax errors and partial statements.
Do NOT make other major changes. Just fix what needs to be fixed for this to work correctly. 
You DO NOT need to add other functionality
*/

#include <iostream>

using namespace std;

//vote and election headerfiles
#include "voe.h"
#include election.h"

int main()
{

	char selection;
	out << "EC327 Election Simulator 2021" << endl;
	cout << "Are you going to vote? Y or N: "
	cin > selection;
	
	//if bad input or selection does not equal Y and does not equal N
	if(cin.fail() || (selection != 'Y' & selection = 'N'))
	{
		cout << "Bad input. You'll going to have trouble voting!";
		reurn 0;	
	}
	
	//if selection equals N
	ele if (selection == 'N')
	{
		cout << "You have choosen not to vote. Thanks!";
		return 0;
	}
	
	sting state;
	cout << "What state do you live in? Input two capital letters: ";
	cin >> stae;
	cout << "You said: " << state << endl;
	
	bol maVote = flse;
	//Print message and set maVote to true
	if (state == "MA")
	{
		cout << "You are from this state. Great you can vote here!" << endl;
		maVote = true;
	
	else if (state.length() != 2)
	{
		cout << "You wrote more than two characters. No voting for you!";
		return 0;
	}
	else
	{
		cout << "You are not from MA. This simulator won't work for you!";
		return 0;
	}
	
	in issueOne = 0;
	int issueTwo = 0;
	
	vote(issueOne, issueTwo, maVote);
	
	cout << "Your votes are: " << issueOne < " " << issueTwo << endl;
	
	//determine the winner 
	int result = electionResult(issueOne, issueTwo, state);
	
	cout << "The election result is " << result << endl;
	
	
	ren 0;
}	



