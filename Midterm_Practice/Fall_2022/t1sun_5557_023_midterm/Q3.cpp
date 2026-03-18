//Provided Code
#include <iostream>
using namespace std;

//Put your code here
void ptrsAreFun()
{
	//Put your code for picture 1 here	
	int i = 10;
	int j = 20;
	int *ptrI = &i;
	int *ptrJ = &j;

	int* ptrArray[2];
	ptrArray[0] = ptrJ;
	ptrArray[1] = ptrI;
	
	//Last 3 lines of this section DON'T CHANGE
	cout << ptrArray[0] << " " << ptrArray[1] << endl;
	cout << j << " " << *ptrJ << " " << ptrJ << endl;
	cout << i << " " << *ptrI << " " << ptrI << endl;
	//***********************************************************
	
	
	//Put your code for picture 2 here
	double *values = new double[40];
	values[38] = 3.65;
	double *ptrD = &values[38];

	delete [] values;
	// delete values;
		
	//Last 4 lines of this section DON'T CgitHANGE
	cout << values[38] << " " << *ptrD << endl;		
	int *testPtr = new int;
	*testPtr = 56;
	cout << values[38] << " " << *ptrD << endl;
	//***********************************************************
	


	//Put your code for picture 3 here
	short *ptr1;
	short *ptr2;

	short **ptrList[100];

	ptrList[57] = &ptr1;
	ptrList[79] = &ptr2;


	short *a_value = new short(50);

	
	ptr1 = a_value;
	ptr2 = a_value;

	delete *ptrList[79];



	
	
	//Last 10 lines of this section DON'T CHANGE
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;
	cout << *ptrList[57] << endl;
	cout << *ptrList[79] << endl;
	int *testPtr2 = new int;
	*testPtr2 = 68;
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;
	cout << *ptrList[57] << endl;
	cout << *ptrList[79] << endl;
}


/*Put your pointerSwap function here
This function should take a pointer to an int as an argument
Create new pointer pointing to an int value of 33 on the heap
Then assign the pointer argument to point at the new heap value just created
The pointer argument originally passed should be changed as a result when the function returns (aka swap the pointer)
This is a void function.
*/
void pointerSwap(int * &ptr)
{
	int *new_ptr = new int(33);
	ptr = new_ptr;
}






/*
 This code is presented for you to test your code. No need to change it (but you can if you want)
*/

int main()
{

	//Section 1 - Recreate pictures in midterm booklet
	ptrsAreFun();

	cout << "*******************" << endl;
	
	//Section 2 - Test the pointerSwap function
	int foo = 10;
	int *test = &foo;
	pointerSwap(test);
	cout << *test << endl;

	return 0;

}

