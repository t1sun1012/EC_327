#include <iostream>
using namespace std;

int main()
{
  int count = 1;
  int &refCount = count;
  
  cout << "count is " << count << endl;
  cout << "refCount is " << refCount << endl;
  
  refCount++;
  cout << "count is " << count << endl;
  cout << "refCount is " << refCount << endl;

  count = 10;
  cout << "count is " << count << endl;
  cout << "refCount is " << refCount << endl;
  
  return 0;
}
