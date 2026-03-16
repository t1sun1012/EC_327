#include <iostream>
// <> library in compiler

#include "mylib.h"
// header file that import the prototype function
// the body of the function will be in the library function file 

using namespace std;

int main()
{
  cout << isEven(4) << endl;
  cout << isEven(5) << endl;

  return 0;
}
