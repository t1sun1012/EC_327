#include <iostream>
#include <string>
using namespace std;



//Put destroy function here
/*
Four arguments
list - the list you are examining
listSize - the size of this list
destroyedSize - the size of the new list you will make
target - what you want to remove from the array

This function should make a new array that has the same order
of elements as the orginal array but removes the target elements

*/

//Put replace function here
/*
Four arguments
list - the list you are examining
listSize - the size of the list you are examining
insert - the element used to replace the target
target - the elements to be replaced with the insert

This function should return an array that is the same 
as the list BUT has all the targets replaced with insert

*/



//DO NOT MODIFY
template<typename T>
void printArray(T list[ ], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}


int main()
{
  int list1[] = {3, 5, 1, 0, 1, 8, 1, 9, 10, 1, 14};
  int realSize;
  
  //Uncomment when done
  /*
  int *destroyedList1 = destroy(list1, 11, realSize, 1);
  printArray(destroyedList1, realSize);
  int *replaceList1 = replace(list1, 11, 99, 1);
  printArray(replaceList1, 11);
  */
  
  
  double list2[] = {3.5, 0.5, 1.4, 0.4, 2.5, 1.8, 4.7, 2.5};
  //Uncomment when done
  /*
  double *destroyedList2 = destroy(list2, 8, realSize, 2.5);
  printArray(destroyedList2, realSize);
  double *replaceList2 = replace(list2, 8, 4.0, 3.5);
  printArray(replaceList2, 8);
 */
  
  char list3[] = {'B', 'C', 'B', 'L', 'B', 'B', 'H'};
  //Uncomment when done
  /*
  char *destroyedList3 = destroy(list3, 7, realSize, 'B');
  printArray(destroyedList3, realSize);
  char *replaceList3 = replace(list3, 7, '9', 'B');
  printArray(replaceList3, 7);
  */
  
  cout << "Q5 compiles" << endl;
}


