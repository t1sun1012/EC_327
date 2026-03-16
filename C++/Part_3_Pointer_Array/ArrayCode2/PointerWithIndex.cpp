#include <iostream>
using namespace std;

int main()
{
  int list[6] = {11, 12, 13, 14, 15, 16};
  //int *pList = &list[0];
  int *pList = list;
  //int *pList = NULL;
  //pList = list //Good
  //list = pList;//Bad
  
  for (int i = 0; i < 6; i++)
    cout << "address: " << (list + i) <<
      " value: " << *(list + i) << " " <<
      " value: " << list[i] << " " <<
      " value: " << *(pList + i) << " " <<
      " value: " << pList[i] << " " << 
	  " address: " << pList << " " << 
	  " address: " << list << " " <<
	  " address: " << &list << " " << endl;

  return 0;
}
