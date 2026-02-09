#include <iostream>
using namespace std;

int increment(int n) {
  n++;
  cout << "n inside the function is " << n << endl;
}

int main()
{
  int x = 1;
  cout << "Before the call, x is " << x << endl;
  increment(x);
  cout << "after the call, x is " << x << endl;

  return 0;
}
