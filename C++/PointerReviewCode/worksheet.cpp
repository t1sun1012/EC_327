#include <iostream>
using namespace std;


int main()
{
  int foo = 365;
  int *fooPtr = &foo;
  
  int *fooPtr2 = fooPtr;
  //int *fooPtr2 = &foo;
  foo = 456;
  //*fooPtr = 456;
  //*fooPtr2 = 456;
  cout << *fooPtr << " " << *fooPtr2 << endl;
  cout << fooPtr << " " << fooPtr2 << endl;
  
  
  fooPtr = new int;
  *fooPtr = 88;
  *fooPtr2 = 900;
  cout << *fooPtr << " " << *fooPtr2 << endl;
  cout << fooPtr << " " << fooPtr2 << endl;
  
  fooPtr = new int;
  *fooPtr = 9021;
  cout << *fooPtr << " " << *fooPtr2 << endl;
  cout << fooPtr << " " << fooPtr2 << endl;
  
  //delete fooPtr;
  cout << *fooPtr << " " << *fooPtr2 << endl;
  cout << fooPtr << " " << fooPtr2 << endl;
  int *fooPtr3 = new int;
  cout << fooPtr3 << endl;
  
  return 0;
}
