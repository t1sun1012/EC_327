#include <iostream>
//#define PI 3.14159
using namespace std;

int main() {
  const double PI = 3.14159; //NOT USED; Example

  // Step 1: Read in radius
  double radius;
  cout << "Input radius " << endl;
  cin >> radius;

  // Step 2: Compute area
  double area = radius * radius * PI;

  // Step 3: Display the area
  cout << "The area is ";
  cout << area << endl;
  cout << sizeof(int) << " " << sizeof(long double) << endl;

  return 0;
}
