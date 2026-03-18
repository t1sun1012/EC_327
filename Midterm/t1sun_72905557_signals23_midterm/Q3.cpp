#include <iostream>
using namespace std;

//Put your code here
void ptrsAreRadical()
{
	//Put your code for picture 1 here	
	double q = 24.2;
	double k = 32.6;
	double * ptrQ = &q;
	double * ptrK = &k;

	double * heap_ptr_p2 = new double(10.5);
	double *ptrH = heap_ptr_p2;

	double *ptrFun[3];
	ptrFun[0] = ptrQ;
	ptrFun[1] = ptrH;
	ptrFun[2] = ptrK;

	
	
	//Last 4 lines of this section DON'T CHANGE
	cout << ptrFun[0] << " " << ptrFun[1] << " " << ptrFun[2] << endl;
	cout << q << " " << *ptrQ << " " << *ptrFun[0] << " " << ptrQ << endl;
	cout << k << " " << *ptrK << " " << *ptrFun[2] << " " << ptrK << endl;
	cout << *ptrFun[1] << endl;
	//***********************************************************
	
	
	//Put your code for picture 2 here
	short * coolStuff = new short[2];
	coolStuff[0] = 3;
	coolStuff[1] = 67;

	short * ptrStuff = &coolStuff[1];
	short ** ptrCool = &ptrStuff;

	delete [] coolStuff;


		
	//Last 6 lines of this section DON'T CHANGE
	cout << coolStuff[0] << " " << coolStuff[1] << " " << *ptrStuff << endl;
	cout << ptrStuff << " " << coolStuff + 1 << endl;
	cout << **ptrCool << endl;
	short *testPtr = new short;
	*testPtr = 69;
	cout << coolStuff[0] << endl;
	//***********************************************************
	
	
	//Put your code for picture 3 here
	int * heap_ptr_p3 = new int(50);
	int * ptr1 = heap_ptr_p3;


	int *ptrList[80];
	
	int ** ptr2 = &ptrList[0];

	ptrList[79] = heap_ptr_p3;


	delete ptrList[79]; 

	
	//Last 8 lines of this section DON'T CHANGE
	cout << *ptrList[79] << endl;
	cout << *ptr1 << endl;
	cout << **(ptr2+79) << endl;
	int *testPtr2 = new int;
	*testPtr2 = 68;
	cout << *ptrList[79] << endl;
	cout << *ptr1 << endl;
	cout << **(ptr2+79) << endl;
	//***********************************************************	
}

/*
Put your pointerAlternate function here
This function should take two double pointers as arguments (used as arrays)
It should also take an int for the size of the arrays pointed to by the other arguments (they will be the same size)
Create new array with the values from the other two arrays but alternating them starting with the first argument
Return that array
e.g
[4.5, 6.9, 8.1]
[6.0, 5.9, 1.2]
Result = [4.5, 6.0, 6.9, 5.9, 8.1, 1.2]

*/

 
double* pointerAlternate (double* array1, double* array2, int size) 
{
	double * result_array = new double[2*size];
	for (int i = 0, j = 0; (i < size*2) ; i += 2, j++) {
		result_array[i] = array1[j];

	}

	for (int i = 1, j = 0; i < size*2; i += 2, j++) {
		result_array[i] = array2[j];
	}
	return result_array;



}


/*
 This code is presented for you to test your code. No need to change it (but you can if you want)
*/

int main()
{

	//Section 1 - Recreate pictures in midterm booklet
	ptrsAreRadical();

	cout << "*******************" << endl;
	
	//Section 2 - Test the pointerAlternate function
	double test[4] = {1.1,2.2,3.3,4.4};
	double test2[4] = {5.5,6.6,7.7,8.8};
	double* result = pointerAlternate(test, test2, 4);
	for(int i =0; i<8; i++)
		cout << result[i] << " ";
	cout << endl;

	return 0;

}

