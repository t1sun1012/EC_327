#include <iostream>
using namespace std;

int main()
{
	
  //Narrowing Examples 
  double i = 1.7;
  int defaultCast = i;
  int cStyleCast = (int)i;
  int staticCast = static_cast<int>(i);
  cout << i << endl;
  cout << defaultCast << endl;
  cout << cStyleCast << endl;
  cout << staticCast << endl;
  
  //Widening Examples
  int j = 4;
  double staticCastDouble = static_cast<double>(j);
  cout << staticCastDouble << endl;
  cout << 1 / 2 << endl;
  cout << static_cast<double>(1) / 2 << endl;
  
  return 0;
}
