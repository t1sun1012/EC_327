#include <iostream>
#include <stack>
using namespace std;

//DO NOT MODIFY THIS CLASS
class Function
{	
	public:
		Function()
		{}
		
		Function(string n, int v)
		{
			name = n;
			value = v;
		}
		
		string name;
		int value;
};


//Stack functions - you ONLY need these (and maybe not all of them)
/*
void push (const value_type& val);
bool empty() const;
void pop();
size_type size() const;
value_type& top();
*/
//LEAVE THIS AS IT IS
stack<Function> callstack;

//Add the call function here
//This needs to add a function object to the stack


//Add the ret function here
//This needs to return an int that is the value of the Function object on the top of the stack
//Pop the stack as well
//Make sure something is on the stack; If not just return 0

//Add the clearStack function here
//Print the name of each function on the stack
//Remove the elements along the way (should be empty when done)
//Format: func1 func2 func3 func4 \n


//DO NOT CHANGE; Just uncomment
int main ()
{
  int value = 0;
  /*
  call("Foo", 10);
  call("Fah", 11);
  value += ret();
  value += ret();
  value += ret();
  call("Fee", 23);
  call("Fi", 56);
  call("Foo", 100);
  value += ret();
  clearStack();
  call("Foo", 1);
  call("Fah", 2);
  call("Fee", 3);
  call("Fi", 4);
  value += ret();
  clearStack();
  value += ret();
  value += ret();
  */
  cout << "Final Value "<< value << endl;
  
  return 0;
}

