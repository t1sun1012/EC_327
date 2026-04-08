#include <iostream>

using namespace std;

int main()
{
	char char1 = 'a';
	char char2 = 'b';
	char char3[4] = {'c', 'g', 'j', 'k'};
	char *ptr[3];

	ptr[0] = &char1;
	ptr[1] = &char2;
	ptr[2] = char3; // Would this give you an error?
	// Can you think of any other ways to achieve this?


	cout << "char1: " << *ptr[0] << endl;
	cout << "char2: " << *ptr[1] << endl;
	cout << "char3: " << *ptr[2] << endl;	// What would this return?
	// Is there any way to print all characterts of the character array?

	return 0;

}
