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
// function declared aftr the body of the function
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