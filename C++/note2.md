# Intro to C/C++

- Loops/Control flow
    - if, while, for, switch
- "Basic Syntax"
    - Syntax vs Semantics
- Compilation Flow



```C++
// preprocessing directive
# include <iostrem> // standard library
"" // paranthese are for file path

# define PI 3.14
using namespace std;
// if not using std, need to use std::
std::cout <<"test";

// all of the above are happening before the main function
// write code
// return type, then function name
int main()
{
    //double is the type, r is the variable 
    double r;
    cout <<"Input Radius"; // console output
    cin >> r; // console input
    double area = r * r * PI;
    // type, variable, = Assign to a value
    cout << "The area is ";
    cout  << area << endl;
    // area is the vraiable, no quotation mark
    cout << sizeof(int) << " " << sizeof(long double) << endl;
    // size of (int) is a function
    // variables are bits => how big

    return 0; // return the type int, main function want return 0 or 1 or other integer
}
```

## Errors
- Syntax error 
    - Wrote wrong 
- Logic error
    - Bad ideas
- Runtime errors
    - Bad input/context/etc


## Casting
upcasting -> Widening
downcasting -> narrowing

0 to 0.0
0.0 to 0



## Example

```C++
if (answer == 'Y')
    date += 1;
```

```C++
double u = 2.6;
double g = u++; // first assign, then increment
double g = ++u; // first increment, then assign
```



### Switch Loop

Sequantial evaluation in switch
Variable:
- int -> any integers
- bool -> 0,1
- char -> ASCII value

```C++
switch(variable) // variable evaluate to int
{
    // no expression after case, integer after case
    case 0: statement;
            statement;
            break;

            // prevent "fall through" using break

    case 1: statement;
            statement;
            break;

    default: statements;
}
```

----------------------------------------------------------------

## Functions
Why function:
- saves code and spce
- modular
- easy to debug

However, 
- due to context switching, functions can be slower
- Caller save vs. Callee save

Three thngs with functions
- define
- declare
- invoke (call)


```C++
// max is the function name, num1 and num2 are the parameters
// need a return type before the function name

int max(int num1, int num2); // declare the prototype function

int max(int num1, int num2) // defining a function
{
    int result;
    if (num1 > num2) {
        result = num1;
    }
    else {
        result = num2;
    }
    return result;
}
// function declared after the body of the function
```


```C++
int val = 2;
int best = 4;
int cool = max(val, best); // invoke/call a function
// pass by value 
```

### Function Overloading
- same name
- different argument
    - types
    - numbers
- cannot do it on Return type, which means same name, same argument, different return type is not allowed.

[example: ./Functions/TestFunctionOverloading.cpp](./Functions/TestFunctionOverloading.cpp)

### library with function
Use the library function

[example code:C++/Functions/MyLib.cpp](./Functions/MyLib.cpp)


```bash
g++ UseMyLib.cpp MyLib.cpp
```
or 

```bash
g++ -c MyLib.cpp
```

this will make the library into the compiler and create a MyLib.o, and this is in binary and prevent to see the content in the original library, but the user can still use the library.

```bash
g++ UseMyLib.cpp MyLib.o
```

Linker will link two cpp file together and output one executable file.


function prototype
```C++
// function signature with variable declared
int max(int foo, int fah);

// function signature without variable declared
int max(int, int)
```
-------------------------------------------------------------

## Recursion

In Dynamic Programming

- function calling itself



Reasons for and not for 
- Not used for efficiency
- Are used for 
    - Natural way to solve a problem

    and/ or
    - "only" way to solve a problem

### Requirements
1.  Base Case
    - when the function will return
2.  "simpler"
    - approaching the base case
3. Call the function


### Example:

#### Factorial
4！ = 4 * 3 * 2 * 1 = 24
0！ = 1

fact(4)
->  4 * fact(3)
        -> 3 * fact(2)
                -> 2 * fact(1)
                        -> 1* fact(0)
                            -> fact(0) is the base case which is 1


```C++
int fact(int); // prototype

int main() {
    cout << "Enter a number";
    int n;
    cin >> n;
    cout << fact(n);
    return 0;
}

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return fact(n-1) * n
    }
}
```


#### Fibonacci

number: 0, 1, 1, 2, 3, 5, 8, 13
index:  0, 1, 2, 3, 4, 5, 6, 7

fib(4)
-> fib(3)         +      fib(2)
-> fib(2) + fib(1)
-> fib(1) + fib(0)


```C++
// The function for finding the Fibonacci number
int fib(int);

int main()
{
  // Prompt the user to enter an integer
  cout <<  "Enter an index for the Fibonacci number: ";
  int index;
  cin >> index;

  // Display factorial
  cout << "Fibonacci number at index " << index << " is "
    << fib(index) << endl;

  return 0;
}

// The function for finding the Fibonacci number
int fib(int index)
{
  if (index == 0) // Base case
    return 0;
  else if (index == 1) // Base case
    return 1;
  else // Reduction and recursive calls
    return fib(index - 1) + fib(index - 2);
}
```



#### Towers of Hanoi
TBD -> Dining Phil -> schedulings




from tower.              to tower               Aux tower

```C++
/* The function for finding the solution to move n disks
    from fromTower to toTower with auxTower */
void moveDisks(int n, char fromTower,
    char toTower, char auxTower)
{
  if (n == 1) // Stopping condition
    cout << "Move disk " << n << " from " <<
      fromTower << " to " << toTower << endl;
  else
  {
    moveDisks(n - 1, fromTower, auxTower, toTower);
    cout << "Move disk " << n << " from " <<
      fromTower << " to " << toTower << endl;
    moveDisks(n - 1, auxTower, toTower, fromTower);
  }
}

int main()
{
  // Read number of disks, n
  cout << "Enter number of disks: ";
  int n;
  cin >> n;

  // Find the solution recursively
  cout << "The moves are: " << endl;
  moveDisks(n, 'A', 'B', 'C');

  return 0;
}
```


### Types of Recurssion

- Head Recurssion

```C++
int rfc() {
    rfc()

    do stuff
}
```

- Tail Recurssion

```C++
int rfc() {
    do stuff

    rfc()
}
```
"Loop"



-------------------------------------------------------------

## File

```C++
#include <fstream>
    // Read
    ifstream input("./foo.txt");
    // type and a object
    string firstName;
    input >> firstName; // assign the content in the file to the varibale firstName

    input.close();
    // or
    while(!input.eof()) // eof stands for end of file
```

```C++

ofstream output;
output.open("./output.txt");
output << "test";
output.close();
```