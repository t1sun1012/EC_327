#include <iostream>
using namespace std;

void t1(); // function prototype

int main()
{
  t1();
  t1();
  return 0;
}

void t1()
{
  static int x = 1; // only initialize once when calling the function in the first time
  int y = 1; // reinitialie if the function is called again
  x++;
  y++;
  cout << "x is " << x << endl;
  cout << "y is " << y << endl;
}
