//Prof. Douglas Densmore
//10-20-21

#include <iostream>

using namespace std;

int main()
{

	cout << "Pointer Fun!" << endl;
	
	//sets the inital pointer to a 3 entry array of pointers to pointers
	char ***p = new char **[3]; 
	
	/*this sets the 3rd element of the array you just made point to a 3 entry array
	of pointers*/
	*(p+2) = new char *[3]; 
	
	
	/*this sets the 1st of the array you just made point to a 8 entry array
	of characaters you are going to fill with the word "Pointers"*/
	**(p+2) = new char[8];
	
	//Fill up the first array
	***(p+2) = 'P';
	*(**(p+2)+1) = 'O';
	*(**(p+2)+2) = 'I';
	*(**(p+2)+3) = 'N';
	*(**(p+2)+4) = 'T';
	*(**(p+2)+5) = 'E';
	*(**(p+2)+6) = 'R';
	*(**(p+2)+7) = 'S';
	
	/*
	This makes the second element of the top array 
	*/
	*(p+1) = (*(p+2)+1);
	//*(p+1) = &(*(*(p+2)+1));//Think why this would work too!
	
	/*
	This makes the first element of the top array 
	*/
	*p = (*(p+2)+2);
	//*p = &(*(*(p+2)+2));//Think why this would work too!
	
	//This is the array that is going to hold "ARE"
	**(p+1) = new char[3];
	
	***(p+1)= 'A';
	*(**(p+1)+1)= 'R';
	*(**(p+1)+2)= 'E';
	
	//This is the array that is going to hold "FUNNY"
	**(p) = new char[5];
	
	***(p)= 'F';
	*(**(p)+1)= 'U';
	*(**(p)+2)= 'N';
	*(**(p)+3)= 'N';
	*(**(p)+4)= 'Y';
	
	//***********************************************
	//The following lines print as requested in the worksheet
	
	//Prints "POINTERS"
	for(int i=0; i<8; i++)
		cout << *(**(p+2)+i);
	
	cout << endl;
	//'E' from "ARE"
	cout << *(**(p+1)+2);
	
	cout << endl;
	//'Y' from "FUNNY"
	cout << *(**(p)+4);
	
	//*************************
	//clean up at the end
	
	delete [] **(p+2);//deletes the array holding POINTERS
	delete [] **(p+1);//delates the array holding ARE
	delete [] **(p);//deletes the array holding FUNNY
	delete [] *(p+2);//deletes the second array
	delete [] p;//deletes the first array

	return 0;

}