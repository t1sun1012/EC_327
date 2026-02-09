#include <iostream>
using namespace std;

void increment(int &n) {
  n++;
  cout << "n inside the function is " << n << endl;
}

int main()
{
  int x = 1;
  int y = 3;
  cout << "Before the call, x is " << x << endl;
  increment(x);
  cout << "after the call, x is " << x << endl;
  increment(y);
  cout << "after the call, x is " << x << endl;
  cout << "after the call, y is " << y << endl;

  return 0;
}
