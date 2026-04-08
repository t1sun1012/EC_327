#include <iostream>
using namespace std;

const int INTMIN = 0;

int maxEntry(const int* const Data, int Sz) { // Line 1

	if ( Data == NULL || Sz <= 0 ) return INT_MIN; // 2
	
	int Count = 0; // 3

	// Set hiSoFar to point to the first array element:
	//const int *hiSoFar = __________; // 4
	//const int *hiSoFar = Data; // 1 - OK
	//const int *hiSoFar = *Data; // 2 - Won't even compile
	//const int *hiSoFar = &Data; // 3 - Won't even compile
	const int *hiSoFar = &Data[0]; // 4 - OK
	//const int *hiSoFar = Data[0]; // 5 - Won't even compile

	
	
	// Set Current to point to the second array element:
	//const int *Current = __________; // 5
	//const int *Current = hiSoFar; // 1 - Fine but logically wrong
	//const int *Current = hiSoFar++; // 2 - Fine but logically wrong; post increment and don't want to change hiSoFar;
	//const int *Current = Data++; // 3 - Won't compile since you can't change data
	const int *Current = &Data[1]; // 4 - OK
	//const int *Current = Data[1]; // 5 - Won't compile
	cout << Current << " " << hiSoFar << endl;
	

	for ( ; Count < Sz-1; Count++, Current++) { // 6
		if (*Current > *hiSoFar) // 7
			hiSoFar = Current; // 8
	}
	

	return (*hiSoFar); // 9
	//return 66;
}

/*
1) int* - Fine
2) int*& - Will compile but not what you want
3) const int* - Can't set to zero this way since data is constant
4) int* const - Can't make it "new" since the pointer is constant
5) const int* const - Previous reasons
*/
void ZeroIt(int* A, const int Size) {
	A = new int[Size];
	for (int Idx = 0; Idx < Size; Idx++) {
		A[Idx] = 0;
	}
}



int main()
{
  int list[] = {1, 2, 3, 4, 5, 6};
  
  cout << maxEntry(list, 6) << endl;
 
  //g++ will use an extension to get around this; -pedantic to catch this 
  //-Wall -std=c++98
  const int size = 10; 
  //int size = 10;
  //size = 1;
  int list2[size];
  list2[3] = 10;
  cout << list2[0] << endl;
  
  int *list3 = new int[size];
  cout << list3[0] << endl;
  
  const int Size = 5;
  int *A = new int[Size];
  int* p = &A[0];
  //int *p = list2;
  A = new int[2*Size];
  delete [] p; //works when it points at A
  cout << p[3] << endl;
  
 
  int *z;
  ZeroIt(z, 5);
 
  return 0;
}
