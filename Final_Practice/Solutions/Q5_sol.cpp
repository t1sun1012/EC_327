#include <iostream>
#include <string>
using namespace std;


template<typename T>
T *destroy(T list[ ], int listSize, int &destroyedSize, T target)
{
  int foundTargets = 0;
  for (int i =0; i<listSize; i++)
  {
	  if (list[i] == target)
      {
        foundTargets++; 
      }
  }
  
  destroyedSize = listSize-foundTargets;
  T *returnList = new T[destroyedSize];
  
  int j = 0;
  for (int i =0; i<listSize; i++)
  {
	if (list[i] != target)
      {
		returnList[j] = list[i];
		j++;
	  }
  
  }
  
  return returnList;
}

template<typename T>
T *replace(T list[ ], int listSize, T insert, T target)
{
	T *returnList = new T[listSize];
	
	for (int i=0; i<listSize; i++)
	{
		if(list[i] == target)
			returnList[i] = insert;
		else
			returnList[i] = list[i];
	}

	return returnList;

}


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
  int *destroyedList1 = destroy(list1, 11, realSize, 1);
  printArray(destroyedList1, realSize);
  int *replaceList1 = replace(list1, 11, 99, 1);
  printArray(replaceList1, 11);
 
  
  double list2[] = {3.5, 0.5, 1.4, 0.4, 2.5, 1.8, 4.7, 2.5};
  double *destroyedList2 = destroy(list2, 8, realSize, 2.5);
  printArray(destroyedList2, realSize);
  double *replaceList2 = replace(list2, 8, 4.0, 3.5);
  printArray(replaceList2, 8);

  
  char list3[] = {'B', 'C', 'B', 'L', 'B', 'B', 'H'};
  char *destroyedList3 = destroy(list3, 7, realSize, 'B');
  printArray(destroyedList3, realSize);
  char *replaceList3 = replace(list3, 7, '9', 'B');
  printArray(replaceList3, 7);
  
  cout << "Q5 compiles" << endl;
  
}


