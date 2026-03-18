#include <iostream>
using namespace std;

//Put your code here
void ptrsAreReallyFun()
{
	//Put your code for picture 1 here	
	char midtermArray[2] = {'z', 'F'};
	char *arrayOfPtrs[2];
	arrayOfPtrs[1] = &midtermArray[1];
	
	char testChar = 'A';
	arrayOfPtrs[0] = &testChar;

	char * ptrToArray = &midtermArray[0];




	
	//Last 4 lines of this section DON'T CHANGE
	cout << "Picture 1" << endl;
	cout << midtermArray[0] << " " << *(midtermArray+1) << endl;
	cout << *ptrToArray << " " << *arrayOfPtrs[1] << endl;
	cout << testChar << " " << *arrayOfPtrs[0] << endl;
	//***********************************************************
	
	
	//Put your code for picture 2 here
	double *heapPtrArray[2];
	heapPtrArray[0] = new double(75.7);
	heapPtrArray[1] = new double(101.79);



		
	//Last 2 lines of this section DON'T CHANGE
	for (int i=0; i<2; i++)
	cout << *(heapPtrArray+i) << endl;

	
	//***********************************************************
	
	
	//Put your code for picture 3 here
	int * value = new int(63); // value is the pointer
	int * intermedPtr = value;
	int * badPtr = value;

	int ** deAllocPtr = &intermedPtr;

	delete deAllocPtr;


		
	//Last 8 lines of this section DON'T CHANGE
	cout << *intermedPtr << endl;
	cout << **deAllocPtr << endl;
	cout << *badPtr << endl;
	int *testPtr = new int;
	*testPtr = 56;
	cout << *intermedPtr << endl;
	cout << **deAllocPtr << endl;
	cout << *badPtr << endl;
	
	
}


/*Put your shiftElementsLower function here
This function takes a pointer to an array and a size
It then should return a new array that has all the same elements 
BUT they are each shifted one position lower (one index lower). The lowest
element should "wrap around" and end up being the last element (now 
the highest element).
*/

int * shiftElementsLower(int * px, int size) 
{ 
	//Add code here
	int *returnArray = new int[size];
	for (int i = 0; i<size; i++) {
		returnArray[i] = px[i];
	}

	int temp = returnArray[0];


	for (int i = 0; i< size - 1; i++) {
		returnArray[i] = returnArray[i+1];
	}
	returnArray[size -1] = temp;

	return returnArray;
}


/*
 This code is presented for you to test your code. No need to change it (but you can if you want)
*/

int main()
{

	//Section 1 - Recreate pictures in midterm booklet
	ptrsAreReallyFun();

	
	//Section 2 - create the shiftElementsLower function
	int array[5] = {1, 2, 3, 4, 5};
	int *newArray = shiftElementsLower(array, 5);
	
	for(int i = 0; i<5; i++)
	{
		cout << newArray[i] << " ";
	}
	return 0;

}

