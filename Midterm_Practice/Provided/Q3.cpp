//Provided Code
#include <iostream>
using namespace std;

//Put your code here
void ptrsAreFun()
{
	//Put your code for picture 1 here	

	
	
	//Last 3 lines of this section DON'T CHANGE
	cout << ptrArray[0] << " " << ptrArray[1] << endl;
	cout << j << " " << *ptrJ << " " << ptrJ << endl;
	cout << i << " " << *ptrI << " " << ptrI << endl;
	//***********************************************************
	
	
	//Put your code for picture 2 here

		
	//Last 4 lines of this section DON'T CHANGE
	cout << values[38] << " " << *ptrD << endl;		
	int *testPtr = new int;
	*testPtr = 56;
	cout << values[38] << " " << *ptrD << endl;
	//***********************************************************
	
	
	//Put your code for picture 3 here

	
	
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
?? pointerSwap(??)
{
	??
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

