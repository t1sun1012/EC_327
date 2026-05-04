#include <iostream>
#include <stack>
using namespace std;

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
stack<Function> callstack;


void call(string func_name, int val)
{
	callstack.push(Function(func_name, val));
}

int ret()
{
	int retVal= 0;
	Function func;
	if(!callstack.empty())
	{
		func = (Function)callstack.top();
		retVal = func.value; 
		callstack.pop();
	}
	return retVal;
}

void clearStack()
{
  Function foo;
  while (!callstack.empty())
  {
     foo = (Function)callstack.top();
	 cout << ' ' << foo.name;
     callstack.pop();
  }
  cout << '\n';
}


int main ()
{
  int value = 0;
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
  cout << "Final Value "<< value << endl;
  
  return 0;
}

