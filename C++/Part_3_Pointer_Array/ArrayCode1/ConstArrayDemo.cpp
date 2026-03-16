#include <iostream>
using namespace std;

void p(int const list[], int arraySize)
{
  // Modify array accidentally
  //list[0] = 100; // Compile error!
}

int main()
{
  //int five = 5;
  int numbers[5] = {1, 4, 3, 6, 8};
  p(numbers, 5);

  return 0;
}
