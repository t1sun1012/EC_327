#include <iostream>
using namespace std;

int main()
{
  int count = 5;
  int *pCount = &count;
  int &cntRefVar = count;

  cout << "The value of count is " << count << endl;
  cout << "The address of count is " << &count << endl;
  cout << "The address of count is " << pCount << endl;
  cout << "The value of count is " << *pCount << endl;
  cout << "The address of pcount is " << &pCount << endl;


  cout << "Test for class " << 	cntRefVar << endl;
  cout << "Test for class2 " << &cntRefVar << endl;
  
  
  return 0;
}
