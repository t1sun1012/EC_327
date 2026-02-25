//Prof. Douglas Densmore
//10-20-21

#include <iostream>

using namespace std;

int main()
{

	cout << "Pointer Fun!" << endl;
	
	
	//Create the arrays first
	char *pointersArray = new char[8];
	char *areArray = new char[3];
	char *funnyArray = new char[5];
	
	*pointersArray = 'P';
	*(pointersArray+1) = 'O';
	*(pointersArray+2) = 'I';
	*(pointersArray+3) = 'N';
	*(pointersArray+4) = 'T';
	*(pointersArray+5) = 'E';
	*(pointersArray+6) = 'R';
	*(pointersArray+7) = 'S';
	
	*areArray = 'A';
	*(areArray+1) = 'R';
	*(areArray+2) = 'E';

	
	*funnyArray = 'F';
	*(funnyArray+1) = 'U';
	*(funnyArray+2) = 'N';
	*(funnyArray+3) = 'N';
	*(funnyArray+4) = 'Y';
	
	
	//Create the array next to the character arrays
	char** firstArray = new char*[3];
	
	*firstArray = pointersArray;
	*(firstArray+1)= areArray;
	*(firstArray+2)= funnyArray;
	
	//Create the array at the top of the picture
	char***secondArray = new char**[3];
	*secondArray = (firstArray+2);
	*(secondArray+1) = (firstArray+1);
	*(secondArray+2) = firstArray;
	
	//create the final variable
	char**** p = &secondArray;
	
	
	//***********************************************
	//The following lines print as requested in the worksheet
	
	//Prints "POINTERS"
	for(int i=0; i<8; i++)
		cout << *(**((*p)+2)+i);
	
	cout << endl;
	//'E' from "ARE"
	cout << *(**((*p)+1)+2);
	
	cout << endl;
	//'Y' from "FUNNY"
	cout << *(**((*p))+4);
	
	
	//*************************
	//clean up at the end
	delete [] pointersArray;
	delete [] areArray;
	delete [] funnyArray;
	delete [] firstArray;
	delete [] secondArray;
	
	return 0;

}