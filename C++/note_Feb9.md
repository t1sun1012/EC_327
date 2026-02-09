# Intro to C/C++

- Loops/Control flow
    - if, while, for, switch
- "Basic Syntax"
    - Syntax vs Semantics
- Compilation Flow

Next time: function

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

```C++
if (answer == 'Y')
    date += 1;
```